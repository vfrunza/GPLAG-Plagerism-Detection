#include <stdio.h>
#include <stdlib.h>
int main() {
    float t1,t2,t3,t4,t5,b1,b2,b3,b4,b5,m1,m2,m3,m4,m5;
	int a,b,c;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &t1);
	if (t1<0 || t1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
    printf("II parcijalni ispit: ");
	scanf("%f", &t2);
	if (t2<0 || t2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &t3);
	if (t3<0 || t3>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &t4);
	if (t4<0 || t4>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &t5);
	if (t5<0 || t5>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &b1);
	if (b1<0 || b1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &b2);
	if (b2<0 || b2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &b3);
	if (b3<0 || b3>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &b4);
	if (b4<0 || b4>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &b5);
	if (b5<0 || b5>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &m1);
	if (m1<0 || m1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &m2);
	if (m2<0 || m2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &m3);
	if (m3<0 || m3>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &m4);
	if (m4<0 || m4>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &m5);
	if (m5<0 || m5>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	system("clear");
a=t1 + t2 + t3 + t4 + t5;
b=b1 + b2 + b3 + b4 + b5;
c=m1 + m2 + m3 + m4 + m5;
if(a<55) {
	a=5;
}
if(a>=55 && a<65) {
	a=6;
}
if(a>=65 && a<75) {
	a=7;
}
if(a>=75 && a<85) {
	a=8;
}
if(a>=85 && a<92) {
	a=9;
}
if(a>=92 && a<=100) {
	a=10;
}
if(b<55) {
	b=5;
}
if(b>=55 && b<65) {
	b=6;
}
if(b>=65 && b<75) {
	b=7;
}
if(b>=75 && b<85) {
	b=8;
}
if(b>=85 && b<92) {
	b=9;
}
if(b>=92 && b<=100) {
	b=10;
}
if(c<55) {
	c=5;
}
if(c>=55 && c<65) {
	c=6;
}
if(c>=65 && c<75) {
	c=7;
}
if(c>=75 && c<85) {
	c=8;
}
if(c>=85 && c<92) {
	c=9;
}
if(c>=92 && c<100) {
	c=10;
}
if(a>5 && b>5 && c>5){
		printf("Sva tri studenta su polozila. \n");
}
if(a<=5 && b<=5 && c<=5){
		printf("Nijedan student nije polozio.\n");
		return 0;
}
	if(a>5 && b<=5 && c<=5){
		printf("Jedan student je polozio.\n");
		return 0;
}
	if(a<=5 && b>5 && c<=5){
		printf("Jedan student je polozio.\n");
		return 0;
}
	if(a<=5 && b<=5 && c>5){
		printf("Jedan student je polozio.\n");
		return 0;
}
if(a>5 && b>5 && c<= 5)
	{
	printf("Dva studenta su polozila.\n");
	return 0;
}
if(a<=5 && b>5 && c>5)
	{
	printf("Dva studenta su polozila.\n");
	return 0;
}
if(a>5 && b<=5 && c>5)
	{
	printf("Dva studenta su polozila.\n");
	return 0;
}
if(a == b && b == c ){
		printf("Sva tri studenta imaju istu ocjenu.\n");
}
if(a != b && b != c ){
		printf("Svaki student ima razlicitu ocjenu.\n");
}
if(a == b && b != c )
	{
		printf("Dva od tri studenta imaju istu ocjenu.\n");
}
if(a != b && b == c )
	{
		printf("Dva od tri studenta imaju istu ocjenu.\n");
}
if(a == c && b != c )
	{
		printf("Dva od tri studenta imaju istu ocjenu.\n");
}
return 0;
}

