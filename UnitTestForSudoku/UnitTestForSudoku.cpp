#include "pch.h"
#include "CppUnitTest.h"
#include "../sudoku-game/common.h"
#include "../sudoku-game/assert.h"
#include "../sudoku-game/getopt.h"
#include "../sudoku-game/sudoku.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForSudoku
{
	TEST_CLASS(UnitTestForSudoku)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{	
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
					Assert::AreEqual(matrix1[i][j], matrix1_result[i][j]);
				}
			}
		}
	};
}
