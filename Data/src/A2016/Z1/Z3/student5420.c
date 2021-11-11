#include <stdio.h>

int main() {
	int br_crnih=0,br_bijelih=0,br_sivih=0,br_crvenih=0,br_plavih=0,br_vozila=0;
	char simbol;
	printf("Unesite vozila: ");
	for(;;) {
		scanf("%c", &simbol);
		if(simbol==67 || simbol==99)
		br_crnih++;
		if(simbol==66 || simbol==98)
		br_bijelih++;
		if(simbol==83 || simbol==115)
		br_sivih++;
		if(simbol==86 || simbol==118)
		br_crvenih++;
		if(simbol==80 || simbol==112)
		br_plavih++;
		if(simbol!=75 && simbol!=107 && simbol!=80 && simbol!=112 && simbol!=86 && simbol!=118 &&
	    simbol!=83 && simbol!=115 && simbol!=66 && simbol!=98 && simbol!=67 && simbol!=99) {
	   	printf("Neispravan unos\n");
	   	continue;
	    }
		if(simbol==75 || simbol==107)
		break;
		br_vozila++;
	}
		printf("Ukupno evidentirano %d vozila.\n", br_vozila);
		if(br_vozila==0) {
		    printf("Najpopularnija boja je crna (0.00%%).");
		    return 0;
		}
		if(br_crnih>=br_bijelih && br_crnih>=br_sivih && br_crnih>=br_crvenih && br_crnih>=br_plavih) 
			printf("Najpopularnija boja je crna (%.2f%%).", (double)br_crnih*100/br_vozila);
		if(br_bijelih>br_crnih && br_bijelih>=br_sivih && br_bijelih>=br_crvenih && br_bijelih>=br_plavih)
			printf("Najpopularnija boja je bijela (%.2f%%).", (double)br_bijelih*100/br_vozila);
		if(br_sivih>br_crnih && br_sivih>br_bijelih && br_sivih>=br_crvenih && br_sivih>=br_plavih)
			printf("Najpopularnija boja je siva (%.2f%%).", (double)br_sivih*100/br_vozila);
		if(br_crvenih>br_crnih && br_crvenih>br_bijelih && br_crvenih>br_sivih && br_crvenih>=br_plavih)
			printf("Najpopularnija boja je crvena (%.2f%%).", (double)br_crvenih*100/br_vozila);
		if(br_plavih>br_crnih && br_plavih>br_bijelih && br_plavih>br_sivih && br_plavih>br_crvenih) 
			printf("Najpopularnija boja je plava (%.2f%%).", (double)br_plavih*100/br_vozila);
	return 0;
}
