#include <stdio.h>
#include <math.h>
int main() {
	/*printf("Zadaća 1, Zadatak 3");*/
	int  crna=0, siva=0, bijela=0, crvena=0, plava=0, i=0;
	char boja;
	double postotak;
	
	printf("Unesite vozila: ");
	while(1) {
	scanf("%c", &boja);
		
		if(boja=='K' || boja =='k') break;
		else if (boja=='c' || boja=='C') {crna++; i=crna+siva+bijela+crvena+plava;}
		else if(boja=='s' || boja=='S') { siva++; i=crna+siva+bijela+crvena+plava;}
		else if(boja=='b' || boja=='B') { bijela++; i=crna+siva+bijela+crvena+plava;}
		else if(boja=='V' || boja =='v') { crvena++; i=crna+siva+bijela+crvena+plava;}
		else if(boja=='p' || boja=='P') { plava++; i=crna+siva+bijela+crvena+plava;}
		else if (boja!='p' && boja!='P' && boja!='k' && boja!='K' && boja!='c' && boja !='C' && boja!='S' && boja!='s' && boja!='B' && boja!='b' && boja!='v' && boja!= 'V') printf("Neispravan unos\n");
	}
	printf("Ukupno evidentirano %d vozila.\n", i);
	if (crna>=siva && crna>= bijela && crna>=crvena && crna>=plava){
		postotak=((float)crna/i)*100;
		if(i==0) printf("Najpopularnija boja je crna (0.00%%).\n");
		else printf("Najpopularnija boja je crna (%.2f%%).\n", postotak); 
		
	}
	else if (siva>=crna && siva>=bijela && siva>=crvena && siva>=plava){
		postotak=((float)siva/i)*100;
		if(i==0) printf("Najpopularnija boja je siva (0.00%%).\n");
		else printf("Najpopularnija boja je siva (%.2f%%).\n", postotak);
	}
	else if (bijela>=crna && bijela >=siva && bijela>=crvena && bijela >=plava){
		postotak=((float)bijela/i)*100;
		if(i==0) printf("Najpopularnija boja je bijela (0.00%%).\n");
		else printf("Najpopularnija boja je bijela (%.2f%%).\n", postotak);
	}
	else if (crvena>=crna && crvena >=siva && crvena>=bijela && crvena>=plava){
		postotak=((float)crvena/i)*100;
		if(i==0) printf("Najpopularnija boja je crvena (0.00%%).\n");
		else printf("Najpopularnija boja je crvena (%.2f%%). \n", postotak);
	}
	else {
		postotak=((float)plava/i)*100;
		if(i==0) printf("Najpopularnija boja je plava (0.00%%).\n");
		else printf ("Najpopularnija boja je plava (%.2f%%). \n", postotak);
	}
	return 0;
}
