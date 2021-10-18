#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, rezultat = 0, cifra1, cifra2, obrnuta = 0, cifre = 0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	n = abs(n);
	if(n/10 == 0) {
	    printf("%d", rezultat);
	    return 0;
	}
	do {
	    cifra1 = n%10;
	    n = n/10;
	    cifra2 = n%10;
	    if(n != 0) {
	        obrnuta = obrnuta*10 + abs(cifra2 - cifra1);
	        cifre++;
	    }
	} while(n != 0);
	do {
	    rezultat = rezultat*10 + obrnuta%10;
	    obrnuta = obrnuta/10;
	    cifre--;
	} while(cifre != 0);
	printf("%d", rezultat);
	return 0;
}
