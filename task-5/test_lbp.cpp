//! \file test_lbp.cpp
//! \author FSIV-UCO

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "lbp.h"

using namespace std;

const cv::String keys =
    "{help h usage ? |      | print this message   }"
    "{@image         |<none>| path to input image.}"
    "{image2         |      | path to second image, for comparison.}"
    ;

int main(int argc, char * argv[])
{
   cv::CommandLineParser parser(argc, argv, keys);
   parser.about("Test LBP implementation.");
   if (parser.has("help"))
   {
      parser.printMessage();
      return 0;
   }

   setvbuf(stdout, NULL, _IONBF, 0);

   /// Load the image
   // TODO
   cv::Mat image = cv::imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);

   /// Compute LBP matrix
   // TODO
   cv::Mat lbpmat;
   image.copyTo(lbpmat);
   fsiv_lbp(image, lbpmat);

	/// Display LBP image
   // TODO
   fsiv_lbp_disp(lbpmat, "LBP image");

   /// Save LBP image to disk
   // TODO

   /// Compute the LBP histogram
   // TODO
   cv::Mat lbp_h1;
   fsiv_lbp_hist(lbpmat, lbp_h1, true);

   // assert(cv::sum(lbp_h1.sum) == 1.0)

   /// Compute the Chi^2 distance between the input image and its mirror
   // TODO
   if (parser.has("image2"))
   {
      cv::Mat lbp_h2;
      float dist = fsiv_chisquared_dist(lbp_h1, lbp_h2);

      // Show distance
   }

	std::cout << "End! " <<std::endl;

   return 0;
}
