#include "task3.hpp"

cv::Mat create_sharp_filter(int &f, float &g){
    //creamos el filtro 3x3
    cv::Mat filter(3,3,CV_32FC1,-1);

    if(f == 1){
        std::cerr<<"Entro if\n";
        //devolver filtro 9 puntos
        for(int x = 0; x < filter.rows; x++){
            float *ptr = filter.ptr<float>(x);
            for(int y = 0; y < filter.cols; y++){
                if( (x == 1) && (y == 1) ){
                    ptr[y] = g+8;
                }
            }
        }
    }else{//devolver filtro 9 puntos
        for(int x = 0; x < filter.rows; x++){
            float *ptr = filter.ptr<float>(x);
            for(int y = 0; y < filter.cols; y++){
                if( (x == 1) && (y == 1) ){
                    ptr[y] = g+4;
                }
                if( ((x == 0) && (y == 0)) || ((x == 0) && (y == 2)) || ((x == 2) && (y == 0)) || ((x == 2) && (y == 2)) ){
                    ptr[y] = 0;
                }
            }
        }
    }

    return filter;
}