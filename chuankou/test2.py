import serial
from time import sleep

def recv(serial):
    while True:
        data = serial.read(10)
        if data == '':
            continue
        else:
            break
        sleep(0.02)
    return data

if __name__ == '__main__':
    serial = serial.Serial('COM4', 9600, timeout=0.5)  #/dev/ttyUSB0
    if serial.isOpen() :
        print("open success")
    else :
        print("open failed")

    while True:
        data=recv(serial)
        if data != b'' :
            print("receive : ",data)