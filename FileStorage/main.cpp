#include "opencv2/opencv.hpp"
using namespace cv;
int main(int, char**argv)
{
  //create our writer
  FileStorage fs("test.yml", FileStorage::WRITE);
  //save an int
  int fps = 5;
  fs << "fps" << fps;
  //create some mat sample
  Mat ml = Mat :: eye(2, 3, CV_32F);
  Mat m2 = Mat :: ones(3, 2, CV_32F);
  Mat result = (ml+1).mul(ml+3);
  //write the result
  fs << "Result" << result;
  //release the file
  fs.release();
  FileStorage fs2("test.yml", FileStorage::READ);
  Mat r;
  fs2["Result"] >> r;
  std::cout << r << std::endl;
  fs2.release();

  return 0;

}
