#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    
    int exitOp = 0;
    int i,j = 0;
    int sex,age;
    float mark;
    int count[2][3] = { {0,0,0},{0,0,0} };
    float avg[2][3] = { {0,0,0},{0,0,0} };
    int over8[2][3] = { {0,0,0},{0,0,0} };
    int less4[2][3] = { {0,0,0},{0,0,0} };
    

    // validators
    int validSex (int val){
        return (val==1 || val==2);
    } 
    int validAge (int val){
        return (val==1 || val==2 || val==3);
    } 
    int validMark (float val){
        return (val>=0 && val<=10);
    } 
    int validExit (int val){
        return (val==1 || val==2);
    } 

    
    do {
        
        do {
            printf("\nChoose Sex \n");
            printf("1. Men \n");
            printf("2. Women \n");
            printf("Type your option : ");
            scanf("%d",&sex);
            
            if (!validSex(sex)) {
                printf("\nWrong choice!\n");
            }
        } while (!validSex(sex));
        
        do {
            printf("\nChoose Age\n");
            printf("1. Less or equal to 30\n");
            printf("2. From 31 to 55\n");
            printf("3. Greater or equal to 56\n");
            printf("Type your option : ");
            scanf("%d",&age);
            
            if(!validAge(age)) {
                printf("\nWrong choice!\n");
            }
        } while (!validAge(age));
        
        do {
            printf("\nMark the product\n");
            printf("Type the consumer mark : ");
            scanf("%f",&mark);
            
            if(!validMark(mark)){
                printf("\nWrong mark! Mark must be (0-10)\n");
            }
        } while (!validMark(mark));
        
        do {
            printf("\n\n\n");
            printf("1. New entry\n");
            printf("2. Exit\n");
            printf("Type your choice : ");
            scanf("%d",&exitOp);            
            
            if(!validExit(exitOp)) {
                printf("\nWrong choice!\n");
            }
        } while (!validExit(exitOp));
        
        // do things
        count[sex-1][age-1]++;
        avg[sex-1][age-1]+=mark;
        
        // count over than 8
        if(mark>8) {
            over8[sex-1][age-1]++;
        }
        
        // count less than 4
        if(mark<4) {
            less4[sex-1][age-1]++;
        }
        
        // debug
        // printf("[%d][%d] -> %f",sex,age,mark);
        
        // prepare for next entry
        i++;
        
    } while (exitOp!=2);
        
        
        
        // calculate avg
        for( i = 0; i < 2; i++ ){
            for( j = 0; j < 3; j++ ){
                if(count[i][j]>0) {
                    avg[i][j]/=count[i][j];
                }
            }
        }        
        
        // display average
        printf("\n\nMen by age");
        for( j = 0; j < 3; j++ ){
            printf("\nAverage for %d group is %f",j+1,avg[0][j] );
        }
        printf("\n\nWomen by age");
        for( j = 0; j < 3; j++ ){
            printf("\nAverage for %d group is %f",j+1,avg[1][j] );
        }
        
        // display greater than 8
        printf("\n\nMen with a mark greater than 8");
        for( j = 0; j < 3; j++ ){
            printf("\nfor %d group is %d",j+1,over8[0][j] );
        }
        printf("\n\nWomen with a mark greater than 8");
        for( j = 0; j < 3; j++ ){
            printf("\nfor %d group is %d",j+1,over8[1][j] );
        }
        
        // display less than 4
        printf("\n\nMen with a mark less than 4");
        for( j = 0; j < 3; j++ ){
            printf("\nfor %d group is %d",j+1,less4[0][j] );
        }
        printf("\n\nWomen with a mark less than 4");
        for( j = 0; j < 3; j++ ){
            printf("\nfor %d group is %d",j+1,less4[1][j] );
        }
        
    
	return 0;
}
