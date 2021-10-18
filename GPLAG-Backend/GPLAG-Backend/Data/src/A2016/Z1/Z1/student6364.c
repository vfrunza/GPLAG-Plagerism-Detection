#include <stdio.h>
int main() {
	double t1, t2, t3, t4, t5, b1, b2, b3, b4, b5, m1, m2, m3, m4, m5, T, B, M, ocjena1=0, ocjena2=0, ocjena3=0;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &t1);
	if(t1<0 || t1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &t2);
	if(t2<0 || t2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &t3);
	if(t3<0 || t3>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &t4);
	if(t4<0 || t4>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &t5);
	if(t5<0 || t5>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &b1);
	if(b1<0 || b1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b2);
	if(b2<0 || b2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &b3);
	if(b3<0 || b3>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &b4);
	if(b4<0 || b4>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &b5);
	if(b5<0 || b5>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &m1);
	if(m1<0 || m1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &m2);
	if(m2<0 || m2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &m3);
	if(m3<0 || m3>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &m4);
	if(m4<0 || m4>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &m5);
	if(m5<0 || m5>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	T=t1+t2+t3+t4+t5;
	B=b1+b2+b3+b4+b5;
	M=m1+m2+m3+m4+m5;
	if(T<55 && B<55 && M<55) {
		printf("Nijedan student nije polozio.\n");
	}
	if((T<55 && B<55 && M>=55) || (T<55 && M<55 && B>=55) || (B<55 && M<55 && T>=55)) {
		printf("Jedan student je polozio.\n");
	}
	if ((T<55 && B>=55 && M>=55)||(B<55 && T>=55 && M>=55)||(M<55 && B>=55 && T>=55)) {
		printf("Dva studenta su polozila.\n");
	}
	if(T>=55 && T<65) ocjena1=6;
	if(B>=55 && B<65) ocjena2=6;
	if(M>=55 && M<65) ocjena3=6;
	if(T>=65 && T<75) ocjena1=7;
	if(B>=65 && B<75) ocjena2=7;
	if(M>=65 && M<75) ocjena3=7;
	if(T>=75 && T<85) ocjena1=8;
	if(B>=75 && B<85) ocjena2=8;
	if(M>=75 && M<85) ocjena3=8;
	if(T>=85 && T<92) ocjena1=9;
	if(B>=85 && B<92) ocjena2=9;
	if(M>=85 && M<92) ocjena3=9;
	if(T>=92 && T<=100) ocjena1=10;
	if(B>=92 && B<=100) ocjena2=10;
	if(M>=92 && M<=100) ocjena3=10;
	if(ocjena1>=6 && ocjena2>=6 && ocjena3>=6) {
		printf("Sva tri studenta su polozila.\n");
	if(ocjena1==ocjena2 && ocjena2==ocjena3) {
		printf("Sva tri studenta imaju istu ocjenu.");
	} else if((ocjena1==ocjena2 && ocjena2!=ocjena3) || (ocjena1==ocjena3 && ocjena3!=ocjena2) || (ocjena2==ocjena3 && ocjena3!=ocjena1)) {
		printf("Dva od tri studenta imaju istu ocjenu.");
		}	
		else {printf("Svaki student ima razlicitu ocjenu.");	
		}
	}
	return 0;
}
