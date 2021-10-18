#include <stdio.h>

int main() {
	
	float parc11,parc12,pris1,zad1,zavrsni1,parc21,parc22,pris2,zad2,zavrsni2,parc31,parc32,pris3,zad3,zavrsni3,b,m,t,oc1,oc2,oc3;
	
	printf("Unesite bodove za Tarika: \n");
	
	printf("I parcijalni ispit: ");

	scanf("%f", &parc11);
	
	if(parc11 < 0 || parc11 > 20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	
	scanf("%f", &parc12);
	
	if(parc12 < 0 || parc12 > 20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	
	scanf("%f", &pris1);
	
	if(pris1 < 0 || pris1 > 10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	
	scanf("%f", &zad1);
	
	if(zad1 < 0 || zad1 > 10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	
	scanf("%f", &zavrsni1);
	
	if(zavrsni1 < 0 || zavrsni1 > 40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Bojana: \n");
	
	printf("I parcijalni ispit: ");

	scanf("%f", &parc21);
	
	if(parc21 < 0 || parc21 > 20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	
	scanf("%f", &parc22);
	
	if(parc22 < 0 || parc22 > 20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	
	scanf("%f", &pris2);
	
	if(pris2 < 0 || pris2 > 10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	
	scanf("%f", &zad2);
	
	if(zad2 < 0 || zad2 > 10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	
	scanf("%f", &zavrsni2);
	
	if(zavrsni2 < 0 || zavrsni2 > 40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Mirzu: \n");
	
	printf("I parcijalni ispit: ");

	scanf("%f", &parc31);
	
	if(parc31 < 0 || parc31 > 20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	
	scanf("%f", &parc32);
	
	if(parc32 < 0 || parc32 > 20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	
	scanf("%f", &pris3);
	
	if(pris3 < 0 || pris3 > 10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	
	scanf("%f", &zad3);
	
	if(zad3 < 0 || zad3 > 10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	
	scanf("%f", &zavrsni3);
	
	if(zavrsni3 < 0 || zavrsni3 > 40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	 t = parc11 + parc12 + pris1 + zad1 + zavrsni1;
	
	 b = parc21 + parc22 + pris2 + zad2 + zavrsni2;
	
	 m = parc31 + parc32 + pris3 + zad3 + zavrsni3;
	
	if(t < 55) oc1 = 5;
	
	else if (t >= 55 && t < 65) oc1 = 6;
	
	else if(t >= 65 && t < 75) oc1 = 7;
	
	else if(t >= 75 && t < 85) oc1 = 8;
	
	else if(t >= 85 && t < 92) oc1 = 9;
	
	else if(t >= 92 && t <= 100) oc1 = 10; 
	
	if(b < 55) oc2 = 5;
	
	else if (b >= 55 && b < 65) oc2 = 6;
	
	else if(b >= 65 && b < 75) oc2 = 7;
	
	else if(b >= 75 && b < 85) oc2 = 8;
	
	else if(b >= 85 && b < 92) oc2 = 9;
	
	else if(b >= 92 && b <= 100) oc2 = 10;
	
	if(m < 55) oc3 = 5;
	
	else if(m >= 55 && m < 65) oc3 = 6;
	
	else if(m >= 65 && m < 75) oc3 = 7;
	
	else if(m >= 75 && m < 85) oc3 = 8;
	
	else if(m >= 85 && m < 92) oc3 = 9;
	
	else if(m >= 92 && m <= 100) oc3 = 10; 
	
	if(t < 55 && b < 55 && m < 55)
	{
		
		printf("Nijedan student nije polozio.");
		return 0;
	}
		
	if(t >= 55 && b < 55 && m < 55)
	{
		printf("Jedan student je polozio.");
		return 0;
	}
		
	if(t < 55 && b >= 55 && m < 55)
	{
	
		printf("Jedan student je polozio.");
		return 0;
	}
	
	if(t < 55 && b < 55 && m >= 55)
	{
		printf("Jedan student je polozio.");
		return 0;
	}
	
	if(t >= 55 && b >= 55 && m < 55)
	{
		printf("Dva studenta su polozila.");
		return 0;
	}
	
	if(t >= 55 && b < 55 && m >= 55)
	{
		printf("Dva studenta su polozila.");
		return 0;
	}
	
	if(t < 55 && b >= 55 && m >= 55)
	{
		printf("Dva studenta su polozila.");
		return 0;
	}
	
	if(t >= 55 && b >=55 && m >= 55)
	
		printf("Sva tri studenta su polozila.\n");
		
		if(oc1 == oc2 && oc1 == oc3) printf("Sva tri studenta imaju istu ocjenu.");
		
		else if(oc1 == oc2 && oc1 != oc3) printf("Dva od tri studenta imaju istu ocjenu.");
		
		else if (oc1 != oc2 && oc2 == oc3) printf("Dva od tri studenta imaju istu ocjenu.");
		
		else  printf("Svaki student ima razlicitu ocjenu.");
		
		return 0;
}
		
	
		
		
	
	