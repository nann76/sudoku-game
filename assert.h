#ifndef ASSERT_H
#define ASSERT_H

#include<iostream>

// ×Ô¶¨Òå¶ÏÑÔ
void assert(bool cond,const char* message) {
    if (!cond) {
        std::cout << message << std::endl;
        exit(EXIT_FAILURE);
    }
}

#endif


