#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,zadnjiBroj, prviBroj, broj = 0, tk = 1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	n = abs(n);
	zadnjiBroj = n % 10;
	n = n / 10;
	while(n>0)
	{
		
		prviBroj = n%10;
		n = n/10;
		broj = broj + abs(zadnjiBroj - prviBroj) * tk;
		tk = tk * 10;
		zadnjiBroj = prviBroj;
	}
	printf("%d", broj);
	return 0;
}
