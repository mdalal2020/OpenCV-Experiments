#include <iostream>
#include <string>
#include <sstream>

using namespace std;
//OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

int main(int argc, const char** argv)
{
  //read images
  Mat color = imread("../a23.jpg");
  Mat gray = imread("../a23.jpg", 0);

  //Write images
  imwrite("a23gray.jpg", gray);

  //get same pixels with opencv functions
  int myRow=color.cols-1;
  int myCol=color.rows-1;
  Vec3b pixel = color.at<Vec3b>(myCol, myRow);
  cout << "Pixel value (B, G, R): (" << (int)pixel[0] << ", " << (int)pixel[1] << ", " << (int)pixel[2] << ")" << endl;
  //show images
  //namedWindow("window", CV_WINDOW_AUTOSIZE);
  imshow("a23", color);
  imshow("a23 Gray", gray);
  //wait for key press
  waitKey(0);
  return 0;
}
