#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])  {
  int i;
  float pin[7];
  for (i = 0; i < 7; i++)   {
     printf("Type a float number : ");
     scanf("%f", &pin[i]);
  }  
  
  printf("The contents of the array\n");
   for (i = 0; i < 7; i++)  {
      printf("%.2f\t", pin[i]);
    }  
  
  return 0;
}


int main2(int argc, char *argv[]) {
  float wks[7], min, max, mesos;
  int i;
  for(i = 0; i < 7; i++)  {
    printf("Type the temperature for ");
    switch(i)  {
    case 0 : printf("Monday : "); break;
    case 1 : printf("Tuesday : "); break; 
    case 2 : printf("Wednesday : ");break; 
    case 3 : printf( "Thursday : "); break;
    case 4 : printf( "Friday : "); break;
    case 5 : printf( "Saturday : "); break; 
    case 6 : printf( "Sunday : "); break;   
    }
    scanf("%f", &wks[i]);
  }

  min = wks[0];    
  max = wks[0];   
  mesos = wks[0]; 

for(i = 1; i < 7; i++)  {
      mesos = mesos + wks[i];
       
      if(wks[i] < min)   {
         min = wks[i];     
         continue;
      }
      
      if(wks[i] > max) 
      {
         max = wks[i];
      }
  }
  
printf("Min Temp = %f\n", min);
printf("Max Temp = %f\n", max);
printf("Aver Temp = %f\n", mesos/7.0);

  return 0;
}


#define plithos 7

int main3(int argc, char *argv[]){
   int Pinakas[plithos] = {0, 4, 4, 5, 3, 8, 9};   
// int Pinakas[] = {0, 4, 4, 5, 3, 8, 9};  // alternative statement
  int X, thesi = 0, emfanisi = 0; 
  
  printf("Type an integer number : ");
  scanf("%d", &X);
  
  for(thesi = 0; thesi < plithos; thesi++)  {
    if(Pinakas[thesi] == X)    {
       emfanisi++;
    }
  }
  printf("The %d appears %d times. ", X, emfanisi); 

  return 0;
}

int main4(int argc, char *argv[]) {
int i,j, x, t;  
int pin[3][3];

for(i =0; i< 2; i++)  {
    t = 0;
    for(j = 0; j < 2; j++)    {
        scanf("%d", &pin[i][j]);
        t = t + pin[i][j];
    }
    pin[i][j] = t;
  }           

  x = 0;
  for(i = 0; i < 2; i++)  {
    t = 0;
    for(j = 0; j < 2; j++)  {
        t = t + pin[j][i];
        if (i == j)
           x = x + pin[j][i];
    } 
    pin[j][i] = t;
  }           
  pin[2][2] = x;
  

for(i =0; i< 3; i++)  {
    for(j = 0; j < 3; j++)    {
        printf("%d\t", pin[i][j]);
    }
    printf("\n");
  }           
  
  return 0;
}


#define size 7

int main5(int argc, char *argv[]){
   int Pinakas[plithos] = {0, 4, 4, 5, 3, 8, 9};   
   int i, X, thesi = -1; 

  printf("Type an integer number : ");
  scanf("%d", &X);
  
   for(i = 0; i < plithos; i++)  {
     if(Pinakas[i] == X)    {
       thesi = i;
       break;
    }
  }
  
  if(thesi < 0)  {
  	printf("The %d not found.", X);
  }
  else
  {
  	printf("The %d found at %d position.", X, thesi); 
  }
 

  return 0;
}
  


  
int main6(int argc, char *argv[]){
  int i, j, temp, pin[5];
  
  for(i = 0; i < 5; i++){
     printf("Type a number : ");
     scanf("%d", &pin[i]);
  }
  printf("\nBefore Sort\n");
  for(i = 0; i < 5; i++){
    printf("%d\t", pin[i]);	
  }

 for(j = 1; j < 5; j++)
     for(i = 0; i < 4; i++)
       if(pin[i] > pin[i+1]){
           temp = pin[i];
           pin[i] = pin[i+1];
           pin[i+1] = temp;
       }
       
  printf("\nAfter Sort\n"); 
  for(i = 0; i < 5; i++){
    printf("%d\t", pin[i]);	
  }
  
  return 0;
}


int main61(int argc, char *argv[]){
  int i, j, temp, pin[5];
  
  for(i = 0; i < 5; i++){
     printf("Type a number : ");
     scanf("%d", &pin[i]);
  }
  printf("\nBefore Sort\n");
  for(i = 0; i < 5; i++){
    printf("%d\t", pin[i]);	
  }

 for(j = 1; j < 5; j++)
     for(i = 0; i < 5-j; i++)
       if(pin[i] > pin[i+1]){
           temp = pin[i];
           pin[i] = pin[i+1];
           pin[i+1] = temp;
       }
       
  printf("\nAfter Sort\n"); 
  for(i = 0; i < 5; i++){
    printf("%d\t", pin[i]);	
  }
  
  return 0;
}

int main62(int argc, char *argv[]){
  int i, j, temp, pin[5];
  
  for(i = 0; i < 5; i++){
     printf("Type a number : ");
     scanf("%d", &pin[i]);
  }
  printf("\nBefore Sort\n");
  for(i = 0; i < 5; i++){
    printf("%d\t", pin[i]);	
  }

 j = 1; 
 int sorted;
 
 do{
     sorted = 1;
     for(i = 0; i < 5-j; i++) {
	    if(pin[i] > pin[i+1]){
           temp = pin[i];
           pin[i] = pin[i+1];
           pin[i+1] = temp;
           sorted=0;
       }
     }
     j++;
 }while(!sorted);
       
  printf("\nAfter Sort\n"); 
  for(i = 0; i < 5; i++){
    printf("%d\t", pin[i]);	
  }
  
  return 0;
}



int main7(int argc, char *argv[])
{       
int pin[5] = { 1, 5, 7, 12, 25 };
int key = 12;
int found = -1, low = 0, high = 4;    int mid;
  
  while (1)
  {
     mid = (low + high) / 2;
     
     if(low > high) 
        break;

     if(pin[mid] == key)     {
        found = mid;
        break;
     }
     else
     {
        if(pin[mid] > key)
           high = mid-1;
        else
           low = mid+1;        
     }
  }
  
  printf("Found : %d",found);
  return 0;
}
