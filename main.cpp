#include<iostream>

//调用自己添加的getopt，以在windows下使用getopt
#include"getopt.h"
#include"assert.h"

using namespace std;


//数独终局
bool if_gen_sudoku_endgame=false;
int num_sudoku_endgame=0;

//


int main(int argc ,char * argv[]){
    
    //参数，只有-u后无参数
    char getopt_arg[] = "c:s:n:m:r:u";
    int opt;

     while ((opt = getopt(argc, argv, getopt_arg)) != -1){
        
        switch (opt)
        {
            case 'c':
                assert(!if_gen_sudoku_endgame,"optarg  -c");
                if_gen_sudoku_endgame =true;
                //取终局的数量
                char temp[10];
                strcpy(temp,optarg);
                num_sudoku_endgame =atoi(temp);


                break;
            case 's':
                printf("s");
                break;
            case 'n':

                break;
            case 'm':
                printf("m");
                break;
            case 'r':

                break;
            case 'u':

                break;
            default:
                break;
        }

     }


}