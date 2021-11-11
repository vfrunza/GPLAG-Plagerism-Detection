#include <stdio.h>
int main () {
	char boja;
	printf("Unesite vozila: ");
	int brC=0, brB=0, brP=0, brV=0, brS=0, broj_auta=0, max=0, redni_broj;
	do {
		scanf("%c",&boja);
		while(boja=='\n') scanf("%c",&boja);
		if((boja=='C' || boja=='P' || boja=='B' || boja=='V' || boja=='S' || boja=='c' || boja=='p' || boja=='b' || boja=='v' || boja=='s') && (boja!='K' && boja!='k')) {
			broj_auta++;
			if(boja=='C' || boja=='c') { brC++; if(brC>max){max=brC; redni_broj=1;} }
			else if(boja=='B' || boja=='b') { brB++; if(brB>max){max=brB; redni_broj=2;} }
			else if(boja=='S' || boja=='s') { brS++; if(brS>max){max=brS; redni_broj=3;} }
			else if(boja=='V' || boja=='v') { brV++; if(brV>max){max=brV; redni_broj=4;} }
			else if(boja=='P' || boja=='p') { brP++; if(brP>max){max=brP; redni_broj=5;} }
			}
		else { if(boja!='K' && boja!='k') {
			printf("Neispravan unos\n"); 
			}
		}
		}
	while(boja!='K' && boja!='k');
	double procenat;
	if(broj_auta!=0) {
		procenat=max*100;
		procenat=procenat/broj_auta; }
	else {
		procenat=0;
		redni_broj=1;
	}
	printf("Ukupno evidentirano %d vozila.\n",broj_auta);
	if(redni_broj==1) printf("Najpopularnija boja je crna (%.2lf%).",procenat);
	else if(redni_broj==2) printf("Najpopularnija boja je bijela (%.2lf%).",procenat);
	else if(redni_broj==3) printf("Najpopularnija boja je siva (%.2lf%).",procenat);
	else if(redni_broj==4) printf("Najpopularnija boja je crvena (%.2lf%).",procenat);
	else if(redni_broj==5) printf("Najpopularnija boja je plava (%.2lf%).",procenat);
	return 0; }
	
	
	
	
	
	