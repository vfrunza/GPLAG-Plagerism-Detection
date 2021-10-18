#include <stdio.h>

int main() {
	float IparcT, IparcB, IparcM, IIparcT, IIparcB, IIparcM, pT, pB, pM, zT, zB, zM, ziT, ziB, ziM, brbodT, brbodB, brbodM, ocjenaT, ocjenaB, ocjenaM;
	printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
	scanf("%f", &IparcT);
	if (IparcT<0 || IparcT>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f", &IIparcT);
	if (IIparcT<0 || IIparcT>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f", &pT);
	if (pT<0 || pT>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f", &zT);
	if (zT<0 || zT>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f", &ziT);
	if (ziT<0 || ziT>40) {printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
	scanf("%f", &IparcB);
	if (IparcB<0 || IparcB>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f", &IIparcB);
	if (IIparcB<0 || IIparcB>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f", &pB);
	if (pB<0 || pB>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f", &zB);
	if (zB<0 || zB>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f", &ziB);
	if (ziB<0 || ziB>40) {printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
	scanf("%f", &IparcM);
	if (IparcM<0 || IparcM>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f", &IIparcM);
	if (IIparcM<0 || IIparcM>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f", &pM);
	if (pM<0 || pM>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f", &zM);
	if (zM<0 || zM>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f", &ziM);
	if (ziM<0 || ziM>40) {printf("Neispravan broj bodova"); return 0;}
	
	brbodT=IparcT+IIparcT+pT+zT+ziT;
	if (brbodT<65) ocjenaT=6;
	else if (brbodT<75) ocjenaT=7;
	else if (brbodT<85) ocjenaT=8;
	else if (brbodT<92) ocjenaT=9;
	else if (brbodT<=100) ocjenaT=10;
	else return 0;
	
	brbodB=IparcB+IIparcB+pB+zB+ziB;
	if (brbodB<65) ocjenaB=6;
	else if (brbodB<75) ocjenaB=7;
	else if (brbodB<85) ocjenaB=8;
	else if (brbodB<92) ocjenaB=9;
	else if (brbodB<=100) ocjenaB=10;
	else return 0;
	
	brbodM=IparcM+IIparcM+pM+zM+ziM;
	if (brbodM<65) ocjenaM=6;
	else if (brbodM<75) ocjenaM=7;
	else if (brbodM<85) ocjenaM=8;
	else if (brbodM<92) ocjenaM=9;
	else if (brbodM<=100) ocjenaM=10;
	else return 0;
	
	if (brbodT>=0 && brbodT<55 && brbodB>=0 && brbodB<55 && brbodM>=0 && brbodM<55) {
		printf("Nijedan student nije polozio. \n");
		return 0;
	} else if ((brbodT>55 && brbodT<=100 && brbodB>=0 && brbodB<55 && brbodM>=0 && brbodM<55) || (brbodT>=0 && brbodT<55 && brbodB>55 && brbodB<=100 && brbodM>=0 && brbodM<55) || (brbodT>=0 && brbodT<55 && brbodB>=0 && brbodB<55 && brbodM>55 && brbodM<=100)) {
		printf("Jedan student je polozio. \n");
		return 0;
	} else if ((brbodT>55 && brbodT<=100 && brbodB>55 && brbodB<=100 && brbodM>=0 && brbodM<55) || (brbodT>55 && brbodT<=100 && brbodB>=0 && brbodB<55 && brbodM>55 && brbodM<=100) || (brbodT>=0 && brbodT<55 && brbodB>55 && brbodB<=100 && brbodM>55 && brbodM<=100)) {
		printf("Dva studenta su polozila. \n");
		return 0;
	} else if (brbodT>55 && brbodT<=100 && brbodB>55 && brbodB<=100 && brbodM>55 && brbodM<=100) {
		printf("Sva tri studenta su polozila. \n");
	}
	
	if (ocjenaT==ocjenaB && ocjenaT==ocjenaM && ocjenaB==ocjenaM) {
		printf("Sva tri studenta imaju istu ocjenu. \n");
		return 0;
	}
	if (ocjenaT==ocjenaB || ocjenaT==ocjenaM || ocjenaB==ocjenaM) {
		printf("Dva od tri studenta imaju istu ocjenu. \n");
		return 0;
	}
	if (ocjenaT!=ocjenaB && ocjenaT!=ocjenaM && ocjenaB!=ocjenaM) {
		printf("Svaki student ima razlicitu ocjenu. \n");
	}
	return 0;
}
