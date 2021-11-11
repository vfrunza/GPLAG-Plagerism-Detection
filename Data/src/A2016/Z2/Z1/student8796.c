#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int broj,stepen=0,rezultat=0,s,a,b;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if(broj<0){
	broj=abs(broj);}
	while(broj>=10) {
		a=broj%10;
		broj=broj/10;
		b=broj%10;
		s=abs((a-b))*pow(10,stepen);
		rezultat=rezultat+s;
		stepen=stepen+1;
	}
		if(broj<=9) {
		printf("%d",rezultat);
		return 0;
	}
	printf("%d",rezultat);
	return 0;
}
