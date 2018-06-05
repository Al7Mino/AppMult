#include <opencv2/opencv.hpp>
#include <opencv2/stitching/stitcher.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#include "stitchingEffect.hpp"

bool try_use_gpu = false;
 
Mat StitchingEffect::doStitch(vector<Mat> imgs, string windowName) {

    Mat pano;
    Stitcher stitcher = Stitcher::createDefault(try_use_gpu);
    Stitcher::Status status = stitcher.stitch(imgs, pano);
 
    if (status != Stitcher::OK) {
        cout << "Can't stitch images, error code = " << status << endl;
    }
    imshow(windowName, pano);
    waitKey(0);
    return pano;
}