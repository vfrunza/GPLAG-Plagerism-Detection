#include <stdio.h>

int main() {
	char brm='a';
	int crna=0,bijela=0,siva=0,crvena=0,plava=0,broj=0;
	float p;
	printf("Unesite vozila: ");
    do {
	scanf("%c", &brm);
	if (brm!='c' && brm!='C' && brm!='s' && brm!='S' && brm!='v' && brm!='V' && brm!='b' && brm!='B' && brm!='p' && brm!='P' && brm!='k' && brm!='K') {
		printf("Neispravan unos\n"); }
		else {
		if(brm=='c' || brm=='C')
		crna++;
		else if(brm=='b' || brm=='B')
		bijela++;
		else if(brm=='s' || brm=='S')
		siva++;
		else if(brm=='v' || brm=='V')
		crvena++;
		else if(brm=='p' || brm=='P')
		plava++; 
	} 
	} while(brm!='k' &&  brm!='K');

	broj=crna+bijela+siva+crvena+plava;
	printf("Ukupno evidentirano %d vozila.\n",broj);
	if (broj!=0){
		if (crna>=bijela && crna>=siva && crna>=crvena && crna>=plava){
		p=((float)crna/broj)*100; printf("Najpopularnija boja je crna (%.2f%%).",p); }
		else if (bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava){
		p=((float)bijela/broj)*100;printf("Najpopularnija boja je bijela (%.2f%%).",p); }
		else if (siva>=bijela && crna<=siva && siva>=crvena && siva>=plava){
		p=((float)siva/broj)*100;printf("Najpopularnija boja je siva (%.2f%%).",p); }
		else if (crvena>=bijela && crvena>=siva && crna<=crvena && crvena>=plava){
		p=((float)crvena/broj)*100;printf("Najpopularnija boja je crvena (%.2f%%).",p); }
		else if (plava>=bijela && plava>=siva && plava>=crvena && crna<=plava){
		p=((float)plava/broj)*100;printf("Najpopularnija boja je plava (%.2f%%).",p); }
		}
		
		else {
		printf ("Najpopularnija boja je crna (0.00%%).");}
	return 0;
}
