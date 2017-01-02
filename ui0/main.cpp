#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

//const int CV_GUI_NORMAL = 0x10;
int main(int argc, const char** argv)
{
  Mat space = imread("../space.jpg");
  Mat photo = imread("../photo.jpg");

  //create windows
  namedWindow("Space", CV_GUI_NORMAL);
  namedWindow("Photo", WINDOW_AUTOSIZE);

  //move window
  moveWindow("Space", 0, 0);
  moveWindow("Photo", 520, 10);

  imshow("Space", space);
  imshow("Photo", photo);

  //resize window, only non autosize
  resizeWindow("Space", 512, 512);

  //wait for key press
  waitKey(0);

  //Destroy the windows
  destroyWindow("Space");
  destroyWindow("Photo");

  //Create 10 windows
  for (int i = 0; i< 10; i++)
  {
    ostringstream ss;
    ss << "Photo" << i;
    namedWindow(ss.str());
    moveWindow(ss.str(), 20*i, 20*i);
    imshow(ss.str(), photo);
  }
  waitKey(0);
  destroyAllWindows();
  return 0;
}
