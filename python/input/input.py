from tkinter import *


def call_back(event):
    print(event.char)  # 按哪个键，在Shell中打印


def main():
    root = Tk()

    # 创建一个框架，在这个框架中响应事件
    frame = Frame(root,
                  width=200, height=200,
                 )

    frame.bind("<Key>", call_back)
    frame.pack()

    # 当前框架被选中，意思是键盘触发，只对这个框架有效
    frame.focus_set()

    mainloop()


if __name__ == '__main__':
    a=1
    main()