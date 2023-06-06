#include"sudoku.h"

using namespace std;


SudoKu::SudoKu(vector<vector<int>>& matrix)
{
    this->active=init(matrix, 0);
}


bool SudoKu::is_valid(int row, int col, int num, vector<vector<int>>& matrix)
{
    for(int i=0; i<matrix[0].size(); i++) if(num == matrix[row][i]) return false;
    for(int i=0; i<matrix.size(); i++)    if(num == matrix[i][col]) return false;
    for(int i=row/3*3; i<row/3*3+3; i++){
        for(int j=col/3*3; j<col/3*3+3; j++){
            if(num == matrix[i][j]) return false;
        }
    }
    return true;
}


bool SudoKu::init(vector<vector<int>>& matrix, int start)
{
    if(start == 81) return true;
    else{
        int row = start / 9;
        int col = start % 9;
        bool current_is_valid = false;
        if(matrix[row][col] == -1){
            for(int i=1; i<10; i++){
                if(this->is_valid(row, col, i, matrix)){
                    matrix[row][col] = i;
                    current_is_valid = init(matrix, start+1);
                    if(!current_is_valid) matrix[row][col] = -1;
                }
            }
        }
        else{
            current_is_valid = init(matrix, start + 1);
        }
        return current_is_valid;
    }
}


void SudoKu::swap_col(int m, int n, vector<vector<int>>& matrix)
{
    vector<int> temp(matrix.size(), -1);
    for(int i=0; i<matrix.size(); i++)
    {
        temp[i] = matrix[i][m];
        matrix[i][m] = matrix[i][n];
        matrix[i][n] = temp[i];
    }
}


void SudoKu::set_blank(int nums, vector<vector<int>>& matrix)
{
    srand(time(NULL));
    while(nums)
    {
        int row = rand() % 9;
        int col = rand() % 9;
        if(matrix[row][col] != -1)
        {
            matrix[row][col] = -1;
            nums--;
        }
    }
}


void SudoKu::create_random_sudoku(int blank, vector<vector<int>>& matrix)
{
    int choice[9][2] = {{0,1},{0,2},{1,2},{3,4},{3,5},{4,5},{6,7},{6,8},{7,8}};
    srand(time(NULL));
    for(int i=0; i<CHANGE_MAX_NUM; i++){
        int index = rand() % 9;
        matrix[choice[index][0]].swap(matrix[choice[index][1]]);
        swap_col(choice[index][0], choice[index][1], matrix);
    }
    set_blank(blank, matrix);
}
