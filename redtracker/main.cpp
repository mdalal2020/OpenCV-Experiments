#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char** argv)
{
  VideoCapture cap(0);
  if(!cap.isOpened())
  {
    cout << "Video Stream did not open" << endl;
    return -1;
  }
  while(1)
  {
    Mat frame;
    cap >> frame;
    Mat hsv;
    cvtColor(frame, hsv, COLOR_BGR2HSV);
    Mat thresholded;
    Mat element;
    int lHue = 170;
    int lSat = 150;
    int lVal = 60;
    int hHue = 179;
    int hSat = 255;
    int hVal = 255;
    Mat blur;
    GaussianBlur(hsv, blur, Size(5, 5), 0);
    inRange(hsv, Scalar(lHue, lSat, lVal), Scalar(hHue, hSat, hVal), thresholded);
    morphologyEx(thresholded, thresholded, 2, element);
    morphologyEx(thresholded, thresholded, 3, element);
    imshow("thresholded", thresholded);
    if(waitKey(30) == 27)
    {
      cout << "Video terminated" << endl;
      return -1;
    }
  }
}
