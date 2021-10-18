#include <stdio.h>
#include <stdlib.h>

void ubaci(int* niz, int duz)
{
	int* clan;
	clan=niz;
	while(clan<niz+duz)
	{
		
		// zbrajanje cifara clana niza
		
		int broj=0;
		int bniz=abs(*clan);
		while(bniz>0)
		{
			broj+=(bniz%10);
			bniz/=10;
		}
		
		// pomjeranje clanova niza
		
		int* qclan;
		qclan=niz+duz;
		while(qclan>clan)
		{
			*qclan=*(qclan-1);
			qclan--;
		}
		
		// ubacivanje novog clana niza
		
		*(clan+1)=broj;
		
		clan+=2;
		duz+=1;
	}
}

int izbaci(int *niz, int duz)
{
	int* clan;
	clan=niz;
	while(clan<niz+duz)
	{
		// provjeravanje da li je clan niza fibonaccijev broj
		int ftrue=0, pprosli=0, prosli=1, fbroj=1;
		while(fbroj<=*clan)
		{
			if(*clan==fbroj) ftrue=1;
			pprosli=prosli;
			prosli=fbroj;
			fbroj=prosli+pprosli;
		}
		if(ftrue)
		{
			// izbacivanje clana iz niza
			int *qclan;
			qclan=clan;
			while(qclan<niz+duz-1)
			{
				*qclan=*(qclan+1);
				qclan++;
			}
			duz--;
			clan--;
		}
		clan++;
	}
	return duz;
}

int main() 
{
	int niz[301], duz;
	int i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
		scanf("%d", &niz[i]);
	}
	ubaci(niz, 10);
	duz=izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<duz;i++)
	{
		printf("%d", niz[i]);
		if(i==duz-1) printf(".");
		else printf(", ");
	}
	return 0;
}
