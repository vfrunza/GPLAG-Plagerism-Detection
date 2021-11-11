#include <stdio.h>
#include <math.h>

int main() {
	int m, n, k, br1, br2, raz, i, broj, brojac;
	broj=0; brojac=0;
	printf("Unesite broj: ");
	scanf("%d", &m);
	if(m<0) m=fabs(m);
	n=m; k=m;
	while(k!=0){
		k=k/10;
		brojac++;
	}
	for(i=0; i<brojac-1; i++){
		br1=n%10;
		n=n/10;
		br2=n%10;
		raz=fabs(br1-br2);
		broj+=raz*(pow(10,i));
		
	}
	printf("%d", broj);
	return 0;
}
