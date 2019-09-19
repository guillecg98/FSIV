#include <opencv2/opencv.hpp>//change color to grayscale
#include <opencv2/core/core.hpp> //core routines
#include <opencv2/imgproc.hpp>//to draw rectangles
#include <opencv2/core/types.hpp>//to add points
#include <opencv2/highgui/highgui.hpp>//imread,imshow,namedWindow,waitKey


#include <iostream>
#include <vector>//to use stl vectors

using namespace std;

void drawRectangle(cv::Point &p1,cv::Point &p2);

cv::Mat image,result,im2;
vector<cv::Point> pointsVector;
vector<cv::Vec3b> pixelVec;
int i = 0, j = 1, k = 2;;


//firstcallback function. Whenever the mouse is moved or a button pressed, this function is called
void on_mouse( int event, int x, int y, int flags, void* param ){

  if(event==CV_EVENT_LBUTTONDOWN){
    pointsVector.push_back(cv::Point(x,y));
    if( (pointsVector.size()%2 != 0) && (pointsVector.size() != 0) ){
      cv::Point current(x,y);
      cout<<"last item"<<pointsVector.back()<<"\n";
      image.copyTo(im2);
      cv::rectangle(im2,pointsVector.back(),current,cv::Scalar(255,0,0),2,0);
      cv::imshow("image",im2);
    }
    if(pointsVector.size() >= k){
      drawRectangle(pointsVector[i],pointsVector[j]);
      i+=2;
      j+=2;
      k+=2;
    }
  }
}

void drawRectangle(cv::Point &p1,cv::Point &p2){
  cout<<"Point 1: ("<<p1.x<<","<<p1.y<<")\n";
  cout<<"Point 2: ("<<p2.x<<","<<p2.y<<")\n";
  image.copyTo(result);
  cv::rectangle(result,p1,p2,cv::Scalar(255,255,255),2,0);//draw the rectangle
  cv::Rect myrectangle(p1,p2);//to work with points inside or outside my rectangle
  for(int x = 0; x<result.rows; x++){
    for(int y = 0; y<result.cols; y++){
      if(!myrectangle.contains(cv::Point(x,y))){
        uchar *ptr=result.ptr<uchar>(y)+3*x;
        int grayscale = (0.11*ptr[0] + 0.59*ptr[1] + 0.3*ptr[2]);
        ptr[0] = ptr[1] = ptr[2] = grayscale;
      }
    }
  }
  cv::imshow("testingRectangle",result);
}

int main(int argc,char **argv){
  try{
    if(argc!=2) {cerr<<"Usage:image"<<endl;return 0;}
    //loads the image from file
    image=cv::imread(argv[1]);
    if( image.rows==0) {cerr<<"Error reading image"<<endl;return 0;}
    //creates a window
    cv::namedWindow("image");
    //indicates that the on_mouse function should be called in case of mouse moved or pressed over window
    cv::setMouseCallback( "image", on_mouse, 0 );
    //shows image
    cv::imshow("image",image);
    char c=0;
    while(c!=27)  //waits until ESC pressed
      c=cv::waitKey(0);
  }catch(std::exception &ex){
    cout<<ex.what()<<endl;
  }
}

