import numpy as np
import cv2 as cv
import matplotlib.pyplot as plt

img1 = cv.imread("/home/dat/optical-flow/frame/frame 114.jpg")
img2 = cv.imread("/home/dat/optical-flow/frame/frame 124.jpg")

img1 = cv.cvtColor(img1, cv.COLOR_BGR2GRAY)
img2 = cv.cvtColor(img2, cv.COLOR_BGR2GRAY)

surf = cv.xfeatures2d.SURF_create()
surf.getHessianThreshold()
surf.setHessianThreshold(300)
kp1, des1 = surf.detectAndCompute(img1, None)
kp2, des2 = surf.detectAndCompute(img2, None)
surf.setUpright(True)
surf.setExtended(True)

bf = cv.BFMatcher(cv.NORM_L1, crossCheck = True)

matches = bf.match(des1, des2)

matches = sorted(matches, key = lambda x:x.distance)

img3 = cv.drawMatches(img1, kp1, img2, kp2, matches[:300], img2, flags=2)
plt.imshow(img3)
plt.show()

cv.imwrite('img3.jpg', img3, [int(cv.IMWRITE_JPEG_QUALITY), 90])