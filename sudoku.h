// Copyright (c) 2023 dingyanfeng/jianghaonan
// All rights reserved.

#ifndef SUDOKU_GAME_SUDOKU_H_
#define SUDOKU_GAME_SUDOKU_H_

#include <io.h>
#include <direct.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
#include <random>


using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

#define CHANGE_MAX_NUM 10

class SudoKu {
 public:
    int solve_with_count(vector<vector<int>>& matrix, int& ans);  /* NOLINT */
    bool init(vector<vector<int>>& matrix, int start);           /* NOLINT */
    static bool is_valid(int row, int col, int num,
                         vector<vector<int>>& matrix);          /* NOLINT */
    static void swap_col(int m, int n, vector<vector<int>>& matrix);    /* NOLINT */
    static void set_blank(int nums, vector<vector<int>>& matrix);   /* NOLINT */

    bool active = false;

    string endgame_dir = "endgames.txt";
    string game_dir = "games.txt";
    enum GAME_LEVEL { NONE, EASY, MEDIUM, HARD };
    SudoKu() = default;
    explicit SudoKu(vector<vector<int>>& matrix);       /* NOLINT */
    // Create a specified number of sudoku and blank numbers,
    // and whether they are unique solutions
    void create_random_sudoku(int num_game, bool if_unique);
    // create endgame
    void create_sudoku_endgame(int num_game, vector<vector<int>>& matrix) const;  /* NOLINT */
    // read file and solve the sudoku
    void read_file(ifstream& file, vector<vector<int>>& matrix);    /* NOLINT */
    // write file
    static void write_file(ofstream& file, vector<vector<int>> matrix);

    ~SudoKu() = default;
};

#endif  // SUDOKU_GAME_SUDOKU_H_
