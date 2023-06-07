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
        if(matrix[row][col] == 0){
            for(int i=1; i<10; i++){
                if(this->is_valid(row, col, i, matrix)){
                    matrix[row][col] = i;
                    current_is_valid = init(matrix, start+1);
                    if(!current_is_valid) matrix[row][col] = 0;
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
    vector<int> temp(matrix.size(), 0);
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
        if(matrix[row][col] != 0)
        {
            matrix[row][col] = 0;
            nums--;
        }
    }
}


// void SudoKu::create_random_sudoku(int blank, vector<vector<int>>& matrix)
// {
//     int choice[9][2] = {{0,1},{0,2},{1,2},{3,4},{3,5},{4,5},{6,7},{6,8},{7,8}};
//     srand(time(NULL));
//     //调整矩阵
//     for(int i=0; i<CHANGE_MAX_NUM; i++){
//         int index = rand() % 9;
//         matrix[choice[index][0]].swap(matrix[choice[index][1]]);
//         swap_col(choice[index][0], choice[index][1], matrix);
//     }
//     //挖空
//     set_blank(blank, matrix);
// }
void SudoKu::create_random_sudoku(int num_game,bool if_unique){


            //挖空数
        int num_blank=10;

        extern bool redundant_m;
        extern int game_level;

        extern bool redundant_r;
        extern int low_range ;
        extern int high_range ;

        //根据游戏难度修改挖空数
        if(redundant_m){
            switch (game_level)
            {
            case GAME_LEVEL::NONE:
                num_blank=10;
                break;
            case GAME_LEVEL::EASY:
                num_blank=10;
                break;
            case GAME_LEVEL::MEDIUM:
                num_blank=30;
                break;
            case GAME_LEVEL::HARD:
                num_blank=60;
                break;     
            default:
                num_blank=10;
                break;
            }
        // cout<<"给定难度为："<<game_level<<"挖空数为: "<<num_blank<<endl;
        }



    //新建
    vector<vector<int>> matrix(9, vector<int>(9, 0));
    this->active=this->init(matrix,0);

    int choice[9][2] = {{0,1},{0,2},{1,2},{3,4},{3,5},{4,5},{6,7},{6,8},{7,8}};
    srand(time(NULL));

    for(int i=0;i<num_game;i++){

    for(int i=0; i<CHANGE_MAX_NUM; i++){
        int index = rand() % 9;
        matrix[choice[index][0]].swap(matrix[choice[index][1]]);
        swap_col(choice[index][0], choice[index][1], matrix);
    }

    //深拷贝初始
    vector<vector<int>> temp(matrix);

    //根据给定范围设置挖空数
    if(redundant_r){
    num_blank= rand() % (high_range - low_range + 1) + low_range;
    // cout<<"给定范围内挖空数为："<<num_blank<<endl;
    }
    

    //挖空
    set_blank(num_blank, temp);

        //输出打印
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<temp[i][j]<<" ";
        }
            cout<<endl;
    }
    cout<<"-----------------"<<endl;
    if (_access(game_dir.c_str(), 0) == -1)	//如果文件夹不存在
        _mkdir(game_dir.c_str());				//则创建

    string file_name=game_dir+to_string(i)+".txt";
    ofstream wfile;
    wfile.open(file_name,ios::out );
    write_file(wfile,temp);


    }

}




//创建终局 
void SudoKu::create_sudoku_endgame(int num_game,vector<vector<int>>& matrix){

    int choice[9][2] = {{0,1},{0,2},{1,2},{3,4},{3,5},{4,5},{6,7},{6,8},{7,8}};
    srand(time(NULL));
    for(int num=0;num<num_game;num++){
        //调整矩阵
        for(int i=0; i<CHANGE_MAX_NUM; i++){
            int index = rand() % 9;
            matrix[choice[index][0]].swap(matrix[choice[index][1]]);
            swap_col(choice[index][0], choice[index][1], matrix);
        }
        //无需挖空
        //输出打印
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<matrix[i][j]<<" ";
            }
                cout<<endl;
        }
        cout<<"-----------------"<<endl;



        if (_access(endgame_dir.c_str(), 0) == -1)	//如果文件夹不存在
            _mkdir(endgame_dir.c_str());				//则创建

        string file_name=endgame_dir+to_string(num)+".txt";
        ofstream wfile;
        wfile.open(file_name,ios::out );
        write_file(wfile,matrix);
        // write_file(endgame_dir+to_string(num)+".txt",matrix);

    }
}


void SudoKu::read_file(ifstream& file,vector<vector<int>> &matrix){

    string line;
    int row=0;
    while (getline(file,line))
    {
        // cout<<line<<endl;
       if(line.empty()){
        break;
       }


        for(int j=0;j<9;j++){
            int num =(char)line[2*j]-'0';
            matrix[row][j]=num;
        }
        row++;
        

    }
    file.close();


}


void SudoKu::write_file(ofstream& file,vector<vector<int>> matrix){

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            file << matrix[i][j] << " ";
        }
        file << std::endl;
    }

    file.close();

}