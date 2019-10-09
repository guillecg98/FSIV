#include "task3.hpp"

cv::Mat create_sharp_filter(int &f, float &g){
    //creamos el filtro 3x3
    cv::Mat filter(3,3,CV_32FC1,0.0);

        if(f == 1){
            //devolver filtro 9 puntos
            for(int x = 0; x < filter.rows; x++){
                float *ptr = filter.ptr<float>(x);
                for(int y = 0; y < filter.cols; y++){
                    ptr[y] =1/pow(filter.rows, 2);
                    /*if( (x == 1) && (y == 1)){
                        ptr[0] == g+8;
                    }else{
                        ptr[0] == -1;
                    }*/
                }
            }
        }/*else{//devolver filtro 9 puntos
        for(int x = 0; x < filter.rows; x++){
            for(int y = 0; y < filter.cols; y++){
                uchar *ptr = filter.ptr<uchar>(x)+y;
            }
        }
    }*/

    return filter;
}