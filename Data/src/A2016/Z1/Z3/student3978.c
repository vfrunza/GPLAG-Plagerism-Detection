#include <stdio.h>

int main() {
	int crna=0, bijela=0, siva=0, crvena=0, plava=0,g=0,s,max=0;
	char n;
	double proc, l, maxmax;
	
	s=1;
	printf ("Unesite vozila: ");
	while (s>0){
		
		scanf ("%c",&n);
		if (n=='c' || n=='C') crna=crna+1;
		else if (n=='b' || n=='B') bijela=bijela+1;
		else if (n=='s' || n=='S') siva=siva+1;
		else if (n=='v' || n=='V') crvena=crvena+1;
		else if (n=='p' || n=='P') plava=plava+1;
		else if (n=='k' || n=='K') break;
		else printf ("Neispravan unos\n");
		
	}
	
	g=crna+bijela+siva+plava+crvena;
	printf("Ukupno evidentirano %d vozila.\n",g);
	
	if (crna>=bijela && crna>=siva && crna>=crvena && crna>=plava) {
		max=crna;
	
	}
	else if (bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava) {
		max=bijela;
	}
	else if (siva>=crna && siva>=bijela && siva>=crvena && siva>=plava){ 
		max=siva;
	
	}
	else if (crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava) {
		max=crvena;
		}
	else if (plava>=crna && plava>=bijela && plava>=siva && plava>=crvena) {
		max=plava;

	}

	
	
	if (g==0) l=1;
	else l=g;
	maxmax=max;
	proc=((maxmax/l)*100);
	
	
	printf ("Najpopularnija boja je "); {
		if (max==crna) printf("crna");
		else if (max==bijela) printf("bijela");
		else if (max==siva) printf("siva");
		else if (max==crvena) printf("crvena");
		else if (max==plava) printf("plava");
	}
	printf (" (%.2f%%).", proc);
	return 0;
}
