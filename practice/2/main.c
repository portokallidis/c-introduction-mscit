#include <stdio.h>
#include <string.h>
// #include <math.h>

void printTable(int rows,int cols, int table[rows][cols]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int i, j, ds, rs, cs;
    int pin[3][3] = {{4,5,0},{2,6,0},{0,0,0}};
    ds=0;
    for (i = 0; i < 2; i++) {
        rs = 0;
        cs = 0;
        for (j = 0; j < 2; j++) {
            rs += pin[i][j];
            cs += pin[j][i];
            if(i==j) {
                ds += pin[i][j];
            }
        }
        printf("i,i = %d,%d => rs= %d \n",i,j,rs);
        pin[i][j] = rs;
        pin[j][i] = cs;
    }
    pin[2][2] = ds;
    printTable(3,3,pin);
    return 0;
}