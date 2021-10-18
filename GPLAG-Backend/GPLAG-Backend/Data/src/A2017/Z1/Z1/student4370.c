#include <stdio.h>


int main() {
	float cijenaR=0,cijenaF=0,cijenaB=0,cijena;
	float brP = 0, brH = 0, brC = 0;
	float popustP,popustH,popustC,popust;
	char tarik,bojan,mirza,novi_red,izbor;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	switch(tarik){
		case 'P' : cijenaR+=6.8; cijenaF+=8.0; cijenaB+=5.3; brP++; break;
		case 'H' : cijenaR+=3.3; cijenaF+=3.0; cijenaB+=5.0; brH++; break;
		case 'C' : cijenaR+=5.0; cijenaF+=3.9; cijenaB+=6.0; brC++; break;
	}
	switch(bojan){
		case 'P' : cijenaR+=6.8; cijenaF+=8.0; cijenaB+=5.3; brP++; break;
		case 'H' : cijenaR+=3.3; cijenaF+=3.0; cijenaB+=5.0; brH++; break;
		case 'C' : cijenaR+=5.0; cijenaF+=3.9; cijenaB+=6.0; brC++; break;
	}
	switch(mirza){
		case 'P' : cijenaR+=6.8; cijenaF+=8.0; cijenaB+=5.3; brP++; break;
		case 'H' : cijenaR+=3.3; cijenaF+=3.0; cijenaB+=5.0; brH++; break;
		case 'C' : cijenaR+=5.0; cijenaF+=3.9; cijenaB+=6.0; brC++; break;
	}
	popustP = 0.1*6.8*brP;
	popustH = 0.1*3.3*brH;
	popustC = 0.1*5.0*brC;
	if(popustP > popustH && popustP > popustC) popust = popustP;
	else if(popustH > popustP && popustH > popustC) popust = popustH;
	else popust = popustC;
	if(cijenaR < cijenaB && cijenaR < cijenaF) izbor = 'R';
	else if(cijenaF < cijenaR && cijenaF < cijenaB) izbor = 'F';
	else izbor = 'B';
	switch(izbor){
		case 'R' : {
			cijena = cijenaR;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",cijena);
			break;
		}
		case 'F' : {
			cijena = cijenaF;
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena);
			break;
		}
		case 'B' : {
			cijena = cijenaB;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena);
			break;
		}
	}
	if(((cijenaR-popust)<cijena)&&izbor!='R'){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijenaR-popust);
	}
	return 0;
}