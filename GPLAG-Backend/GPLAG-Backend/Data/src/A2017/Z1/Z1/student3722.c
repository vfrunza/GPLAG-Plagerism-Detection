#include <stdio.h>
#include <math.h>

int main() {
	char tarik, bojan, mirza, novi_red, countP=0, countH=0, countC=0;
	double konj=0, ff=0, bistro=0, discount=0, all=0, konjp=0, konjh=0, konjc=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	/* unosi za jela */
	
	if(tarik=='P')
	countP+=1;

	if(tarik=='H')
	countH+=1;
	
	if(tarik=='C')
	countC+=1;
	
	if(mirza=='P')
	countP+=1;
	
	if(mirza=='H')
	countH+=1;
	
	if(mirza=='C')
	countC+=1;
	
	if(bojan=='P')
	countP=countP+1;
	
	if(bojan=='H')
	countH+=1;
	
	if(bojan=='C')
	countC+=1;
	
	/* najjeftiniji restoran*/
	
	konj+=countP*6.80+countC*5+countH*3.30;
	ff+=countP*8.00+countC*3.90+countH*3.00;
	bistro+=countP*5.30+countC*6.00+countH*5.00;
	
	
	if((bistro<konj) && (bistro<ff))
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", bistro);
	
	if(ff<konj && ff<bistro)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", ff);
	
	if((konj<ff)&&(konj<bistro))
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", konj);
	
	/* popust */
	
	
	konjc=countC*5.00;
	konjp=countP*6.80;
	konjh=countH*3.30;
	
	if((konjc>konjh) && (konjc>konjp))
	all=konjc;
	
	if(konjh>konjp && konjh>konjc)
	all=konjh;
	
	if((konjp>konjh) && (konjp>konjc))
	all=konjp;
	
	
	/* konacni popust */ 
	
	discount=konj-(all*10)/100;
	
	if(konj>ff || konj>bistro) {
	if((fabs(discount-konj)>0.01 || fabs(discount-ff)>0.01 || fabs(discount-bistro)>0.01)) {
	if(discount<konj && discount<ff && discount<bistro) {
	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", discount);
	}
	}
	}
	
	return 0;
}
