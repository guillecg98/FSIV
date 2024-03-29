#include <opencv2/core/core.hpp> //core routines
#include <opencv2/imgproc.hpp>//to draw rectangles
#include <opencv2/core/types.hpp>//to add points
#include <opencv2/highgui/highgui.hpp>//imread,imshow,namedWindow,waitKey

#include <iostream>
#include <vector>//to use stl vectors
#include <cmath>//for pow function

using namespace std;

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

//global vars
double c = 1,b = 0,g = 1;

//function to process image
void processImg(cv::Mat image,float c,float b,float g);

void on_trackbar_contrast(int contrast,void *userdata){
  cv::Mat img = *((cv::Mat*)userdata);
  c = (contrast * 2.0) / 200.0;
  processImg(img,c,b,g);
}

void on_trackbar_gamma(int gamma,void * userdata){
  cv::Mat img = *((cv::Mat*)userdata);
  g = (gamma * 2.0) / 200.0;
  processImg(img,c,b,g);
}

void on_trackbar_brightness(int brightness,void * userdata){
  cv::Mat img = *((cv::Mat*)userdata);
  if(brightness == 100){
    b = 0.0;
  }else{
    if(brightness > 100){
    b = brightness / 200.0;
    }else{
      b = -1 + (brightness/200.0);
    }
  }
  processImg(img,c,b,g);
}

void processImg(cv::Mat image,float c,float b,float g){

  cv::Mat normalized,result;
  image.convertTo(normalized,CV_32F,1./255.);
  for(int x = 0; x < normalized.rows; x++){
    for(int y = 0; y < normalized.cols; y++){
      float *ptr = normalized.ptr<float>(x)+3*y;
      ptr[0] = c * pow(ptr[0],g) + b;
      ptr[1] = c * pow(ptr[1],g) + b;
      ptr[2] = c * pow(ptr[2],g) + b;
      ptr += 3;
    }
  }
  cv::imshow("processed",normalized);
  normalized.convertTo(result,CV_8UC3,255);
  cv::imwrite("out.jpg",result); //PARA GUARDAR LA IMAGEN RESULTADO
}


//Example of use
int main(int argc,char **argv){

  cv::Mat image;
  CmdLineParser cml(argc,argv);
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

    if(cml["-c"]){
      if( (stof(cml("-c")) >= 0) && (stof(cml("-c")) <= 2) ){
        c = std::stof(cml("-c"));//convert to float
        //int i= std::stoi( cml("-p"));//convert to int
      }else{
        c = 1;
      }
    }
    if(cml["-b"]){
      if( (stof(cml("-b")) >= -1) && (stof(cml("-b")) <= 1) ){
        b = std::stof(cml("-b"));//convert to float
        //int i= std::stoi( cml("-p"));//convert to int
      }else{
        b = 0;
      }
    }
    if(cml["-g"]){
      if( (stof(cml("-g")) >= 0) && (stof(cml("-g")) <= 2) ){
        g = std::stof(cml("-g"));//convert to float
        //int i= std::stoi( cml("-p"));//convert to int
      }else{
        g = 1;
      }
    }
    if(cml["-i"]){ //interactive mode
      int contrast = 100;
      int gamma = 100;
      int brightness = 100;
      cv::namedWindow("image");
      cv::imshow("image",image);
      cv::createTrackbar("Contrast","image",&contrast,200,on_trackbar_contrast,(void *) &image);
      cv::createTrackbar("Gamma","image",&gamma,200,on_trackbar_gamma,(void *) &image);
      cv::createTrackbar("Bright","image",&brightness,200,on_trackbar_brightness,(void *) &image);

      cerr<<"c option is in the command line = "<<c<<"\n";
      cerr<<"b option is in the command line = "<<b<<"\n";
      cerr<<"g option is in the command line = "<<g<<"\n";
    }else{
      cv::namedWindow("image");
      cv::imshow("image",image);

      cerr<<"c option is in the command line = "<<c<<"\n";
      cerr<<"b option is in the command line = "<<b<<"\n";
      cerr<<"g option is in the command line = "<<g<<"\n";
      processImg(image,c,b,g);
    }
    char c=0;
    while(c!=27)  //waits until ESC pressed
      c=cv::waitKey(0);
  }
  catch(const std::exception& ex)
  {
    std::cerr << ex.what() << '\n';
  }
}
