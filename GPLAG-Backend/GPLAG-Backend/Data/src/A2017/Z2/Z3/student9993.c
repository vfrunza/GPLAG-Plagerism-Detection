#include <stdio.h>

int main() {
	
	int x,i,sum=0;

	printf("Unesite broj: \n");
	scanf("%d",&x);
	
  while (x!=0)
  { x /= 10; 
  x /= 10;
  sum += (x % 10); 
 }
  
  printf("Suma iznosi : %d",sum);
  return 0;}