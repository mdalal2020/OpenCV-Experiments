#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{
  VideoCapture cap;
  cap.open(0);
  Mat frame;
  cap >> frame;

  Mat element;
  Mat transform;
  Mat blurred;

  blur(frame, blurred, Size(3, 3));
  dilate(frame, transform, element);
  imshow("Normal", frame);
  imshow("Blurred", blurred);
  imshow("Dilated", transform);
  waitKey(0);
  return 0;
}
