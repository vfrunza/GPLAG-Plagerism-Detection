#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ubaci(int niz[], int vel)
{
	int i, suma, a;
	int niz1[20000], niz2[20000];
	
	for(i=0;i<vel;i++)
	{
		suma=0;
		a=fabs(niz[i]);
		while(a>0)
		{
			suma+=a%10;
			a=a/10;
		}
		niz2[i]=suma;
	}
	
	i=0;
	a=0;
	while(a<vel)
	{
		niz1[i++]=niz[a];
		niz1[i++]=niz2[a];
		a++;
	}
	
	for(i=0;i<vel*2;i++)
		niz[i]=niz1[i];
}



int izbaci(int niz[], int vel)
{
	int fibonaci[100000]; 
	int i, j, k, a, b, c, z;
	a=0;
	b=1;
	for(i=0;i<45;i++)
	{
		c=a+b;
		a=b;
		b=c;
		
		fibonaci[i]=c;
	}
	z=vel;
	for(i=0;i<z;i++)
	{
		a=niz[i];
		for(j=0;j<45;j++)
		{
			b=fibonaci[j];
			if(a==b)
			{
				for(k=i;k<z-1;k++)
					niz[k]=niz[k+1];
				i--;
				z--;
			}
				
		}
	}
	return z;
}



int main() {
	int niz[10000], i, vel;
	vel=10;
	
	printf("Unesite niz od 10 brojeva: ");
	
	for(i=0;i<vel;i++)
		scanf("%d", &niz[i]);
	
	ubaci(niz, vel);
	vel=vel*2;

	vel=izbaci(niz,vel);
	
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++)
	{
		if(i<vel-1) printf("%d, ", niz[i]);
		else printf("%d.", niz[i]);
	}
	return 0;
}