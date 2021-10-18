#include <stdio.h>
#define PR 6.80 /*Cijena Pizze u Restoranu*/
#define HR 3.30 /*Cijena Hamburgera u Restoranu*/
#define CR 5.00 /*Cijena Cevapa u Restoranu*/
#define PF 8.00 /*Cijena Pizze u Fast-foodu*/
#define HF 3.00 /*Cijena Hambrgera u Fast-foodu*/
#define CF 3.90 /*Cijena Cevapa u Fast-foodu*/
#define PB 5.30 /*Cijena Pizze u Bistrou*/
#define HB 5.00 /*Cijena Hamburgera u Bistrou*/
#define CB 6.00 /*Cijena Cevapa u Bistrou*/
int main()
{
	
	char Tarik, Bojan, Mirza, novi_red;
	float u1=0, u2=0, u3=0, u4=0, u5=0, u6=0, u7=0, u8=0, u9=0, u10=0, un1=0, un2=0, un3=0, un4=0, un5=0, un6=0, un7=0, un8=0, un9=0, un10=0, un11=0, un12=0, un13=0, un14=0, un15=0, un16=0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &Tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &Bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &Mirza);
	scanf("%c", &novi_red);

	/*Postavljanje uslova na osnovu mogucnosti izbora*/
	if(Tarik=='P' && Bojan=='P' && Mirza=='P') {
		u1=PB+PB+PB; /*Ukupna cijena jela u Bistru*/
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", u1);
		un1=3*(PR-PR*(10./100));  /*Ukupna cijena u Restoranu sa popustom od 10% na Pizzu*/
	} else if(Tarik=='H' && Bojan=='H' && Mirza=='H') {
		u2=HF+HF+HF; /*Ukupna cijena jela u Fast-foodu*/
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", u2);
		un2=3*(HR-HR*(10./100));  /*Ukupna cijena u Restoranu sa popustom od 10% na Hamburger*/
	} else if(Tarik=='C' && Bojan=='C' && Mirza=='C') {
		u3=CF+CF+CF; /*Ukupna cijena jela u Fast-foodu*/
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", u3);
		un3=3*(CR-CR*(10./100));  /*Ukupna cijena u Restoranu sa popustom od 10% na Cevape*/
	} else if((Tarik=='H' && Bojan=='C' && Mirza=='P')||(Tarik=='H' && Bojan=='P' && Mirza=='C')||(Tarik=='P' && Bojan=='H' && Mirza=='C')||(Tarik=='P' && Bojan=='C' && Mirza=='H')||(Tarik=='C' && Bojan=='H' && Mirza=='P')||(Tarik=='C' && Bojan=='P' && Mirza=='H')) {
		u4=HF+PF+CF; /*Ukupna cijena jela u Fast-foodu*/
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", u4);
		un14=(HR-HR*(10./100))+CR+PR;  /*Ukupna cijena u Restoranu sa popustom od 10% na Hamburger*/
		un15=(CR-CR*(10./100))+PR+HR;  /*Ukupna cijena u Restoranu sa popustom od 10% na Cevape*/
		un16=HR+CR+(PR-PR*(10./100));  /*Ukupna cijena u Restoranu sa popustom od 10% na Pizzu*/
	} else if((Tarik=='P' && Bojan=='P' && Mirza=='H')||(Tarik=='P' && Bojan=='H' && Mirza=='P')||(Tarik=='H' && Bojan=='P' && Mirza=='P')) {
		u5=PB+PB+HB; /*Ukupna cijena jela u Bistrou*/
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", u5);
		un4=2*(PR-PR*(10./100))+HR;  /*Ukupna cijena u Restoranu sa popustom od 10% na Pizzu*/
		un5=2*PR+(HR-HR*(10./100));  /*Ukupna cijena u Restoranu sa popustom od 10% na Hamburger*/
	} else if((Tarik=='P' && Bojan=='P' && Mirza=='C')||(Tarik=='P' && Bojan=='C' && Mirza=='P')||(Tarik=='C' && Bojan=='P' && Mirza=='P')) {
		u6=PB+PB+CB; /*Ukupna cijena jela u Bistrou*/
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", u6);
		un6=2*(PR-PR*(10./100))+CR; /*Ukupna cijena u Restoranu sa popustom od 10% na Pizzu*/
		un7=2*PR+(CR-CR*(10./100)); /*Ukupna cijena u Restoranu sa popustom od 10% na Cevape*/
	} else if((Tarik=='H' && Bojan=='H' &&Mirza=='P')||(Tarik=='H' && Bojan=='P' && Mirza=='H')||(Tarik=='P' && Bojan=='H' && Mirza=='H')) {
		u7=HR+HR+PR; /*Ukupna cijena jela u Restoranu*/
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", u7);
	} else if((Tarik=='H' && Bojan=='H' && Mirza=='C')||(Tarik=='H' && Bojan=='C' && Mirza=='H')||(Tarik=='C' && Bojan=='H' && Mirza=='H')) {
		u8=HF+HF+CF; /*Ukupna cijena jela u Fast-foodu*/
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", u8);
		un8=2*(HR-HR*(10./100))+CR;  /*Ukupna cijena u Restoranu sa popustom od 10% na Hamburger*/
		un9=2*HR+(CR-CR*(10./100));  /*Ukupna cijena u Restoranu sa popustom od 10% na Cevape*/
	} else if((Tarik=='C' && Bojan=='C' && Mirza=='H')||(Tarik=='C' && Bojan=='H' && Mirza=='C')||(Tarik=='H' && Bojan=='C' && Mirza=='C')) {
		u9=CF+CF+HF; /*Ukupna cijena jela u Fast-foodu*/
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", u9);
		un10=2*(CR-CR*(10./100))+HR;  /*Ukupna cijena u Restoranu sa popustom od 10% na Cevapi*/
		un11=2*CR+(HR-HR*(10./100));  /*Ukupna cijena u Restoranu sa popustom od 10% na Hamburger*/
	} else if((Tarik=='C' && Bojan=='C' && Mirza=='P')||(Tarik=='C' && Bojan=='P' && Mirza=='C')||(Tarik=='P' && Bojan=='C' && Mirza=='C')) {
		u10=CF+CF+PF; /*Ukupna cijena jela u Fast-foodu*/
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", u10);
		un12=2*(CR-CR*(10./100))+PR;  /*Ukupna cijena u Restoranu sa popustom od 10% na Cevape*/
		un13=2*CR+(PR-PR*(10./100));  /*Ukupna cijena u Restoranu sa popustom od 10% na Pizzu*/
	}
	/*Poredenje cijena Fast-fooda i Bistra sa cijenom Restorana koristeci isti izbor jela ali sa popustom na jedno od jela*/
	if(un1<u1) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un1);
	} else if(un2<u2) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un2);
	} else if(un3<u3) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un3);
	}
	if(un4<u5) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un4);
	} else if(un5<u5) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un5);
	}
	if(un6<u6) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un6);
	} else if(un7<u6) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un7);
	}
	if(un8<u8) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un8);
	} else if(un9<u8) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un9);
	}
	if(un10<u9) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un10);
	} else if(un11<u9) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un11);
	}
	if(un12<u10) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un12);
	} else if(un13<u10) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un13);
	}
	if(un14<u4 || un15<u4 || un16<u4) {
		if(un15<un14 && un15<un16) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un15);
		} else if(un14<un15 && un16<un15) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un14);
		} else if(un16<un14 && un16<un15) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", un16);
		}
	}


	return 0;
}