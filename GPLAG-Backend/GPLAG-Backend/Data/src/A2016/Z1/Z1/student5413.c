#include <stdio.h>
#define EPS 0.000000000000001

int main() 
{
	double pI, pII, P, dz, zi, x;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &pI);
	if(pI < 0 || pI > 20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &pII);
	if(pII < 0 || pII > 20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &P);
	if(P < 0 || P > 10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &dz);
	if(dz < 0 || dz > 10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zi);
	if(zi < 0 || zi > 40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	x = pI + pII + P + dz + zi;
	
	double bpI, bpII, bP, bdz, bz, y;
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &bpI);
	if(bpI < 0 || bpI > 20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &bpII);
	if(bpII < 0 || bpII > 20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &bP);
	if(bP < 0 || bP > 10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &bdz);
	if(bdz < 0 || bdz > 10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &bz);
	if(bz < 0 || bz > 40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	y = bpI + bpII + bP + bdz + bz;
	
	double mpI, mpII, mP, mdz, mz, z;
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &mpI);
	if(mpI < 0 || mpI > 20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &mpII);
	if(mpII < 0 || mpII > 20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &mP);
	if(mP < 0 || mP > 10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &mdz);
	if(mdz < 0 || mdz > 10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &mz);
	if(mz < 0 || mz > 40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	z = mpI + mpII + mP + mdz + mz;
	if(x < 55)
	  x = 5;
	else if(x >= 55 && x < 65)
	  x = 6;
	else if(x >= 65 && x < 75)
	  x = 7;
	else if(x >= 75 && x < 85)
	  x = 8;
	else if(x >= 85 && x < 92)
	  x = 9;
	else
	  x = 10;
	
	if(y < 55)
	  y = 5;
	else if(y >= 55 && y < 65)
	  y = 6;
	else if(y >= 65 && y < 75)
	  y = 7;
	else if(y >= 75 && y < 85)
	  y = 8;
	else if(y >= 85 && y < 92)
	  y = 9;
	else
	  y = 10;
	
	if(z < 55) 
	  z = 5; 
	else if(z >= 55 && z < 65)
	  z = 6;
	else if(z >= 65 && z < 75)
	  z = 7;
	else if(z >= 75 && z < 85)
	  z = 8;
	else if(z >= 85 && z < 92)
	  z = 9;
	else
	  z = 10;
	  
	  int b = 0;
	  if(x > 5)
	    b++;
	  if(y > 5)
	    b++;
	  if(z > 5)
	    b++;
	  /*printf("%g %g %g\n", x, y, z);
	  printf("\nb = %d", b);*/
	  
	if(b == 0)
	{
		printf("Nijedan student nije polozio.");
		return 0;
	}
	else if(b == 1)
	{
		printf("Jedan student je polozio.");
		return 0;
	}
	else if(b == 2)
	{
		printf("Dva studenta su polozila.");
		return 0;
	}
	else if(b == 3)
	{
		printf("Sva tri studenta su polozila.\n");
		if(x - y == 0 && x - z == 0 && y - z == 0)
		{
			printf("Sva tri studneta imaju istu ocjenu.");
		}
		else if(x != y && x != z && y != z)
		{
			printf("Svaki student ima razlicitu ocjenu.");
		}
		else
			printf("Dva od tri studenta imaju istu ocjenu.");
	}
	return 0;
}
