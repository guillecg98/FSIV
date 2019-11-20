//! \file lbp.cpp
//! Utils for LBP

#include "lbp.h"
#include <vector>

using namespace std;


void fsiv_lbp(cv::Mat imagem, cv::Mat & lbp){
  cv::Mat img;
  imagem.copyTo(img);
  for(int x = 1; x < img.rows - 1; x++){
    uchar *ptrImage = img.ptr<uchar>(x);
    uchar *ptrLbp = lbp.ptr<uchar>(x);
    for(int y = 1; y < img.cols - 1; y++){
      cv::Mat subImage = get_sub_image(img,x,y);
      ptrLbp[y] = get_lbp_value(subImage,ptrImage[y]);
    }
  }
}

cv::Mat get_sub_image(cv::Mat img, int i, int j){
    cv::Mat sub(3,3,CV_8UC1);
    for(int x = 0; x < 3; x++){
        uchar *ptr_image = img.ptr<uchar>(x+i-1);
        uchar *ptr_sub_image = sub.ptr<uchar>(x);
        for(int y = 0; y < 3; y++){
            ptr_sub_image[y] = ptr_image[y+j-1];
        }
    }
    return sub;
}

unsigned char get_lbp_value(cv::Mat subImage, unsigned char value){
  unsigned char binary_number = 1;
    //filling the sumImage with
    for(int x = 0; x < subImage.rows; x++){
        uchar *ptr = subImage.ptr<uchar>(x);
        for(int y = 0; y < subImage.cols; y++){
          for(int z = 0; z < 8; z++){
            if( x != 1 && y != 1 ){
              binary_number = binary_number  | ((ptr[y] >= value) << z);
            }
          }
      }
    }
    return binary_number;
}

void fsiv_lbp_hist(const cv::Mat & lbp, cv::Mat & lbp_hist, bool normalize){
    std::vector<cv::Mat> images = { lbp };
    std::vector<int> channels = { 0 }, sizes = { 256 };
    std::vector<float> range = { 0, (float)256 };
    cv::calcHist(images, channels, cv::Mat(), lbp_hist, sizes, range);
    lbp_hist = lbp_hist.mul(1.0 / (lbp.cols * lbp.rows));
}

void fsiv_lbp_desc(const cv::Mat & image, cv::Mat & lbp_desc, const int *ncells, bool normalize, bool asrows){

}

void fsiv_lbp_disp(const cv::Mat & lbpmat, const std::string & winname){
  cv::imshow(winname,lbpmat);
}

float fsiv_chisquared_dist(const cv::Mat & h1, const cv::Mat & h2){
    float error = 0.0;
    float xi, yi;

    for (int i = 0; i < h1.rows; i++) {
        xi = *h1.ptr<float>(i);
        yi = *h2.ptr<float>(i);
        if (abs(xi + yi) > 0.00001) {
            error += (pow(xi - yi, 2) / (xi + yi));
        }
    }
    error *= 0.5;
    return error;
}
