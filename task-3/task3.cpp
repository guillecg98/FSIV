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

int main(int argc,char **argv){

    cv::Mat image;
    float g;
    int f;
    CmdLineParser cml(argc,argv);
    //check if a command is present
    try{
        if(argc < 3){
            cerr<<"Usage: <input img> <output img>\n Options:\n \t[-f filter type: [0-1]] \n \t[-g gain > 0.0]"<<endl;
            return 0;
        }

        image=cv::imread(argv[1]);

        if( image.rows==0){
            cerr<<"Error reading image"<<endl;
            return 0;
        }

        if(cml["-f"]){
            if( (stoi(cml("-f")) >= 0) && (stoi(cml("-c")) <= 1) ){
                int f= std::stoi( cml("-f"));//convert to int
            }else{
                f = 0;
            }
        }
        if(cml["-g"]){
            if (stof(cml("-g")) >= 0){
                g = std::stof(cml("-g"));//convert to float
            }else{
                g = 1;
            }
        }

        char c=0;
        while(c!=27)  //waits until ESC pressed
        c=cv::waitKey(0);
    }
    catch(const std::exception& ex){
        std::cerr << ex.what() << '\n';
    }
}