#include <stdio.h>

int main() {
	double T1,T2,Tp,Tz,T,B1,B2,Bp,Bz,B,M1,M2,Mp,Mz,M,OT,OM,OB,Tarik,Mirza,Bojan;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&T1);
	if(T1<0 || T1>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf",&T2);
	if(T2<0 || T2>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&Tp);
	if(Tp<0 || Tp>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf",&Tz);
	if(Tz<0 || Tz>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&T);
	if(T<0 || T>40) {printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&B1);
	if(B1<0 || B1>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf",&B2);
	if(B2<0 || B2>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&Bp);
	if(Bp<0 || Bp>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf",&Bz);
	if(Bz<0 || Bz>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&B);
	if(B<0 || B>40) {printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&M1);
	if(M1<0 || M1>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf",&M2);
	if(M2<0 || M2>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&Mp);
	if(Mp<0 || Mp>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf",&Mz);
	if(Mz<0 || Mz>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&M);
	if(M<0 || M>40) {printf("Neispravan broj bodova"); return 0;}
	OT=T1+T2+Tz+Tp+T;
	OB=B1+B2+Bz+Bp+B;
	OM=M1+M2+Mz+Mp+M;
	if(OT<55) {Tarik=0;}
	else if(OT>=55 && OT<65) {Tarik=2;}
    else if(OT>=65 && OT<75) {Tarik=3;}
	else if(OT>=75 && OT<85) {Tarik=4;}
	else if(OT>=85 && OT<92) {Tarik=5;}
	else if(OT>=92 && OT<=100) {Tarik=6;}
	if(OB<55) {Bojan=0;}
	else if(OB>=55 && OB<65){Bojan=2;}
	else if(OB>=65 && OB<75) {Bojan=3;}
	else if(OB>=75 && OB<85) {Bojan=4;}
	else if(OB>=85 && OB<92) {Bojan=5;}
	else if(OB>=92 && OB<=100) {Bojan=6;}
	if(OM<55) {Mirza=0;}
	else if(OM>=55 && OM<65) {Mirza=2;}
	else if(OM>=65 && OM<75) {Mirza=3;}
	else if(OM>=75 && OM<85) {Mirza=4;}
	else if(OM>=85 && OM<92) {Mirza=5;}
	else if(OM>=92 && OM<=100) {Mirza=6;}
	if(Tarik!=0 && Bojan!=0 && Mirza!=0) printf("Sva tri studenta su polozila.\n");
	else if(Tarik!=0 && Bojan==0 && Mirza==0) printf("Jedan student je polozio.\n");
	else if(Tarik==0 && Bojan!=0 && Mirza==0) printf("Jedan student je polozio.\n");
	else if(Tarik==0 && Bojan==0 && Mirza!=0) printf("Jedan student je polozio.\n");
	else if(Tarik!=0 && Bojan!=0 && Mirza==0) printf("Dva studenta su polozila.\n");
	else if(Tarik!=0 && Bojan==0 && Mirza!=0) printf("Dva studenta su polozila.\n");
	else if(Tarik==0 && Bojan!=0 && Mirza!=0) printf("Dva studenta su polozila.\n");
	else if(Tarik==0 && Bojan==0 && Mirza==0) printf("Nijedan student nije polozio.\n");
	if(Tarik!=0 && Bojan!=0 && Mirza!=0) {
		if(Tarik==Bojan && Bojan==Mirza && Tarik==Mirza) printf("Sva tri studenta imaju istu ocjenu.");
		else if(Tarik==Bojan && Bojan!=Mirza) printf("Dva od tri studenta imaju istu ocjenu.");
		else if(Tarik==Mirza && Mirza!=Bojan) printf("Dva od tri studenta imaju istu ocjenu.");
		else if(Bojan==Mirza && Mirza!=Tarik)printf("Dva od tri studenta imaju istu ocjenu.");
		else printf("Svaki student ima razlicitu ocjenu.");
	}
		return 0;
}
