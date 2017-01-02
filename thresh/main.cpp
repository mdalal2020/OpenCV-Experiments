#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{
  Mat img = imread("../threshold.jpg", IMREAD_GRAYSCALE);
  Mat threshed;
  double thresh = 0;
  double maxValue = 255;

  //binary threshold
  threshold(img, threshed, thresh, maxValue, THRESH_TOZERO);
  Mat element;
  // Mat open;
  // morphologyEx(threshed, open, 3, element);
  imshow("Normal", img);
  imshow("Thresholded", threshed);
  // imshow("Opened", open);
  waitKey(0);
  return 0;
}
