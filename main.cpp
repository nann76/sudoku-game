// Copyright (c) 2023 dingyanfeng/jianghaonan
// All rights reserved.

// 调用自己添加的getopt，以在windows下使用getopt
#include "getopt.h"         // NOLINT
#include "gtest/gtest.h"

// #define TEST_SUDOKU

#ifndef TEST_SUDOKU
#include<iostream>
#include"common.h"          // NOLINT
#include"my_assert.h"       // NOLINT

int main(int argc, char* argv[]) {
    // 参数，只有-u后无参数
    char getopt_arg[] = "c:s:n:m:r:u";
    int opt;

    while ((opt = getopt(argc, argv, getopt_arg)) != -1) {
        char* endptr = nullptr;
        switch (opt) {
            case 'c':
                my_assert(!if_gen_sudoku_endgame, "redundant optarg  -c");
                if_gen_sudoku_endgame = true;
                // 取终局的数量
                num_sudoku_endgame = static_cast<int>(strtol(
                                                    optarg,
                                                    &endptr,
                                                    10));
                my_assert(num_sudoku_endgame != 0, "optarg  -c not a num ");
                my_assert(1 <= num_sudoku_endgame &&
                                    num_sudoku_endgame <= 1000000,
                          "The number of endgame is not in range");
                break;
            case 's':
                my_assert(!redundant_s, "redundant optarg  -s");
                redundant_s = true;
                // 取求解路径
                snprintf(sudoku_solve_path, sizeof(sudoku_solve_path),
                         "%s", optarg);
                break;
            case 'n':
                my_assert(!redundant_n, "redundant optarg  -n");
                redundant_n = true;

                // 取需要的游戏数量
                num_sudoku_game = static_cast<int>(strtol(optarg, &endptr, 10));
                my_assert(num_sudoku_game != 0, "optarg  -n not a num ");
                my_assert(1 <= num_sudoku_game && num_sudoku_game <= 1000,
                          "The required number of games is out of range!");
                break;
            case 'm':
                my_assert(!redundant_m, "redundant optarg  -m");
                redundant_m = true;

                // 取需要的游戏数量
                game_level = static_cast<int>(strtol(optarg, &endptr, 10));
                my_assert(game_level != 0,
                          "optarg  -m not a num ");
                my_assert(1 <= game_level && game_level <= 3,
                          "Game difficulty is out of range!");
                break;
            case 'r':
                my_assert(!redundant_r, "redundant optarg  -r");
                redundant_r = true;

                char temp[20];
                snprintf(temp, sizeof(temp), "%s", optarg);
                char* low;
                char* up;

                char *my_saveptr1;
                low = strtok_r(temp, "~", &my_saveptr1);
                low_range = static_cast<int>(strtol(low, &endptr, 10));
                up = strtok_r(nullptr, "~", &my_saveptr1);
                high_range = static_cast<int>(strtol(up, &endptr, 10));
                my_assert(low_range != 0, "optarg  -u  low range not a num ");
                my_assert(high_range != 0, "optarg  -u  high range not a num ");

                my_assert(20 <= low_range && low_range <= 55,
                          "The blank range low_range is "
                          "not within the specified range!");
                my_assert(20 <= high_range && high_range <= 55,
                          "The blank range high_range is"
                          " not within the specified range!");
                if (high_range < low_range) {
                    my_assert(false,
                              "The blank range low range "
                              "should be smaller than high_range ");
                }
                break;
            case 'u':
                my_assert(!redundant_u, "redundant optarg  -u");
                redundant_u = true;
                break;
            default:
                // 无效opt
                std::cout << "exit invalid opt:" << std::endl;
                break;
        }
    }

    // 判断参数同时出现
    if (redundant_m) {
        if (!redundant_n) {
            my_assert(false, "m and n do not appear at the same time");
        }
    }

    if (redundant_r) {
        if (!redundant_n) {
            my_assert(false, "r and n do not appear at the same time");
        }
    }

    if (redundant_u) {
        if (!redundant_n) {
            my_assert(false, "u and n do not appear at the same time");
        }
    }

    if (redundant_m && redundant_r) {
        my_assert(false, "m and r can not appear at the same time");
    }

    if (redundant_s) {
        vector<vector<int>> matrix(9, vector<int>(9, 0));
        SudoKu solve_game;

        ifstream in;
        in.open(sudoku_solve_path, std::ios::in);
        std::cout << sudoku_solve_path << std::endl;
        solve_game.read_file(in, matrix);
    }

    // 调用生成终局
    if (if_gen_sudoku_endgame) {
        vector<vector<int>> matrix(9, vector<int>(9, 0));
        // 初始化矩阵
        SudoKu endgame(matrix);

        endgame.create_sudoku_endgame(num_sudoku_endgame, matrix);
    }

    // 生成游戏-n
    if (redundant_n) {
        SudoKu gen_game;
        gen_game.create_random_sudoku(num_sudoku_game, redundant_u);
    }
}
#endif

#ifdef TEST_SUDOKU

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
