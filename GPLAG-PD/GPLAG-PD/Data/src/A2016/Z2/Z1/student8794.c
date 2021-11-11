#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, nb=0;
	int cifra1, cifra2, razlika, st=1;
	
	printf ("Unesite broj: ");
	scanf ("%d", &n);
	
	if (n<0)
	n=abs(n);
	
	if (n<10)
	{printf("%d", nb); return 0;}
	
	else {
		
		do {
			cifra1=n%10;
			n=n/10;
			cifra2=n%10;
			razlika=cifra2-cifra1;
			
			nb=nb+abs(razlika)*st;
			st*=10;
			
			
		}
		while (n>=10);
		
		printf ("%d", nb);
	}
	return 0;
}
