#include "task3.hpp"

int main(int argc,char **argv){

    cv::Mat image,filter;
    float g;
    int f;
    CmdLineParser cml(argc,argv);
    //check if a command is present
    try{
        if(argc < 3){
            cerr<<"Usage: <input img> <output img>\n Options:\n \t[-f filter type: [0-1]] \n \t[-g gain > 0.0]"<<endl;
            return 0;
        }

        image=cv::imread(argv[1]);

        if( image.rows==0){
            cerr<<"Error reading image"<<endl;
            return 0;
        }

        if(cml["-f"]){
            if( (stoi(cml("-f")) >= 0) && (stoi(cml("-c")) <= 1) ){
                int f= std::stoi( cml("-f"));//convert to int
            }else{
                f = 0;
            }
        }
        if(cml["-g"]){
            if (stof(cml("-g")) >= 0){
                g = std::stof(cml("-g"));//convert to float
            }else{
                g = 1;
            }
        }

        //do things
        filter = create_sharp_filter(f,g);


        for(int x = 0; x < filter.rows; x++){
            float *ptr = filter.ptr<float>(x);
            for(int y = 0; y < filter.cols; y++){
                std::cout<<"filtro["<<x<<"]["<<y<<"] = "<<ptr[y]<<"\t";
            }
            std::cout<<"\n";
        }

        // char c=0;
        // while(c!=27)  //waits until ESC pressed
        // c=cv::waitKey(0);
    }
    catch(const std::exception& ex){
        std::cerr << ex.what() << '\n';
    }
}