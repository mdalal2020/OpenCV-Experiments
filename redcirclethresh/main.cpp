#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

int main(int argc, const char** argv)
{
  Mat img = imread("../circle.jpg");
  Mat hsv;
  Mat threshed;
  double thresh = 0;
  double maxVal = 255;
  cvtColor(img, hsv, COLOR_BGR2HSV);
  Mat lower;
  Mat upper;
  inRange(hsv, Scalar(0, 100, 100), Scalar(10, 255, 255), lower);
  inRange(hsv, Scalar(160, 100, 100), Scalar(179, 255, 255), upper);
  Mat red;
  addWeighted(lower, 1.0, upper, 1.0, 0.0, red);
  GaussianBlur(red, red, Size(3, 3), 2, 2);
  vector<Vec3f> circles;

  //detects circles and stores in circles vector
  HoughCircles(red, circles, CV_HOUGH_GRADIENT, 1, red.rows/8, 100, 20);

 	for(size_t current_circle = 0; current_circle < circles.size(); ++current_circle) {
 		  Point center(round(circles[current_circle][0]), round(circles[current_circle][1]));
 		  int radius = round(circles[current_circle][2]);
		  circle(img, center, radius, Scalar(0, 255, 0), 5);
	 }

  imshow("normal", img);
  // imshow("upper", upper);
  // imshow("lower", lower);
  // imshow("red", red);
  waitKey(0);
  return 0;
}
