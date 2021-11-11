#include <stdio.h>
#define epsilon 0.00000001
#include <math.h>
int main() {
	printf("Unesite vozila: ");
	char n='n';
	float suma,broj;
	int brs=0,brc=0,brv=0,brb=0,brp=0;
	do{ 
		scanf("%c",&n);
	   if(n!='s' && n!='S' && n!='c' && n!='C' && n!='v' && n!='V' && n!='b' && n!='B' &&
	                  n!='p' && n!='P' && n!='k' && n!='K'){printf("Neispravan unos\n");}
		if(n=='s' || n=='S'){ brs=brs+1;}
		if(n=='c' || n=='C'){ brc=brc+1;}
		if(n=='v' || n=='V'){ brv=brv+1;}
		if(n=='b' || n=='B'){ brb=brb+1;}
		if(n=='p' || n=='P'){ brp=brp+1;}
	}while(n!='k' && n!='K');
	suma=brs+brb+brc+brv+brp;
	printf("Ukupno evidentirano %.f vozila.", suma); 
	if(fabs(suma)<epsilon){ printf("\nNajpopularnija boja je crna (0.00%)."); return 0;}
if(brc>=brb && brc>=brs && brc>=brp && brc>=brv){ 
	broj=(brc/suma)*100;
	printf("\nNajpopularnija boja je crna (%.2f%%).", broj); }
else if(brb>=brs && brb>=brc && brb>=brp && brb>=brv){ 
	broj=(brb/suma)*100; 
	printf("\nNajpopularnija boja je bijela (%.2f%%).", broj); }
else if(brs>=brb && brs>=brc && brs>=brp && brs>=brv){ 
	broj=(brs/suma)*100; 
	printf("\nNajpopularnija boja je siva (%.2f%%).", broj); }
else if(brv>=brb && brv>=brc && brv>=brp && brv>=brb){ 
	broj=(brv/suma)*100;
	printf("\nNajpopularnija boja je crvena (%.2f%%).", broj); }
else if(brp>=brb && brp>=brc && brp>=brs && brp>=brv){ 
	broj=(brp/suma)*100; 
	printf("\nNajpopularnija boja je plava (%.2f%%).", broj); }

	return 0;
}
