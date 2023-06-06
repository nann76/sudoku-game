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
