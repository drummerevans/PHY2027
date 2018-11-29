#include <stdio.h>

int main()
{
   float sum=0, num=0;
   int nval;
   float ave;
   float array[nval];

   printf("How many numbers do you want to average?\n");
   scanf("%d",&nval);

   printf("Please enter in the integer numbers: \n");
   
   for(int i = 0; i < nval; i++) {
       scanf("%f", &array[i]);
   }

   for (int i=0 ; i < nval ; i++){
	    sum += array[i];
   }

   if (nval > 0){
     ave = sum/nval;
     printf("Average is %f\n",ave);
   }

   return 0;
}
