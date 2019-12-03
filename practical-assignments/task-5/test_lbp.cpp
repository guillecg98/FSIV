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

   try{

      parser.about("Test LBP implementation.");
   if (parser.has("help"))
   {
      parser.printMessage();
      return 0;
   }

   setvbuf(stdout, NULL, _IONBF, 0);

   /// Load the image
   // TODO
   cv::Mat image = cv::imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);//PARSER DOES NOT WORK VERY WELL
   /// Compute LBP matrix
   // TODO
   cv::Mat lbpmat,lbpmat2;
   fsiv_lbp(image, lbpmat);

	/// Display LBP image
   // TODO
   fsiv_lbp_disp(lbpmat, "LBP image");

   /// Save LBP image to disk
   // TODO

   // Compute the LBP histogram
   // TODO
   cv::Mat lbp_h1;
   fsiv_lbp_hist(lbpmat, lbp_h1, true);
   // assert(cv::sum(lbp_h1.sum) == 1.0)

   /// Compute the Chi^2 distance between the input image and its mirror
   // TODO
   if (argc == 3)
   {
      cv::Mat imagem2 = cv::imread(argv[2],CV_LOAD_IMAGE_GRAYSCALE);
      cv::Mat lbp_h2, lbpmat2;
      imagem2.copyTo(lbpmat2);
      fsiv_lbp(imagem2,lbpmat2);
      fsiv_lbp_disp(lbpmat2,"LBP image 2");
      fsiv_lbp_hist(lbpmat2,lbp_h2,true);
      float dist = fsiv_chisquared_dist(lbp_h1, lbp_h2);

      // Show distance
      std::cout<<"Dist = "<<dist<<"\n";
   }

   char c=0;
   while(c!=27)  //waits until ESC pressed
   c=cv::waitKey(0);
	std::cout << "End! " <<std::endl;
   }
   catch(const std::exception& ex){
        std::cerr << ex.what() << '\n';
   }
}
