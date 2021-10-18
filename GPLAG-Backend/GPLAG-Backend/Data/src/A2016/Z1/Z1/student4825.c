#include <stdio.h>
#define eps 0.0001
int main() {
	int brpolozenih=0, Mocjena=0, Bocjena=0, Tocjena=0;
	float T1bod, T2bod, Tpri, Tzad, Tzav, Tsuma=0;
	float B1bod, B2bod, Bpri, Bzad, Bzav, Bsuma=0;
	float M1bod, M2bod, Mpri, Mzad, Mzav, Msuma=0;
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &T1bod);
	if (T1bod>20 || T1bod<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &T2bod);
	if (T2bod>20 || T2bod<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &Tpri);
	if (Tpri>10 || Tpri<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &Tzad);
	if (Tzad>20 || Tzad<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &Tzav);
	if (Tzav>40 || Tzav<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	Tsuma=T1bod+T2bod+Tpri+Tzad+Tzav;
	if (Tsuma<55-eps) Tocjena=0;
	else if (Tsuma>=55-eps){
		if (Tsuma>=55-eps && Tsuma<65) Tocjena=6;
		if (Tsuma>=65 && Tsuma<75) Tocjena=7;
		if (Tsuma>=75 && Tsuma<85) Tocjena=8;
		if (Tsuma>=85 && Tsuma<92) Tocjena=9;
		if (Tsuma>=92 && Tsuma<=100) Tocjena=10;
		brpolozenih++;
	}
	
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &B1bod);
	if (B1bod>20 || B1bod<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &B2bod);
	if (B2bod>20 || B2bod<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &Bpri);
	if (Bpri>10 || Bpri<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &Bzad);
	if (Bzad>20 || Bzad<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &Bzav);
	if (Bzav>40 || Bzav<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	Bsuma=B1bod+B2bod+Bpri+Bzad+Bzav;
	if (Bsuma<55-eps) Bocjena=0;
	else if (Bsuma>=55-eps){
		if (Bsuma>=55-eps && Bsuma<65) Bocjena=6;
		if (Bsuma>=65 && Bsuma<75) Bocjena=7;
		if (Bsuma>=75 && Bsuma<85) Bocjena=8;
		if (Bsuma>=85 && Bsuma<92) Bocjena=9;
		if (Bsuma>=92 && Bsuma<=100) Bocjena=10;
		brpolozenih++;
	}
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &M1bod);
	if (M1bod>20 || M1bod<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &M2bod);
	if (M2bod>20 || M2bod<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &Mpri);
	if (Mpri>10 || Mpri<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &Mzad);
	if (Mzad>20 || Mzad<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &Mzav);
	if (Mzav>40 || Mzav<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	Msuma=M1bod+M2bod+Mpri+Mzad+Mzav;
	if (Msuma<55-eps) Mocjena=0;
	else if (Msuma>=55-eps){
		if (Msuma>=55-eps && Msuma<65) Mocjena=6;
		if (Msuma>=65 && Msuma<75) Mocjena=7;
		if (Msuma>=75 && Msuma<85) Mocjena=8;
		if (Msuma>=85 && Msuma<92) Mocjena=9;
		if (Msuma>=92 && Msuma<=100) Mocjena=10;
		brpolozenih++;
	}
	if (brpolozenih==0)
	printf("Nijedan student nije polozio.");
	if (brpolozenih==1)
	printf("Jedan student je polozio.");
	if (brpolozenih==2)
	printf("Dva studenta su polozila.");
	if (brpolozenih==3)
	printf("Sva tri studenta su polozila.");
	printf("\n");
	if (brpolozenih==3){
		if (Tocjena==Bocjena && Tocjena==Mocjena)
		printf("Sva tri studenta imaju istu ocjenu.");
		if (Tocjena!=Bocjena && Tocjena!=Mocjena && Bocjena!=Mocjena)
		printf("Svaki student ima razlicitu ocjenu.");
		if ((Tocjena==Bocjena && Tocjena!=Mocjena) || (Tocjena==Mocjena && Tocjena!=Bocjena) || (Bocjena==Mocjena && Bocjena!=Tocjena))
		printf("Dva od tri studenta imaju istu ocjenu.");
	}
	return 0;
}