#include <opencv2/core/core.hpp> //core routines
#include <opencv2/imgproc.hpp>//to draw rectangles
#include <opencv2/core/types.hpp>//to add points
#include <opencv2/highgui/highgui.hpp>//imread,imshow,namedWindow,waitKey


#include <iostream>
#include <vector>//to use stl vectors

using namespace std;

cv::Mat image,histogram;
vector<double> times_each_color_appears(256,0);
vector<double> normalized_vector(256,0);
vector<double> cumulative(256,0);
void processImage();


void processImage(){
  image.copyTo(histogram);
  int total_pixels = histogram.rows * histogram.cols;
  
  for(int x = 0; x < histogram.rows; x++){
    for(int y = 0; y < histogram.cols; y++){
      uchar *ptr = histogram.ptr<uchar>(x)+y;
      for(int i = 0; i < times_each_color_appears.size(); i++){
        if(ptr[0] == i){
          times_each_color_appears[i] ++;
        }
      }
    }
  }

  //normalized grayscale image
  for(int i = 0; i < times_each_color_appears.size(); i++){
    normalized_vector[i] = (times_each_color_appears[i] / total_pixels) * 255;
  }

  cumulative = normalized_vector;
  for(int i = 0; i < cumulative.size(); i++){
    if( i != 0){
      cumulative[i] += cumulative[i-1];
    }
  }

  for(int x = 0; x < histogram.rows; x++){
    for(int y = 0; y < histogram.cols; y++){
      uchar *ptr = histogram.ptr<uchar>(x)+y;
      ptr[0] = cumulative[ptr[0]];
    }
  }
  imshow("histogram",histogram);
}

int main(int argc,char **argv){
  try{
    if(argc!=2) {cerr<<"Usage:image"<<endl;return 0;}
    //loads the image from file
    image=cv::imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
    if( image.rows==0) {cerr<<"Error reading image"<<endl;return 0;}
    //creates a window
    cv::namedWindow("image");
    //indicates that the on_mouse function should be called in case of mouse moved or pressed over window
    //shows image
    cv::imshow("image",image);
    processImage();

    char c=0;
    while(c!=27)  //waits until ESC pressed
      c=cv::waitKey(0);
  }catch(std::exception &ex){
    cout<<ex.what()<<endl;
  }
}
