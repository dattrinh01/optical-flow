import numpy as np
import cv2 as cv
import time
import matplotlib.pyplot as plt


cap = cv.VideoCapture("/home/dat/data2.mp4")
prev_frame_time, new_frame_time = 0, 0

while(cap.isOpened()):
    ret, frame = cap.read()
    if ret:
        gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
        new_frame_time = time.time()

        surf = cv.xfeatures2d.SURF_create()
        kp, des = surf.detectAndCompute(gray, None)
        surf.getHessianThreshold()
        surf.setHessianThreshold(300)
        rs = cv.drawKeypoints(
            gray, kp, None, flags=cv.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
        surf.setUpright(True)
        surf.setExtended(True)

        fps = 1/(new_frame_time - prev_frame_time)
        prev_frame_time = new_frame_time
        print(fps)
        cv.imshow("frame", rs)

    if cv.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv.destroyAllWindows()
