#include"sudoku.h"

using namespace std;


SudoKu::SudoKu(vector<vector<int>>& matrix)
{
    this->active = init(matrix, 0);
}


bool SudoKu::is_valid(int row, int col, int num, vector<vector<int>>& matrix)
{
    for (int i = 0; i < matrix[0].size(); i++) if (num == matrix[row][i]) return false;
    for (int i = 0; i < matrix.size(); i++)    if (num == matrix[i][col]) return false;
    for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++) {
        for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++) {
            if (num == matrix[i][j]) return false;
        }
    }
    return true;
}


bool SudoKu::init(vector<vector<int>>& matrix, int start)
{
    if (start == 81)  return true; 
    else {
        int row = start / 9;
        int col = start % 9;
        bool current_is_valid = false;
        if (matrix[row][col] == 0) {
            for (int i = 1; i < 10; i++) {
                if (this->is_valid(row, col, i, matrix)) {
                    matrix[row][col] = i;
                    current_is_valid = init(matrix, start + 1);
                    if (!current_is_valid) matrix[row][col] = 0;
                }
            }
        }
        else {
            current_is_valid = init(matrix, start + 1);
        }
        return current_is_valid;
    }
}

bool get_RC(int& row, int& col, vector<vector<int>>& matrix)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (matrix[row][col] == 0)
                return true;
    return false;
}

//本函数可以获得全部的解的数量，但当有2个时则返回
bool not_unique = false;
int SudoKu::solve_with_count(vector<vector<int>>& matrix,int  &ans) {
   // cout << start << "start" << endl;

    int i, j;
    if (get_RC(i, j, matrix))
    {
        for (int num = 1; num <= 9; num++)
        {
            if (not_unique) {
            
                return ans;
            }

            if (is_valid(i, j, num, matrix))

            {
                //cout << i << "  "<<  j<< "  " << num << "  " << endl;
                matrix[i][j] = num;
                /*
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        cout << matrix[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "-----------------" << endl;
                */
                ans = solve_with_count(matrix,ans);
                matrix[i][j] = 0;
                /*

                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        cout << matrix[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "-----------------" << endl;

                */

            }
        }
    }
    else {
       ans++;

       if(ans==2)
       not_unique = true;
    }
        
    return ans;

    
}



void SudoKu::swap_col(int m, int n, vector<vector<int>>& matrix)
{
    vector<int> temp(matrix.size(), 0);
    for (int i = 0; i < matrix.size(); i++)
    {
        temp[i] = matrix[i][m];
        matrix[i][m] = matrix[i][n];
        matrix[i][n] = temp[i];
    }
}


void SudoKu::set_blank(int nums, vector<vector<int>>& matrix)
{
    srand((unsigned int)time(NULL));
    while (nums)
    {
        int row = rand() % 9;
        int col = rand() % 9;
        if (matrix[row][col] != 0)
        {
            matrix[row][col] = 0;
            nums--;
        }
    }
}




void SudoKu::create_random_sudoku(int num_game,bool if_unique) {


    // 挖空数
    int num_blank = 20;

    extern bool redundant_m;
    extern int game_level;

    extern bool redundant_r;
    extern int low_range;
    extern int high_range;

    // 根据游戏难度修改挖空数
    if (redundant_m) {
        switch (game_level)
        {
        case GAME_LEVEL::NONE:
            num_blank = 20;
            break;
        case GAME_LEVEL::EASY:
            num_blank = 25;
            break;
        case GAME_LEVEL::MEDIUM:
            num_blank = 30;
            break;
        case GAME_LEVEL::HARD:
            num_blank = 60;
            break;
        default:
            num_blank = 20;
            break;
        }
    }

    // 新建矩阵
    vector<vector<int>> matrix(9, vector<int>(9, 0));
    this->active = this->init(matrix, 0);

    int choice[9][2] = { {0,1},{0,2},{1,2},{3,4},{3,5},{4,5},{6,7},{6,8},{7,8} };
    srand((unsigned int)time(NULL));
    /*
    if (_access(game_dir.c_str(), 0) == -1)	// 如果文件夹不存在
    {
        int ret = _mkdir(game_dir.c_str());// 则创建
        if (ret == -1) cout << "mkdir failed!" << endl;
    }
    */

    string file_name = game_dir ;
    ofstream wfile;
    wfile.open(file_name, ios::out);

    for (int i = 0; i < num_game; i++) {

        for (int i = 0; i < CHANGE_MAX_NUM; i++) {
            int index = rand() % 9;
            matrix[choice[index][0]].swap(matrix[choice[index][1]]);
            swap_col(choice[index][0], choice[index][1], matrix);
        }

        
        // 根据给定范围设置挖空数
        if (redundant_r) {
            num_blank = rand() % (high_range - low_range + 1) + low_range;
        }



        if (if_unique) {
            //num_blank = 40;

            // 深拷贝初始
            vector<vector<int>> temp(matrix);
            // 挖空
            set_blank(num_blank, temp);
            int a = 0;
            

            int ans=solve_with_count(temp,a);
            not_unique = false;

            write_file(wfile, temp);

            //cout << ans << "&&&" << endl;
            
            int i = 0;
            while (ans >= 2) {


                for (int i = 0; i < CHANGE_MAX_NUM; i++) {
                    int index = rand() % 9;
                    matrix[choice[index][0]].swap(matrix[choice[index][1]]);
                    swap_col(choice[index][0], choice[index][1], matrix);
                }


                vector<vector<int>> temp2(matrix);
                set_blank(num_blank, temp2);


                a = 0;
                i++;
                ans = solve_with_count(temp2, a);
                not_unique = false;

                if (ans < 2) {
                    /*
                    for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                            cout << temp2[i][j] << " ";
                        }
                        cout << endl;
                    }
                    cout << "-----------------" << endl;
                    */

                    write_file(wfile, temp2);
                }

                //cout << ans << "&&&" << endl;
            }

            cout << i << "次" << endl;

        
        
        }

        else {
            // 深拷贝初始
            vector<vector<int>> temp(matrix);
            // 挖空
            set_blank(num_blank, temp);



            // 输出打印
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    cout << temp[i][j] << " ";
                }
                cout << endl;
            }
            cout << "-----------------" << endl;

            write_file(wfile, temp);
        }
        
    }
    wfile.close();

}


// 创建终局 
void SudoKu::create_sudoku_endgame(int num_game, vector<vector<int>>& matrix) {

    int choice[9][2] = { {0,1},{0,2},{1,2},{3,4},{3,5},{4,5},{6,7},{6,8},{7,8} };
    srand((unsigned int)time(NULL));

    /*
    if (_access(endgame_dir.c_str(), 0) == -1)	// 如果文件夹不存在
    {
        int ret = _mkdir(endgame_dir.c_str());// 则创建
        if (ret == -1) cout << "mkdir failed!" << endl;
    }
    */
    string file_name = endgame_dir;
    ofstream wfile;
    wfile.open(file_name, ios::out);

    for (int num = 0; num < num_game; num++) {
        // 调整矩阵
        for (int i = 0; i < CHANGE_MAX_NUM; i++) {
            int index = rand() % 9;
            matrix[choice[index][0]].swap(matrix[choice[index][1]]);
            swap_col(choice[index][0], choice[index][1], matrix);
        }
        // 无需挖空
        // 输出打印
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-----------------" << endl;




        write_file(wfile, matrix);
    }
    wfile.close();
}


void SudoKu::read_file(ifstream& file, vector<vector<int>>& matrix) {

    string line;
    int row = 0;
   
    ofstream wfile;
    wfile.open("result.txt", ios::out);

    while (getline(file, line))
    {
        

        if (line.empty()) {
            break;
        }

        if (row==9) {
            row = 0;
        
            cout << "求解结果：" << endl;
            bool activate = init(matrix, 0);

            write_file(wfile, matrix);

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    cout << matrix[i][j] << " ";
                    matrix[i][j] = 0;

                }
                cout << endl;
            }
            cout << "-----------------" << endl;

        }
        else {
            for (int j = 0; j < 9; j++) {
                int num = (char)line[2 * (long long)j] - '0';
                matrix[row][j] = num;
            }
            row++;

        }


        
    }
    cout << "结果输出到result.txt" << endl;
    wfile.close();
    file.close();
}


void SudoKu::write_file(ofstream& file, vector<vector<int>> matrix) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            file << matrix[i][j] << " ";
        }
        file << std::endl;
    }

    file << "-----------------" << endl;
    
}