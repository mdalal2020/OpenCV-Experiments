#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{
  VideoCapture cap;
  bool isOpened = cap.open(0);
  if(!isOpened)
  {
    cout << "ERROR" << endl;
    return -1;
  }
  while(1)
  {
    Mat frame;
    cap >> frame;
    Mat eroded;
    Mat kernel;
    Mat dilated;
    erode(frame, eroded, kernel);
    dilate(frame, dilated, kernel);
    imshow("Normal", frame);
    imshow("eroded", eroded);
    imshow("dilated", dilated);
    if(waitKey(30) ==  27)
    {
      cout << "Video Stream Terminated" << endl;
      cap.release();
      return -1;
    }
  }
}
