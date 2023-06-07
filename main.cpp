<<<<<<< HEAD
#include"sudoku.h"

using namespace std;


int main(){
    vector<vector<int>> matrix(9, vector<int>(9, -1));
    SudoKu test(matrix);
    test.create_random_sudoku(1, matrix);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
=======
#include<iostream>
// 调用自己添加的getopt，以在windows下使用getopt
#include"getopt.h"
#include"assert.h"
#include"common.h"
#pragma warning(disable:4996)
using namespace std;



int main(int argc, char* argv[]) {
    // 参数，只有-u后无参数
    char getopt_arg[] = "c:s:n:m:r:u";
    int opt;

    while ((opt = getopt(argc, argv, getopt_arg)) != -1) {
        switch (opt){
        case 'c':
            assert(!if_gen_sudoku_endgame, "redundant optarg  -c");
            if_gen_sudoku_endgame = true;

            // 取终局的数量
            num_sudoku_endgame = atoi(optarg);
            assert(num_sudoku_endgame != 0, "optarg  -c not a num ");
            assert(1 <= num_sudoku_endgame && num_sudoku_endgame <= 1000000, "终局的数量不在范围内");
            break;
        case 's':
            assert(!redundant_s, "redundant optarg  -s");
            redundant_s = true;
            // 取求解路径
            strcpy(sudoku_slove_path, optarg);
            break;
        case 'n':
            assert(!redundant_n, "redundant optarg  -n");
            redundant_n = true;

            // 取需要的游戏数量
            num_sudoku_game = atoi(optarg);
            assert(num_sudoku_game != 0, "optarg  -n not a num ");
            assert(1 <= num_sudoku_game && num_sudoku_game <= 1000, "需要的游戏数量不在范围内");
            break;
        case 'm':
            assert(!redundant_m, "redundant optarg  -m");
            redundant_m = true;

            // 取需要的游戏数量
            game_level = atoi(optarg);
            assert(game_level != 0, "optarg  -m not a num ");
            assert(1 <= game_level && game_level <= 3, "游戏难度不在范围内");
            break;
        case 'r':
            assert(!redundant_r, "redundant optarg  -r");
            redundant_r = true;

            char temp[20];
            strcpy(temp, optarg);
            char* low;
            char* up;

            low = strtok(temp, "~");
            low_range = atoi(low);
            up = strtok(NULL, "~");
            high_range = atoi(up);

            assert(low_range != 0, "optarg  -u  low range not a num ");
            assert(high_range != 0, "optarg  -u  high range not a num ");

            assert(20 <= low_range && low_range <= 55, "挖空的范围low_range 不在过规定范围内");
            assert(20 <= high_range && high_range <= 55, "挖空的范围high_range 不在过规定范围内");
            if (high_range < low_range) {
                assert(0, "挖空的范围low range 小于high_range ");
            }
            break;
        case 'u':
            assert(!redundant_u, "redundant optarg  -u");
            redundant_u = true;
            break;
        default:
            // 无效opt
            cout << "exit invalid opt:" << endl;
            break;
        }

    }

    // 判断参数同时出现
    if (redundant_m) {
        if (!redundant_n) {
            assert(0, "m与n未同时出现");
        }
    }

    if (redundant_r) {
        if (!redundant_n) {
            assert(0, "r与n未同时出现");
        }
    }

    if (redundant_u) {
        if (!redundant_n) {
            assert(0, "u与n未同时出现");
        }
    }

    if (redundant_m && redundant_r) {
        assert(0, "m和r不能同时出现");
    }

    if (redundant_s) {
        vector<vector<int>> matrix(9, vector<int>(9, 0));
        SudoKu slove_game;

        ifstream in;
        in.open(sudoku_slove_path, ios::in);
        cout << sudoku_slove_path << endl;
        slove_game.read_file(in, matrix);

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
>>>>>>> development
