#include <stdio.h>

int main() {
	int kolicina=0;
	int crvena=0,plava=0,crna=0,siva=0,bijela=0;
	int max;
	
	char z;
	
	printf("Unesite vozila: ");
	while(1){
		scanf("%c",&z);
		/* provjera */
		if(z == 'k' || z == 'K')
			break;
		if(z=='\n')
			continue;
		/* boje */
		if(z == 'c' ||z == 'C')
			crna++;
		else if(z == 'p' || z == 'P')
			plava++;
		else if(z == 's' || z == 'S')
			siva++;
		else if(z == 'v' || z == 'V')
			crvena++;
		else if(z=='b' || z== 'B')
			bijela++;
		else{
			printf("Neispravan unos\n");
			kolicina--;
		}
		kolicina++;
	}
	printf("Ukupno evidentirano %d vozila. \n", kolicina);
	printf("Najpopularnija boja je ");
	if(crvena>crna && crvena>bijela && crvena>=plava && crvena>siva){
		max = crvena;
		if(kolicina == 0)
			printf("crvena (0.00%%).");
		else
			printf("crvena (%.2f%%).",(float)max/kolicina*100);
	}
	if(crna>=bijela && crna>=plava && crna>=crvena && crna>=siva){
		max = crna;
		if(kolicina == 0)
			printf("crna (0.00%%).");
		else
			printf("crna (%.2f%%).",(float)max/kolicina*100);
		
	}
	if(bijela>crna && bijela>=plava && bijela>=crvena && bijela>=siva){
		max = bijela;
		if(kolicina == 0)
			printf("bijela (0.00%%).");
		else
			printf("bijela (%.2f%%).",(float)max/kolicina*100);
	}
	if(siva>crna && siva>bijela && siva>=plava && siva>=crvena){
		max = siva;
		if(kolicina == 0)
			printf("siva (0.00%%).");
		else
			printf("siva (%.2f%%).",(float)max/kolicina*100);
	}
	if(plava>crna && plava>crvena && plava > siva && plava > bijela){
		max = plava;
		if(kolicina == 0)
			printf("plava (0.00%%).");
		else
			printf("plava (%.2f%%).",(float)max/kolicina*100);
	
	}
	return 0;
}
