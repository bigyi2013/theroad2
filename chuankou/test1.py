import serial
from time import sleep


if __name__ == '__main__':
    serial = serial.Serial('COM2', 9600, timeout=0.5)  #/dev/ttyUSB0
    if serial.isOpen() :
        print("open success")
    else :
        print("open failed")

    while True:
        serial.write(b'hello')  # 向端口写数据