#include <stdio.h>
#define PR 6.80 
#define HR 3.30 
#define CR 5.00 
#define PF 8.00 
#define HF 3.00 
#define CF 3.90 
#define PB 5.30 
#define HB 5.00 
#define CB 6.00 
int main()
{
	
	char tarik, bojan, mirza, novi_red;
	float R1=0, R2=0, R3=0, R4=0, R5=0, R6=0, R7=0, R8=0, R9=0, R10=0, Rn1=0, Rn2=0, Rn3=0, Rn4=0, Rn5=0, Rn6=0, Rn7=0, Rn8=0, Rn9=0, Rn10=0, Rn11=0, Rn12=0, Rn13=0, Rn14=0, Rn15=0, Rn16=0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);

	
	if(tarik=='P' && bojan=='P' && mirza=='P') {
		R1=PB+PB+PB; 
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", R1);
		Rn1=3*(PR-PR*(10./100)); 
	} else if(tarik=='H' && bojan=='H' && mirza=='H') {
		R2=HF+HF+HF; 
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", R2);
		Rn2=3*(HR-HR*(10./100)); 
	} else if(tarik=='C' && bojan=='C' && mirza=='C') {
		R3=CF+CF+CF; 
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", R3);
		Rn3=3*(CR-CR*(10./100));  
	} else if((tarik=='H' && bojan=='C' && mirza=='P')||(tarik=='H' && bojan=='P' && mirza=='C')||(tarik=='P' && bojan=='H' && mirza=='C')||(tarik=='P' && bojan=='C' && mirza=='H')||(tarik=='C' && bojan=='H' && mirza=='P')||(tarik=='C' && bojan=='P' && mirza=='H')) {
		R4=HF+PF+CF; 
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", R4);
		Rn14=(HR-HR*(10./100))+CR+PR; 
		Rn15=(CR-CR*(10./100))+PR+HR;  
		Rn16=HR+CR+(PR-PR*(10./100));  
	} else if((tarik=='P' && bojan=='P' && mirza=='H')||(tarik=='P' && bojan=='H' && mirza=='P')||(tarik=='H' && bojan=='P' && mirza=='P')) {
		R5=PB+PB+HB; 
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", R5);
		Rn4=2*(PR-PR*(10./100))+HR; 
		Rn5=2*PR+(HR-HR*(10./100));  
	} else if((tarik=='P' && bojan=='P' && mirza=='C')||(tarik=='P' && bojan=='C' && mirza=='P')||(tarik=='C' && bojan=='P' && mirza=='P')) {
		R6=PB+PB+CB; 
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", R6);
		Rn6=2*(PR-PR*(10./100))+CR; 
		Rn7=2*PR+(CR-CR*(10./100)); 
	} else if((tarik=='H' && bojan=='H' &&mirza=='P')||(tarik=='H' && bojan=='P' && mirza=='H')||(tarik=='P' && bojan=='H' && mirza=='H')) {
		R7=HR+HR+PR; 
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", R7);
	} else if((tarik=='H' && bojan=='H' && mirza=='C')||(tarik=='H' && bojan=='C' && mirza=='H')||(tarik=='C' && bojan=='H' && mirza=='H')) {
		R8=HF+HF+CF; 
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", R8);
		Rn8=2*(HR-HR*(10./100))+CR;  
		Rn9=2*HR+(CR-CR*(10./100));  
	} else if((tarik=='C' && bojan=='C' && mirza=='H')||(tarik=='C' && bojan=='H' && mirza=='C')||(tarik=='H' && bojan=='C' && mirza=='C')) {
		R9=CF+CF+HF; 
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", R9);
		Rn10=2*(CR-CR*(10./100))+HR;  
		Rn11=2*CR+(HR-HR*(10./100));  
	} else if((tarik=='C' && bojan=='C' && mirza=='P')||(tarik=='C' && bojan=='P' && mirza=='C')||(tarik=='P' && bojan=='C' && mirza=='C')) {
		R10=CF+CF+PF; 
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", R10);
		Rn12=2*(CR-CR*(10./100))+PR;  
		Rn13=2*CR+(PR-PR*(10./100));  
	}
	
	if(Rn1<R1) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn1);
	} else if(Rn2<R2) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn2);
	} else if(Rn3<R3) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn3);
	}
	if(Rn4<R5) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn4);
	} else if(Rn5<R5) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn5);
	}
	if(Rn6<R6) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn6);
	} else if(Rn7<R6) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn7);
	}
	if(Rn8<R8) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn8);
	} else if(Rn9<R8) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn9);
	}
	if(Rn10<R9) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn10);
	} else if(Rn11<R9) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn11);
	}
	if(Rn12<R10) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn12);
	} else if(Rn13<R10) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn13);
	}
	if(Rn14<R4 || Rn15<R4 || Rn16<R4) {
		if(Rn15<Rn14 && Rn15<Rn16) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn15);
		} else if(Rn14<Rn15 && Rn16<Rn15) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn14);
		} else if(Rn16<Rn14 && Rn16<Rn15) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn16);
		}
	}


	return 0;
}