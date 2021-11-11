#include <stdio.h>

int main() {
	char tarik, bojan, mirza, novi_red;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	if((mirza=='C'&& bojan=='H' &&tarik=='P')||(mirza=='C'&& bojan=='P' &&tarik=='H')||(mirza=='P'&& bojan=='H' &&tarik=='C')||(mirza=='P'&& bojan=='C' &&tarik=='H')||(mirza=='H'&& bojan=='C' &&tarik=='P')||(mirza=='H'&& bojan=='P'&& tarik=='C'))
	printf("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\nSa popustom bi Restoran bio jeftiniji (14.10 KM).");
	else if((mirza=='C'&& bojan=='H' &&tarik=='H')||(mirza=='H'&& bojan=='H' &&tarik=='C')||(mirza=='H'&& bojan=='C' &&tarik=='H'))
	printf("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM).");
	else if((mirza=='C'&& bojan=='P'&&tarik=='P')||(mirza=='P'&& bojan=='C' &&tarik=='P')||(mirza=='P'&& bojan=='P' &&tarik=='C'))
	printf("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
	else if((mirza=='P'&& bojan=='C' &&tarik=='C')||(mirza=='C'&& bojan=='P' &&tarik=='C')||(mirza=='C'&& bojan=='C'&& tarik=='P'))
	printf("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM).\n");
	else if((mirza=='P'&& bojan=='H' &&tarik=='H')||(mirza=='H'&& bojan=='P' &&tarik=='H')||(mirza=='H'&& bojan=='H'&& tarik=='P'))
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM).");
	else if((mirza=='C'&& bojan=='C' &&tarik=='C'))
	printf("Najjeftiniji je Fast-food \"Trovac\" (11.70 KM).");
	else if((mirza=='P'&& bojan=='P' &&tarik=='P'))
	printf("Najjeftiniji je Bistro \"Lorelei\" (15.90 KM).");
	else if((mirza=='H'&& bojan=='H' &&tarik=='H'))
	printf("Najjeftiniji je Fast-food \"Trovac\" (9.00 KM).\nSa popustom bi Restoran bio jeftiniji (8.91 KM).");
	else if((mirza=='H'&& bojan=='C' &&tarik=='C')||(mirza=='C'&& bojan=='H' &&tarik=='C')||(mirza=='C'&& bojan=='C'&& tarik=='H'))
	printf("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM).");
	else if((mirza=='H'&& bojan=='P' &&tarik=='P')||(mirza=='P'&& bojan=='H' &&tarik=='P')||(mirza=='P'&& bojan=='P'&& tarik=='H'))
	printf("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).");
	return 0;
}
