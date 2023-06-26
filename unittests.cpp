//
// Created by nan on 2023/6/26.
//

# include "gtest/gtest.h"
#include "sudoku.h"
#include "common.h"
/*
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

*/
TEST(swap_col, null) {
    SudoKu test1;
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
    test1.swap_col(1, 2, matrix1);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            EXPECT_EQ(matrix1[i][j], matrix1_result[i][j]);
        }
    }
}


TEST(solve_with_count, null) {

    // ≤‚ ‘∫Ø ˝SudoKu::solve_with_count
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


TEST(init, null) {
    // ≤‚ ‘SudoKu::init
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


TEST(is_valid,null){
        // ≤‚ ‘SudoKu::is_valid
        SudoKu test;
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
        bool res1 = test.is_valid(2, 3, 0, matrix);
        bool res2 = test.is_valid(0, 8, 8, matrix);
        bool res3 = test.is_valid(3, 4, 7, matrix);
        bool res4 = test.is_valid(1, 1, 1, matrix);
        EXPECT_EQ(true, res1);
        EXPECT_EQ(false, res2);
        EXPECT_EQ(false, res3);
        EXPECT_EQ(false, res4);

}

TEST(set_blank,null){
                // ≤‚ ‘Sudoku::set_blank
        SudoKu test;
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
        test.set_blank(21, matrix);
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

TEST(create_random_sudoku,null)
        {
                // ≤‚ ‘SudoKu::create_random_sudoku
                // ≤‚ ‘ƒ—∂»£¨Œ®“ªΩ‚
                SudoKu test;
        redundant_m = true;
        game_level = 1;
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
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    count++;
                }
            }
        }
        cout << count << endl;
            EXPECT_EQ((count == 25), true);
        int temp = 0;
            EXPECT_EQ(test.solve_with_count(matrix, temp), 1);


        // ≤‚ ‘∑∂Œß£¨Œ®“ªΩ‚
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
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    count++;
                }
            }
        }
        cout << count << endl;
            EXPECT_EQ((count>=25 && count <=50), true);
        temp = 0;
            EXPECT_EQ(test.solve_with_count(matrix, temp), 1);
        }

Test