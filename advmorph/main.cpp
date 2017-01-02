#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void morphops(int operation, Mat normal, Mat transform, Mat element);

int main(int argc, const char** argv)
{
  Mat space = imread("../Space.jpg");
  Mat element;
  for(int i = 2; i<=6; i++)
  {
    Mat transform;
    morphops(i, space, transform, element);
    cvWaitKey(0);
  }
  waitKey(0);
  return 0;
}

void morphops(int operation, Mat normal, Mat transform, Mat element)
{
  morphologyEx(normal, transform, operation, element);
  imshow("Space", normal);
  imshow("Transform", transform);
}
