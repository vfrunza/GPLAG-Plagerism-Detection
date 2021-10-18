#include <stdio.h>
#include <math.h>

/*RESTORAN KOD KONJA I KONJUSARA*/
#define P1 6.80
#define H1 3.30
#define C1 5.00
/*FAST-FOOD TROVAC*/
#define P2 8.00
#define H2 3.00
#define C2 3.90
/*BISTRO LORELEI*/
#define P3 5.30
#define H3 5.00
#define C3 6.00



int main()
{
	char tarik;
	char bojan;
	char mirza;
	char P;
	char H;
	char C;
	char novi_red;

	int brojacH=0;
	int brojacP=0;
	int brojacC=0;

	float S1,S2,S3,S1P1,S1P2,S1P3;

	P='P';
	H='H';
	C='C';

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);

	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);

	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);

	switch(tarik) {
	case 'H':
		brojacH++;
		break;

	case 'P':
		brojacP++;
		break;

	case 'C':
		brojacC++;
		break;
	}

	switch(bojan) {
	case 'H':
		brojacH++;
		break;

	case 'P':
		brojacP++;
		break;

	case 'C':
		brojacC++;
		break;
	}

	switch(mirza) {
	case 'H':
		brojacH++;
		break;

	case 'P':
		brojacP++;
		break;

	case 'C':
		brojacC++;
		break;
	}

	S1 = (brojacH*H1 + brojacP*P1 + brojacC*C1);
	S2 = (brojacH*H2 + brojacP*P2 + brojacC*C2);
	S3 = (brojacH*H3 + brojacP*P3 + brojacC*C3);
	S1P1 = (0.9 * brojacH*H1 + brojacP*P1 + brojacC*C1);
	S1P2 = (brojacH*H1 + brojacP*P1 * 0.9 + brojacC*C1);
	S1P3 = (brojacH*H1 + brojacP*P1 + brojacC*C1 * 0.9);


	if((S1<S2)&&(S2<S3)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", S1);
	} else if((S2<S1)&&(S1<S3)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", S2);
		if((S1P1<S2)||(S1P2<S2)||(S1P3<S2)) {
			if((S1P1<S1P3)&&(S1P1<S1P2)) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",S1P1);
			} else if((S1P2<S1P3)&&(S1P3<S1P1)) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",S1P2);
			} else if((S1P3<S1P1)&&(S1P1<S1P2)) {
				printf("Sa popustom bi restoan bio jeftiniji (%.2f KM).\n",S1P3);
			}
		}
	} else if((S3<S1)&&(S1<S2)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",S3);
		if((S1P1<S3)||(S1P2<S3)||(S1P3<S3)) {
			if((S1P1<S1P2)&&(S1P2<S1P3)) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",S1P1);
			} else if((S1P2<S1P1)&&(S1P1<S1P3)) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",S1P2);
			} else if((S1P3<S1P2)&&(S1P2<S1P1)) {
				printf("Sa popustom bi restoan bio jeftiniji (%.2f KM).\n",S1P3);
			}
		}
	}

	return 0;
}