#include <stdio.h>
#include <math.h>
int main() {
	
	int n=0, umanjenik=0, umanjilac=0, broj=0, k=0, pomocna=0;
	int l=1, novi_broj=0;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if (broj <=0){
		broj=fabs(broj);
	}
	pomocna=broj;
	while(pomocna!=0){
	pomocna=pomocna/10;
	k++;
	}
	
	

	while(k !=1) {
	umanjenik=broj%10;
	broj=broj/10;
	umanjilac=broj%10;
	n=fabs(umanjenik-umanjilac);
	novi_broj=novi_broj+n*l;
	k--;
	l=l*10;} 
	printf("%d", novi_broj);
	return 0;
}
