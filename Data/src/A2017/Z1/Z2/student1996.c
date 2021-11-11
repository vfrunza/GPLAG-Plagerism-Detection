#include <stdio.h>

int main() {
	int p,iznos,k;
	printf("Unesite iznos:");
	scanf("%d", &iznos);
	k=iznos/50;
	printf("%d novcanica od 50 Km/n", k);
	
	p=iznos%50;
	k=p/20;
	printf("%d novcanica od 20 KM/n", k);

	p=p%20;
	k=p/10;
	printf("%d novcanica od 10 KM/n", k);

	p=p%10;
	k=p/5;
	printf("%d novcanica od 5 KM/n", k);

	p=p%5;
	k=p/2;
	printf("%d novcanica od 2 KM/n", k);
	
	p=p%2;
	k=p/1;
	printf("%d novcanica od 1 KM/n", k);
	
	return 0;
}
