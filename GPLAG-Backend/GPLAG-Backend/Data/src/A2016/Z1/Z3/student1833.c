#include <stdio.h>

int main() {
	char auta;
	float pc, pp, ps, pv, pb, brojc, brojs, brojv, brojb, brojp, i;
	i=0; brojp=0; brojc=0; brojv=0; brojs=0; brojb=0; auta=' ';
  printf("Unesite vozila: ");
  
  
    while(auta!='K' && auta!='k') {
	scanf("%c", &auta);
	if(auta=='k' || auta=='K') break;
	if(auta!='c' && auta!='C' && auta!='b' && auta!='B' && auta!='v' && auta!='V' && auta!='p' && auta!='P' && auta!='s' && auta!='S') { 
		printf ("Neispravan unos");
		printf("\n");

	}

	
	if(auta=='c' || auta=='C') brojc+=1; 
	if(auta=='b' || auta=='B') brojb+=1;
	if(auta=='v' || auta=='V') brojv+=1;
	if(auta=='s' || auta=='S') brojs+=1;
	if(auta=='p' || auta=='P') brojp+=1;
	
	}
	
	
	i=brojc+brojb+brojv+brojs+brojp;
printf("Ukupno evidentirano %g vozila.", i);

pc=(brojc/i)*100; 
pp=(brojp/i)*100;
ps=(brojs/i)*100;
pv=(brojv/i)*100;
pb=(brojb/i)*100;
if(i==0) pc=0;
if(brojc>=brojp && brojc>=brojb && brojc>=brojs && brojc>=brojv) { printf("\nNajpopularnija boja je crna (%.2f%%).", pc); return 0; }
if(brojb>brojc && brojb>=brojs && brojb>=brojv && brojb>=brojp) { printf("\nNajpopularnija boja je bijela (%.2f%%).", pb); return 0; }
if(brojs>brojc && brojs>=brojp && brojs>brojb && brojs>=brojv) { printf("\nNajpopularnija boja je siva (%.2f%%).", ps); return 0; }
if(brojv>=brojp && brojv>brojb && brojv>brojs && brojv>brojc) { printf("\nNajpopularnija boja je crvena (%.2f%%).", pv); return 0; }
if(brojp>brojv && brojp>brojb && brojp>brojv && brojp>brojs) { printf("\nNajpopularnija boja je plava (%.2f%%).", pp); return 0; }


	return 0;
}
