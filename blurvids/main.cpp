#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;
int main(int argc, const char** argv)
{
  VideoCapture cap;
  bool success = cap.open(0);
  if(!success)
  {
    cout << "ERROR Capture not opening" << endl;
    return -1;
  }
  while(1)
  {
    Mat frame;
    Mat blurred;
    Mat gauss;
    Mat median;
    cap >> frame;
    blur(frame, blurred, Size(3, 2));
    //GaussianBlur(frame, gauss, Size(5, 5), 0);
    // medianBlur(frame, median, 1);
    // imshow("Frame", frame);
    imshow("Blurred", blurred);
    // imshow("Guassian Blur", gauss);
    // imshow("Median Blur", median);
    if(waitKey(30) == 27)
    {
      cout << "Video Terminated" << endl;
      return -1;
    }

  }
}
