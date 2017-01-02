#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

//create a variable to save the position value in track
int blurAmount = 15;

//trackbar call back function
static void onChange(int pos, void* userInput);

//Mouse callback
static void onMouse(int event, int x, int y, int, void* userInput);

int main(int argc, char** argv)
{
  //read images
  Mat space = imread("../space.jpg");

  //create windows
  namedWindow("Space");

  //create a trackbar
  createTrackbar("Space", "Space", &blurAmount, 30, onChange, &space);
  setMouseCallback("Space", onMouse, &space);

  //Call to onChange to init
  onChange(blurAmount, &space);

  //wait for a key to exit
  waitKey(0);
  destroyAllWindows();
  return 0;
}

//trackbar call back function
static void onChange(int pos, void* userInput)
{
  if (pos <= 0)
    return;
  //Aux variable for result
  Mat imgBlur;

  //Get the pointer input image
  Mat* img=(Mat*)userInput;
  
  //Apply a blur filter
  blur(*img, imgBlur, Size(pos, pos));

  //Show the result
  imshow("Space", imgBlur);
}
