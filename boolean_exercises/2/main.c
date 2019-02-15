#include <stdio.h>
#include <string.h>
// #include <math.h>


int main(int argc, char *argv[]) {
    
    char truthTable[9];
    char cur[4];
    char result[500] = "Function is: ";
    
    // dec to binary char[]
    void toBin(int value, int bitsCount, char* output) {
        int i;
        output[bitsCount] = '\0';
        for (i = bitsCount - 1; i >= 0; --i, value >>= 1) {
            output[i] = (value & 1) + '0';
        }
    }
    
    printf("\nEnter Truth Table: ");
    scanf("%s",&truthTable);
        
    for(int i=0;i<7;i++){
        
        // skip iteration if zero
        if(truthTable[i]=='0') continue;
        toBin(i,3,cur);
        if(i>0) strcat(result," OR ");
        strcat(result," ( ");
        
        // printf("\ni=%d",i);
        // printf("\n%s -> %c",cur,truthTable[i]);
        
        for(int j=0;j<3;j++){
            if(j>0) strcat(result," AND ");
            if(cur[j]=='0') strcat(result,"NOT ");
            switch(j){
                case 0:
                    strcat(result,"A"); 
                    break;
                case 1:
                    strcat(result,"B"); 
                    break;
                case 2:
                    strcat(result,"C"); 
                    break;
            }
        }
        strcat(result," ) ");
    }
    printf("\n\n%s",result);
	return 0;
}
