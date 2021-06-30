#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>

int main() {

    cv::VideoCapture capture;
    capture.open("/home/dat/data2.mp4");
    cv::Mat frame, gray_frame;

    for(;;) {
        capture >> frame;
        if (frame.empty()) {
            std::cerr << "Image not found" << std::endl;
            break;
        }
        cv::cvtColor(frame, gray_frame, cv::COLOR_RGB2GRAY); 
        //
        //
        std::vector<cv::KeyPoint> keypoints;
        cv::Mat descriptors;

        cv::Ptr<cv::xfeatures2d::SurfFeatureDetector> Descriptor = cv::xfeatures2d::SurfFeatureDetector::create();
        cv::Ptr<cv::xfeatures2d::SurfDescriptorExtractor> featureDetector = cv::xfeatures2d::SurfDescriptorExtractor::create();

        featureDetector -> cv::Feature2D::detect(gray_frame, keypoints);
        Descriptor      -> cv::Feature2D::compute(gray_frame, keypoints, descriptors);

        cv::Mat img_matcher;
        cv::drawKeypoints(gray_frame, keypoints, img_matcher);
        // 
        //
        cv::imshow("Video", img_matcher);
        if (cv::waitKey(33) >= 0) {
            break;
        }
    }
    cv::destroyAllWindows();
    return 0;
}