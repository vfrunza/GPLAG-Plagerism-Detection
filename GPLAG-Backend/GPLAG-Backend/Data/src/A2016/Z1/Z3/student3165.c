#include <stdio.h>

int main() {
	char vozila;
	int br_crna = 0;
	int br_bijela = 0;
	int br_siva = 0;
	int br_crvena = 0;
	int br_plava = 0;
	int ukupno = 0;
	float udio_crna = 0;
	float udio_siva = 0;
	float udio_plava = 0;
	float udio_crvena = 0;
	float udio_bijela = 0;
	
	printf ("Unesite vozila: ");
	
	while (1) {
		scanf ("%c", &vozila);
		if (vozila == 'C' || vozila == 'c'){
			br_crna++; ukupno++;
		}
		else if (vozila == 'B' || vozila == 'b'){
			br_bijela++; ukupno++;
		}
		else if (vozila == 'S' || vozila == 's'){
			br_siva++; ukupno++;
		}
		else if (vozila == 'v' || vozila == 'V'){
			br_crvena++; ukupno++;
		}
		else if  (vozila == 'p' || vozila == 'P'){
			br_plava++; 
			ukupno++;
		}
		else if	(vozila == 'k' || vozila == 'K'){
			break;
		}
		else printf ("Neispravan unos\n");
	}
	udio_bijela += (br_bijela/(float)ukupno)*100.0;
	udio_crvena += (br_crvena/(float)ukupno)*100.0;
	udio_plava += (br_plava/(float)ukupno)*100.0;
	udio_siva += (br_siva/(float)ukupno)*100.0;
	udio_crna += (br_crna/(float)ukupno)*100.0;
		printf ("Ukupno evidentirano %d vozila.", ukupno);
	if(br_crna > 0 && br_crna >= br_siva && br_crna >= br_plava && br_crna >= br_crvena && br_crna >= br_bijela) {
		printf("\nNajpopularnija boja je crna (%.2f%%).", udio_crna);
	}
	else if(br_bijela > br_crna && br_bijela >= br_crvena && br_bijela >= br_plava && br_bijela >= br_siva) {
		printf("\nNajpopularnija boja je bijela (%.2f%%).", udio_bijela);
	}
	else if(br_siva > br_crna && br_siva > br_bijela && br_siva >= br_crvena && br_siva >= br_plava) {
		printf("\nNajpopularnija boja je siva (%.2f%%).", udio_siva);
	}
	else if(br_crvena > br_crna && br_crvena > br_bijela && br_crvena > br_siva && br_crvena >= br_plava) {
		printf("\nNajpopularnija boja je crvena (%.2f%%).", udio_crvena);
	}
	else if(br_plava > br_crna && br_plava > br_bijela && br_plava > br_crvena && br_plava > br_siva) {
		printf("\nNajpopularnija boja je plava (%.2f%%).", udio_plava);
	}
	else if(br_crna==0 && br_crvena==0 && br_siva==0 && br_plava==0 && br_bijela==0) {
		printf("\nNajpopularnija boja je crna (0.00%%).");
	}
	return 0;
}
