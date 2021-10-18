#include <stdio.h>

int main() {
	int n,i=0,suma=0,k=1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0){n=-n;}
	if(n<10 && n>=0){printf("0"); return 0;}
	while(n>10){
		suma=n%10;
		n/=10;
		suma-=n%10;
		if(suma<0){suma=-suma;}
		i+=suma*k;
		k*=10;
		
	}
	printf("%d", i);
	
	return 0;
}
