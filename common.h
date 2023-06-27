// Copyright (c) 2023 dingyanfeng/jianghaonan
// All rights reserved.
#ifndef SUDOKU_GAME_COMMON_H_
#define SUDOKU_GAME_COMMON_H_
#include"sudoku.h" // NOLINT

// Sudoku Endgame -c
bool if_gen_sudoku_endgame = false;
int num_sudoku_endgame = 0;

// Path to Solve Sudoku -s
bool redundant_s = false;
char sudoku_solve_path[256];

// number of games required -n
bool redundant_n = false;
int num_sudoku_game = 0;

// The difficulty of generating game -m
// enum GAME_LEVEL{NONE,EASY,MEDIUM,HARD};
bool redundant_m = false;
int game_level = SudoKu::GAME_LEVEL::NONE;

// the number of blank -r
bool redundant_r = false;
int low_range = 0;
int high_range = 0;

// The solution of the generated game is unique -u
bool redundant_u = false;
bool if_unique = false;

#endif  // SUDOKU_GAME_COMMON_H_
