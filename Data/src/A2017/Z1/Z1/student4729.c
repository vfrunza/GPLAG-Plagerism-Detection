#include <stdio.h>
#include <math.h>
#define P 5.30
#define H 3.00
#define C 3.90
#define P1 6.12
#define H1 2.97
#define C1 4.50
#define PK 6.80
#define CK 5.00
#define HK 3.30
#define PT 8.00
#define HL 5.00
#define CL 6.00



int main()
{
	char tarik, bojan, mirza, novi_red;
	double R,K;


	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &tarik);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &bojan);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &mirza);
	scanf ("%c", &novi_red);

	if (tarik==bojan && bojan==mirza) {

		if (bojan=='P') {
			R=3*P;
			K=2*PK + P1;
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",R);
			if (K<R) {
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",K);
			}
		}

		else if (bojan=='H') {
			R=3*H;
			K=3*H1;
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",R);
			if(K<R) {
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",K);
			}
		}

		else if (bojan=='C') {
			R=3*C;
			K=2*CK + C1;
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",R);
			if (K<R) {
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",K);
			}
		}

	}

	else if ((tarik==bojan && tarik=='P' && mirza=='H') || (tarik==mirza && mirza=='P' && bojan=='H') || (bojan==mirza && mirza=='P' && tarik=='H')) {

		R=2*P+HL;
		K=P1+ P1 +HK;
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",R);
		if (K<R){
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",K);
		
	}}

	else if ((tarik==bojan && tarik=='H' && mirza=='P') || (tarik==mirza && mirza=='H' && bojan=='P') || (bojan==mirza && mirza=='H' && tarik=='P')) {
		R=2*HK + PK;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R);
	}
	else if ((tarik==bojan && tarik=='P' && mirza=='C') || (tarik==mirza && mirza=='P' && bojan=='C') || (bojan==mirza && mirza=='P' && tarik=='C')) {
		R=2*P+CL;
		K=P1 + PK +CK;
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",R);
		if(K<R) {
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",K);
		}
	}
	else if ((tarik==bojan && tarik>='H' && mirza=='C')|| (tarik==mirza && mirza=='H' && bojan=='C')|| (bojan==mirza && mirza=='H' && tarik=='C')) {
		R=2*H+C;
		K=CK + H1 +HK;
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",R);
		if (K<R) {
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",K);
		}
	}
	else if ((tarik==bojan && tarik>='C' && mirza=='P')|| (tarik==mirza && mirza=='C' && bojan=='P')|| (bojan==mirza && mirza=='C' && tarik=='P')) {
		R=2*C+PT;
		K=C1 + CK+PK;
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",R);
		if (K<R) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",K);
		}
	}
	else if ((tarik==bojan && tarik=='C' && mirza=='H')|| (tarik==mirza && mirza=='C' && bojan=='H')|| (bojan==mirza && mirza=='C' && tarik=='H')) {
	R=2*C+H;
	K=C1+CK+HK;
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",R);
		if (K<R) {
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",K);

		}
	}
	else if ((tarik>='P' && bojan=='H' && mirza=='C')||(tarik=='H' && bojan=='P' && mirza=='C')|| (tarik=='C' && bojan=='P' && mirza=='H')|| (tarik=='P' && bojan=='C' && mirza=='H')|| (tarik=='H' && bojan=='C' && mirza=='P')|| (tarik=='C' && bojan=='H' && mirza=='P')) {
	
	R=PT+H+C;
	K=P1+CK+HK;
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",R);
		if (K<R) {
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", K);
		}
	}



	return 0;
}
