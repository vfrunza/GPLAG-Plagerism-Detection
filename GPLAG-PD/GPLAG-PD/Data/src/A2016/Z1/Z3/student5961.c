#include <stdio.h>

int main() {
	char boja;
	int brojacC=0, brojacS=0, brojacB=0, brojacV=0, brojacP=0, max, brojacvozila=0;
	float postotak;
	printf("Unesite vozila: ");
	do{
		scanf("%c", &boja);
		if(boja=='c' || boja=='C'){
			brojacC++; 
			brojacvozila++;
			
		}
		else if(boja=='b' || boja=='B'){
			brojacB++; 
			brojacvozila++;
			
		}
		else if(boja=='s' || boja=='S'){
			brojacS++; 
			brojacvozila++;
			
		}
		else if(boja=='v' || boja=='V'){
			brojacV++; 
			brojacvozila++;
			
		}
		else if(boja=='p' || boja=='P'){
			brojacP++; 
			brojacvozila++;
			
		}
		if(boja!='c' && boja!='C' && boja!='b' && boja!='B' && boja!='s' && boja!='S' && boja!='v' && boja!='V' && boja!='p' && boja!='P' && boja!='k' && boja!='K'){
			printf("Neispravan unos\n");
		}
	} while(boja!='k' && boja!='K');
	max=brojacC;
	if (brojacB>max){
		max=brojacB;
	}
	if(brojacS>max){
		max=brojacS;
	}
	if(brojacV>max){
		max=brojacV;
	}
	if(brojacP>max){
		max=brojacP;
	}
	if(brojacvozila!=0) postotak=(float)(max*100)/brojacvozila;
	else if(brojacvozila==0) postotak=0;
	printf("Ukupno evidentirano %d vozila.\n", brojacvozila);
	if(max==brojacC) printf("Najpopularnija boja je crna (%.2f%%).", postotak);
	else if(max==brojacB) printf("Najpopularnija boja je bijela (%.2f%%).", postotak);
	else if(max==brojacS) printf("Najpopularnija boja je siva (%.2f%%).", postotak);
	else if(max==brojacV) printf("Najpopularnija boja je crvena (%.2f%%).", postotak);
	else printf("Najpopularnija boja je plava (%.2f%%).", postotak);
	return 0;
}
