#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int broj, i, pom1, pom2, suma;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if(broj<0) broj*=(-1);
	pom1=broj;
	pom2=1;
	suma=0;
	do{
		pom1=pom1/10;
		pom2*=10;
	}while(pom1>0);
	pom2=pom2/10;
	for(i=1;i<pom2;i*=10){
		suma+=(abs(((broj%(10*i))/i)-(((broj%(100*i))/(i*10)))))*i; //pisem pom2*(10*i) prije
	}
	printf("%d", suma);
	return 0;
}
