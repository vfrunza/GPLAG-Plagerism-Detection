#include <stdio.h>

int main() {
	
	double t1parc, t2parc, tpr, tzad, tzi, b1parc, b2parc, bpr, bzad, bzi, m1parc, m2parc, mpr, mzad, mzi, tbod, bbod, mbod;
	int toc, boc, moc;
	
	printf("Unesite bodove za Tarika:");
	
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &t1parc);
	if(t1parc<0 || t1parc>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &t2parc);
	if(t2parc<0 || t2parc>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &tpr);
	if(tpr<0 || tpr>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &tzad);
	if(tzad<0 ||tzad>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &tzi);
	
	if(tzi<0 || tzi>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Bojana:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &b1parc);
	if(b1parc<0 || b1parc>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b2parc);
	if(b2parc<0 || b2parc>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &bpr);
	if(bpr<0 || bpr>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &bzad);
	if(bzad<0 || bzad>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &bzi);
	if(bzi<0 || bzi>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Mirzu:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &m1parc);
	if(m1parc<0 || m1parc>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &m2parc);
	if(m2parc<0 || m2parc>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &mpr);
	if(mpr<0 || mpr>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &mzad);
	if(mzad<0 || mzad>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &mzi);
	if(mzi<0 || mzi>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
		tbod = t1parc + t2parc + tpr + tzad + tzi;
		bbod = b1parc + b2parc + bpr + bzad + bzi;
		mbod = m1parc + m2parc + mpr + mzad + mzi;
		
		
		//Tarikova ocjena
		if(tbod<55)
		{
			toc=5;
		}
		else if(tbod>=55 && tbod<65)
		{
			toc=6;
		}
		else if(tbod>=56 && tbod<75)
		{
			toc=7;
		}
		else if(tbod>=75 && tbod<85)
		{
			toc=8;
		}
		else if(tbod>=85 && tbod<92)
		{
			toc=9;
		}
		else if(tbod>=92 && tbod<=100)
		{
			toc=10;
		}
		
		//bojanova ocjena
		if(bbod<55)
		{
			boc=5;
		}
		else if(bbod>=55 && bbod<65)
		{
			boc=6;
		}
		else if(bbod>=56 && bbod<75)
		{
			boc=7;
		}
		else if(bbod>=75 && bbod<85)
		{
			boc=8;
		}
		else if(bbod>=85 && bbod<92)
		{
			boc=9;
		}
		else if(bbod>=92 && bbod<=100)
		{
			boc=10;
		}
		
		//mirzina ocjena
		
		if(mbod<55)
		{
			moc=5;
		}
		else if(mbod>=55 && mbod<65)
		{
			moc=6;
		}
		else if(mbod>=56 && mbod<75)
		{
			moc=7;
		}
		else if(mbod>=75 && mbod<85)
		{
			moc=8;
		}
		else if(mbod>=85 && mbod<92)
		{
			moc=9;
		}
		else if(mbod>=92 && mbod<=100)
		{
			moc=10;
		}
		
		if(toc==5 && boc==5 && moc==5)
		{
			printf("Nijedan student nije polozio.");
		}
		else if((toc==5 && boc==5 && moc!=5) || (toc==5 && boc!=5 && moc==5) || (toc!=5 && boc==5 && moc==5))
		{
			printf("Jedan student je polozio.");
		}
		else if((toc!=5 && boc!=5 && moc==5) || (toc!=5 && boc==5 && moc!=5) || (toc==5 && boc!=5 && moc!=5))
		{
			printf("Dva studenta su polozila.");
		}
		else {
			printf("Sva tri studenta su polozila.");
			
			if(toc==moc && toc==boc && boc==moc)
			{
				printf("\nSva tri studenta imaju istu ocjenu.");
			}
			else if(toc==moc || toc==boc || moc==boc)
			{
				printf("\nDva od tri studenta imaju istu ocjenu.");
			}
			else
			{
				printf("\nSvaki student ima razlicitu ocjenu.");
			}
		}
		
		
	return 0;
}
