#include <stdio.h>

int main() {
	char tarik, bojan, mirza, novi_red;
	double P1=6.8, P2=8.0, P3=5.3, H1=3.3, H2=3.0, H3=5.0, C1=5.0, C2=3.9, C3=6.0;
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
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", P3*3);
	}else if(tarik=='H' && bojan=='H' && mirza=='H'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", H2*3);
		if((H2*3)>(H1*3)-(H1*3*10./100))
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", (H1*3)-(H1*3*10./100) );
	}		
	else if(tarik=='C' && bojan=='C' && mirza=='C'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", C2*3);
		if((C2*3)>(C1*3+C1)-((C1*3+C1)*(10./100)))
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(C1*3+C1)-(C1*3+C1)*(10./100));	
	}		
	else if((tarik=='P' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='P') || (tarik=='H' && mirza=='P' && bojan=='P')){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", (P3*2+H3) );
		if((P3*2+H3)>((P1*2)-(P1*2)*(10./100)+H1) )
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", ((P1*2)-(P1*2)*(10./100))+H1 );
	}
	
	else if((tarik=='P' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='C' && mirza=='P' && bojan=='P')){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", P3*2+C3);
		
	}else if((tarik=='H' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='H') || (tarik=='P' && mirza=='H' && bojan=='H')){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", H1*2+P1);
		
	}else if((tarik=='H' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='H') || (tarik=='C' && mirza=='H' && bojan=='H')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", H2*2+C2);
		
	}else if((tarik=='C' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='C') || (tarik=='P' && mirza=='C' && bojan=='C')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", C2*2+P2);
		if((C2*2+P2)>((C1*2)-(C1*2)*(10./100)+P1) )
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",((C1*2)-(C1*2)*(10./100)+P1));
	}
	else if((tarik=='C' && bojan=='C' && mirza=='H') || (tarik=='C' && bojan=='H' && mirza=='C') || (tarik=='H' && mirza=='C' && bojan=='C')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", C2*2+H2);
	}
	else{
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", P2+H2+C2);
		if((P2+H2+C2)>(P1-P1*(10./100)+H1+C1))
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(P1-P1*(10./100)+H1+C1));
	}

	return 0;
}
