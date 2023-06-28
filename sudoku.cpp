// Copyright (c) 2023 dingyanfeng/jianghaonan
// All rights reserved.
#include"sudoku.h"  // NOLINT


SudoKu::SudoKu(vector<vector<int>>& matrix) {
    this->active = init(matrix, 0);
}


bool SudoKu::is_valid(int row, int col, int num, vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix[0].size(); i++)
        if (num == matrix[row][i])
            return false;
    for (auto & i : matrix)    if (num == i[col]) return false;
    for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++) {
        for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++) {
            if (num == matrix[i][j]) return false;
        }
    }
    return true;
}


bool SudoKu::init(vector<vector<int>>& matrix, int start){ /* NOLINT */
    if (start == 81) {
        return true;
    } else {
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
        } else {
            current_is_valid = init(matrix, start + 1);
        }
        return current_is_valid;
    }
}


bool get_RC(int& row, int& col, vector<vector<int>>& matrix) {  /* NOLINT */
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (matrix[row][col] == 0)
                return true;
    return false;
}


// This function can get the number of all solutions,
// but return when there are 2
bool not_unique = false;
int SudoKu::solve_with_count(vector<vector<int>>& matrix,int  &ans) {   /* NOLINT */
    int i, j;
    if (get_RC(i, j, matrix)) {
        for (int num = 1; num <= 9; num++) {
            if (not_unique) {
                return ans;
            }
            if (is_valid(i, j, num, matrix)) {
                matrix[i][j] = num;
                ans = solve_with_count(matrix, ans);
                matrix[i][j] = 0;
            }
        }
    } else {
        ans++;
        if (ans == 2) not_unique = true;
    }

    return ans;
}


void SudoKu::swap_col(int m, int n, vector<vector<int>>& matrix) {
    vector<int> temp(matrix.size(), 0);
    for (int i = 0; i < matrix.size(); i++) {
        temp[i] = matrix[i][m];
        matrix[i][m] = matrix[i][n];
        matrix[i][n] = temp[i];
    }
}


void SudoKu::set_blank(int nums, vector<vector<int>>& matrix) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> row_dis(0, 8);
    std::uniform_int_distribution<> col_dis(0, 8);
    while (nums) {
        int row = row_dis(gen);
        int col = col_dis(gen);
        if (matrix[row][col] != 0) {
            matrix[row][col] = 0;
            nums--;
        }
    }
}


void SudoKu::create_random_sudoku(int num_game, bool if_unique) {
    // the num of the blank
    int num_blank = 20;

    extern bool redundant_m;
    extern int game_level;

    extern bool redundant_r;
    extern int low_range;
    extern int high_range;

    // Modify the number of blank according to the difficulty of the game
    if (redundant_m) {
        switch (game_level) {
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

    // new matrix
    vector<vector<int>> matrix(9, vector<int>(9, 0));
    this->active = this->init(matrix, 0);

    int choice[9][2] = { {0, 1}, {0, 2}, {1, 2},
                         {3, 4}, {3, 5}, {4, 5},
                         {6, 7}, {6, 8}, {7, 8} };
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> index_dis1(0, 8);
    std::uniform_int_distribution<> index_dis2(0, 8);
    std::uniform_int_distribution<> num_blank_dis(0,
                                    (high_range-low_range+1)+low_range-1);

    string file_name = game_dir;
    ofstream wfile;
    wfile.open(file_name, std::ios::out);

    for (int i = 0; i < num_game; i++) {
        for (int j = 0; j < CHANGE_MAX_NUM; j++) {
            int index = index_dis1(gen);
            matrix[choice[index][0]].swap(matrix[choice[index][1]]);
            swap_col(choice[index][0], choice[index][1], matrix);
        }

        // Set the number of blank according to the given range
        if (redundant_r) {
            num_blank = num_blank_dis(gen);
        }

        if (if_unique) {
            // deep copy initial
            vector<vector<int>> temp(matrix);
            // get some blank
            set_blank(num_blank, temp);
            int a = 0;

            int ans = solve_with_count(temp, a);
            not_unique = false;

            if (ans < 2) {
                write_file(wfile, temp);
            }

            int ii = 0;
            while (ans >= 2) {
                for (int j = 0; j < CHANGE_MAX_NUM; j++) {
                    int index = index_dis2(gen);
                    matrix[choice[index][0]].swap(matrix[choice[index][1]]);
                    swap_col(choice[index][0], choice[index][1], matrix);
                }

                vector<vector<int>> temp2(matrix);
                set_blank(num_blank, temp2);

                a = 0;
                ii++;
                ans = solve_with_count(temp2, a);
                not_unique = false;

                if (ans < 2) {
                    write_file(wfile, temp2);
                }
            }
        } else {
            // deep copy initial
            vector<vector<int>> temp(matrix);
            // get some blank
            set_blank(num_blank, temp);

            write_file(wfile, temp);
        }
    }
    wfile.close();
}


// create endgame
void SudoKu::create_sudoku_endgame(int num_game,
                                   vector<vector<int>>& matrix) const {
    int choice[9][2] = {
              {0, 1}, {0, 2}, {1, 2},
              {3, 4}, {3, 5}, {4, 5},
              {6, 7}, {6, 8}, {7, 8} };
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> index_dis(0, 8);

    string file_name = endgame_dir;
    ofstream wfile;
    wfile.open(file_name, std::ios::out);

    for (int num = 0; num < num_game; num++) {
        // adjustment matrix
        for (int i = 0; i < CHANGE_MAX_NUM; i++) {
            int index = index_dis(gen);
            matrix[choice[index][0]].swap(matrix[choice[index][1]]);
            swap_col(choice[index][0], choice[index][1], matrix);
        }
        // needn't blank
        // print
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "-----------------" << std::endl;
        write_file(wfile, matrix);
    }
    wfile.close();
}


void SudoKu::read_file(ifstream& file, vector<vector<int>>& matrix) {
    string line;
    int row = 0;

    ofstream wfile;
    wfile.open("result.txt", std::ios::out);

    while (getline(file, line)) {
        if (line.empty()) {
            break;
        }

        if (row == 9) {
            row = 0;

            std::cout << "Solution result:" << std::endl;
            init(matrix, 0);

            write_file(wfile, matrix);

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    std::cout << matrix[i][j] << " ";
                    matrix[i][j] = 0;
                }
                std::cout << std::endl;
            }
            std::cout << "-----------------" << std::endl;
        } else {
            for (int j = 0; j < 9; j++) {
                if(line[2 * static_cast<int64_t>(j)] == '$') {
                    matrix[row][j] = 0;
                } else {
                    int num = static_cast<int>(
                            line[2 * static_cast<int64_t>(j)] - '0');
                    matrix[row][j] = num;
                }
            }
            row++;
        }
    }
    std::cout << "Output the result to result.txt" << std::endl;
    wfile.close();
    file.close();
}


void SudoKu::write_file(ofstream& file, vector<vector<int>> matrix) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(matrix[i][j] == 0) {
                file << '$' << " ";
            } else {
                file << matrix[i][j] << " ";
            }
        }
        file << std::endl;
    }
    file << "-----------------" << std::endl;
}
