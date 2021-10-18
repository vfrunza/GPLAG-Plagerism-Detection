#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int n,suma=0,a=0,b=0,c=0,broj=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n>=-9 && n <= 9) printf("0");
	else {
		while(n!=0) {
			n = abs(n);
			a=n%10;
			n/=10;
			if(broj>=1) {
				b=abs(a-c);
				suma=suma+b*pow(10,broj-1);
			}
			c=a;
			broj++;
		}
		printf("%d",suma);
	}
	return 0;
}
