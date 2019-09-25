#include <opencv2/core/core.hpp> //core routines
#include <opencv2/imgproc.hpp>//to draw rectangles
#include <opencv2/core/types.hpp>//to add points
#include <opencv2/highgui/highgui.hpp>//imread,imshow,namedWindow,waitKey

#include <iostream>
#include <vector>//to use stl vectors
#include <cmath>//for pow function

using namespace std;

cv::Mat image,result;
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
  float pixel = 0;
  float normalized = 0;
  for(int x = 0; x < result.rows; x++){
    for(int y = 0; y < result.cols; y++){
      uchar *ptr = result.ptr<uchar>(y)+3*x;
      pixel = (ptr[0] + ptr[1] + ptr[2]) / 255;
      ptr += 3;
      normalized +=pixel;
    }
  }
  normalized = c * (pow(normalized,g)) + b;
  //denormalize the image
  for(int x = 0; x < result.rows; x++){
    for(int y = 0; y < result.cols; y++){
      uchar *ptr = result.ptr<uchar>(y)+3*x;
      ptr[0] = ptr[1] = ptr[2] = normalized;
      ptr += 3;
    }
  }
  cv::imshow("Processed",result);
}


//Example of use
int main(int argc,char **argv){

  CmdLineParser cml(argc,argv);
  float c,b,g;
  //check if a command is present
  try{

    if(argc < 3){
      cerr<<"Usage: <input img> <output img>\n Options:\n \t[-i interactive mode] \n \t[-c range: [0,2]] \n \t[-b range: [-1,1]] \n \t[-g range: [0-2]]"<<endl;
      return 0;
    }

    image=cv::imread(argv[1]);

    if( image.rows==0){
      cerr<<"Error reading image"<<endl;
      return 0;
    }

    if (cml["-c"]){
      c = std::stof( cml("-c"));//convert to float
      //int i= std::stoi( cml("-p"));//convert to int
    }else{//used with default values
      c = std::stof(cml("-c","1"));//if -p is not, then, return 1
    }
    if (cml["-b"]){
      b = std::stof( cml("-b"));//convert to float
      //int i= std::stoi( cml("-p"));//convert to int
    }else{  //used with default values
      b = std::stof(cml("-b","0"));//if -p is not, then, return 1
    }
    if (cml["-g"]){
      g = std::stof( cml("-g"));//convert to float
      //int i= std::stoi( cml("-p"));//convert to int
    }else{  //used with default values
      g = std::stof(cml("-g","1"));//if -p is not, then, return 1
    }

    cv::namedWindow("image");
    cv::imshow("image",image);

    cerr<<"c option is in the command line = "<<c<<"\n";
    cerr<<"b option is in the command line = "<<b<<"\n";
    cerr<<"g option is in the command line = "<<g<<"\n";
    //processImg(c,b,g);
  }
  catch(const std::exception& ex)
  {
    std::cerr << ex.what() << '\n';
  }
}
