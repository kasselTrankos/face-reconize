#include <iostream>                        // std::cout
#include <opencv2/core/core.hpp>           // cv::Mat
#include <opencv2/highgui/highgui.hpp>     // cv::imread()
#include <opencv2/imgproc/imgproc.hpp>     // cv::Canny()
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    // Mat image;
    // image = imread( argv[1], CV_LOAD_IMAGE_COLOR );
    // CascadeClassifier face_cascade;
    // CascadeClassifier eyes_cascade;
    // CascadeClassifier smile_cascade;

}