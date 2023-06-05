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