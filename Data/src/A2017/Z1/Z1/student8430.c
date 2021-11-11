#include <stdio.h>
#include <stdlib.h>

int main() {
	char t,b,m,trash;
	double konjusar=0, trovac=0, loreli=0;
	int hamb=0, pizza=0, cevap=0;
	int najjeftiniji=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&t);
	scanf("%c",&trash);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&b);
	scanf("%c",&trash);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&m);
	scanf("%c",&trash);
	if(t=='H')
	hamb++;
	if(b=='H')
	hamb++;
    if(m=='H')
    hamb++;
    if(t=='P')
    pizza++;
    if(b=='P')
    pizza++;
    if(m=='P')
    pizza++;
    if(t=='C')
    cevap++;
    if(b=='C')
    cevap++;
    if(m=='C')
    cevap++;
    konjusar=pizza*6.80 + hamb*3.30 + cevap*5.00;
    trovac=pizza*8.00 + hamb*3.00 + cevap*3.90;
    loreli=pizza*5.30 + hamb*5.00 + cevap*6.00;
    if(konjusar<trovac && konjusar<loreli){
    	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",konjusar);
    	najjeftiniji=1;
    }
    else if(trovac<konjusar && trovac<loreli)
    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", trovac);
    else
    printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",loreli);
    
    if(najjeftiniji==0){
    	if(pizza>0)
    	konjusar=pizza*6.80*0.9 + hamb*3.30 + cevap*5.00;
    	else if(cevap>0)
    	konjusar=pizza*6.80 + hamb*3.30 + cevap*5.0*0.9;
    	else
    	konjusar=pizza*6.80 + hamb*3.30*0.9 + cevap*5.00;
    	if(konjusar<trovac && konjusar<loreli) 
    	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",konjusar);
    }
	return 0;
}
