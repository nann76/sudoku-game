# include "gtest/gtest.h"
# include "sudoku.h"
//#define ADD_COMMON

#ifdef ADD_COMMON
# include "common.h"
#endif

#ifndef ADD_COMMON
extern bool if_gen_sudoku_endgame;
extern int num_sudoku_endgame;

extern bool redundant_s;
extern char sudoku_slove_path[256];

extern bool redundant_n;
extern int num_sudoku_game;

extern bool redundant_m;
extern int game_level;

extern bool redundant_r;
extern int low_range;
extern int high_range;

extern bool redundant_u;
extern bool if_unique;
#endif

TEST(swap_col, null) {  /* NOLINT */
    vector<vector<int>> matrix1 = {
            {0, 2, 3, 4, 5, 6, 7, 9, 8},
            {4, 5, 6, 7, 8, 9, 1, 3, 2},
            {7, 8, 9, 1, 2, 3, 4, 6, 5},
            {2, 1, 4, 3, 6, 5, 8, 7, 9},
            {3, 6, 5, 8, 9, 7, 2, 4, 1},
            {8, 9, 7, 2, 1, 4, 3, 5, 6},
            {5, 3, 1, 6, 4, 2, 9, 8, 7},
            {9, 7, 8, 5, 3, 1, 6, 2, 4},
            {6, 4, 2, 9, 7, 8, 5, 1, 3}
    };
    vector<vector<int>> matrix1_result = {
            {0, 3, 2, 4, 5, 6, 7, 9, 8},
            {4, 6, 5, 7, 8, 9, 1, 3, 2},
            {7, 9, 8, 1, 2, 3, 4, 6, 5},
            {2, 4, 1, 3, 6, 5, 8, 7, 9},
            {3, 5, 6, 8, 9, 7, 2, 4, 1},
            {8, 7, 9, 2, 1, 4, 3, 5, 6},
            {5, 1, 3, 6, 4, 2, 9, 8, 7},
            {9, 8, 7, 5, 3, 1, 6, 2, 4},
            {6, 2, 4, 9, 7, 8, 5, 1, 3}
    };
    SudoKu::swap_col(1, 2, matrix1);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            EXPECT_EQ(matrix1[i][j], matrix1_result[i][j]);
        }
    }
}


TEST(solve_with_count, null) {  /* NOLINT */

    // ���Ժ���SudoKu::solve_with_count
    SudoKu test2;
    vector<vector<int>> matrix2 = {
            {0, 0, 8, 0, 3, 0, 0, 0, 4},
            {3, 1, 0, 4, 6, 0, 9, 0, 0},
            {0, 0, 5, 0, 0, 8, 3, 2, 1},
            {4, 0, 0, 3, 5, 6, 0, 9, 0},
            {7, 8, 9, 2, 0, 1, 0, 6, 0},
            {0, 0, 6, 8, 7, 9, 0, 0, 2},
            {0, 9, 7, 0, 1, 3, 0, 4, 0},
            {0, 6, 4, 9, 8, 7, 1, 3, 5},
            {1, 5, 3, 6, 2, 4, 8, 7, 9}
    };

    int num2 = 0;
    EXPECT_EQ(1, test2.solve_with_count(matrix2, num2));
    EXPECT_EQ(1, num2);
}


TEST(init, null) {   /* NOLINT */
    // ����SudoKu::init
    SudoKu test;
    vector<vector<int>> matrix(9, vector<int>(9, 0));
    vector<vector<int>> matrix_result = {
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {4, 5, 6, 7, 8, 9, 1, 2, 3},
            {7, 8, 9, 1, 2, 3, 4, 5, 6},
            {2, 1, 4, 3, 6, 5, 8, 9, 7},
            {3, 6, 5, 8, 9, 7, 2, 1, 4},
            {8, 9, 7, 2, 1, 4, 3, 6, 5},
            {5, 3, 1, 6, 4, 2, 9, 7, 8},
            {6, 4, 2, 9, 7, 8, 5, 3, 1},
            {9, 7, 8, 5, 3, 1, 6, 4, 2}
    };
    bool res = test.init(matrix, 0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            EXPECT_EQ(matrix[i][j], matrix_result[i][j]);
        }
    }
    EXPECT_EQ(true, res);
}


TEST(is_valid,null){     /* NOLINT */
    // ����SudoKu::is_valid
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5, 6, 7, 0, 9},
        {4, 5, 6, 7, 8, 9, 0, 2, 3},
        {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {2, 0, 4, 3, 6, 5, 8, 9, 7},
        {3, 6, 5, 8, 9, 7, 2, 1, 4},
        {8, 9, 7, 2, 1, 4, 3, 6, 5},
        {5, 3, 1, 6, 4, 2, 9, 7, 8},
        {6, 4, 2, 9, 7, 8, 5, 3, 1},
        {9, 7, 8, 5, 3, 1, 6, 4, 2}
    };
    bool res1 = SudoKu::is_valid(2, 3, 0, matrix);
    bool res2 = SudoKu::is_valid(0, 8, 8, matrix);
    bool res3 = SudoKu::is_valid(3, 4, 7, matrix);
    bool res4 = SudoKu::is_valid(1, 1, 1, matrix);
    EXPECT_EQ(true, res1);
    EXPECT_EQ(false, res2);
    EXPECT_EQ(false, res3);
    EXPECT_EQ(false, res4);
}

TEST(set_blank,null){    /* NOLINT */
    // ����Sudoku::set_blank
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {4, 5, 6, 7, 8, 9, 1, 2, 3},
        {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {2, 1, 4, 3, 6, 5, 8, 9, 7},
        {3, 6, 5, 8, 9, 7, 2, 1, 4},
        {8, 9, 7, 2, 1, 4, 3, 6, 5},
        {5, 3, 1, 6, 4, 2, 9, 7, 8},
        {6, 4, 2, 9, 7, 8, 5, 3, 1},
        {9, 7, 8, 5, 3, 1, 6, 4, 2}
    };
    SudoKu::set_blank(21, matrix);
    int blank_num = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                blank_num++;
            }
        }
    }
    EXPECT_EQ(21, blank_num);
}

TEST(create_random_sudoku,unique){   /* NOLINT */
    // ����SudoKu::create_random_sudoku
    // �����Ѷȣ�Ψһ��
    SudoKu test;
    redundant_m = true;
    game_level = 2;
    redundant_r = false;
    low_range = 25;
    high_range = 50;
    test.create_random_sudoku(1, true);
    vector<vector<int>> matrix(9, vector<int>(9, 0));

    ifstream in;
    in.open("games.txt", ios::in);
    string line;
    int row = 0;

    while (getline(in, line))
    {
        if (line.empty()) {
            break;
        }
        if (row == 9) {
            row = 0;
        }
        else {
            for (int j = 0; j < 9; j++) {
                int num = (char)line[2 * (long long)j] - '0';
                matrix[row][j] = num;
            }
            row++;
        }
    }
    in.close();
    int count = 0;
    for (auto & i : matrix) {
        for (int j : i) {
            if (j == 0) {
                count++;
            }
        }
    }
    cout << count << endl;
        EXPECT_EQ((count == 30), true);
    int temp = 0;
        EXPECT_EQ(test.solve_with_count(matrix, temp), 1);


    // ���Է�Χ��Ψһ��
    redundant_m = false;
    redundant_r = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            matrix[i][j] = 0;
        }
    }

    in.open("games.txt", ios::in);
    row = 0;

    while (getline(in, line))
    {
        if (line.empty()) {
            break;
        }
        if (row == 9) {
            row = 0;
        }
        else {
            for (int j = 0; j < 9; j++) {
                int num = (char)line[2 * (long long)j] - '0';
                matrix[row][j] = num;
            }
            row++;
        }
    }
    in.close();
    count = 0;
    for (auto & i : matrix) {
        for (int j : i) {
            if (j == 0) {
                count++;
            }
        }
    }
    cout << count << endl;
    EXPECT_EQ((count>=25 && count <=50), true);
    temp = 0;
    EXPECT_EQ(test.solve_with_count(matrix, temp), 1);
}

TEST(create_random_sudoku,not_unique){   /* NOLINT */
    SudoKu test;
    redundant_m = true;
    game_level = 2;
    redundant_r = false;
    low_range = 25;
    high_range = 50;
    test.create_random_sudoku(1, false);
    vector<vector<int>> matrix(9, vector<int>(9, 0));

    ifstream in;
    in.open("games.txt", ios::in);
    string line;
    int row = 0;

    while (getline(in, line))
    {
        if (line.empty()) {
            break;
        }
        if (row == 9) {
            row = 0;
        }
        else {
            for (int j = 0; j < 9; j++) {
                int num = (char)line[2 * (long long)j] - '0';
                matrix[row][j] = num;
            }
            row++;
        }
    }
    in.close();
    int count = 0;
    for (auto & i : matrix) {
        for (int j : i) {
            if (j == 0) {
                count++;
            }
        }
    }
    cout << count << endl;
    EXPECT_EQ((count == 30), true);
}


TEST(SudoKu ,null){  /* NOLINT */
    //���캯��
    vector<vector<int>> matrix(9, vector<int>(9, 0));
    SudoKu test(matrix);
}


TEST(create_sudoku_endgame ,null){   /* NOLINT */
    //�����վ�
    vector<vector<int>> matrix(9, vector<int>(9, 0));
    // ��ʼ������
    SudoKu endgame(matrix);

    endgame.create_sudoku_endgame(3, matrix);
}

TEST(read_file ,null){   /* NOLINT */
    // ���ļ�
    vector<vector<int>> matrix(9, vector<int>(9, 0));
    SudoKu slove_game;

    ifstream in;
    in.open("games.txt", ios::in);
    cout << sudoku_slove_path << endl;
    slove_game.read_file(in, matrix);
}


