#include <stdio.h>

int main() {
	float tarik, tarik1, tarik2, tarikp, tarikz, tarikk, bojan, bojan1, bojan2, bojanp, bojanz, bojank, mirza, mirza1, mirza2, mirzap, mirzaz, mirzak;
	int ocjenat=5, ocjenab=5, ocjenam=5;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &tarik1);
	if(tarik1<0 || tarik1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &tarik2);
	if(tarik2<0 || tarik2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &tarikp);
	if(tarikp<0 || tarikp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &tarikz);
	if(tarikz<0 || tarikz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &tarikk);
	if(tarikk<0 || tarikk>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &bojan1);
	if(bojan1<0 || bojan1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &bojan2);
	if(bojan2<0 || bojan2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &bojanp);
	if(bojanp<0 || bojanp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &bojanz);
	if(bojanz<0 || bojanz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &bojank);
	if(bojank<0 || bojank>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &mirza1);
	if(mirza1<0 || mirza1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &mirza2);
	if(mirza2<0 || mirza2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &mirzap);
	if(mirzap<0 || mirzap>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &mirzaz);
	if(mirzaz<0 || mirzaz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &mirzak);
	if(mirzak<0 || mirzak>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	tarik = (float) (tarikk + tarikz + tarikp + tarik2 + tarik1);
	bojan = (float) (bojank + bojanz + bojanp + bojan2 + bojan1);
	mirza = (float) (mirzak + mirzaz + mirzap + mirza2 + mirza1);
	
	if(tarik>=55 && tarik<65) ocjenat = 6;
	else if (tarik>=65 && tarik<75) ocjenat = 7;
	else if (tarik>=75 && tarik<85) ocjenat = 8;
	else if (tarik>=85 && tarik<92) ocjenat = 9;
	else if (tarik>=92) ocjenat = 10;
	if (bojan>=55 && bojan<65) ocjenab = 6;
	else if (bojan>=65 && bojan<75) ocjenab = 7;
	else if (bojan>=75 && bojan<85) ocjenab = 8;
	else if (bojan>=85 && bojan<92) ocjenab = 9;
	else if (bojan>=92) ocjenab = 10;
	if (mirza>=55 && mirza<65) ocjenam = 6;
	else if (mirza>=65 && mirza<75) ocjenam = 7;
	else if (mirza>=75 && mirza<85) ocjenam = 8;
	else if (mirza>=85 && mirza<92) ocjenam = 9;
	else if (mirza>=92) ocjenam = 10;
	if(tarik<55 && bojan<55 && mirza<55) printf("Nijedan student nije polozio.");
	else if((tarik<55 && bojan<55) || (tarik<55 && mirza<55) || (bojan<55 && mirza<55)) printf("Jedan student je polozio.");
	else if(tarik<55 || bojan<55 || mirza<55) printf("Dva studenta su polozila.");
	else{
		printf("Sva tri studenta su polozila.\n");
		if(ocjenat == ocjenam && ocjenat == ocjenab) printf("Sva tri studenta imaju istu ocjenu.");
		else if( ocjenat==ocjenam || ocjenat==ocjenab || ocjenab==ocjenam) printf("Dva od tri studenta imaju istu ocjenu.");
		else printf("Svaki student ima razlicitu ocjenu.");
	}
	return 0;
}







