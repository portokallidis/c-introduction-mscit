#include <stdio.h>
// #include <stdlib.h>
// #include <math.h>


int main(int argc, char *argv[]) {
    
    char truthTable[9];
    char comb[4];
    int i;
    
    // power function
    int pow(int b, int e) {
        int result=1;
        int power = e;
        while (e != 0) { result *= b; --e; }
        return result;
    }
    
    int charArrayToDec(char bin[]){
        int sum = 0;
        int val;
        for (int i=0; i<3; i++) {
            if(bin[i]=='-') return -1;
            val = bin[i]-'0'; // trick to convert char to int
            sum+=val*pow(2,2-i);
        }
        return sum;
    }    
    
    printf("\nEnter Truth Table: ");
    scanf("%s",&truthTable);
    // printf("%s",truthTable);
        
    do {
        printf("\nEnter combination: ");
        scanf("%s",&comb);
        // printf("\n%s",comb);
        i = charArrayToDec(comb);
        // printf("\ni=%d",i);
        if(i!=-1) {
            printf("\nThe response of the function is: %c \n",truthTable[i]);
        } else {
            printf("\nGoodbye!");
        }
        
    } while (i!=-1);
    
    
    
        
	return 0;
}
