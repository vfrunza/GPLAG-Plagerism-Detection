#include <stdio.h>

/* RESTORAN CIJENE */
#define REST_P 6.8
#define REST_H 3.3
#define REST_C 5.0

/* FAST-FOOD CIJENE */
#define FAST_P 8.0
#define FAST_H 3.0
#define FAST_C 3.9

/* BISTRO */
#define BIST_P 5.3
#define BIST_H 5.0
#define BIST_C 6.0

int main() {
	char unos, ws;
	double rest = 0.0, fast = 0.0, bist = 0.0;
	double rest_disc = 0.0;
	int PCount = 0, HCount = 0, CCount = 0, i;
	
	for (i = 0; i < 3; i++) {
		printf("Unesite jelo za ");
		
		switch(i) {
			case 0:
				printf("Tarika: ");
				break;
			case 1:
				printf("Bojana: ");
				break;
			case 2:
				printf("Mirzu: ");
				break;
		}
		
		scanf("%c%c", &unos, &ws);
		switch(unos) {
			case 'P':
				rest += REST_P;
				fast += FAST_P;
				bist += BIST_P;
				PCount++;
				break;
			case 'H':
				rest += REST_H;
				fast += FAST_H;
				bist += BIST_H;
				HCount++;
				break;
			case 'C':
				rest += REST_C;
				fast += FAST_C;
				bist += BIST_C;
				CCount++;
				break;
		}
	}
	
	rest_disc = (PCount * REST_P > HCount * REST_H) ? (PCount * REST_P) : (HCount * REST_H);
	rest_disc = (rest_disc < CCount * REST_C) ? (CCount * REST_C) : rest_disc;
	rest_disc = rest - rest_disc * 0.1;
	
	printf("Najjeftiniji je ");
	if (rest < fast && rest < bist)
		printf("Restoran \"Kod konja i konjusara\" (%.2f KM).\n", rest);
	else if (fast < rest && fast < bist) {
		printf("Fast-food \"Trovac\" (%.2f KM).\n", fast);
		if (rest_disc < fast)
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", rest_disc);
	}
	else {
		printf("Bistro \"Lorelei\" (%.2f KM).\n", bist);
		if (rest_disc < bist)
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", rest_disc);
	}
	
	return 0;
}
