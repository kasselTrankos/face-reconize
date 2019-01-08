// Test application for the Visual Studio Image Watch Debugger extension

#include <iostream>                        // std::cout
#include <opencv2/core/core.hpp>           // cv::Mat
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>     // cv::imread()
#include <opencv2/imgproc/imgproc.hpp>     // cv::Canny()
#include <opencv2/objdetect/objdetect.hpp>
#include <vector>

using namespace std;
using namespace cv;



int main(int argc, char *argv[])
{
  if (argc != 2) {
    cout << "Wrong number of parameters" << endl;
    return -1;
  }
  const char *r = "rect-";
  char* imageName = argv[1];
  cout << "Loading input image: " << imageName << endl;
  Mat img;
  img = imread(imageName, COLOR_BGR2GRAY);

    CascadeClassifier cascade;
    CascadeClassifier profileface;
    CascadeClassifier eyes;
    if (cascade.load("haarcascade_frontalface_default.xml")
      && eyes.load("haarcascade_eye.xml")) {
      cout << " FOLO" << endl;
      vector<Rect> faces;
      cascade.detectMultiScale(img, faces, 1.3, 5);
      printf("%zd face(s) are found.\n", faces.size());
      for( vector<cv::Rect>::const_iterator r = faces.begin(); r != faces.end(); r++) {            
        //rectangle(img, *r, Scalar(0,0,255), 2, 8, 0);
        rectangle( img, 
          Point( r->x, r->y ), 
          Point( r->x + r->width, r->y + r->height ), 
          Scalar(0,0,255));
        string m = "rect-"  + string(imageName);
        // eyes = eyes.detectMultiScale(roi_gray)
        // for( vector<cv::Rect>::const_iterator r = faces.begin(); r != faces.end(); r++) {
        //   cv2.rectangle(roi_color,(ex,ey),(ex+ew,ey+eh),(0,255,0),2);
        // }
        imwrite(m, img);
      }
    }
    namedWindow( "Faces", WINDOW_NORMAL );// Create a window for display.
    imshow( "Faces", img );               // Show our image inside it.

    waitKey(0);                           // Wait for a keystroke in the window
    return 0;
}