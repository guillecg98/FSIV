//! \file lbp.h
//! Utils for LBP

#ifndef _FSIV_LBP_H_
#define _FSIV_LBP_H_

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv::ml;

//! Computes a LBP matrix
//! \param imagem [in] Input image (gray scale)
//! \param lbp [out] Output matrix. Memory is allocated inside the function
void fsiv_lbp(const cv::Mat & imagem, cv::Mat & lbp);

cv::Mat get_sub_image(cv::Mat img, int i, int j);
unsigned char get_lbp_value(cv::Mat subImage,unsigned char value);

//! Displays a LBP image
//! \param lbpmat [in] LBP matrix
//! \param winname [in] Window name (to be displayed in)
void fsiv_lbp_disp(const cv::Mat & lbpmat, const std::string & winname);

//! Computes a LBP histogram
//! \param lbp [in] Input LBP matrix
//! \param lbp_hist [out] Output histogram. Memory is allocated inside the function
//! \param [in] Normalize histogram?
void fsiv_lbp_hist(cv::Mat & lbp, cv::Mat & lbp_hist, bool normalize=true);

//! Computes a LBP descriptor (concatenation of cells)
//! \param ncells [in] [rows x cols] E.g. {6,4}
void fsiv_lbp_desc(cv::Mat & image, cv::Mat & lbp_desc, const int *ncells, bool normalize=true, bool asrows=true);

//! Computes Chi^2 distance between two distributions
//! \param h1, h2 Row vectors with the same dimensions.
//! \return The distance
float fsiv_chisquared_dist(const cv::Mat & h1, const cv::Mat & h2);

// where:
    // \param image [in] is the input GRAY image.
// \param svm [in] is the classifier.
// \param winsize [in] the window size.
// \param stride [in] is the used step for the scanning scheme.
// \param ncelss [in] set the grid geometry to compute the lbp descriptor.
// \param nlevels [in] is the maximum number of levels of the multi-resolution pyramid.
// \param lRs [out] List of detections bb.
// \param lscores [out] List of scores (one per detection in lRs)
void fsiv_detect_pyr(const cv::Mat & image, const cv::Ptr<SVM> & svm, const int *winsize, int stride, int * ncells, int nlevels, float factor, float thr_det, std::vector<cv::Rect> & lRs, std::vector<float> & lscores);




#endif
