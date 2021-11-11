#include <stdio.h>

int main() {
	int broj, suma=0, umjesto_pow=1;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if(broj<0) broj=broj*(-1);
	
	while(1==1){
		int cifra1,cifra2;
		if(broj <10) break;
		
		cifra1=broj%10;
		broj=broj/10;
		cifra2=broj%10;
		if(cifra2>cifra1)
			suma=suma+(cifra2-cifra1)*umjesto_pow;
		else
			suma=suma+(cifra1-cifra2)*umjesto_pow;
		umjesto_pow*=10;
	}
	printf("%d",suma);
	return 0;
}
