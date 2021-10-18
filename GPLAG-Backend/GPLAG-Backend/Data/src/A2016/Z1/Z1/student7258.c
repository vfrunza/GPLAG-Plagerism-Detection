#include <stdio.h>

int main() {
	double T1,T2,TP,TZ,TZI,B1,B2,BP,BZ,BZI,M1,M2,MP,MZ,MZI,ST,SB,SM;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&T1);
	if (T1<0 || T1>20) {
		printf("Neispravan broj bodova ");
	} else {
	printf("II parcijalni ispit: "); 
	scanf("%lf",&T2); 
	if (T2<0 || T2>20) {
		printf("Neispravan broj bodova ");
	} else {
	printf("Prisustvo: ");
	scanf("%lf",&TP); 
	if (TP<0 || TP>10) {
		printf("Neispravan broj bodova ");
	} else {
	printf("Zadace: ");
	scanf("%lf",&TZ); 
	if (TZ<0 || TZ>10) {
		printf("Neispravan broj bodova ");
	} else {
	printf("Zavrsni ispit: ");
	scanf("%lf",&TZI); 
	if (TZI<0 || TZI>40) {
		printf("Neispravan broj bodova ");
	} else {
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&B1); }
	if (B1<0 || B1>20) {
		printf("Neispravan broj bodova ");
	} else {
	printf("II parcijalni ispit: ");
	scanf("%lf",&B2);
	if (B2<0 || B2>20) {
		printf("Neispravan broj bodova ");
	} else {
	printf("Prisustvo: ");
	scanf("%lf",&BP);
	if (BP<0 || BP>10) {
		printf("Neispravan broj bodova ");
	} else {
	printf("Zadace: ");
	scanf("%lf",&BZ);
	if (BZ<0 || BZ>10) {
		printf("Neispravan broj bodova ");
	} else {
	printf("Zavrsni ispit: ");
	scanf("%lf",&BZI);
	if (BZI<0 || BZI>40) {
		printf("Neispravan broj bodova ");
	} else {
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&M1);
	if (M1<0 || M1>20) {
		printf("Neispravan broj bodova ");
	} else {
	printf("II parcijalni ispit: ");
	scanf("%lf",&M2);
	if (M2<0 || M2>20) {
		printf("Neispravan broj bodova ");
	} else {
	printf("Prisustvo: ");
	scanf("%lf",&MP);
	if (MP<0 || MP>10) {
		printf("Neispravan broj bodova ");
	} else {
	printf("Zadace: ");
	scanf("%lf",&MZ);
	if (MZ<0 || MZ>10) {
		printf("Neispravan broj bodova ");
	} else {
	printf("Zavrsni ispit: ");
	scanf("%lf",&MZI);
	if (MZI<0 || MZI>40) {
		printf("Neispravan broj bodova ");
	} else {
	ST=T1+T2+TP+TZ+TZI;
	SB=B1+B2+BP+BZ+BZI;
	SM=M1+M2+MP+MZ+MZI;
	
	if(ST>=55 && SB>=55 && SM>=55) {
		printf("Sva tri studenta su polozila.\n");
	} else if (ST>=55 && SB>=55 && SM<55) {
		printf("Dva studenta su polozila.\n");
	} else if (ST>=55 && SB<55 && SM>=55) {
		printf("Dva studenta su polozila.\n");
	} else if (ST<55 && SB>=55 && SM>=55) {
		printf("Dva studenta su polozila.\n");
	} else if (ST<55 && SB<55 && SM>=55) {
		printf("Jedan student je polozio.\n");
	} else if (ST>=55 && SB<55 && SM<55) {
		printf("Jedan student je polozio.\n");
	} else if (ST<55 && SB>=55 && SM<55) {
		printf("Jedan student je polozio.\n");
	} else if (ST<55 && SB<55 && SM<55) {
		printf("Nijedan student nije polozio.\n");
	} 
	int OT,OB,OM;
	if (ST>=55) OT=6;
	if (ST>=65) OT=7;
	if (ST>=75) OT=8;
	if (ST>=85) OT=9;
	if (ST>=92) OT=10;
	if (SB>=55) OB=6;
	if (SB>=65) OB=7;
	if (SB>=75) OB=8;
	if (SB>=85) OB=9;
	if (SB>=92) OB=10;
	if (SM>=55) OM=6;
	if (SM>=65) OM=7;
	if (SM>=75) OM=8;
	if (SM>=85) OM=9;
	if (SM>=92) OM=10;
	if (ST>=55 && SB>=55 && SM>=55) {
		if (OT==OB && OT==OM) {
			printf("Sva tri studenta imaju istu ocjenu. ");
		} else if (OT==OB && OB!=OM) {
			printf("Dva od tri studenta imaju istu ocjenu. ");
		} else if (OT==OM && OB!=OM) {
			printf("Dva od tri studenta imaju istu ocjenu. ");
		} else if (OB==OM && OM!=OT) {
			printf("Dva od tri studenta imaju istu ocjenu. ");
		} else if (OT!=OB && OT!=OM && OB!=OM) {
			printf("Svaki student ima razlicitu ocjenu. ");
	}}	
	return 0;
	}}}}}}}}}}}}}}}
