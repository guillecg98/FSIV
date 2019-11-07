//! \file lbp.cpp
//! Utils for LBP

#include "lbp.h"
#include <vector>

using namespace std;


void fsiv_lbp(const cv::Mat & imagem, cv::Mat & lbp){
  int value;
  for(int x = 1; x < imagem.rows - 1; x++){
    uchar *ptrImage = imagem.ptr<uchar>(x);
    uchar *ptrLbp = lbp.ptr<uchar>(x);
    for(int y = 1; y < imagem.cols - 1; y++){
      cv::Mat subImage = get_sub_image(imagem,x,y);
      value = ptrImage[y];
      ptrLbp[y] = get_lbp_value(subImage,value);
    }
  }
}

cv::Mat get_sub_image(const cv::Mat &imagem, int i, int j){
    cv::Mat sub(3,3,CV_8UC1);
    for(int x = 0; x < 3; x++){
        uchar *ptr_image = imagem.ptr<uchar>(x+i-1);
        uchar *ptr_sub_image = sub.ptr<uchar>(x);
        for(int y = 0; y < 3; y++){
            ptr_sub_image[y] = ptr_image[y+j-1];
        }
    }
    return sub;
}

int get_lbp_value(cv::Mat &subImage, int value){
  std::vector <int> binary_value;
  int decimal = 0;
    //filling the sumImage with
    for(int x = 0; x < subImage.rows; x++){
        uchar *ptr = subImage.ptr<uchar>(x);
        for(int y = 0; y < subImage.cols; y++){
          if( x != 1 && y != 1 ){
            if(ptr[y] > value){
               binary_value.push_back(1);
            }else{
              binary_value.push_back(0);
            }
          }
        }
    }
    //converting binary to int
    for(int i = 0; i < binary_value.size(); i++){
      if(binary_value[i] == 1){
        decimal += pow(2,i);
      }
    }
    return decimal;
}

void fsiv_lbp_hist(const cv::Mat & lbp, cv::Mat & lbp_hist, bool normalize){

}

void fsiv_lbp_desc(const cv::Mat & image, cv::Mat & lbp_desc, const int *ncells, bool normalize, bool asrows){

}

void fsiv_lbp_disp(const cv::Mat & lbpmat, const std::string & winname){
  cv::imshow(winname,lbpmat);
}

float fsiv_chisquared_dist(const cv::Mat & h1, const cv::Mat & h2){
  return -1;
}
