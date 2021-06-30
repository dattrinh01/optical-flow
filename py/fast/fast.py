import numpy as np
import cv2
import time

cap = cv2.VideoCapture("/home/dat/data2.mp4")
prev_frame_time, new_frame_time = 0,0

while (cap.isOpened()):
    ret, frame = cap.read()
    if ret:
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        new_frame_time = time.time()

        fast = cv2.FastFeatureDetector_create()

        keypoint = fast.detect(frame, None)
        result = cv2.drawKeypoints(gray, keypoint, None, color = (255,0,0))
        
        fps = 1/(new_frame_time - prev_frame_time)
        font = cv2.FONT_HERSHEY_SIMPLEX
        prev_frame_time = new_frame_time
        print(fps)
        cv2.imshow("frame", result)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()