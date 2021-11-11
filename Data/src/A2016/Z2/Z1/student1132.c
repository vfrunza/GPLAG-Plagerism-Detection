#include <stdio.h>
#include <stdlib.h>
int main() 
{
int N,s = 0,diff,sol = 0,TEN = 1;
printf("Unesite broj: ");
scanf("%d",&N);
N = abs(N);
while(N/10)
{
	diff = abs(N%10 - N/10%10);
	s = s + diff*TEN;
	N/=10;
	TEN *= 10;
}
printf("%d",s);
	return 0;
}
