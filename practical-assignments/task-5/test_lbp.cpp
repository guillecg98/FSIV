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
   int ncells [] = {5,5};
   cv::Mat lbpmat;
   fsiv_lbp(image, lbpmat);
   fsiv_lbp_disp(lbpmat, "LBP Image");

   cv::Mat lbp_desc1;
   fsiv_lbp_desc(image,lbp_desc1,ncells,true,true);
   //fsiv_lbp_hist(lbpmat, lbp_desc1, true);

   if (argc == 3)
   {
      cv::Mat image2 = cv::imread(argv[2],CV_LOAD_IMAGE_GRAYSCALE);
      cv::Mat lbpmat2;
      fsiv_lbp(image2, lbpmat2);
      fsiv_lbp_disp(lbpmat2, "LBP Image 2");

      cv::Mat lbp_desc2;
      fsiv_lbp_desc(image2,lbp_desc2,ncells,true,true);
      //fsiv_lbp_hist(lbpmat2, lbp_desc2, true);

      float dist = fsiv_chisquared_dist(lbp_desc1, lbp_desc2);
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
