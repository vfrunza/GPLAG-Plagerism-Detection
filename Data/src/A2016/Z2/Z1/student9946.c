#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int cb1,ostatak1,ostatak2,rezultat=0,suma,s=0;

	printf("Unesite broj: ");
	scanf("%d",&cb1);
	cb1=abs(cb1);

	if(cb1<10) {

		printf("0");

	}else{
		do {
			ostatak1=cb1%10;
			cb1/=10;
			if(cb1!=0) {

				ostatak2=cb1%10;
				suma=abs(ostatak2-ostatak1);
				rezultat=(suma*pow(10,s)+rezultat);
				s++;
			}
		} while (cb1!=0);
		printf("%d" ,rezultat);
	}
	return 0;
}
