#include <stdio.h>
#include <stdlib.h>
int main() {
	float tp1,tp2,tp,tz,tza,bp1,bp2,bp,bz,bza,mp1,mp2,mp,mz,mza,ocjena1,ocjena2,ocjena3;
	scanf("%f", &tp1);
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	if (tp1<0 || tp1>20) 
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &tp2);
	if (tp2<0 || tp2>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &tp);
	if (tp<0 || tp>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &tz);
	if (tz<0 || tz>10) 
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &tza);
	if (tza<0 || tza>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	} 
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &bp1);
	if (bp1<0 || bp1>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &bp2);
	if (bp2<0 || bp2>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &bp);
	if (bp<0 || bp>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &bz);
	if (bz<0 || bz>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &bza);
	if (bza<0 || bza>40) 
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &mp1);
	if (mp1<0 || mp1>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &mp2);
	if (mp2<0 || mp2>20) 
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &mp);
	if (mp<0 || mp>10) 
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &mz);
	if (mz<0 || mz>10) 
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &mza);
	if (mza<0 || mza>40) 
	{
		printf("Neispravan broj bodova");
		return 0;
	} 
	system("clear");
	ocjena1=tp1+tp2+tza+tz+tp;
	ocjena2=bp1+bp2+bza+bz+bp;
	ocjena3=mp1+mp2+mza+mz+mp;
	if(ocjena1<55)
	{
		ocjena1=5;
	}
	if(ocjena1>=55 && ocjena1<65)
	{
		ocjena1=6;
	}
	if(ocjena1>=65 && ocjena1<75)
	{
		ocjena1=7;
	}
	if(ocjena1>=75 && ocjena1<85)
	{
		ocjena1=8;
	}
	if(ocjena1>=85 && ocjena1<92)
	{
		ocjena1=9;
	}
	if(ocjena1>=92 && ocjena1<=100)
	{
		ocjena1=10;
	}
	if(ocjena2<55)
	{
		ocjena2=5;
	}
	if(ocjena2>=55 && ocjena2<65)
	{
		ocjena2=6;
	}
	if(ocjena2>=65 && ocjena2<75)
	{
		ocjena2=7;
	}
	if(ocjena2>=75 && ocjena2<85)
	{
		ocjena2=8;
	}
	if(ocjena2>=85 && ocjena2<92)
	{
		ocjena2=9;
	}
	if(ocjena2>=92 && ocjena2<=100)
	{
		ocjena2=10;
	}
	if(ocjena3<55)
	{
		ocjena3=5;
	}
	if(ocjena3>=55 && ocjena3<65)
	{
		ocjena3=6;
	}
	if(ocjena3>=65 && ocjena3<75)
	{
		ocjena3=7;
	}
	if(ocjena3>=75 && ocjena3<85)
	{
		ocjena3=8;
	}
	if(ocjena3>=85 && ocjena3<92)
	{
		ocjena3=9;
	}
	if(ocjena3>=92 && ocjena3<=100)
	{
		ocjena3=10;
	}
	if(ocjena1 >5 && ocjena2 >5 && ocjena3 >5)
	{
		printf("Sva tri studenta su polozila. \n");
	}
	if(ocjena1 <=5 && ocjena2 <=5 && ocjena3 <= 5)
	{
		printf("Nijedan student nije polozio.\n");
		return 0;
	}
	if((ocjena1 >=5 && ocjena2 <=5 && ocjena3 <= 5) || (ocjena1 <=5 && ocjena2 >=5 && ocjena3 <= 5) || (ocjena1 <=5 && ocjena2 <=5 && ocjena3 >= 5))
	{
		printf("Jedan student je polozio.\n");
		return 0;
	}
	if((ocjena1 >=5 && ocjena2 >=5 && ocjena3 <= 5) || (ocjena1 <=5 && ocjena2 >=5 && ocjena3 >= 5)|| (ocjena1 >=5 && ocjena2 <=5 && ocjena3 >= 5))
	{
	printf("Dva studenta su polozila.\n");
	return 0;
	}
	if(ocjena1 == ocjena2 && ocjena2 == ocjena3 )
	{
		printf("Sva tri studenta imaju istu ocjenu.\n");
	}
	if(ocjena1 != ocjena2 && ocjena2 != ocjena3 )
	{
		printf("Svaki student ima razlicitu ocjenu.\n");
	}
	if((ocjena1 == ocjena2 && ocjena2 != ocjena3 ) || (ocjena1 != ocjena2 && ocjena2 == ocjena3 ) || (ocjena1 == ocjena3 && ocjena2 != ocjena3 ))
	{
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	return 0;
}
