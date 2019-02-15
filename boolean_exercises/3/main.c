#include <stdio.h>
#include <string.h>
// #include <math.h>


int main(int argc, char *argv[]) {
    
    char truthTable[17];
    char cur[5];
    char gate[5];
    int inputs;
    int totalBits;
    int truthTableLen;
    
    // power function
    int pow(int b, int e) {
        int result=1;
        int power = e;
        while (e != 0) { result *= b; --e; }
        return result;
    }
    // dec to binary
    void toBin(int value, int bitsCount, char* output) {
        int i;
        output[bitsCount] = '\0';
        for (i = bitsCount - 1; i >= 0; --i, value >>= 1) {
            output[i] = (value & 1) + '0';
        }
    }
    
    // boolean functions
    int and(int a, int b) { return (a&b);}
    int or(int a, int b) { return (a|b);}
    int xor(int a, int b) { return (a^b);}
    
    // calculate bit
    char calculateResult(char gate[],int bitsCount, char current[]) {
        int result=current[0]-'0';
        for(int i=1; i<bitsCount; i++){
            if(strcmp(gate, "AND")==0) result = and(result,(int)(current[i]-'0'));
            else if(strcmp(gate, "OR")==0) result = or(result,(int)(current[i]-'0'));
            else if(strcmp(gate, "XOR")==0) result = xor(result,(int)(current[i]-'0'));
            else if(strcmp(gate, "NAND")==0) result = !and(result,(int)(current[i]-'0'));
            else if(strcmp(gate, "NOR")==0) result = !or(result,(int)(current[i]-'0'));
            else if(strcmp(gate, "NXOR")==0) result = !xor(result,(int)(current[i]-'0'));
        }
        return result+'0';
    }
    
    printf("\nEnter gate name: ");
    scanf("%s",&gate);
    printf("\nEnter number of inputs: ");
    scanf("%d",&inputs);
    printf("\nTruth Table is:: ");
    
    // printf("\n%d\n",!(1^0));
    truthTableLen = pow(2,inputs);
    
    for(int i=0;i<truthTableLen;i++){
        
        toBin(i,inputs,cur);
        // e.g. 0,0,0,1
        
        truthTable[i] = calculateResult(gate,inputs,cur);
        printf("%c",truthTable[i]);
        
    }
	return 0;
}
