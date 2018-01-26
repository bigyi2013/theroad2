import os
def rename():
    path='C:/theroad/opencv/image'
    filelist=os.listdir(path)
    i=0
    for files in filelist:
        old=os.path.join(path,files)
        i+=1
        if os.path.isdir(old):
            continue
        filename=os.path.splitext(files)[0]
        filetype = os.path.splitext(files)[1]
        image=str('image'+str(i))
        new=os.path.join(path,image+filetype)
        os.rename(old,new)
rename()