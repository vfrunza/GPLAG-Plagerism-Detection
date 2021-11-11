#include <stdio.h>

int main() {
	int i=0, c=0, b=0, s=0, v=0, p=0;
	char x;
	float n;
	printf ("Unesite vozila: ");
	do
	
	{
	
	x=getchar ();
	
	 if (x=='k' || x=='K') 
		break;
	
	if (x=='c' || x=='C') {
		i++;
		c++; 
		
	}
	
	else if (x=='b' || x=='B') {
		i++;
		b++; 
	}
	
	else if (x=='s' || x=='S') {
		i++;
		s++;
	}
	
	else if (x=='v' || x=='V') {
		i++;
		v++;
	}
	
	else if (x=='p' || x=='P') {
		i++;
		p++;
	}
	
	
	
	else if (x!='c' && x!='C' && x!='b' && x!='B' && x!='s' && x!='S' && x!='v' && x!='V' && x!='p' && x!='P' && 
	         x!='k' && x!='K' ) {
	         printf ("Neispravan unos\n");
	         }
	
	} while (x!='k' && x!='K') ;
	
	printf ("Ukupno evidentirano %d vozila.\n", i);
	
	if (i!=0) {
	
	if (c>=b && c>=s && c>=v && c>=p ) {
		n = (float) c*100/i;
		printf ("Najpopularnija boja je crna (%.2f%%).", n);
	}
	
	else if (b>=c && b>=s && b>=v && b>=p ) {
		n = (float) b*100/i;
		printf ("Najpopularnija boja je bijela (%.2f%%).", n);
	}
	
	else if (s>=b && s>=c && s>=v && s>=p ) {
		n = (float) s*100/i;
		printf ("Najpopularnija boja je siva (%.2f%%).", n);
	}
	
	else if (v>=b && v>=c && v>=s && v>=p ) {
		n = (float) v*100/i;
		printf ("Najpopularnija boja je crvena (%.2f%%).", n);
	}
	
	else if (p>=b && p>=c && p>=s && p>=v ) {
		n = (float) p*100/i;
		printf ("Najpopularnija boja je plava (%.2f%%).", n);
	}
	
	}
	
	else if (i==0)
	printf ("Najpopularnija boja je crna (0.00%).");
	
	return 0;
}
