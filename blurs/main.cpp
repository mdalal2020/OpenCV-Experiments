#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{
  Mat space = imread("../space.jpg");
  // Mat blurred;
  // blur(space, blurred, Size(3, 3));
  // Mat gauss;
  // GaussianBlur(space, gauss, Size(1, 1), 0);
  // imshow("Normal", space);
  // imshow("blurred", blurred);
  // imshow("Gauss", gauss);
  for(int i = 1; i <= 31; i+=2)
  {
    Mat median;
    medianBlur(space, median, i);
    imshow("median", median);
    waitKey(1000);
  }
  for(int i = 1; i <= 31; i+=2)
  {
    Mat blurred;
    blur(space, blurred, Size(i, i));
    imshow("blurred", blurred);
    waitKey(1000);
  }
  for(int i = 1; i <= 31; i+=2)
  {
    Mat gauss;
    GaussianBlur(space, gauss, Size(i, i), 0);
    imshow("Gaussian Blur", gauss);
    waitKey(1000);
  }
  for(int i = 1; i <= 31; i+=2)
  {
    Mat bilateral;
    bilateralFilter(space, bilateral, i, i*2, i/2);
    imshow("Bilateral Blur", bilateral);
    waitKey(1000);
  }
  waitKey(0);
  return 0;
}
