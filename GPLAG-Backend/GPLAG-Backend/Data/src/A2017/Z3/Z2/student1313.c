#include <stdio.h> Potrebno je najprije napraviti funkciju zaokruzi1 koja prima 
                   niz realnih brojeva i sve članove niza zaokružuje na 1 decimalu .
                   Zatim treba napraviti funkciju preslozi koja također prima niz realnih brojeva i 
                    jedan prirodan broj k, poziva prvu funkciju, a zatim niz preslaže tako da se na
                    početku niza nalaze svi članovi niza čija je suma cifara veća
                      ili jednaka k, a zatim oni članovi niza čija je suma cifara manja od k.
#include <math.h>

void zaokruzi1(float niz[], int vel)
{
	int i;
	
	for(i=0; i<vel; i++)
	{
		niz[i]=niz[i]*10;
		niz[i]=round(niz[i]);
		niz[i]/=10;
	}
}

void preslozi(float niz[], int vel, int k)
{
	int i, j ,temp1, suma, ostatak, ubacivanje=0;
	float temp2;
	
	zaokruzi1(niz, vel);
	/*rastavljanje broja na cifre i racunanje sume cifara*/
	for(i=0; i<vel; i++)
	{
		temp1=(fabs(niz[i])*10+0.5);
		suma=0;
		while(temp1!=0)
		{
			ostatak=temp1%10;
			suma+=ostatak;
			temp1/=10;
		}
		/*promjena elemenata u nizu*/
		if (suma>=k)
		{
			temp2=niz[i];
			for(j=i; j>ubacivanje; j--)
				niz[j]=niz[j-1];
			niz[ubacivanje]=temp2;
			ubacivanje++;
		}
		
	}

}

int main() {
	int i, br, vel, k;
	float niz[100];
	
	printf("Unesite broj elemenata niza: ");
	scanf("%d", &br);
	
	printf("Unesite niz: ");
	for(i=0; i<br; i++)
		scanf("%f",&niz[i]);
	
	vel=i;	
	
	printf("Unesite k: ");
	scanf("%d",&k);
	
	preslozi(niz,vel,k);
	
	for(i=0; i<vel; i++)
		printf("%.1f ",niz[i]);
	return 0;
}
