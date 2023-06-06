#ifndef SUDOKU_H
#define SUDOKU_H
#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

#define CHANGE_MAX_NUM 1

class SudoKu
{
private:
    bool init(vector<vector<int>>& matrix, int start);
    bool is_valid(int row, int col, int num, vector<vector<int>>& matrix);
    void swap_col(int m, int n, vector<vector<int>>& matrix);
    void set_blank(int nums, vector<vector<int>>& matrix);
public:
    bool active = false;
    SudoKu(vector<vector<int>>& matrix);
    void create_random_sudoku(int blank, vector<vector<int>>& matrix);
    ~SudoKu(){};
};

#endif
