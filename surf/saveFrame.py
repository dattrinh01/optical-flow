import numpy as np
import cv2 as cv
import os

video = cv.VideoCapture("data2.mp4")
path = "/home/dat/optical-flow/frame"
count = 0
success = 1
while success:
    success, image = video.read()
    cv.imwrite(os.path.join(path, "frame %d.jpg") % count, image)
    count+=1