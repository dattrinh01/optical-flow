# Optical Flow

## Prerequisites OpenCV C++
### ----------------------------------------------------------

You need to install some dependencies on your system before installing `OpenCV4`

```sh
sudo apt install build-essential cmake git pkg-config libgtk-3-dev \
    libavcodec-dev libavformat-dev libswscale-dev libv4l-dev \
    libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev \
    gfortran openexr libatlas-base-dev python3-dev python3-numpy \
    libtbb2 libtbb-dev libdc1394-22-dev
```

### Install OpenCV4 from source

```sh
# First cd into where you want to put the Opencv library, e.g ~/dev/libs/
mkdir -p ~/dev/libs && cd ~/dev/libs/
git clone https://github.com/opencv/opencv.git -b 3.4.2
git clone https://github.com/opencv/opencv_contrib.git -b 3.4.2
mkdir opencv/build && cd opencv/build
cmake -DOPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules ..
make -j$(nproc --all) && sudo make install
```

### Build is straightforward:

```sh
mkdir build/
cd build/
cmake ..
make
```
### Visual Studio Setting
```sh
{
  /*-------------------- GLOBAL EDITOR CONFIGURATIONS -------------------------*/
  "editor.minimap.enabled": false,
  "editor.formatOnType": true,
  "editor.formatOnPaste": true,
  "editor.formatOnSave": true,
  /*----------------------------- C++ STUFF ----------------------------------*/
  "C_Cpp.autocomplete": "Disabled",
  "C_Cpp.formatting": "Disabled",
  "C_Cpp.errorSquiggles": "Disabled",
  "C_Cpp.intelliSenseEngine": "Disabled",
  //clangd
  "clangd.arguments": [
    "--background-index",
    "--clang-tidy",
    "--header-insertion=never",
    "--suggest-missing-includes",
    "--compile-commands-dir=./build/"
  ],
  //cppcheck
  "c-cpp-flylint.clang.enable": false,
  "c-cpp-flylint.flexelint.enable": false,
  "c-cpp-flylint.cppcheck.enable": true,
  "c-cpp-flylint.cppcheck.inconclusive": true,
  "c-cpp-flylint.cppcheck.verbose": true
}
```
Finally install ![install_llvm_toolchain.sh](/toolkit/install_llvm_toolchain.sh) and ![install_vs_code_extensions.sh](/optical-flow/toolkit/install_vs_code_extensions.sh)
### ----------------------------------------------------------
## Result
1) Test 2 method: SIFT, SURF

![image](https://user-images.githubusercontent.com/45755087/117583371-fdd3e100-b130-11eb-80dd-f939028ef0ca.png)


Video test: https://drive.google.com/file/d/10xzBH3hG21_A4IeWZ1g3uI9jLxM-T-Ov/view?usp=sharing

# SURF
## FPS: ~ 3.5-4.3
![image](py/surf/img3.jpg)

# FAST
## FPS: ~ 25-30
### Config:
* Threshold = 10
* Nonmax Suppression = True
* type = FastFeatureDetector::TYPE_9_16 (*16 is the total number of points on the arc, and 9 is the number of consecutive points actually detected. This corresponds to a radius of 3.*)

![image](py/fast/img.png)
