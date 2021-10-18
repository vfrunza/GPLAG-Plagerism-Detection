#include <stdio.h>

int main() {
	double ppT, ppB, ppM;
	double dpT, dpB, dpM;
	double pT, pB, pM;
	double zT, zB, zM;
	double ziT, ziB, ziM;
	int oT,oB,oM;
	double zbirT, zbirB, zbirM;
	printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
	scanf("%lf", &ppT);
	if(ppT<0 || ppT>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &dpT);
	if(dpT<0 || dpT>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &pT);
	if(pT<0 || pT>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zT);
	if(zT<0 || zT>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ziT);
	if(ziT<0 || ziT>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
	scanf("%lf", &ppB);
	if(ppB<0 || ppB>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &dpB);
	if(dpB<0 || dpB>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &pB);
	if(pB<0 || pB>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zB);
	if(zB<0 || zB>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ziB);
	if(ziB<0 || ziB>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
	scanf("%lf", &ppM);
	if(ppM<0 || ppM>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &dpM);
	if(dpM<0 || dpM>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &pM);
	if(pM<0 || pM>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zM);
	if(zM<0 || zM>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ziM);
	if(ziM<0 || ziM>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	zbirT=ppT+dpT+pT+zT+ziT;
	
	zbirB=ppB+dpB+pB+zB+ziB;
	
	zbirM=ppM+dpM+pM+zM+ziM;
if(zbirT<55){
	oT=5;
}
if(zbirB<55){
	oB=5;
}
if(zbirM<55){
	oM=5;
}
if(zbirT>=55 && zbirT<65){
	oT=6;
}
if(zbirB>=55 && zbirB<65){
	oB=6;
}
if(zbirM>=55 && zbirM<65){
	oM=6;
}
if(zbirT>=65 && zbirT<75){
	oT=7;
}
if(zbirB>=65 && zbirB<75){
	oB=7;
}
if(zbirM>=65 && zbirM<75){
	oM=7;
}
if(zbirT>=75 && zbirM<85){
	oT=8;
}
if(zbirB>=75 && zbirM<85){
	oB=8;
}
if(zbirM>=75 && zbirM<85){
	oM=8;
}
if(zbirT>=85 && zbirM<92){
	oT=9;
}
if(zbirB>=85 && zbirB<92){
	oB=9;
}
if(zbirM>=85 && zbirM<92){
	oM=9;
}
 if(zbirT>=92 && zbirT<=100){
	oT=10;
}
if(zbirB>=92 && zbirB<=100){
	oB=10;
}
if(zbirM>=92 && zbirM<=100){
	oM=10;
}

if(oT>=6 && oB>=6 && oM>=6){
	printf("Sva tri studenta su polozila.\n");
}
if((oT<6 && oB>=6 && oM>=6) || (oT>=6 && oB>=6 && oM<6) || (oT>=6 && oB<6 && oM>=6)){
	printf("Dva studenta su polozila.\n");
}
if((oT<6 && oB<6 && oM>=6) || (oT<6 && oB>=6 && oM<6) || (oT>=6 && oB<6 && oM<6)){
	printf("Jedan student je polozio.\n");
}
if(oT<6 && oB<6 && oM<6) {
	printf("Nijedan student nije polozio.\n");
}
if((oT==oB && oT!=oM && oB!=oM && oT>5) || (oT!=oB && oT!=oM && oB==oM && oB>5) || (oT!=oB && oB!=oM && oT==oM && oT>5)){
	printf("Dva od tri studenta imaju istu ocjenu.\n");
}
if(oT==oB && oT==oM && oB==oM  && oT>5 && oB>5 && oM>5){
	printf("Sva tri studenta imaju istu ocjenu.\n");
}
 if(oT!=oB && oT!=oM && oB!=oM && oT>5 && oM>5 && oB>5){
	printf("Svaki student ima razlicitu ocjenu.\n");
}

	return 0;
}
