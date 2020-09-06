#include <bits/stdc++.h>
using namespace std;
#define N 9
#define UNFILLED 0
int Map[N][N];

void printMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d", Map[i][j]);
            if(j != N-1) printf(" ");
        }
        printf("\n");
    }
}

bool findUnfilledPosition(int& row, int& col){
    for(row = 0; row < N; row++){
        for(col = 0; col < N; col++){
            if(Map[row][col] == UNFILLED)
                return true;
        }
    }
    return false;
}

bool checkRow(int row, int num){
    for(int j=0; j<N; j++){
        if( Map[row][j] == num ) return false;
    }
    return true;
}

bool checkCol(int col, int num){
    for(int i=0; i<N; i++){
        if( Map[i][col] == num ) return false;
    }
    return true;
}

bool checkSquare(int row, int col, int num){
    int squareRowStart = row / 3 * 3;
    int squareColStart = col / 3 * 3;

    for(int i=squareRowStart; i<squareRowStart+3; i++){
        for(int j=squareColStart; j<squareColStart+3; j++){
            if( Map[i][j] == num ) return false;
        }
    }
    return true;
}

bool isSafe(int row, int col, int num){
    return checkRow(row, num) 
        && checkCol(col, num) 
        && checkSquare(row, col, num);
}

bool solveSudoku(){
    int row, col;
    
    // 取得下一格要填的位置
    if(!findUnfilledPosition(row, col)){
        // Sudoku solved successfully 
        return true;
    }

    for(int num=1; num<=9; num++){

        // 測試num可不可以放入(row, col)
        if(isSafe(row, col, num)){
            
            // num通過測試，賦值
            Map[row][col] = num;

            if(solveSudoku()) return true;
            
            // 失敗，回復成空格
            Map[row][col] = UNFILLED;
        }
    }

    // this triggers backtracking 
	return false; 
}

int main(){
    int Cases;
    cin>>Cases;
    while(Cases--){
        // input Sudoku Map
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> Map[i][j];
            }
        }

        if(solveSudoku() == true)
            printMap();
        else
           printf("NO\n");
    }
    return 0;
}