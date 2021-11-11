#include <stdio.h>
#include <stdlib.h>

int main() {
 int brojac=0,n,i,x=1,broj1,rezultat=0;
 printf("Unesite broj: ");
 scanf("%d", &n);
 broj1=n;
 while(broj1!=0)
{
	broj1=broj1/10;
	brojac++;
	
}
for(i=0; i<brojac-1; i++){
	rezultat=rezultat+x*(abs((n%10)-((n/10)%10)));
	x=10*x;
	n=n/10;
}
printf("%d", rezultat);

	return 0;
}
