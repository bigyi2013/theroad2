import threading,time
def key():
    global keys
    while True:
        print(1)
        keys=input()
def printkey():
    while True:
        print(2)
        print(keys)
keys=str('start')
t1=threading.Thread(target=key())
t2=threading.Thread(target=printkey())
t1.start()
t2.start()
t1.join()
t2.join()