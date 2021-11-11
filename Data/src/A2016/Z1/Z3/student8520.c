#include <stdio.h>

int main() {
	char znak;
	int broj_auta=0,crvena=0,plava=0,crna=0,siva=0,bijela=0,max,help;
	printf("Unesite vozila: ");
	for(;;){
		scanf("%c", &znak);
		if(znak=='k' || znak=='K')
		break;
		if(znak=='\n')
		continue;
		switch (znak){
			case 'c':
			crna++;
			break;
			case 'C':
			crna++;
			break;
			case 'p':
			plava++;
			break;
			case 'P':
			plava++;
			break;
			case 's':
			siva++;
			break;
			case 'S':
			siva++;
			break;
			case 'v':
			crvena++;
			break;
			case 'V':
			crvena++;
			break;
			case 'b':
			bijela++;
			break;
			case 'B':
			bijela++;
			break;
			default:
			printf("Neispravan unos\n");
			continue;
			break;
		}
		broj_auta++;
	
	}
	printf("Ukupno evidentirano %d vozila.\n", broj_auta);
	if(crvena>crna && crvena>bijela && crvena>=crna && crvena>siva){
		max=crvena;
		help=0;
	}
	if(crna>=bijela && crna>=plava && crna>=crvena && crna>=siva){
		max=crna;
		help=1;
		}
	if(bijela>crna && bijela>=siva && bijela>=crvena && bijela>=plava){
		help=2;
		max=bijela;
	}
	if(siva>crna && siva>bijela && siva>=plava && siva>=crvena){
		max=siva;
		help=3;
	}
	if(plava>crna && plava>crvena && plava>siva && plava>bijela){
		help=4;
		max=plava;
	}
	switch(help){
		case 0:
		if(broj_auta==0)
		printf("Najpopularnija boja je crvena (0.00%%).");
		else printf("Najpopularnija boja je crvena (%.2f%%).", (float)max/broj_auta*100);
		break;
		case 1:
		if(broj_auta==0)
		printf("Najpopularnija boja je crna (0.00%%).");
		else printf("Najpopularnija boja je crna (%.2f%%).", (float)max/broj_auta*100);
		break;
		case 2:
		if(broj_auta==0)
		printf("Najpopularnija boja je bijela (0.00%%).");
		else printf("Najpopularnija boja je bijela (%.2f%%).", (float)max/broj_auta*100);
		break;
		case 3:
		if(broj_auta==0)
		printf("Najpopularnija boja je siva (0.00%%).");
		else printf ("Najpopularnija boja je siva (%.2f%%).", (float)max/broj_auta*100);
		break;
		case 4:
		if(broj_auta==0)
		printf("Najpopularnija boja je plava (0.00%%).");
		else printf("Najpopularnija boja je plava (%.2f%%).", (float)max/broj_auta*100);
		break;
	}
	return 0;
}
