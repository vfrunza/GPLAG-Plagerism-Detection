#include <stdio.h>
#define bigNumber 9999

int main() {
	int crna = 0, bijela = 0, siva = 0, crvena = 0, plava = 0, boja;
	int indeksCrne = bigNumber, indeksBijele = bigNumber, indeksSive = bigNumber, indeksCrvene = bigNumber, indeksPlave = bigNumber;
	int sumaVozila = 0, i = 0;
	char slovo;
	printf("Unesite vozila: ");
	while(1){
		slovo = getchar();
		if(slovo == 'c' || slovo == 'C') {
			crna++;
			if(indeksCrne == bigNumber) indeksCrne = i;
		}
		else if(slovo == 'b' || slovo == 'B') {
			bijela++;
			if(indeksBijele == bigNumber) indeksBijele = i;
		}
		else if(slovo == 's' || slovo == 'S') {
			siva++;
			if(indeksSive == bigNumber) indeksSive = i;
		}
		else if(slovo == 'v' || slovo == 'V') {
			crvena++;
			if(indeksCrvene == bigNumber) indeksCrvene = i;
		}
		else if(slovo == 'p' || slovo == 'P') {
			plava++;
			if(indeksPlave == bigNumber) indeksPlave = i;
		}
		else if(slovo == 'k' || slovo == 'K') break;
		else printf("Neispravan unos\n");
		i++;
	}
	sumaVozila = crna + bijela + siva + crvena + plava;
	printf("Ukupno evidentirano %d vozila.\n", sumaVozila);
	printf("Najpopularnija boja je ");
	
	if(crna > bijela && crna > siva && crna > crvena && crna > plava){
		printf("crna");
		boja = crna;
	}
	else if(bijela > crna && bijela > siva && bijela > crvena && bijela > plava){
		printf("bijela");
		boja = bijela;
	}
	else if(siva > crna && siva > bijela && siva > crvena && siva > plava){
		printf("siva");
		boja = siva;
	}
	else if(crvena > crna && crvena > bijela && crvena > siva && crvena > plava){
		printf("crvena");
		boja = crvena;
	}
	else if(plava > crna && plava > bijela && plava > siva && plava > crvena){
		printf("plava");
		boja = plava;
	}
	else if(indeksCrne < indeksBijele && indeksCrne < indeksSive && indeksCrne < indeksCrvene && indeksCrne < indeksPlave &&
			crna >= bijela && crna >= siva && crna >= crvena && crna >= plava){
				printf("crna"); 
				boja = crna; 
	}
	else if(indeksBijele< indeksCrne && indeksBijele < indeksSive && indeksBijele < indeksCrvene && indeksBijele < indeksPlave &&
			bijela >= crna && bijela >= siva && bijela >= crvena && bijela >= plava){
				printf("bijela"); 
				boja = bijela; 
	}
	else if(indeksSive < indeksBijele && indeksSive < indeksCrne && indeksSive < indeksCrvene && indeksSive < indeksPlave &&
			siva >= bijela && siva >= crna && siva >= crvena && siva >= plava){
				printf("siva"); 
				boja = siva; 
	}
	else if(indeksCrvene < indeksBijele && indeksCrvene < indeksSive && indeksCrvene < indeksCrne && indeksCrvene < indeksPlave &&
			crvena >= bijela && crvena >= siva && crvena >= crna && crvena >= plava){
				printf("crvena"); 
				boja = crvena; 
	}
	else if(indeksPlave < indeksBijele && indeksPlave < indeksSive && indeksPlave < indeksCrvene && indeksPlave < indeksCrne &&
			plava >= bijela && plava >= siva && plava >= crvena && plava >= crna){
				printf("plava");
				boja = plava; 
	}
	
	float procenat = 0.;
	if(sumaVozila != 0) procenat = ((float)boja / (float)sumaVozila) * 100.;
	else printf("crna");
	printf(" (%.2f%%).", procenat);
	/*
	printf("\nindeksCrna = %d", indeksCrne);
	printf("\nindeksBijela = %d", indeksBijele);
	printf("\nindeksSiva = %d", indeksSive);
	printf("\nindeksCrvena = %d", indeksCrvene);
	printf("\nindeksPlave = %d", indeksPlave);
	*/
	return 0;
}
