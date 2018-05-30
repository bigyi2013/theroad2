from multiprocessing import Process
import time
def funa():
    global key
    while True:
        key=input()
def funb():
    global key
    key=1
    while True:
        time.sleep(0.01)
if __name__=='__main__':
    p1= Process(target=funa)
    p2 = Process(target=funb)
    p1.start()
    p2.start()

