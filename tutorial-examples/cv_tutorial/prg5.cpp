/***********************************
 * Autor: Rafael Muñoz Salinas
 * Universidad de Córdoba (Spain)
 * Master en Sistemas Inteligentes
 * Asignatura: Realidad Virtual y Aumentada
 *
 * Info:
 * Shows how to capture mouse events
 *
 *
 * ******************************************/
#include <opencv2/core/core.hpp> //core routines
#include <opencv2/highgui/highgui.hpp>//imread,imshow,namedWindow,waitKey
#include <iostream>
using namespace std;
cv::Mat image;


//callback function. Whenever the mouse is moved or a button pressed, this function is called
void on_mouse( int event, int x, int y, int flags, void* param )
{
if (event==CV_EVENT_RBUTTONDOWN)
{
  cout<<"x,y="<<x<<" "<<y<<endl;
  //set as red a small window around
  int xleft=x-3;
  if( xleft<0) xleft=0;//check not out of image
  int yleft=y-3;
  if( yleft<0) yleft=0;//check not out of image
  int xright=x+3;
  if( xright> image.cols) xright=image.cols-1;//check not out of image
  int yright=y+3;
  if( yright> image.rows) yright=image.rows-1;//check not out of image

  for( int x=xleft;x<=xright;x++)
	for( int y=yleft;y<=yright;y++){
	uchar *ptr=image.ptr<uchar>(y)+3*x;
	ptr[0]=0;
	ptr[1]=0;
	ptr[2]=255;
	}

  //refresh the image window
  cv::imshow("image",image);

}
}


int main(int argc,char **argv){
try{
//Create image 320x240
image.create(240,320,CV_8UC3);
//set all pixels to specified value
image.setTo(cv::Scalar(0,244,123));
//creates a window
cv::namedWindow("image");
//indicates that the on_mouse function should be called in case of mouse moved or pressed over window
cvSetMouseCallback( "imagen", on_mouse, 0 );
//shows image
cv::imshow("image",image);
char c=0;
while(c!=27)  //waits until ESC pressed
	c=cv::waitKey(0);

}catch(std::exception &ex)
{
  cout<<ex.what()<<endl;
}
}

