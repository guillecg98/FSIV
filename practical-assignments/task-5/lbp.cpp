//! \file lbp.cpp
//! Utils for LBP

#include "lbp.h"
#include <vector>

using namespace std;


void fsiv_lbp(cv::Mat imagem, cv::Mat & lbp){
  cv::Mat img;
  imagem.copyTo(img);
  imagem.copyTo(lbp);
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
  unsigned char binary_number = 0;
  //filling the sumImage with
  int x = 0;
  uchar *ptr1 = subImage.ptr<uchar>(x);
  uchar *ptr2 = subImage.ptr<uchar>(x+1);
  uchar *ptr3 = subImage.ptr<uchar>(x+2);

  binary_number |= ((ptr1[x] >= value) << 7);
  binary_number |= ((ptr1[x+1] >= value) << 6);
  binary_number |= ((ptr1[x+2] >= value) << 5);
  binary_number |= ((ptr2[x+2] >= value) << 4);
  binary_number |= ((ptr3[x+2] >= value) << 3);
  binary_number |= ((ptr3[x+1] >= value) << 2);
  binary_number |= ((ptr3[x] >= value) << 1);
  binary_number |= ((ptr2[x] >= value) << 0);

  return binary_number;
}

void fsiv_lbp_hist(const cv::Mat & lbp, cv::Mat & lbp_hist, bool normalize){
    std::vector<int> histSize = { 256 };
    std::vector<float> ranges = { 0, (float)256 };
    std::vector<cv::Mat> lbpVector {lbp};
    std::vector<int> channels = { 0 };
    cv::calcHist(lbpVector, channels, cv::Mat(), lbp_hist, histSize, ranges);
    lbp_hist = lbp_hist.mul(1.0 / (lbp.cols * lbp.rows));
}

void fsiv_lbp_desc(const cv::Mat & image, cv::Mat & lbp_desc, const int *ncells, bool normalize, bool asrows){

}

void fsiv_lbp_disp(const cv::Mat & lbpmat, const std::string & winname){
  cv::imshow(winname,lbpmat);
}

float fsiv_chisquared_dist(const cv::Mat & h1, const cv::Mat & h2){
    float error = cv::compareHist(h1,h2,cv::HISTCMP_CHISQR);
    return error;
}
