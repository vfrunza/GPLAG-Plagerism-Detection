#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int ostatak=0;
	int jedna_cifra=0;
	int broj, rez_broj=0, cifra2, rez1,cifra;
	printf("Unesite broj: ");
	scanf("%d", &broj);

	while (broj!=0){
		if(broj<0){
			broj=abs(broj);
		}
		if(broj/10==0){
			printf("%d",jedna_cifra);
			goto a;
		}
		cifra=broj%10;
		broj=broj/10;
		cifra2=broj%10;
		rez1=cifra-cifra2;
		if(rez1<0){
			rez1=abs(rez1);}
			
			rez_broj=rez_broj*10+rez1;
			if(broj/10==0)
			break;
		}
		do{
			ostatak=ostatak*10;
			ostatak=ostatak+rez_broj%10;
			rez_broj=rez_broj/10;
		}while(rez_broj!=0);
		printf("%d",ostatak);
		a:
		return 0;
	}

