#ifndef COMMOM_H
#define COMMON_H
#include"sudoku.h"

//�����վ� -c
bool if_gen_sudoku_endgame = false;
int num_sudoku_endgame = 0;

//���������·�� -s
bool redundant_s = false;
char sudoku_slove_path[256];



//��Ҫ����Ϸ���� -n
bool redundant_n = false;
int num_sudoku_game = 0;

//������Ϸ���Ѷ� -m
// enum GAME_LEVEL{NONE,EASY,MEDIUM,HARD};
bool redundant_m = false;
int game_level = SudoKu::GAME_LEVEL::NONE;

//�ڿյ�������Χ -r
bool redundant_r = false;
int low_range = 0;
int high_range = 0;


//���ɵ���Ϸ�Ľ�Ψһ -u
bool redundant_u = false;
bool if_unique = false;





#endif