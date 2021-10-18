#include <stdio.h>

int main() {
	double TP1, TP2, TPR, TZ, TZI, BP1, BP2, BPR, BZ, BZI, MP1, MP2, MPR, MZ, MZI;
	double TUK, BUK, MUK;
	int TO, BO, MO;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &TP1);
	if(TP1<0 || TP1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &TP2);
	if(TP2<0 || TP2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &TPR);
	if(TPR<0 || TPR>10)	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &TZ);
	if(TZ<0 || TZ>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &TZI);
	if(TZI<0 || TZI>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &BP1);
	if(BP1<0 || BP1>20)	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &BP2);
	if(BP2<0 || BP2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &BPR);
	if(BPR<0 || BPR>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &BZ);
	if(BZ<0 || BZ>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &BZI);
	if(BZI<0 || BZI>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &MP1);
	if(MP1<0 || MP1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &MP2);
	if(MP2<0 || MP2>20)	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &MPR);
	if(MPR<0 || MPR>10)	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &MZ);
	if(MZ<0 || MZ>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &MZI);
	if(MZI<0 || MZI>40) {
        printf("Neispravan broj bodova");
		return 0;
	}
	
	TUK = TP1 + TP2 + TPR + TZ + TZI;
	BUK = BP1 + BP2 + BPR + BZ + BZI;
	MUK = MP1 + MP2 + MPR + MZ + MZI;
	
	if(TUK>=55 && TUK<65) {
		TO = 6;
	}
	else if(TUK>=65 && TUK<75) {
		TO = 7;
	}
	else if(TUK>=75 && TUK<85) {
		TO = 8;
	}
	else if(TUK>=85 && TUK<92) {
		TO = 9;
	}
	else if(TUK>=92 && TUK<=100) {
		TO = 10;
	}
		if(BUK>=55 && BUK<65) {
		BO = 6;
	}
	else if(BUK>=65 && BUK<75) {
		BO = 7;
	}
	else if(BUK>=75 && BUK<85) {
		BO = 8;
	}
	else if(TUK>=85 && TUK<92) {
		BO = 9;
	}
	else if(BUK>=92 && BUK<=100) {
		BO = 10;
	}
		if(MUK>=55 && MUK<65) {
		MO = 6;
	}
	else if(MUK>=65 && MUK<75) {
		MO = 7;
	}
	else if(MUK>=75 && MUK<85) {
		MO = 8;
	}
	else if(MUK>=85 && MUK<92) {
		MO = 9;
	}
	else if(MUK>=92 && MUK<=100) {
		MO = 10;
	}

if(TUK<55 && BUK<55 && MUK<55) {
	printf("Nijedan student nije polozio.");
}
else if(TUK>54 && BUK>54 && MUK>54) {
	printf("Sva tri studenta su polozila.\n");
if(TO==BO && TO==MO) {
	printf ("Sva tri studenta imaju istu ocjenu.");
     }
else if(TO!=BO && TO!=MO && BO!=MO) {
	printf("Svaki student ima razlicitu ocjenu.");
     }
else {
	printf("Dva od tri studenta imaju istu ocjenu.");
     }
     }
else if((TUK>54 && BUK<55 && MUK<55) || (TUK<55 && BUK>54 && MUK<55) || (TUK<55 && BUK<55 && MUK>54)) {
	printf("Jedan student je polozio.");
}
else {
	printf("Dva studenta su polozila.");
}
return 0;
}
