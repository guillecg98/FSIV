//! \file lbp.cpp
//! Utils for LBP

#include "lbp.h"
#include <vector>

using namespace std;


void fsiv_lbp(const cv::Mat & imagem, cv::Mat & lbp){
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

void fsiv_lbp_hist(cv::Mat & lbp, cv::Mat & lbp_hist, bool normalize){
    int histSize = 256;
    const float range[] = { 0, 256 };
    const float* histRange = { range };
    cv::calcHist(&lbp, 1, 0, cv::Mat(), lbp_hist, 1, &histSize, &histRange,true,false);
    if(normalize){
      cv::normalize(lbp_hist,lbp_hist,1,0,cv::NORM_L1,-1,cv::Mat());
    }
}

void fsiv_lbp_desc(cv::Mat & image, cv::Mat & lbp_desc, const int *ncells, bool normalize, bool asrows){
  cv::Mat lbp_aux,lbp_aux_hist;
  cv::Mat desc(256,1,CV_32F);
  desc.copyTo(lbp_desc);
  std::vector<cv::Mat> grid;
  std::vector<cv::Mat> histograms;
  std::vector<float> sumHistogram(256,0);

  //Save each zone of the grid in a vector to compute them individually
  for(int y = 0; y < (image.cols - ncells[1]); y += image.cols / ncells[1]){
    for(int x = 0; x < (image.rows - ncells[0]); x += image.rows / ncells[0]){
      grid.push_back(image(cv::Rect(y,x,(image.cols/ncells[1]),(image.rows/ncells[0]))).clone());
      cv::rectangle(image,cv::Point(y,x),cv::Point(y+(image.cols/ncells[1])-1,x+(image.rows/ncells[0])-1),cv::Scalar(0, 255, 0), 1);
    }
  }
//Computing each zone of the grid individually and saving their histograms to another vector
 for(int i = 0; i < grid.size(); i++){
    fsiv_lbp(grid[i],lbp_aux);
    fsiv_lbp_hist(lbp_aux,lbp_aux_hist,false);
    histograms.push_back(lbp_aux_hist);
  }
//calculating the total value of the histogram
  for(int i = 0; i < histograms.size(); i++){
    for(int x = 0; x < histograms[i].rows; x++){
      float *ptr_hist = histograms[i].ptr<float>(x);
      for(int y = 0; y < histograms[i].cols; y++){
        sumHistogram[x] += ptr_hist[y];
      }
    }
  }
//Passing histogram information to the image
  for(int x = 0; x < lbp_desc.rows; x++){
    float *ptr_desc = lbp_desc.ptr<float>(x);
    for(int y = 0; y < lbp_desc.cols; y++){
      ptr_desc[y] = sumHistogram[x];
    }
  }
  //Normalizing the histogram
  cv::normalize(lbp_desc,lbp_desc,1,0,cv::NORM_L1,-1,cv::Mat());
}

void fsiv_lbp_disp(const cv::Mat & lbpmat, const std::string & winname){
  cv::imshow(winname,lbpmat);
}

float fsiv_chisquared_dist(const cv::Mat & h1, const cv::Mat & h2){
    float error = cv::compareHist(h1,h2,cv::HISTCMP_CHISQR);
    return error;
}
