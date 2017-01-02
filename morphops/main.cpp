#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

int main(int argc, const char** argv)
{
  Mat space = imread("../space.jpg");
  Mat dilated;
  Mat eroded;
  Mat element;
  dilate(space, dilated, element);
  erode(space, eroded, element);
  imshow("Normal", space);
  imshow("Eroded", eroded);
  imshow("Dilated", dilated);
  waitKey(0);
  return 0;
}
