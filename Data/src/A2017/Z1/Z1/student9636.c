#include <stdio.h>

int main() {
	char tarik, bojan, mirza, novired;
	float suma1, suma2, suma3, suma4, suma5, suma6, suma7, suma8, suma9, suma10, suma11, suma12, suma13, suma15, suma16, suma17, suma18, suma19, suma20;
	/*unos jela*/
	printf ("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novired);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novired);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novired);
	float PKK=6.80;
	float HKK=3.30;
	float CKK=5.00;
	float PT=8.00;
	float HT=3.00;
	float CT=3.90;
	float PBL=5.30;
	float HBL=5.00;
	float CBL=6.00;
	suma1=3*PBL;
	suma2=2*PBL+HBL;
	suma3=2*PBL+CBL;
	suma4=PKK+2*HKK;/*restoran*/
	suma5=PT+HT+CT;
	suma6=PT+2*CT;
	suma7=3*HT;
	suma8=2*HT+CT;
	suma9=2*CT+HT;
	suma10=3*CT;
	suma11=(PKK-PKK*0.1)*3;
	suma12=(PKK-PKK*0.1)+(PKK-PKK*0.1)+HKK;
	suma13=(PKK-PKK*0.1)+(PKK-PKK*0.1)+CKK;
	suma15=(PKK-PKK*0.1)+HKK+CKK;
	suma16=PKK+(CKK-CKK*0.1)+(CKK-CKK*0.1);
	suma17=(HKK-HKK*0.1)+(HKK-HKK*0.1)+(HKK-HKK*0.1);
	suma18=CKK+(HKK-HKK*0.1)+(HKK-HKK*0.1);
	suma19=(CKK-CKK*0.1)+(CKK-CKK*0.1)+HKK;
	suma20=(CKK-CKK*0.1)+(CKK-CKK*0.1)+(CKK-CKK*0.1);
	if (tarik=='P' && bojan=='P'){
		if (mirza=='P') {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma1);
			if (suma11<suma1)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma11);
			else printf("");
		}
		else if (mirza=='H'){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma2);
			if(suma12<suma2)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma12);
			else printf("");
		}
		else if (mirza=='C'){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
			if(suma13<suma3) 
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM)", suma13);
			else printf("");
		}
	}
	
	
	if (tarik=='P' && bojan =='H'){
		if (mirza=='P'){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma2);
			if(suma12<suma2)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma12);
			else printf("");
		}
		else if (mirza=='H'){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma4);}
		else if (mirza=='C'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma5);
			if(suma15<suma5)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma15);
			else printf("");
		}
	}
	if (tarik=='P' && bojan=='C'){
		if (mirza=='P'){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
			if(suma13<suma3)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma13);
			else printf("");
		}
		else if (mirza=='H'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma5);
			if(suma15<suma5)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma15);
			else printf("");
		}
		else if(mirza=='C'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma6);
			if (suma16<suma6)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma16);
			else printf("");
		}
	}
	if (tarik=='H' && bojan=='P'){
		if(mirza=='P'){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma2);
			if (suma12<suma2)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma12);
			else printf("");
		}
		else if (mirza=='H')
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma4);
		else if(mirza=='C'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma5);
			if(suma15<suma5)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma15);
			else printf("");
		}
	}
	if (tarik=='H' && bojan=='H'){
		if(mirza=='P')
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma4);
		else if(mirza=='H'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma7);
			if (suma17<suma7)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma17);
			else printf("");
		}
		else if(mirza=='C'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma8);
			if (suma18<suma8)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma18);
			else printf("");
		}
	}
	
	if(tarik=='H' && bojan=='C'){
		if (mirza=='P'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma5);
			if(suma15<suma5)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma15);
			else printf("");
		}
		else if (mirza=='H'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma8);
			if(suma18<suma8)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma18);
			else printf("");
		}
		else if (mirza=='C'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma9);
			if(suma19<suma9)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma19);
			else printf("");
		}
	}
	
	
	if (tarik=='C'&& bojan=='P'){
		if (mirza=='P'){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
			if(suma13<suma3)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma13);
			else printf("");
		}
		else if(mirza=='H'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma5);
			if(suma15<suma5)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma15);
			else printf("");
		}
		else if (mirza=='C'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma6);
			if(suma16<suma6)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma16);
			else printf("");
		}
	}
	if (tarik=='C'&& bojan=='H'){
		if(mirza=='P'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma5);
			if(suma15<suma5)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma15);
			else printf("");
		}
		else if(mirza=='H'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma8);
			if(suma18<suma8)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma18);
			else printf("");
		}
		else if (mirza=='C'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma9);
			if(suma19<suma9)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma19);
			else printf("");
		}
	}
	if (tarik=='C' && bojan=='C'){
		if (mirza=='P'){
		printf("Najjeftiniji je Fast-foof \"Trovac\" (%.2f KM).", suma6);
			if (suma16<suma6)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma16);
			else printf("");
		}
		else if (mirza=='H'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma9);
			if(suma19<suma9)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM.", suma19);
			else printf("");
		}
		else if(mirza=='C'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma10);
			if(suma20<suma10)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma20);
			else printf("");
		}
	}

	return 0;
}
