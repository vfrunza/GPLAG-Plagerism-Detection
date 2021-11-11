#include <stdio.h>
#include <stdlib.h>


int main()
{

	char tarik, bojan, mirza;
	char novired;
	char navodnici=34, OZ=40, ZZ=41;

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novired);

	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novired);

	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novired);
	
	if (tarik=='P' && bojan=='P' && mirza=='P') {

		printf("Najjeftiniji je Bistro %cLorelei%c %c15.90 KM%c.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='P' && bojan=='P' && mirza=='H') {

		printf("Najjeftiniji je Bistro %cLorelei%c %c15.60 KM%c\n.", navodnici, navodnici, OZ, ZZ);
			printf("Sa popustom bi Restoran bio jeftiniji %c15.54 KM%c.", OZ, ZZ);
	} else if (tarik=='P' && bojan=='P' && mirza=='C') {

		printf("Najjeftiniji je Bistro %cLorelei%c %c16.60 KM%c.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='P' && bojan=='H' && mirza=='P') {

		printf("Najjeftiniji je Bistro %cLorelei%c %c15.60 KM%c.\n", navodnici, navodnici, OZ, ZZ);
			printf("Sa popustom bi Restoran bio jeftiniji %c15.54 KM%c.", OZ, ZZ);
	} else if (tarik=='P' && bojan=='H' && mirza=='H') {

		printf("Najjeftiniji je Restoran %cKod konja i konjusara%c %c13.40 KM%c.", navodnici, navodnici, OZ, ZZ);
			printf("Sa popustom bi Restoran bio jeftiniji %c12.72 KM%c.", OZ, ZZ);
	} else if (tarik=='P' && bojan=='H' && mirza=='C') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c14.90 KM%c.\n", navodnici, navodnici, OZ, ZZ);
		printf("Sa popustom bi Restoran bio jeftiniji %c14.42 KM%c.", OZ, ZZ);
	} else if (tarik=='P' && bojan=='C' && mirza=='P') {

		printf("Najjeftiniji je Bistro %cLorelei%c %c16.60 KM%c.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='P' && bojan=='C' && mirza=='H') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c14.90 KM%c.\n",navodnici, navodnici, OZ, ZZ);
		printf("Sa popustom bi Restoran bio jeftiniji %c14.42 KM%c.", OZ, ZZ);
	} else if (tarik=='P' && bojan=='C' && mirza=='C') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c15.80 KM%c.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='H' && bojan=='P' && mirza=='P') {

		printf("Najjeftiniji je Bistro %cLorelei%c %c15.60 KM%c.\n", navodnici, navodnici, OZ, ZZ);
			printf("Sa popustom bi Restoran bio jeftiniji %c15.54 KM%c.", OZ, ZZ);
	} else if (tarik=='H' && bojan=='P' && mirza=='H') {

		printf("Najjeftiniji je Restoran %cKod konja i konjusara%c %c16.90 KM%c.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='H' && bojan=='P' && mirza=='C') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c14.90 KM%c.\n", navodnici, navodnici, OZ, ZZ);
		printf("Sa popustom bi Restoran bio jeftiniji %c14.42 KM%c.", OZ, ZZ);
	} else if (tarik=='H' && bojan=='H' && mirza=='P') {

		printf("Najjeftiniji je Restoran %cKod konja i konjusara%c %c13.40 KM%c.\n", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='H' && bojan=='H' && mirza=='H') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c9.00 KM%c.\n", navodnici, navodnici, OZ, ZZ);
		printf("Sa popustom bi Restoran bio jeftiniji %c8.91 KM%c.", OZ, ZZ);
	} else if (tarik=='H' && bojan=='H' && mirza=='C') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c9.90 KM%c.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='H' && bojan=='C' && mirza=='P') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c14.90 KM%c.\n", navodnici, navodnici, OZ, ZZ);
		printf("Sa popustom bi Restoran bio jeftiniji %c14.42 KM%c.", OZ, ZZ);	
	} else if (tarik=='H' && bojan=='C' && mirza=='H') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c9.90 KM%c.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='H' && bojan=='C' && mirza=='C') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c10.80 KM%c.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='C' && bojan=='P' && mirza=='P') {

		printf("Najjeftiniji je Bistro %cLorelei%c %c16.60 KM%c.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='C' && bojan=='P' && mirza=='H') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c14.90 KM%c.\n", navodnici, navodnici, OZ, ZZ);
		printf("Sa popustom bi Restoran bio jeftiniji %c14.42 KM%c.", OZ, ZZ);
	} else if (tarik=='C' && bojan=='P' && mirza=='C') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c15.80 KM%c.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='C' && bojan=='H' && mirza=='P') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c14.90 KM%c.\n", navodnici, navodnici, OZ, ZZ);
		printf("Sa popustom bi Restoran bio jeftiniji %c14.42 KM%c.", OZ, ZZ);	
	} else if (tarik=='C' && bojan=='H' && mirza=='H') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c9.90 KM%c.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='C' && bojan=='H' && mirza=='C') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c10.80 KM%c.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='C' && bojan=='C' && mirza=='P') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c15.80 KM')'.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='C' && bojan=='C' && mirza=='H') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c10.80 KM')'.", navodnici, navodnici, OZ, ZZ);
	} else if (tarik=='C' && bojan=='C' && mirza=='C') {

		printf("Najjeftiniji je Fast-food %cTrovac%c %c11.70 KM%c.", navodnici, navodnici, OZ, ZZ);
	}
	return 0;
}
