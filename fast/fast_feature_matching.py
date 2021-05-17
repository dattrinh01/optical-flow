import numpy as np
import cv2 
import matplotlib.pyplot as plt

img1 = cv2.imread("/home/dat/optical-flow/frame/frame 114.jpg")
img2 = cv2.imread("/home/dat/optical-flow/frame/frame 124.jpg")

img1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)
img2 = cv2.cvtColor(img2, cv2.COLOR_BGR2GRAY)


fast = cv2.FastFeatureDetector_create()

kp1, des1 = fast.detectAndCompute(img1, None)

kp2, des2 = fast.detectAndCompute(img2, None)

bf = cv2.BFMatcher(cv2.NORM_L1, crossCheck = True)

matches = bf.match(des1, des2)

matches = sorted(matches, key = lambda x:x.distance)

img3 = cv2.drawMatches(img1, keypoint1, img2, keypoint2, matches[:300], img2, flags=2)
plt.imshow(img3)
plt.show()

cv2.imwrite('img3.jpg', img3, [int(cv2.IMWRITE_JPEG_QUALITY), 90])