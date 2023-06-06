#ifndef COMMOM_H
#define COMMON_H

//数独终局 -c
bool if_gen_sudoku_endgame=false;
int num_sudoku_endgame=0;

//求解数独的路径 -s
bool redundant_s=false;
char sudoku_slove_path[256];



//需要的游戏数量 -n
bool redundant_n=false;
int num_sudoku_game=0;

//生成游戏的难度 -m
enum GAME_LEVEL{NONE,EASY,MID,HARD};
bool redundant_m=false;
int game_level=GAME_LEVEL::NONE;

//挖空的数量范围 -r
bool redundant_r=false;
int low_range =0;
int high_range =0;


//生成的游戏的解唯一 -u
bool redundant_u=false;
bool if_unique=false;





#endif