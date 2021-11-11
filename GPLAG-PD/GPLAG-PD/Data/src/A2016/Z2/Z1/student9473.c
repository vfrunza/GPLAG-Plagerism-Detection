#include <stdio.h>

int main() {
	int n, desna, lijeva, NoviBroj=0,NoviBroj1=0, razlika, vrijednost;
	printf ("Unesite broj: ");
	scanf ("%d", &n);
	if (n<0) { 
		n=-n;
	}
	while (n/10>0) {
	      desna=n%10;
	      n=n/10;
	      lijeva=n%10;
	      razlika=desna-lijeva;
	if (razlika<0) 
		razlika=-razlika;
		NoviBroj=NoviBroj*10+razlika;
	}
	while (NoviBroj>0) {
		vrijednost=NoviBroj%10;
		NoviBroj1=NoviBroj1*10+vrijednost;
		NoviBroj=NoviBroj/10;
	}
	printf ("%d", NoviBroj1);
	
	return 0;
	
	
}
