#ifndef ASSERT_H
#define ASSERT_H

#include<iostream>

// �Զ������
void my_assert(bool cond,const char* message) {
    if (!cond) {
        std::cout << message << std::endl;
        exit(EXIT_FAILURE);
    }
}

#endif


