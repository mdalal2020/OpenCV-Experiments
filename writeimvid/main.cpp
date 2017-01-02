#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{
  Mat img(650, 600, CV_16UC3, Scalar(0, 50000, 50000));
  // if (img.empty())
  // {
  //   cout << "Error" << endl;
  //   return -1;
  // }
  vector <int> compression_params;
  compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
  compression_params.push_back(98);

  bool bSuccess = imwrite("Cool.jpg", img, compression_params);

  // if(!bSuccess)
  // {
  //   cout << "ERROR" << endl;
  //   return -1;
  // }
  imshow("Whoa", img);
  waitKey(0);
  return 0;
}
