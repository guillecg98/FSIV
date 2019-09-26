#include <opencv2/core/core.hpp> //core routines
#include <opencv2/imgproc.hpp>//to draw rectangles
#include <opencv2/core/types.hpp>//to add points
#include <opencv2/highgui/highgui.hpp>//imread,imshow,namedWindow,waitKey

#include <iostream>
#include <vector>//to use stl vectors
#include <cmath>//for pow function

using namespace std;

cv::Mat image,normalized,result;
void processImg(float c,float b,float g,string output_name);

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

void processImg(float c,float b,float g,string output_name){
  image.convertTo(normalized,CV_32F,1./255.);
  cerr<<"C = "<<c<<" B = "<<b<<" G = "<<g<<"\n";
  //denormalize the image
  for(int x = 0; x < normalized.rows; x++){
    for(int y = 0; y < normalized.cols; y++){
      float *ptr = normalized.ptr<float>(x)+3*y;
      ptr[0] = c * pow(ptr[0],g) + b;
      ptr[1] = c * pow(ptr[1],g) + b;
      ptr[2] = c * pow(ptr[2],g) + b;
      ptr += 3;
    }
  }
  normalized.convertTo(result,CV_8UC3,255);
  cv::imshow(output_name,result);
  cv::imwrite(output_name,result);
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
    processImg(c,b,g,argv[2]);
    char c=0;
    while(c!=27)  //waits until ESC pressed
      c=cv::waitKey(0);
  }
  catch(const std::exception& ex)
  {
    std::cerr << ex.what() << '\n';
  }
}
