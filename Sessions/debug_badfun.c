#include <stdio.h>
#include <stdlib.h>

#define N 6

void badfun(double a[N]){
   for (int i=0; i < N; ++i){
      a[i] = i;	
      printf("The number is: %f\n", a[i]);
   }
}

int main(){
   double ar[N];

   badfun(ar);

   return 0;
}
