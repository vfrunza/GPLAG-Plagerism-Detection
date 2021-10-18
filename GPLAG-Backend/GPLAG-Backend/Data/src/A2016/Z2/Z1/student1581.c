#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
/*	printf("Zadaća 2, Zadatak 1");*/

int x;
printf("Unesite broj: ");
scanf("%d", &x);



if(x>-10 && x<10) printf("0");

else if(x<=-10){
	int r=1,cifra1, cifra2, broj=0;
	while(x<=-10){
		

		cifra1=x%10;
		cifra2=(x/10)%10;
		broj = broj + (abs(cifra1-cifra2)*r);
		r=r*10;
		x/=10;

	}
	printf("%d\n", broj);
}

else if(x>=10)
{

int l,c1,c2,br=0;
l=1;

while (x>=10)
{

		c1=x%10;
		c2=(x/10)%10;
		br= br + (abs(c1-c2)*l);
		l = l * 10;
		x = x / 10;
	
}

printf("%d", br);	
}
	return 0;
}
