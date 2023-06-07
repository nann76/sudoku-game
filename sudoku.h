#ifndef SUDOKU_H
#define SUDOKU_H
#include<iostream>
#include<vector>
#include<time.h>
#include <fstream>
#include<string>
#include <io.h>
#include <direct.h>


using namespace std;

#define CHANGE_MAX_NUM 10

class SudoKu
{
public:
    int num_solutions=0;
    int solve_with_count(vector<vector<int>>& matrix, int& ans);
    bool init(vector<vector<int>>& matrix, int start);
    bool is_valid(int row, int col, int num, vector<vector<int>>& matrix);
    void swap_col(int m, int n, vector<vector<int>>& matrix);
    void set_blank(int nums, vector<vector<int>>& matrix);

    bool active = false;

    string endgame_dir = "endgames.txt";
    string game_dir = "games.txt";
    enum GAME_LEVEL { NONE, EASY, MEDIUM, HARD };
    SudoKu() {};
    SudoKu(vector<vector<int>>& matrix);
    // 创建指定数量和挖空数量的数独，以及是否唯一解
    void create_random_sudoku(int num_game, bool if_unique);
    // 创建终局 
    void create_sudoku_endgame(int num_game, vector<vector<int>>& matrix);
    //创建解唯一

    void swap_col_row(vector<vector<int>>& matrix);


    // 读文件
    void read_file(ifstream& file, vector<vector<int>>& matrix);
    // 写文件
    void write_file(ofstream& file, vector<vector<int>> matrix);

    ~SudoKu() {};
};

#endif