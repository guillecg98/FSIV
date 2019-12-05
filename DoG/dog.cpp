// Difference of Gaussians
//
// (c) MJMJ/2018

#include <stdio.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

void readme(string exe);
void mat2img(Mat & M);

/** @function main */
int main( int argc, char** argv )
{
  float sigma1, sigma2;
  int ksize = 5;
  if( argc < 4 )
  { readme(argv[0]); return -1; }

  // Fetch sigma values
  sigma1 = atof(argv[2]);
  sigma2 = atof(argv[3]);

  if (argc > 4)
	  ksize = atoi(argv[4]);

  Mat img_scene = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE );

  if(!img_scene.data )
  { std::cout<< " --(!) Error reading images " << std::endl; return -1; }

  namedWindow("Image", 1);

  //-- Show detected matches
  imshow( "Image", img_scene );

  cout << "+ Filtering images..." << endl;
  // 1) Gaussian with sigma1
  Mat gauss1 = getGaussianKernel(ksize, sigma1, CV_32F);
  Mat img1;
  sepFilter2D(img_scene, img1, -1, gauss1, gauss1);

  // 2) Gaussian with sigma1
  Mat gauss2 = getGaussianKernel(ksize, sigma2, CV_32F);
  Mat img2;
  sepFilter2D(img_scene, img2, -1, gauss2, gauss2);

  // 3) DoG
  Mat DoG = img2-img1;

  // Show result
  mat2img(DoG);
  namedWindow("DoG", 1);
  imshow("DoG", DoG);

  waitKey(0);
  return 0;
}

/** @function readme */
void readme(string exe)
{
	std::cout << " Usage: " << exe << " <img> <sigma1> <sigma2> [<kernel_size>]" << std::endl;
}

void mat2img(Mat & M)
{
	double minVal, maxVal;

	// Find mininum
	minMaxLoc(M, &minVal, &maxVal, NULL, NULL);

	M = M-minVal;

	minMaxLoc(M, &minVal, &maxVal, NULL, NULL);
	M = (M / maxVal)*255;

/*
	// Sanity check
	minMaxLoc(M, &minVal, &maxVal, NULL, NULL);
	cout << "min: " << minVal << " max: " << maxVal << endl;
*/
}
