#include <stdio.h>

int main() {
	double T1p, T2p, Tpr, Tzad, Tzav, B1p, B2p, Bpr, Bzad, Bzav, M1p, M2p, Mpr, Mzad, Mzav, T, B, M;
	int a, b, c;
	
	/* Bodovi za Tarika */
	
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &T1p);
	if(T1p<0||T1p>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &T2p);
	if(T2p<0||T2p>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Tpr);
	if(Tpr<0||Tpr>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Tzad);
	if(Tzad<0||Tzad>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &Tzav);
	if(Tzav<0||Tzav>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	
	/* Bodovi za Bojana */
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &B1p);
	if(B1p<0||B1p>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &B2p);
	if(B2p<0||B2p>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Bpr);
	if(Bpr<0||Bpr>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Bzad);
	if(Bzad<0||Bzad>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &Bzav);
	if(Bzav<0||Bzav>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	
	/* Bodovi za Mirzu */
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &M1p);
	if(M1p<0||M1p>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &M2p);
	if(M2p<0||M2p>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Mpr);
	if(Mpr<0||Mpr>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Mzad);
	if(Mzad<0||Mzad>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &Mzav);
	if(Mzav<0||Mzav>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	
	/* Racunanje bodova */
	
	T=T1p+T2p+Tpr+Tzad+Tzav;
	B=B1p+B2p+Bpr+Bzad+Bzav;
	M=M1p+M2p+Mpr+Mzad+Mzav;
	/* Provjera ocjene za Tarika */
	if(T<55) {
		a=0;
	}
	else if(T>=55&&T<65) {
		a=6;
	}
	else if(T>=65&&T<75) {
		a=7;
	}
	else if(T>=75&&T<85) {
		a=8;
	}
	else if(T>=85&&T<92) {
		a=9;
	}
	else {
		a=10;
	}
	/* Provjera ocjene za Bojana */
	if(B<55) {
		b=0;
	}
	else if(B>=55.0&&B<65) {
		b=6;
	}
	else if(B>=65&&B<75) {
		b=7;
	}
	else if(B>=75&&B<85) {
		b=8;
	}
	else if(B>=85&&B<92) {
		b=9;
	}
	else {
		b=10;
	}
	/* Provjera ocjene za Mirzu */
	if(M<55) {
		c=0;
	}
	else if(M>=55&&M<65) {
		c=6;
	}
	else if(M>=65&&M<75) {
		c=7;
	}
	else if(M>=75&&M<85) {
		c=8;
	}
	else if(M>=85&&M<92) {
		c=9;
	}
	else {
		c=10;
	}
	
	/* ISPIS */
	
	if(a==0&&b==0&&c==0) {
		printf("Nijedan student nije polozio.");
		return 0;
	}
	else if(a+b+c==a||a+b+c==b||a+b+c==c) {
		printf("Jedan student je polozio.");
		return 0;
	}
	else if((a==0&&b!=0&&c!=0)||(b==0&&a!=0&&c!=0)||(c==0&&a!=0&&b!=0)) {
		printf("Dva studenta su polozila.");
		return 0;
	}
	else {
		printf("Sva tri studenta su polozila.");
		if(a==b&&a==c) {
			printf("\nSva tri studenta imaju istu ocjenu.");
			return 0;
		}
		else if(a==b||a==c||b==c) {
			printf("\nDva od tri studenta imaju istu ocjenu.");
			return 0;
		}
		else {
			printf("\nSvaki student ima razlicitu ocjenu.");
			return 0;
		}
	}
}
