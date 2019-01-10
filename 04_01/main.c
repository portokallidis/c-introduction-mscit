#include <stdio.h>
#include <stdlib.h>

int main1(int argc, char *argv[]) {
  int i;
  for (i = 1; i < 4; i++)
  {
   printf("%d) Hello World\n", i);      
  }
  return 0;
}

int main2(int argc, char *argv[])
{
  int i, A;
  long int sum = 0;
  printf("Type an integer number : ");
  scanf("%d", &A);
  if(A < 0)
 {
      printf("Invalid number");
  }
  else
  {
     for (i = 1; i <= A; i++)
     {
         sum = sum + i;
     }
     printf("sum = %ld\n",sum);
  }

  return  0;
}


int main3(int argc, char *argv[])
{
  int i, A;
  long int sum = 0;

  for (i = 1; i <= 5; i++)
  {
     printf("Type an integer number : ");
     scanf("%d",&A); 
     if((A % 2) == 0)
     {
         sum = sum + A;
     }
  }
  printf("sum = %d\n",sum);	
  return  0;
}


int main4(int argc, char *argv[])
{
  int x = 0, sum = 0;
  
  for(x = 40; x > 35; x++)
  {
     sum = sum + 10;
  }
  
  printf("sum = %d", sum);
  
  	
  return 0;
}


int main5(int argc, char *argv[])
{
  int x = 0, y = 10, sum = 0;
    
  for(x = 25; (x <=30) && (y < 20);  x++)
  {
     sum = sum + 10;
     y = y + 5;
  }
  
  printf("sum = %d", sum);
    	
  return 0;
}


int main6(int argc, char *argv[]) {
  float value, product, total = 0.0;
  int quantity, i;

  for(i = 0; i < 3; i++)  {
    printf("Type quantity : ");   
	scanf("%d", &quantity);
    printf("Type value : ");
	scanf("%f", &value); 
    product = quantity * value;
    printf("Product = %f\n",product);
    total = total + product;
    printf("=====================\n");
  }
  
  printf("Total = %f", total);

  return 0;
}


int main(int argc, char *argv[]) {
	int i  = 1;
	for(;;)
	{
	   printf("%d) first line\n", i );
	   i = i + 1;
	   if(i > 3){
	   	  break;
	   }
	   printf("\tsecond line\n");  	
	}
}
