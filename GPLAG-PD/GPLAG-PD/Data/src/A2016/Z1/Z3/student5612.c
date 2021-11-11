#include <stdio.h>
/*U-udio;S-suma*/
int main() {
	char boje;
	int crna = 0, bijela = 0, siva = 0, crvena = 0, plava = 0;
	int max;
	float U,S;
	printf("Unesite vozila: ");
	do {
		scanf("%c", &boje);
		if(boje == 'c' || boje == 'b' || boje == 's' || boje == 'v' || boje == 'p' || boje == 'C' || boje == 'B' || boje == 'S' || boje == 'V' || boje == 'P' || boje == 'k' || boje == 'K' ){
			if (boje == 'c' || boje == 'C'){
				crna = crna + 1;
			}else if (boje == 'b' || boje == 'B'){
				bijela = bijela + 1;
			}else if (boje == 's' || boje == 'S'){
				siva = siva + 1;
			}else if(boje == 'v' || boje == 'V'){
				crvena = crvena + 1;
			}else if (boje == 'p' || boje == 'P'){
				plava = plava + 1;
			}
		}
		else if (boje != 'c' && boje != 'C' && boje != 'b' && boje != 'B' && boje != 's' && boje != 'S' && boje != 'V' && boje != 'v' && boje != 'p' && boje != 'P' && boje != 'k' && boje != 'K'){
			printf("Neispravan unos\n");
		}
	}
	while (boje != 'k' && boje != 'K');
	S = crna + bijela + siva + crvena + plava;
	max = plava;
	if(crna > max){
		max = crna;
	}if(bijela > max){
		max = bijela;
	}if(siva > max){
		max = siva;
	}if (crvena > max){
		max = crvena;
	}
	U = max*100/S;
	if (S == 0){
		printf("Ukupno evidentirano 0 vozila.\n");
		
			printf("Najpopularnija boja je crna (0.00%%).\n");
	}
	else{
		printf("Ukupno evidentirano %g vozila.\n", S);
		if(crna == max){
			printf("Najpopularnija boja je crna (%.2f%%).\n", U);
		}else if (bijela == max){
			printf("Najpopularnija boja je bijela (%.2f%%).\n", U);
		}else if (siva == max){
			printf("Najpopularnija boja je siva (%.2f%%).\n", U);
		}else if (crvena == max){
			printf("Najpopularnija boja je crvena (%.2f%%).\n", U);
		}else if (plava == max){
			printf("Najpopularnija boja je plava (%.2f%%).\n", U);
		}
	}
	
	return 0;
}
