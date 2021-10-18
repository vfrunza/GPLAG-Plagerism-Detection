#include <stdio.h>
#include<math.h>

int main() {
	int cifra1, broj, novi=0, cifra2, k=1,trenutni=0;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if(broj<0) 
		broj*=-1;
	while((broj/10)>0){
		cifra1=broj%10;
		broj/=10;
		cifra2=broj%10;
		trenutni=(cifra1-cifra2);
		if (trenutni<0)
			trenutni*=-1;
		novi+=k*trenutni;
		k*=10;
		
	}
	printf("%d", novi);
	return 0;
}
