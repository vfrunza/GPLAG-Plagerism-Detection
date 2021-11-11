#include <stdio.h>

int main() {
	
	char b;
	
	int brc=0, brp=0, brs=0, brv=0, brb=0;
	
	float udio;
	
	int suma, max;
	
	printf("Unesite vozila: ");
	
	do{ scanf("%c", &b);
	
	if(b!='P'&&b!='p'&&b!='B'&&b!='b'&&b!='C'&&b!='c'&&b!='S'&&b!='s'&&b!='V'&&b!='v'&&b!='K'&&b!='k') printf("Neispravan unos\n");
	else {
		
		if(b=='C'||b=='c') brc++;
		else if(b=='P'||b=='p') brp++;
		else if(b=='S'||b=='s') brs++;
		else if(b=='B'||b=='b') brb++;
		else if(b=='V'||b=='v') brv++;
		
	}	
	}while(b!='k'&&b!='K');
	
	suma=brc+brp+brs+brb+brv;
	
	max=brc;
	if(brp>max) max=brp;
	if(brs>max) max=brs;
	if(brb>max) max=brb;
	if(brv>max) max=brv;
	
	if(suma==0){printf("Ukupno evidentirano 0 vozila.\nNajpopularnija boja je crna (0.00%%).");}
	
else {	udio=(float)max*100/suma;
	
	if(brc==max) {printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je crna (%.2f%%).", suma, udio);}
	else if(brb==max) {printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je bijela (%.2f%%).", suma, udio);}
	else if(brs==max) {printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je siva (%.2f%%).", suma, udio);}
	else if(brv==max) {printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je crvena (%.2f%%).", suma, udio);}
	else if(brp==max) {printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je plava (%.2f%%).", suma, udio);}
	
	

}
	return 0;
}
