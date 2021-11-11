#include <stdio.h>
#include <stdlib.h>

int main() {
	int broj, cifra1, cifra2, d=0,k=1,c=0, br=0, i;

	printf("Unesite broj: ");
	scanf("%d", &broj );
	
	if(broj<0) broj=abs(broj);
	
	while (broj!=0) {
		br++;
		
		cifra1=broj%10;
		broj=broj/10;
		cifra2=broj%10;

		d=abs(cifra1-cifra2)*k;
		c=c+d;
		k=k*10;
	
		
		
		if(broj<=9) break;
	}
	
	if(br==1) printf("0");
	else
	printf("%d" , c);
		
	
	return 0;
}
