#include <stdio.h>
#include <stdlib.h>

int main() {

int x=0,c=0,c1=0,y=0,z=0,cifre;

printf("Unesite broj: ");
scanf("%d", &x);

cifre=1;

while (x>=10 || x<=-10)

{
	c=x%10;
	c1=x/10;
	c1=c1%10;
	y=c-c1;
	z+=abs(y)*cifre;
	cifre*=10;
	x=x/10;
	
}

printf("%d",z);



	return 0;
}
