#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    int data[1000][3];
    int exitOp = 0;
    int i = 0;
    
    int printfArray(int my_array[2][3]){
        int i,j;
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 3; j++) {
                printf("%d ", my_array[i][j]);
            }
            printf("\n");
        } 
      return 0;
    }

    int printfArrayFloat(double my_array[2][3]){
        int i,j;
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 3; j++) {
                printf("%f ", my_array[i][j]);
            }
            printf("\n");
        } 
      return 0;
    }

    int validSex (int val){
        return (val==1 || val==2);
    } 
    int validAge (int val){
        return (val==1 || val==2 || val==3);
    } 
    int validMark (int val){
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
            scanf("%d",&data[i][0]);
            
            if (!validSex(data[i][0])) {
                printf("\nWrong choice!\n");
            }
        } while (!validSex(data[i][0]));
        
        do {
            printf("\nChoose Age\n");
            printf("1. Less or equal to 30\n");
            printf("2. From 31 to 55\n");
            printf("3. Greater or equal to 56\n");
            printf("Type your option : ");
            scanf("%d",&data[i][1]);
            
            if(!validAge(data[i][1])) {
                printf("\nWrong choice!\n");
            }
        } while (!validAge(data[i][1]));
        
        do {
            printf("\nMark the product\n");
            printf("Type the consumer mark : ");
            scanf("%d",&data[i][2]);
            
            if(!validMark(data[i][2])){
                printf("\nWrong mark! Mark must be (0-10)\n");
            }
        } while (!validMark(data[i][2]));
        
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
        
        
        // prepare for next entry
        i++;
        
    } while (exitOp!=2);
        
        int j;
        int count[2][3];
        double mean[2][3];
        
        int over8[2][3];
        int less4[2][3];
        
        int curSex;
        int currentAge;
        // printf("Records: \n");
        
        // calculate sums and counts
        for( j = 0; j < i; j++ ){
            
            count[data[j][0]-1][data[j][1]-1]++;
            mean[data[j][0]-1][data[j][1]-1] += (double)data[j][2];
            
            // count over than 8
            if(data[j][2]>8) {
                over8[data[j][0]-1][data[j][1]-1]++;
            }
            
            // count less than 4
            if(data[j][2]<4) {
                less4[data[j][0]-1][data[j][1]-1]++;
            }
            
            // printf("%d. Sex: %d, Age: %d, Mark: %d\n", j+1, data[j][0],data[j][1],data[j][2]);
                        
        }
        
        // calculate mean
        for( j = 0; j < i; j++ ){
            mean[data[j][0]-1][data[j][1]-1] /= count[data[j][0]-1][data[j][1]-1];
        }
        
        printf("\n\nCounts (Men,Women) (age groups 1,2,3)\n");
        printfArray(count);
        
        printf("\n\nMean (Men,Women) (age groups 1,2,3)\n");
        printfArrayFloat(mean);
        
        printf("\n\nover8 (Men,Women) (age groups 1,2,3)\n");
        printfArray(over8);
        
        printf("\n\nless4 (Men,Women) (age groups 1,2,3)\n");
        printfArray(less4);
        
        
 
        
        
    
	return 0;
}
