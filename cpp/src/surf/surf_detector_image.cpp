#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <iostream>

int main() {

    // Convert 3-channel video to 1-channel video
    cv::Mat image1 = cv::imread("/home/dat/frame/frame 0.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat image2 = cv::imread("/home/dat/frame/frame 100.jpg", cv::IMREAD_GRAYSCALE);
    // Check error images 
    if (image1.empty() || image2.empty()) {
        std::cerr << "Image not found" << std::endl;
        return -1;
    }
    //
    // Init keypoint and descriptor 2 images
    std::vector<cv::KeyPoint> keypoint1, keypoint2;
    cv::Mat descriptor1, descriptor2;
    // Init feature detector and descriptor extraction
    cv::Ptr<cv::xfeatures2d::SurfDescriptorExtractor> featureDetector = cv::xfeatures2d::SurfDescriptorExtractor::create();
    cv::Ptr<cv::xfeatures2d::SurfFeatureDetector> Descriptor = cv::xfeatures2d::SurfFeatureDetector::create();
    // Detect keypoints 
    featureDetector -> cv::Feature2D::detect(image1, keypoint1);
    featureDetector -> cv::Feature2D::detect(image2, keypoint2);
    // Compute descriptors
    Descriptor->cv::Feature2D::compute(image1, keypoint1, descriptor1);
    Descriptor->cv::Feature2D::compute(image2, keypoint2, descriptor2);
    // Init matches vector
    std::vector<cv::DMatch> matches;
    // Init descriptor matcher 
    cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create(cv::DescriptorMatcher::BRUTEFORCE);
    // Match 2 images from 2 descriptors
    matcher -> cv::DescriptorMatcher::match (descriptor1, descriptor2, matches);
    // Init result image.
    cv::Mat img_matcher;
    // Draw result image from keypoints
    cv::drawMatches(image1, keypoint1, image2, keypoint2, matches, img_matcher);
    //
    //
    cv::imshow("Result SURF", img_matcher);
    cv::waitKey();

    return 0;
}