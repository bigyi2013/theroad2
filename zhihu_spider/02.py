import os
import re
from bs4 import BeautifulSoup
import requests
import time, threading
import queue


def error_log(url):
    with open(error_log_file, 'a') as f:
        f.write('"')
        f.write(str(url))
        f.write('";')


def worker(que):
    while True:
        if not que.empty():
            url = que.get()
            if download(url) == False:
                error_log(url)
            # print('下载' + str(url) + '成功')
            que.task_done()
        else:
            break


def download(url):
    if not os.path.exists(folder):
        os.makedirs(folder)
    name = "./" + folder + '/' + url.split('/')[-1]
    if os.path.exists(name):
        return
    try:

        req = session.get(url)
        if req.status_code == requests.codes.ok:
            with open(name, 'wb') as f:
                f.write(req.content)
            return True
        else:
            return False
    except:
        return False


def init_url(url):
    ua = {
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36'}
    s = requests.Session()
    s.headers.update(ua)
    ret = s.get(url)
    # s.headers.update({"authorization":"oauth c3cef7c66a1843f8b3a9e6a1e3160e20"})
    return s


def fetch_answer(s, qid, limit, offset):
    params = {
        'sort_by': 'default',
        'include': 'data[*].is_normal,admin_closed_comment,reward_info,is_collapsed,annotation_action,annotation_detail,collapse_reason,is_sticky,collapsed_by,suggest_edit,comment_count,can_comment,content,editable_content,voteup_count,reshipment_settings,comment_permission,created_time,updated_time,review_info,relevant_info,question,excerpt,relationship.is_authorized,is_author,voting,is_thanked,is_nothelp,is_labeled;data[*].mark_infos[*].url;data[*].author.follower_count,badge[*].topics',
        'limit': limit,
        'offset': offset
    }
    url = "https://www.zhihu.com/api/v4/questions/" + qid + "/answers"
    return s.get(url, params=params)


def get_image_urls(answers):
    soup = BeautifulSoup(answers, "html.parser")
    jpg = re.compile(r'data-actualsrc="(.*?)"')
    jpg1 = re.compile(r'data-original="(.*?)"')
    img_urls = []
    for tag in soup.find_all('noscript'):
        if len(jpg1.findall(str(tag))) >= 1:
            img_urls += jpg1.findall(str(tag))
        else:
            img_urls += jpg.findall(str(tag))

    return img_urls

def get_images(answers):
    img_urls=get_image_urls(answers)
    with open(url_log_file, 'a') as f:
        f.write(str(img_urls))
    que=queue.Queue()
    for url in img_urls:
        que.put(url)
    for i in range(6):
        t=threading.Thread(target=worker(que))
        t.daemon = True
        t.start()
    que.join()
url = "https://www.zhihu.com/question/46508954"
error_log_file = './log/error_log.txt'
url_log_file = './log/url_log.txt'
folder = '03'
session = init_url(url)
offset = 700
limit = 10
q_id = url.split('/')[-1]
is_end = False
while not is_end:
    time.sleep(10)
    ret = fetch_answer(session, q_id, limit, offset)
    print(offset, '返回值', ret)
    answers = ret.json()['data']
    offset += limit
    for ans in answers:
        print('next id')
        get_images(ans['content'])
    is_end = ret.json()['paging']['is_end']



