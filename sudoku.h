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

#define CHANGE_MAX_NUM 5

class SudoKu
{
private:
    // //��Ϸ�Ѷ�
    // int level_game=0;
    // //�ڿ�������Χ
    // bool opt_r=false;
    // int low_range =0;
    // int high_range =0; 

    // //Ψһ��
    // bool opt_u=false;

    // int num_blank =5;

public:

    bool init(vector<vector<int>>& matrix, int start);
    bool is_valid(int row, int col, int num, vector<vector<int>>& matrix);
    void swap_col(int m, int n, vector<vector<int>>& matrix);
    void set_blank(int nums, vector<vector<int>>& matrix);

    bool active = false;

    string endgame_dir = "./endgames/";
    string game_dir = "./games/";
    enum GAME_LEVEL { NONE, EASY, MEDIUM, HARD };
    SudoKu() {};
    SudoKu(vector<vector<int>>& matrix);
    //����ָ���������ڿ��������������Լ��Ƿ�Ψһ��
    void create_random_sudoku(int num_game, bool if_unique);
    //�����վ� 
    void create_sudoku_endgame(int num_game, vector<vector<int>>& matrix);
    //����ָ���������ڿ��������������Լ��Ƿ�Ψһ��
    void create_sudoku(vector<vector<int>> matrix);

    //���ļ�
    void read_file(ifstream& file, vector<vector<int>>& matrix);
    //д�ļ�
    void write_file(ofstream& file, vector<vector<int>> matrix);



    ~SudoKu() {};
};

#endif