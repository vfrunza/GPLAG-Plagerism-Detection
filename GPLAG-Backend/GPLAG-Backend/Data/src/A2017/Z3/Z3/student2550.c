#include <stdio.h>
/* Ok hombre vrijeme da sve izmjnimo pa da ne izleti slucajno prepisano*/
	/* Ovdje provjeravamo da li se u nizu pojavljuju brojevi veci od 9 ili manji od 0, i potencijalno ponavljanje brojeva*/
	int provjera(int niz[],int x)
	{
		int i=0,j=i+1;
			while(i<x)
			{
				if(niz[i]<0 || niz[i]>9)
					return 1;
				i++;
			}
			i=0;
			while(i<x)
			{
				while(j<x)
				{
					if(niz[i]==niz[j])
						return 1;
					j++;
				}
				i++;
			}	
			
		return 0;
	}
int izbaci_cifre(int niz1[], int x, int niz2[], int y)
{
	int i,j;
		if(provjera(niz2,y))
			return 0;
	
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			int p=niz1[i],suma=0;
			
				while(p!=0)
				{
					if(p<0)
						p*=-1;
					int r=p%10;
						if(r!=niz2[j])
						{
							suma=suma*10+r;
						}
					p/=10;
				}
				int suma1=0;
					
					/*E ako sada iskoci prepisano...*/
					while(suma!=0)
					{
						int jos_nesto=suma%10;
						
							suma1=suma1*10+jos_nesto;
							
							suma/=10;
					}
			if(niz1[i]<0) 
				suma1*=-1;
			niz1[i]=suma1;
		}
	}
	return 1;
}
int main() {
	int brojevi[] = {12345, -12345};
int cifre[] = {3,5};
izbaci_cifre(brojevi, 2, cifre, 2);
printf("%d %d", brojevi[0], brojevi[1]);
	printf("\nKumbajaaaa");
}
