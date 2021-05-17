# optical-flow
1) Test 2 method: SIFT, SURF

![image](https://user-images.githubusercontent.com/45755087/117583371-fdd3e100-b130-11eb-80dd-f939028ef0ca.png)


Video test: https://drive.google.com/file/d/10xzBH3hG21_A4IeWZ1g3uI9jLxM-T-Ov/view?usp=sharing

# SURF
## FPS: ~ 3.5-4.3
![image](/surf/img3.jpg)

# FAST
## FPS: ~ 25-30
### Config:
* Threshold = 10
* Nonmax Suppression = True
* type = FastFeatureDetector::TYPE_9_16 (*16 is the total number of points on the arc, and 9 is the number of consecutive points actually detected. This corresponds to a radius of 3.*)

![image](/fast/img.png)
