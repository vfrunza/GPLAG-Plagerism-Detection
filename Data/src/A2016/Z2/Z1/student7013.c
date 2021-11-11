#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main ()
{
	int n, cifra1, cifra2, brojac = 15;
	char niz[20] = "000000000000000000";
	char c;
	printf ("Unesite broj: ");
	scanf ("%d", &n);
	n = fabs(n);
	if (n>-10 && n<10) {
		printf ("0");
		return 0;
	}
	while (n>0) {
		cifra1=n%10;
		n=n/10;
		cifra2=n%10;
 		
 		niz[brojac--] = (int)fabs(cifra1-cifra2) + '0';
	}
	niz[brojac+1] = '0';
	niz[16] = '\0';
	printf("%d", atoi(niz));
	return 0;
}