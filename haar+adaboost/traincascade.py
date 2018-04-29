import cv2
import numpy as np
import time
class Params(object):
    def __init__(self):
        self.numPos = 0
        self.numNeg = 0
        self.numStages = 0
def train(params):
    for i in range(params.numStages):
        print('=========TRAINING',i,'-stage ================')
        print('<BEGIN')

def main():
    params=Params()
    params.numPos=100
    params.numNeg=100
    params.numStages=20
    train(params)
if __name__ == '__main__':
  main()