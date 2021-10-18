#include <stdio.h>

int main() {
	
	char vozila;
	float brojacVozila = 0, brojacCrna = 0, brojacPlava = 0, brojacCrvena=0, brojacSiva=0, brojacBijela=0, max;
	float postotak;
	
	
	printf("Unesite vozila: ");
	
	while(1) {
		
		
		scanf("%c", &vozila);
		
		
		if(vozila == 'k' || vozila == 'K') break;
		if(vozila == 'c' || vozila == 'C' || vozila == 'b' || vozila == 'B' || vozila == 's' ||vozila == 'S' || vozila == 'v' || vozila == 'V' || vozila == 'p' ||vozila == 'P' ) brojacVozila++; else printf("Neispravan unos\n");
		if(vozila == 'c' || vozila == 'C') brojacCrna++;
		if(vozila == 'b' || vozila == 'B') brojacBijela++;
		if(vozila == 's' ||vozila == 'S') brojacSiva++;
		if(vozila == 'v' || vozila == 'V') brojacCrvena++;
		if(vozila == 'p' ||vozila == 'P') brojacPlava++;
		
	}
	
	printf("Ukupno evidentirano %.f vozila.\n", brojacVozila);

	max = brojacCrna;
	if(brojacBijela > max) max = brojacBijela;
	if(brojacCrvena > max) max = brojacCrvena;
	if(brojacSiva > max) max = brojacSiva;
	if(brojacPlava > max) max = brojacPlava;
	
	if(brojacVozila == 0) { printf("Najpopularnija boja je crna (0.00%)."); return 0; }
	

		if (max ==brojacCrna) {
			
			postotak = (brojacCrna * 100 ) / brojacVozila;
			printf("Najpopularnija boja je crna (%.2f%%).", postotak);
			return 0;
		}
		
		if (max == brojacBijela) {
		
			postotak = (brojacBijela / brojacVozila) * 100; 
			printf("Najpopularnija boja je bijela (%.2f%%).", postotak);
			return 0;
			}
			
			if(max == brojacSiva) {
			postotak = (brojacSiva / brojacVozila) * 100;
			printf("Najpopularnija boja je siva (%.2f%%). ", postotak);
			return 0;
			}
		
		if (max==brojacCrvena) {
			postotak = (brojacCrvena / brojacVozila) * 100;
			printf("Najpopularnija boja je crvena (%.2f%%). ", postotak);return 0;
			}
		
		
		if(max == brojacPlava) {
			postotak = (brojacPlava / brojacVozila) * 100;
			printf("Najpopularnija boja je plava (%.2f%%). ", postotak);
			return 0;
			}
	
	

	return 0;
}
