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

void fsiv_lbp_hist(cv::Mat & lbp, cv::Mat & lbp_hist, bool normalize){
    int histSize = 256;
    const float range[] = { 0, 256 };
    const float* histRange = { range };
    cv::calcHist(&lbp, 1, 0, cv::Mat(), lbp_hist, 1, &histSize, &histRange,true,false);
    cv::normalize(lbp_hist,lbp_hist,1,0,cv::NORM_L1,-1,cv::Mat());
}

void fsiv_lbp_desc(cv::Mat & image, cv::Mat & lbp_desc, const int *ncells, bool normalize, bool asrows){
  std::vector<cv::Mat> grid;
  //if(image.rows % ncells[0] == 0 && image.cols % ncells[1] == 0){
    for(int y = 0; y < image.cols - ncells[1]; y += image.cols / ncells[1]){
      for(int x = 0; x < image.rows - ncells[0]; x += image.rows / ncells[0]){
        // cv::Rect grid_rect(x,y,image.rows/ncells[0],image.cols/ncells[1]);
        // cv::rectangle(image, grid_rect, cv::Scalar(0, 255, 0), 1);
        grid.push_back(image(cv::Rect(y,x,(image.cols/ncells[1]),(image.rows/ncells[0]))).clone());
        cv::rectangle(image,cv::Point(y,x),cv::Point(y+(image.cols/ncells[1])-1,x+(image.rows/ncells[0])-1),cv::Scalar(0, 255, 0), 1);
        //cv::imshow("Image", maskImage); // visualization
        //cv::waitKey(0); // visualization
      }
    }
  // }else{
  //   std::cerr<<"No valids cells grid\n";
  // }
  std::cerr<<"Tamaño del vector de bloques = "<<grid.size()<<"\n";
}

void fsiv_lbp_disp(const cv::Mat & lbpmat, const std::string & winname){
  cv::imshow(winname,lbpmat);
}

float fsiv_chisquared_dist(const cv::Mat & h1, const cv::Mat & h2){
    float error = cv::compareHist(h1,h2,cv::HISTCMP_CHISQR);
    return error;
}
