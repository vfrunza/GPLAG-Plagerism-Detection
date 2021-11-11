#include <stdio.h>
#include <stdlib.h>

int main() {
	int slova=0, brojacc=0, brojacb=0, brojacs=0, brojacv=0, brojacp=0;
	float crna=0, bijela=0, siva=0, crvena=0, plava=0;
	char vozila=' ';
	printf("Unesite vozila: ");
	while(1){
		scanf("%c", &vozila);
		if(vozila=='k' || vozila=='K') break;
		else if(vozila=='c' || vozila=='C') brojacc++;
		else if(vozila=='b' || vozila=='B') brojacb++;
		else if(vozila=='s' || vozila=='S') brojacs++;
		else if(vozila=='v' || vozila=='V') brojacv++;
		else if(vozila=='p' || vozila=='P') brojacp++;
		else printf("Neispravan unos\n");
	}
	slova = brojacp + brojacv + brojacc + brojacs + brojacb;
	printf("Ukupno evidentirano %d vozila.\n", slova);
	//printf("%d %d %d %d %d", brojacc, brojacb, brojacs, brojacv, brojacp);
	crna = ((float)brojacc/slova)*100;
	bijela = ((float)brojacb/slova)*100;
	siva = ((float)brojacs/slova)*100;
	crvena = ((float)brojacv/slova)*100;
	plava = ((float)brojacp/slova)*100;
	if (crna>=bijela && crna>=siva && crna>=crvena && crna>=plava) printf("Najpopularnija boja je crna (%.2f%%).", crna);
	else if (bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava) printf("Najpopularnija boja je bijela (%.2f%%).", bijela);
	else if (siva>=crna && siva>=bijela && siva>=crvena && siva>=plava) printf("Najpopularnija boja je siva (%.2f%%).", siva);
	else if (crvena>=crna && crvena>=bijela && crvena>=plava && crvena>=siva) printf("Najpopularnija boja je crvena (%.2f%%).", crvena);
	else if (plava>=crna && plava>=bijela && plava>=crvena && plava>=siva) printf ("Najpopularnija boja je plava (%.2f%%).", plava);
	else printf("Najpopularnija boja je crna (0.00%).");
	return 0;
}
