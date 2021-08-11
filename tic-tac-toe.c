//计算tic-tac-toe的胜负
#include <stdio.h>
#define SIZE 3

int main() {
    int board[SIZE][SIZE];
    int i, j; //i行，j列
    int rowNum0fO; //计行O个数
    int columnNum0fO; //计列O个数
    int rowNum0fX;
    int columnNum0fX;
    int tiltO1 = 0;
    int tiltX1 = 0;
    int tiltO2 = 0;
    int tiltX2 = 0;
    int result = -1; //result=-1无胜负 0 O胜 1 X胜

    //读入矩阵
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    //判断行列
    for (i = 0; i < SIZE && result == -1; i++) {
        rowNum0fX = 0; rowNum0fO = 0; columnNum0fX = 0; columnNum0fO = 0;
        tiltO1 = 0;tiltX1 = 0;tiltO2 = 0;tiltX2 = 0;
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                rowNum0fO++;
            }else if (board[i][j] == 1) {
                rowNum0fX++;
            }
            if (board[j][i] == 0) {
                columnNum0fO++;
            }else if (board[j][i] == 1) {
                columnNum0fX++;
            }
            if (board[j][j] == 0) {
                tiltO1++;
            }else if (board[j][j] == 1) {
                tiltX1++;
            }
            if (board[SIZE-j-1][j] == 0) {
                tiltO2++;
            }else if (board[SIZE-j-1][j] == 1) {
                tiltX2++;
            }

            if (rowNum0fO == SIZE || columnNum0fO == SIZE || tiltO1 == SIZE || tiltO2 == SIZE) {
                result = 0;
            }
            if (rowNum0fX == SIZE || columnNum0fX == SIZE || tiltX1== SIZE || tiltX2 == SIZE) {
                result = 1;
            }
        }
    }

    if (result == 0) {
        printf("O方胜\n");
    }
    else if (result == 1) {
        printf("X方胜\n");
    }
    else
    {
        printf("平局\n");
    }

    return 0;
}
