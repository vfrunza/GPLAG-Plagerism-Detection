#include <stdio.h>

int main()
{

	char T,B,M;
	int NH=0,NP=0,NC=0;

	/*Restoran "Kod konja i konjušara"*/
	float P1=6.8,H1=3.3,C1=5.0;
	char R1[] = "Restoran \"Kod konja i konjusara\"";

	/*Fast-food "Trovač"*/
	float P2=8.0,H2=3.0,C2=3.9;
	char R2[] = "Fast-food \"Trovac\"";

	/*Bistro "Lorelei"*/
	float P3=5.3,H3=5.0,C3=6.0;
	char R3[] = "Bistro \"Lorelei\"";

	printf("Unesite jelo za Tarika: ");
	scanf(" %c",&T);
	if(T=='H') NH++;
	else if(T=='P') NP++;
	else if(T=='C')NC++;
	printf("Unesite jelo za Bojana: ");
	scanf(" %c",&B);
	if(B=='H') NH++;
	else if(B=='P') NP++;
	else if(B=='C')NC++;
	printf("Unesite jelo za Mirzu: ");
	scanf(" %c",&M);
	if(M=='H') NH++;
	else if(M=='P') NP++;
	else if(M=='C')NC++;

	if(NH==3) {
		printf("Najjeftiniji je %s (%.2f KM).\n",R2,3*H2);
		if(3*(H1-H1*0.1)<3*H2)
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",3*(H1-H1*0.1));
	}

	else if(NP==3)
		printf("Najjeftiniji je %s (%.2f KM).\n",R3,3*P3);

	else if(NC==3)
		printf("Najjeftiniji je %s (%.2f KM).\n",R2,3*C2);

	else if(NH==2 && NP==1)
		printf("Najjeftiniji je %s (%.2f KM).\n",R1,2*H1+P1);

	else if(NH==2 && NC==1)
		printf("Najjeftiniji je %s (%.2f KM).\n",R2,2*H2+C2);

	else if(NP==2 && NH==1) {
		printf("Najjeftiniji je %s (%.2f KM).\n",R3,2*P3+H3);
		if(2*(P1-P1*0.1)+H1<2*P3+H3)
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",2*(P1-P1*0.1)+H1);
	}

	else if(NP==2 && NC==1)
		printf("Najjeftiniji je %s (%.2f KM).\n",R3,2*P3+C3);

	else if(NC==2 && NH==1)
		printf("Najjeftiniji je %s (%.2f KM).\n",R2,2*C2+H2);

	else if(NC==2 && NP==1)
		printf("Najjeftiniji je %s (%.2f KM).\n",R2,2*C2+P2);

	else if(NC==1 && NP==1 && NH==1) {
		printf("Najjeftiniji je %s (%.2f KM).\n",R2,H2+C2+P2);
		if(C1+H1+(P1-P1*0.1)<C2+P2+H2)
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",C1+H1+(P1-P1*0.1));
	}
	return 0;
}
