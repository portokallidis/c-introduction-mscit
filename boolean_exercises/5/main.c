#include <stdio.h>
#include <string.h>
// #include <math.h>


int main(int argc, char *argv[]) {
    
    char cur[5];
    char fn[200];
    char entity[20];
    char architecture[20];
    int totalInputs;
    int i;
    //improve it with malloc later
    char inputs[20]; 
    char output;
    char result[500]="";

    // helper to create 1 char string (f*** C)
    char c[2];
    char out[2];
    
    printf("\nEnter number of inputs:  ");
    scanf("%d",&totalInputs);
    
    for (i=0; i<totalInputs; i++){
        printf("Enter name of input %d:  ",i+1);
        scanf(" %c",&inputs[i]);
    }
    
    printf("\nEnter name of output:  ");
    scanf(" %c",&output);
    
    // create a string for it!!
    out[0] = output;
    out[1] = '\0';
    
    // clean input to be able to scanf spaced words
    int a;do{a = getchar();}while(a != EOF && a != '\n');
    printf("\nEnter function: ");
    scanf("%[^\n]s",&fn);
        
    printf("\nEnter entity name: ");
    scanf("%s",&entity);
    
    printf("\nEnter architecture name: ");
    scanf("%s",&architecture);
    
    // Construct the result
    
    strcat(result,"ENTITY ");
    strcat(result,entity);
    strcat(result," IS PORT(");
    for (i=0; i<totalInputs; i++) {
        if(i!=0) {
            strcat(result,", ");
        }
        c[0] = inputs[i];
        c[1] = '\0';
        strcat(result,c);
    }
    strcat(result,": IN BIT; ");
    strcat(result,out);
    strcat(result,": OUT BIT); END ");
    strcat(result,entity);
    strcat(result,";\nARCHITECTURE ");
    strcat(result,architecture);
    strcat(result," OF ");
    strcat(result,entity);
    strcat(result," IS\nBEGIN\n");
    strcat(result," ");
    strcat(result,out);
    strcat(result," <= ");
    strcat(result,fn);
    strcat(result,";\nEND ");
    strcat(result,architecture);
    strcat(result,";");
    
    // save the result in a file
    FILE *fp = fopen("circ1.vhd", "w");
    if (fp != NULL)
    {
        fputs(result, fp);
        fclose(fp);
    }
    
    
	return 0;
}
