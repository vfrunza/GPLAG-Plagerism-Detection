#include <stdio.h>
#define P1 6.8
#define P2 8.0
#define P3 5.3
#define H1 3.3
#define H2 3.0
#define H3 5.0
#define C1 5.0
#define C2 3.9
#define C3 6.0
int main() {
	int brP=0,brH=0,brC=0;
	float cijenaR=0,cijenaFF=0,cijenaB=0,cijenaspopustom,PP1,CP1,HP1;
	char tarik,bojan,mirza,novired;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novired);
	if(tarik=='H') brH++;
	else if(tarik=='P') brP++;
	else if(tarik=='C') brC++;
	else {
	printf("Pogresan unos");
	return 1;
	}
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novired);
	if(bojan=='H') brH++;
	else if(bojan=='P') brP++;
	else if(bojan=='C') brC++;
	else {
	printf("Pogresan unos");
	return 1;
	}
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novired);
	if(mirza=='H') brH++;
	else if(mirza=='P') brP++;
	else if(mirza=='C') brC++;
	else {
	printf("Pogresan unos");
	return 1;
	}
	cijenaR=brP*P1+brH*H1+brC*C1;
	cijenaFF=brP*P2+brH*H2+brC*C2;
	cijenaB=brP*P3+brH*H3+brC*C3;
	if(brP!=0 && (brH!=0 ||brH==0) && (brC!=0 || brC==0)) {
		PP1=0.9*P1;
		cijenaspopustom=brP*PP1+brH*H1+brC*C1;
	}
	if(brP==0 && (brH!=0 || brH==0) && brC!=0) {
		CP1=0.9*C1;
	    cijenaspopustom=brP*P1+brH*H1+brC*CP1;
	}
	if(brP==0 && brC==0 && brH!=0) {
		HP1=0.9*H1;
		cijenaspopustom=brP*P1+brH*HP1+brC*C1;
	}
	if(cijenaR<cijenaFF && cijenaR<cijenaB) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",cijenaR);
		return 0;
	}
	if(cijenaR>cijenaFF && cijenaFF<cijenaB) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijenaFF);
		if(cijenaspopustom<cijenaFF) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijenaspopustom);
		}
		return 0;
	}
	if(cijenaB<cijenaR && cijenaB<cijenaFF) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijenaB);
		if(cijenaspopustom<cijenaB) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijenaspopustom);
		}
		return 0;
		}
	return 0;
}
