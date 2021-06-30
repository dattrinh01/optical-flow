#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <iostream>


int main(int argc, char** argv) {

    cv::VideoCapture capture;
    capture.open("/home/dat/data2.mp4");
    cv::Mat frame, gray_frame;

    for (;;) {
        capture >> frame;
        if (frame.empty()) {
            std::cerr << "Video not found" << std::endl;
            break;
        }

        std::vector<cv::KeyPoint> keypoints;
        cv::Mat descriptor;
        cv::Mat result_frame;

        cv::cvtColor(frame, gray_frame, cv::COLOR_RGB2GRAY);

        cv::Ptr<cv::FastFeatureDetector> detectorFast = cv::FastFeatureDetector::create();
        detectorFast -> cv::Feature2D::detect(gray_frame, keypoints, cv::noArray());

        cv::drawKeypoints(gray_frame, keypoints, result_frame, cv::Scalar::all(-1),   cv::DrawMatchesFlags::DEFAULT);

        cv::imshow("Video", gray_frame);
        if (cv::waitKey(33) >= 0) {
            break;
        }

    }
    cv::destroyAllWindows();
    return 0;
}