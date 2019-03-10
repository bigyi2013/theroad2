# 这种命名方式真是可以，test2.py   你赢了好不好
def my_callback(input):
    print("function my_callback was called with {}".format(input))


def caller(input, func):
    func(input)


for i in range(5):
    caller(i, my_callback)

