// Copyright (c) 2023 dingyanfeng/jianghaonan
// All rights reserved.
#ifndef SUDOKU_GAME_MY_ASSERT_H_
#define SUDOKU_GAME_MY_ASSERT_H_

#include<iostream>

// my custom assertion
void my_assert(bool cond, const char* message) {
    if (!cond) {
        std::cout << message << std::endl;
        exit(EXIT_FAILURE);
    }
}

#endif  // SUDOKU_GAME_MY_ASSERT_H_
