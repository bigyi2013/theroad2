import cv2
from matplotlib import pyplot as plt
def test1():
    ksize=100
    sigma=0.3*((ksize-1)*0.5 - 1) + 0.8
    kernal=cv2.getGaussianKernel(ksize,5)
    plt.plot(kernal)
    plt.show()
    print(kernal)