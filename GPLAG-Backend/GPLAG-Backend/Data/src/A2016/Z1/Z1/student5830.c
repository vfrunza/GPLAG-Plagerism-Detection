#include <stdio.h>

int main() {
	double t1,t2,t3,t4,t5,b1,b2,b3,b4,b5,m1,m2,m3,m4,m5;
	double t,b,m;
	int ot,ob,om;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&t1);if(t1<0 || t1>20){printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf",&t2);if(t2<0 || t2>20){printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&t3);if(t3<0 || t3>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf",&t4);if(t4<0 || t4>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&t5);if(t5<0 || t3>40){printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&b1);if(b1<0 || b1>20){printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf",&b2);if(b2<0 || b2>20){printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&b3);if(b3<0 || b3>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf",&b4);if(b4<0 || b4>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&b5);if(b5<0 || b3>40){printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&m1);if(m1<0 || m1>20){printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf",&m2);if(m2<0 || m2>20){printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&m3);if(m3<0 || m3>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf",&m4);if(m4<0 || m4>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&m5);if(m5<0 || m3>40){printf("Neispravan broj bodova"); return 0;}
	t=t1+t2+t3+t4+t5;
	b=b1+b2+b3+b4+b5;
	m=m1+m2+m3+m4+m5;
	if (t<55)
	{ot=5;}
	else if(t>=55 && t<65)
	{ot=6;}
	else if(t>=65 && t<75)
	{ot=7;}
	else if(t>=75 && t<85)
	{ot=8;}
	else if(t>=85 && t<92)
	{ot=9;}
	else if(t>=92 && t<=100)
	{ot=10;}
	if (b<55)
	{ob=5;}
	else if(b>=55 && b<65)
	{ob=6;}
	else if(b>=65 && b<75)
	{ob=7;}
	else if(b>=75 && b<85)
	{ob=8;}
	else if(b>=85 && b<92)
	{ob=9;}
	else if(b>=92 && b<=100)
	{ob=10;}
	if (m<55)
	{om=5;}
	else if(m>=55 && m<65)
	{om=6;}
	else if(m>=65 && m<75)
	{om=7;}
	else if(m>=75 && m<85)
	{om=8;}
	else if(m>=85 && m<92)
	{om=9;}
	else if(m>=92 && m<=100)
	{om=10;}
	if(ot==5 && ob==5 && om==5)
	{printf("Nijedan student nije polozio.\n"); return 0;}
	if ((ot>5 && ob==5 && om==5)||(ot==5 && ob>5 && om==5)||(ot==5 && ob==5 && om>5))
	{printf("Jedan student je polozio.\n"); return 0;}
	if ((ot>5 && ob>5 && om==5)||(ot==5 && ob>5 && om>5)||(ot>5 && ob==5 && om>5))
	{printf("Dva studenta su polozila.\n");}
	if (ot>5 && ob>5 && om>5)
	{printf("Sva tri studenta su polozila.\n");}
	if (ot==ob && ot==om)
	{printf("Sva tri studenta imaju istu ocjenu.\n");}
	if (ot==ob || ot==om || ob==om)
	{printf("Dva od tri studenta imaju istu ocjenu.\n");}
	if ((ot>5 && ob>5 && om>5)&&(ot!=ob && ot!=om && ob!=om))
	{printf("Svaki student ima razlicitu ocjenu.\n");}
	return 0;
}
