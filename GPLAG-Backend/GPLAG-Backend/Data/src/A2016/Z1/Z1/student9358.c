#include <stdio.h>

int main() {
	double m,b,t,t1,t2,t3,t4,t5,b1,b2,b3,b4,b5,m1,m2,m3,m4,m5;
	printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
	scanf("%lf",&t1);
	if(t1<0 || t1>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf",&t2);
	if(t2<0 || t2>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&t3);
	if(t3<0 || t3>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf",&t4);
	if(t4<0 || t4>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&t5);
	if(t5<0 || t5>40) {printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
	scanf("%lf",&b1);
	if(b1<0 || b1>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf",&b2);
	if(b2<0 || b2>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&b3);
	if(b3<0 || b3>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf",&b4);
	if(b4<0 || b4>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&b5);
	if(b5<0 || b5>40) {printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
	scanf("%lf",&m1);
	if(m1<0 || m1>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf",&m2);
	if(m2<0 || m2>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&m3);
	if(m3<0 || m3>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf",&m4);
	if(m4<0 || m4>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&m5);
	if(m5<0 || m5>40) {printf("Neispravan broj bodova"); return 0;}
	m=m1+m2+m3+m4+m5;
	t=t1+t2+t3+t4+t5;
	b=b1+b2+b3+b4+b5;
	if (m<55 && t<55 && b<55) {printf("Nijedan student nije polozio.\n"); return 0;}
	else if((m>=55 && b<55 && t<55) || (m<55 && b>=55 && t<55) || (m<55 && b<55 && t>=55)) {printf("Jedan student je polozio.\n"); return 0;}
	else if((m>55 && b>55 && t<55) || (m>55 && t>55 && b<55) || (m<55 && b>55 && t>55)) {printf("Dva studenta su polozila.\n"); return 0;}
	else printf("Sva tri studenta su polozila.\n");
	if ((m>=55 && m<65 && t>=55 && t<65 && b>=55 && b<65) || (m>=65 && m<75 && t>=65 && t<75 && b>=65 && b<75) || (m>=75 && m<85 && t>=75 && t<85 && b>=75 && t<85) || (m>=85 && m<95 && t>=85 && t<95 && b>=85 && b<95) || (m>=95 && b>=95 && t>=95)) {printf("Sva tri studenta imaju istu ocjenu."); return 0;}
	if ((m>=55 && m<65 && t>=55 && t<65 && b>=65) || (m>=55 && m<65 && b>=55 && b<65 && t>=65) || (b>=55 && b<65 && t>=55 && t<65 && m>=65) || (m>=65 && m<75 && t>=65 && t<75 && (b>=75 || b<65)) || (m>=65 && m<75 && b>=65 && b<75 && (t>=75 || t<65)) || (b>=65 && b<75 && t>=65 && t<75 && (m<65 || m>=75)) ||  (m>=75 && m<85 && t>=75 && t<85 && (b>=85 || b<75)) || (m>=75 && m<85 && b>=75 && b<85 && (t>=85 || t<75)) || (b>=75 && b<85 && t>=75 && t<85 && (m<75 || m>=85)) || (m>=85 && m<95 && t>=85 && t<95 && (b>=95 || b<85)) || (m>=85 && m<95 && b>=85 && b<95 && (t>=95 || t<85)) || (b>=85 && b<95 && t>=85 && t<95 && (m<85 || m>=95)) || (m>=95 && t>=95 && b<95) || (m>=95 && b>=95 && t<95) || (b>=95 && t>=95 && m<95)) printf("Dva od tri studenta imaju istu ocjenu.");
	else printf("Svaki student ima razlicitu ocjenu.");
	
	return 0;
}
