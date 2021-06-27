cmake_minimum_required(VERSION 3.1)

project(surf)


find_package(OpenCV 3.4.2 REQUIRED)
include_directories(${OpenCV_INCLUDE_LIBS})

add_executable(detect_img surf_detector_image.cpp)
target_link_libraries(detect_img ${OpenCV_LIBS})

add_executable(detect_vid surf_detector_video.cpp)
target_link_libraries(detect_vid ${OpenCV_LIBS})
