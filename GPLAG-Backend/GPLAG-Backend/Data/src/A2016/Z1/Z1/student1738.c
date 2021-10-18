#include <stdio.h>

int main() 
{
	/*tarik*/
	double p1,p2,pr,zd,zi,ocj;
	double b;
	printf ("Unesite bodove za Tarika: \nI parcijalni ispit: ");
	scanf ("%lf",&p1);
	if (p1<0||p1>20)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%lf",&p2);
	if (p2<0||p2>20)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Prisustvo: ");
	scanf ("%lf",&pr);
	if (pr<0||pr>10)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%lf",&zd);
	if (zd<0||zd>10)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf ("%lf",&zi);
	if (zi<0||zi>40)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	
		b=p1+p2+pr+zd+zi;
		if (b<55)
		{
			/*printf ("Student pao.");*/
			ocj=5;
		}
		else if (b>55&&b<65)
		{
			/*printf ("ocjena 6");*/
			ocj=6;
		}
		else if (b>=65&&b<75)
		{
			/*printf ("ocjena 7");*/
			ocj=7;
		}
		else if (b>=75&&b<85)
		{
			/*printf ("ocjena 8");*/
			ocj=8;
		}
		else if (b>=85&&b<92)
		{
			/*printf ("ocjena 9");*/
			ocj=9;
		}
		else
		{
			/*printf ("ocjena 10");*/
			ocj=10;
		}
	
	
	
	/*bojan*/
	double pb1,pb2,prb,zdb,zib,bb,ocjb;
	printf ("Unesite bodove za Bojana: \nI parcijalni ispit: ");
	scanf ("%lf",&pb1);
	if (pb1<0||pb1>20)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%lf",&pb2);
	if (pb2<0||pb2>20)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Prisustvo: ");
	scanf ("%lf",&prb);
	if (prb<0||prb>10)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%lf",&zdb);
	if (zdb<0||zdb>20)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf ("%lf",&zib);
	if (zib<0||zib>40)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}

		bb=pb1+pb2+prb+zdb+zib;
		if (bb<55)
		{
			/*printf ("Student pao.");*/
			ocjb=5;
		}
		else if (bb>55&&bb<65)
		{
			/*printf ("ocjena 6");*/
			ocjb=6;
		}
		else if (bb>=65&&bb<75)
		{
			/*printf ("ocjena 7");*/
			ocjb=7;
		}
		else if (bb>=75&&bb<85)
		{
			/*printf ("ocjena 8");*/
			ocjb=8;
		}
		else if (bb>=85&&bb<92)
		{
			/*printf ("ocjena 9");*/
			ocjb=9;
		}
		else
		{
			/*printf ("ocjena 10");*/
			ocjb=10;
		}
		
		
	
	
	
	/*mirza*/
	double pm1,pm2,prm,zdm,zim,bm,ocjm;
	printf ("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
	scanf ("%lf",&pm1);
	if (pm1<0||pm1>20)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%lf",&pm2);
	if (pm2<0||pm2>20)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Prisustvo: ");
	scanf ("%lf",&prm);
	if (prm<0||prm>10)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%lf",&zdm);
	if (zdm<0||zdm>10)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf ("%lf",&zim);
	if (zim<0||zim>40)
	{
		printf ("Neispravan broj bodova");
		return 0;
	}
	/*if ((pm1<0||pm1>20)||(pm2<0||pm2>20)||(prm<0||prm>10)||(zdm<0||zdm>10)||(zim<0||zim>40))
	{
		printf ("Neispravan broj bodova");
		return 0;
		
	}
	else
	{*/
		bm=pm1+pm2+prm+zdm+zim;
		if (bm<55)
		{
			/*printf ("Student pao.");*/
			ocjm=5;
		}
		else if (bm>55&&bm<65)
		{
			/*printf ("ocjena 6");*/
			ocjm=6;
		}
		else if (bm>=65&&bm<75)
		{
			/*printf ("ocjena 7");*/
			ocjm=7;
		}
		else if (bm>=75&&bm<85)
		{
			/*printf ("ocjena 8");*/
			ocjm=8;
		}
		else if (bm>=85&&bm<92)
		{
			/*printf ("ocjena 9");*/
			ocjm=9;
		}
		else
		{
			/*printf ("ocjena 10");*/
			ocjm=10;
		}
	
	
	/****************************************/
	
	if (ocj==5&&ocjb==5&&ocjm==5)
	{
		printf ("Nijedan student nije polozio.");
	}
	else if ((ocj>5&&ocjb==5&&ocjm==5)||(ocj==5&&ocjb>5&&ocjm==5)||(ocj==5&&ocjb==5&&ocjm>5))
	{
		printf ("Jedan student je polozio.");
	}
	else if (ocj>5&&ocjb>5&&ocjm>5)
	{
		printf ("Sva tri studenta su polozila.");
	}
	else
	{
		
		printf ("Dva studenta su polozila.");
	}
	
	if (ocj==ocjb && ocjb==ocjm)
	{
		if (ocj>5 && ocjb>5 && ocjm>5)
		printf ("\nSva tri studenta imaju istu ocjenu.");
		
	}
	else if (ocj!=ocjb && ocj!=ocjm && ocjb!=ocjm)
	{
		if (ocj>5&&ocjb>5&&ocjm>5)
		printf ("\nSvaki student ima razlicitu ocjenu.");
	}
	else
	{
		if (ocj>5&&ocjb>5&&ocjm>5)
		printf ("\nDva od tri studenta imaju istu ocjenu.");
	}

	
	
	return 0;
}
