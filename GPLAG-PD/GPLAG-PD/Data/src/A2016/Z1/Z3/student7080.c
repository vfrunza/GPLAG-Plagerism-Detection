#include <stdio.h>
#define BROJ_EL 10000

int main() {
	char x;
	int i,n;
	float crna=0,bijela=0,siva=0,crvena=0,plava=0;
	float procenat;
		printf ("Unesite vozila: ");
		for (i=0;i<BROJ_EL;i++) {
		scanf ("%c",&x);
	if (x=='C'||x=='c')  crna++; 
	if (x=='B'||x=='b')  bijela++; 
	if (x=='S'||x=='s')  siva++; 
	if (x=='V'||x=='v')  crvena++; 
	if (x=='P'||x=='p')  plava++; 
	if (x=='K'||x=='k')  break;
	
	if (x!='C' && x!='c' && x!='B' && x!='b' && x!='S' && x!='s' && x!='V' && x!='v' && x!='P' && x!='p') { printf ("Neispravan unos\n");
	i--; continue;
	}
		}
	
	n=i;
	printf ("Ukupno evidentirano %d vozila.\n", n);
	
	
	
	if (crna>=bijela && crna>=siva && crna>=crvena && crna>=plava) {
		if (crna==0 && bijela==0 && siva==0 && crvena==0 && plava==0) { printf ("Najpopularnija boja je crna (0.00%)."); return 0; }
            procenat=( (float)(crna/n)*100 );
            printf ("Najpopularnija boja je crna (%.2f%).", procenat); return 0; }

	if (bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava) {
            procenat=((float)(bijela/n)*100 );
            printf ("Najpopularnija boja je bijela (%.2f%).", procenat); return 0;  }


	if (siva>=crna && siva>=bijela && siva>=crvena && siva>=plava) {
            procenat=( (float)(siva/n) )*100;
            printf ("Najpopularnija boja je siva (%.2f%).", procenat); return 0;  }
            
    if (crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava) {
    	procenat=( (float)(crvena/n)*100 );
    	printf ("Najpopularnija boja je crvena (%.2f%).", procenat); return 0; }

	if (plava>=crna && plava>=bijela && plava>=siva && plava>=crvena) {
            procenat=( (float)(plava/n)*100 );
            printf ("Najpopularnija boja je plava (%.2f%).", procenat); return 0;  }
            
          return 0;
}



