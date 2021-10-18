#include <stdio.h>
#include <stdlib.h>

int main() {
	float postotak,nesto;
	int crni=0,bijeli=0,sivi=0,crveni=0,plavi=0,ukupno=0;
	char znak;
	printf("Unesite vozila: ");
	while (1){
		scanf("%c", &znak);
		if(znak=='k' || znak=='K')break;
		else if(znak=='c' || znak=='C')	{crni++; ukupno++;}
		else if(znak=='b' || znak=='B') {bijeli++; ukupno++;}
		else if(znak=='s' || znak=='S') {sivi++; ukupno++;}
		else if(znak=='v' || znak=='V') {crveni++; ukupno++;}
		else if(znak=='p' || znak=='P') {plavi++; ukupno++;}
		else printf("Neispravan unos\n");
	}
	printf("Ukupno evidentirano %d vozila.\n", ukupno);
	if(ukupno==0) printf("Najpopularnija boja je crna (0.00%%).");
	else if(crni>=bijeli && crni>=bijeli && crni>=crveni && crni>=plavi){
		nesto=crni*100;
		postotak=nesto/ukupno;
		printf("Najpopularnija boja je crna (%.2f%%).", postotak);
	}
	else if(bijeli>=crni && bijeli>=sivi && bijeli>=crveni && bijeli>=plavi){
		nesto=bijeli*100;
		postotak=nesto/ukupno;
		printf("Najpopularnija boja je bijela (%.2f%%).", postotak);
	}
	else if(sivi>=crni && sivi>=bijeli && sivi>=crveni && sivi>=plavi) {
		nesto=sivi*100;
		postotak=nesto/ukupno;
		printf("Najpopularnija boja je siva (%.2f%%).", postotak);
	}
	else if(crveni>=crni && crveni>=bijeli && crveni>=sivi && crveni>=plavi) {
		nesto=crveni*100;
		postotak=nesto/ukupno;
		printf("Najpopularnija boja je crvena (%.2f%%).", postotak);	
	}
	else if(plavi>=crni && plavi>=bijeli && plavi>=sivi && plavi>=crveni){
		nesto=plavi*100;
		postotak=nesto/ukupno;
		printf("Najpopularnija boja je plava (%.2f%%).", postotak);
	}
		return 0;
}
