#include<iostream>
#include<vector>

using namespace std;

class SudoKu
{
private:
    bool init(vector<vector<int>>& matrix, int start);
    bool is_valid(int row, int col, int num, vector<vector<int>>& matrix);
public:
    bool active = false;
    SudoKu(vector<vector<int>>& matrix);
    ~SudoKu(){};
};