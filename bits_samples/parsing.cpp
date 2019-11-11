//! \file parsing.cpp
//! How to use OpenCV parser
//! (c) MJMJ/2019

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

// Example: 
//    ./parsing 8 --withend -T=3.5 -S="Hola mundo"


const cv::String keys =
    "{help h usage ? |      | print this message   }"
    "{@n             |<none>| repetitions.}"    
    "{T              |  1.0 | value to show. Def. 1.0}"
    "{S str          |Hello | string to show. Def. Hello}"
    "{withend        |      | with end message?}"
    ;

int main(int argc, char * argv[])
{
   /// Init the parser
   cv::CommandLineParser parser(argc, argv, keys);
   parser.about("Demo of OpenCV parser.");
   if (parser.has("help"))
   {
      parser.printMessage();
      return 0;
   }
   
   cout << "===========================" << endl;
   
   // Get the values
   int repetitions = parser.get<int>(0);
   cout << "Repetitions: " << repetitions << endl;
           
   float T = parser.get<float>("T");
   cout << "T: " << T << endl;
   
   std::string msg = parser.get<std::string>("str");
   cout << "Message: " << msg << endl;
   
   cout << "===========================" << endl << endl;
   
   // Do something
   for (int i = 0; i < repetitions; i++)
      cout << msg << " " << T << endl;
   
	if (parser.has("withend"))
      std::cout << "End! " <<std::endl;
   
   return 0;
}
