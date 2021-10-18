#include <stdio.h>

int main()
{
	double T1, T2, Tp, Tz, TZ, Tzb;
	double B1, B2, Bp, Bz, BZ, Bzb;
	double M1, M2, Mp, Mz, MZ, Mzb;
	int To, Bo, Mo;
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &T1);
	if(T1<0 || T1>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &T2);
	if(T2<0 || T2>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Tp);
	if(Tp<0 || Tp>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Tz);
	if(Tz<0 || Tz>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &TZ);
	if(TZ<0 || TZ>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &B1);
	if(B1<0 || B1>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &B2);
	if(B2<0 || B2>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Bp);
	if(Bp<0 || Bp>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Bz);
	if(Bz<0 || Bz>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &BZ);
	if(BZ<0 || BZ>40)
	{
		printf("Nesipravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &M1);
	if(M1<0 || M1>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &M2);
	if(M2<0 || M2>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Mp);
	if(Mp<0 || Mp>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Mz);
	if(Mz<0 || Mz>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &MZ);
	if(MZ<0 || MZ>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	Tzb=T1+T2+Tp+Tz+TZ;
	To=(Tzb+5)/10;
	Bzb=B1+B2+Bp+Bz+BZ;
	Bo=(Bzb+5)/10;
	Mzb=M1+M2+Mp+Mz+MZ;
	Mo=(Mzb+5)/10;
	if(To<6 && Bo<6 && Mo<6)
	{
		printf("Nijedan student nije polozio.\n");
		return 0;
	}
	else if((To<6 && Bo<6 && Mo>=6) || (To>=6 && Bo<6 && Mo<6) || (To<6 && Bo>=6 && Mo<6))
	{
		printf("Jedan student je polozio.\n ");
		return 0;
	}
	else if((To>=6 && Bo>=6 && Mo<6) || (To>=6 && Bo<6 && Mo>=6) || (To<6 && Bo>=6 && Mo>=6))
	{
		printf("Dva studenta su polozila.\n");
		return 0;
	}
	else if(To>=6 && Bo>=6 && Mo>=6)
	{
		printf("Sva tri studenta su polozila.\n");
		if(To==Bo && Bo==Mo)
		{
			printf("Sva tri studenta imaju istu ocjenu.\n");
		}
		else if(To==Bo || To==Mo || Mo==Bo)
		{
			printf("Dva od tri studenta imaju istu ocjenu.\n");
		}
		else
		{
		printf("Svaki student ima razlicitu ocjenu.\n");
		}
	}
		return 0;
}
