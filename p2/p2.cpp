#include <opencv2/opencv.hpp>//change color to grayscale
#include <opencv2/core/core.hpp> //core routines
#include <opencv2/imgproc.hpp>//to draw rectangles
#include <opencv2/core/types.hpp>//to add points
#include <opencv2/highgui/highgui.hpp>//imread,imshow,namedWindow,waitKey

#include <iostream>
#include <vector>//to use stl vectors

using namespace std;

cv:.Mat image,result;
void processImg(float c,float b,float g);

// Copy in your program!
class CmdLineParser{
   int argc;
   char **argv;
public:
   CmdLineParser(int _argc,char **_argv):argc(_argc),argv(_argv){}
   bool operator[] ( string param ) {
     int idx=-1;
     for ( int i=0; i<argc && idx==-1; i++ )
     if ( string ( argv[i] ) == param ) idx=i;
     return ( idx!=-1 ) ;
   }
   string operator()(string param,string defvalue="-1"){
     int idx=-1;
     for ( int i=0; i<argc && idx==-1; i++ )
     if ( string ( argv[i] ) ==param ) idx=i;
     if ( idx==-1 ) return defvalue;
     else  return ( argv[  idx+1] );
   }
};

void processImg(float c,float b,float g){
  image.copyTo(result);
  for(int x = 0; x < result.rows; x++){
    for(int y = 0; y < result.cols; y++){
      uchar *prt = result.prt<uchar>(y)+3*x;
      float pixel = (ptr[0] + ptr[1] + ptr[2]) / 255;
    }
  }


//Example of use
int main(int argc,char **argv){

   CmdLineParser cml(argc,argv);
   //check if a command is present
   if (cml["-c"]){
       cout<<"-c option is in the command line";
       float f= std::stof( cml("-c"));//convert to float
       //int i= std::stoi( cml("-p"));//convert to int
   }
   //used with default values
   float f=std::stof(cml("-c","1"));//if -p is not, then, return 1


   processImg();
}
