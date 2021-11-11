#include <stdio.h>
#define P1 6.80
#define P2 8.00
#define P3 5.30
#define P1 6.80
#define H1 3.30
#define H2 3.00
#define H3 5.00
#define C1 5.00
#define C2 3.90
#define C3 6.00

int main() {
	float c,cp;
	char tarik,bojan,mirza,novi_red,P;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	if(tarik=='P' && bojan=='P' && mirza=='P'){
	c=3*P3;
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",c); 
	}
	
	if(tarik=='H' && bojan=='H' && mirza=='H'){
	c=3*H2;
	cp=3*(0.9*H1);
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",c);
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cp);
	}
	
	if(tarik=='C' && bojan=='C' && mirza=='C'){
	c=3*C2;
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",c);
	}
	
	if((tarik=='H' && bojan=='P' && mirza=='P')||(tarik=='P' && bojan=='H' && mirza=='P')||(tarik=='P' && bojan=='P' && mirza=='H')){
	c=H3+2*P3;
	cp=2*(0.9*P1)+H1;
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",c);
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cp);
	}
	
	if((tarik=='H' && bojan=='H' && mirza=='P')||(tarik=='H' && bojan=='P' && mirza=='H')||(tarik=='P' && bojan=='H' && mirza=='H')){
	c=2*H1+P1;
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",c);
	}
	
	if((tarik=='H' && bojan=='P' && mirza=='C')||(tarik=='H' && bojan=='C' && mirza=='P')||(tarik=='C' && bojan=='H' && mirza=='P')||(tarik=='C' && bojan=='P' && mirza=='H')||(tarik=='P' && bojan=='C' && mirza=='H')||(tarik=='P' && bojan=='H' && mirza=='C')){
	c=P2+H2+C2;
	cp=0.9*P1+H1+C1;
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",c);
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cp);
	}
	
	if((tarik=='H' && bojan=='C' && mirza=='C')||(tarik=='C' && bojan=='H' && mirza=='C')||(tarik=='C' && bojan=='C' && mirza=='H')){
	c=2*C2+H2;
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",c);
	}
	
	if((tarik=='C' && bojan=='P' && mirza=='P')||(tarik=='P' && bojan=='C' && mirza=='P')||(tarik=='P' && bojan=='P' && mirza=='C')){
	c=2*P3+C3;
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",c);
	}
	
	if((tarik=='C' && bojan=='H' && mirza=='H')||(tarik=='H' && bojan=='C' && mirza=='H')||(tarik=='H' && bojan=='H' && mirza=='C')){
	c=2*H2+C2;
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",c);
	}
	
	if((tarik=='P' && bojan=='C' && mirza=='C')||(tarik=='C' && bojan=='P' && mirza=='C')||(tarik=='C' && bojan=='C' && mirza=='P')){
	c=2*C2+P2;
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",c);
	}
	return 0;
}