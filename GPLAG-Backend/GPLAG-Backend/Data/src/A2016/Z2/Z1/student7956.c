#include <stdio.h>
#include <math.h>

int main() {
	
	int broj, br_cifara=0, cifra1, cifra2, rezultat, pomocna, i, k;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	pomocna=broj;
	while(pomocna!=0) {
		br_cifara++;
		pomocna=pomocna/10;
	}
	if(br_cifara<=1){printf("0"); return;}
	
	i=1;
	for(k=0;;k++) {
		cifra1=broj%10;
		broj=broj/10;
		cifra2=broj%10;
		rezultat=(cifra2-cifra1);
		if(rezultat<0) rezultat=-rezultat;
		if(i==1) pomocna=rezultat;
		else {
			pomocna=pomocna+(rezultat*pow(10, i-1));
		}
		i++;

		if(broj==0 || i>=br_cifara) break;
		
	}
	printf("%d", pomocna);
	
	
	return 0;
}