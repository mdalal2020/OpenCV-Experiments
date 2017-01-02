#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//Opencv includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

//Opencv command line parser functions
//keys accepted by command line parser

const char* keys = {"{help h usage ? | | print this message}" "{@video | | Video file, if not defined try to use webcamera}"};

int main (int argc, const char** argv)
{
  CommandLineParser parser(argc, argv, keys);
  parser.about("Chapter 2. v1.0.0");
  //if requires help show
  if (parser.has("help"))
  {
    parser.printMessage();
    return 0;
  }
  String videoFile = parser.get<String>(0);
  //Check if params are correctly parsed in these variables
  if(!parser.check())
  {
    parser.printErrors();
    return 0;
  }
  VideoCapture cap; //open the default camera
  if (videoFile != "")
    cap.open(videoFile);
  else
    cap.open(0);
  if(!cap.isOpened()) // check if we succeeded
    return -1;
  namedWindow("Video", 1);
  for(;;)
  {
    Mat frame;
    bool success = cap.read(frame); //get a new image from the camera
    if (!success)
    {
      cout << "ERROR" << endl;
      break;
    }
    imshow("Video", frame);
    if(waitKey(30) == 27)
      break;
  }
  //release the camera or video cap
  cap.release();
  return 0;
}
