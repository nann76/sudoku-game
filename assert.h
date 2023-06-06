#ifndef ASSERT_H
#define ASSERT_H

#include<iostream>

//自定义断言
void assert(bool cond,char * message){

    if(!cond){
        std::cout<<message<<std::endl;
        exit(EXIT_FAILURE);
    }
}


#endif

