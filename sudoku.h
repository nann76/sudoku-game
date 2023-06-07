#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

#define CHANGE_MAX_NUM 5

class SudoKu
{
private:
    // //游戏难度
    // int level_game=0;
    // //挖空数量范围
    // bool opt_r=false;
    // int low_range =0;
    // int high_range =0; 

    // //唯一解
    // bool opt_u=false;

    // int num_blank =5;



    bool init(vector<vector<int>>& matrix, int start);
    bool is_valid(int row, int col, int num, vector<vector<int>>& matrix);
    void swap_col(int m, int n, vector<vector<int>>& matrix);
    void set_blank(int nums, vector<vector<int>>& matrix);
public:
    bool active = false;
    SudoKu(){};
    SudoKu(vector<vector<int>>& matrix);
    //创建指定数量和挖空数量的数独，以及是否唯一解
    void create_random_sudoku(int num_game,int num_blank,bool if_unique);
    //创建终局 
    void create_sudoku_endgame(vector<vector<int>>& matrix);
    //创建指定数量和挖空数量的数独，以及是否唯一解
    void create_sudoku(vector<vector<int>> matrix);



    ~SudoKu(){};
};