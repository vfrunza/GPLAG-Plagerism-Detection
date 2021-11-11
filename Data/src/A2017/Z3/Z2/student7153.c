#include <stdio.h>
#include <math.h>


void zaokruzi1 (float niz[], int n)
{
	int i, a, b, logicko=0;
	float x, c, temp;
	
	for(i=0; i<n; i++) {
		if(niz[i]<0)
		{
			x=niz[i]*(-1);
			temp=niz[i]*(-1);
			logicko=1;
		}
		else
		{x=niz[i];
		temp=niz[i];}
		
		x=x-(int)x;
		x=x*10;
		a=(int)x;
		x=x-(int)x;
		x=x*10;
		b=(int)x;
		
		if(b>=5)
		a++;
		c=((float)a)/10;
		
		niz[i]=(int)temp+c;
		
		if(logicko==1)
		niz[i]=niz[i]*(-1);
		logicko=0;
		
	}
	
	
}	

void preslozi(float niz[], int n, int k)
{
	int i, x, suma=0, nizk[10000];
	int a=0, b=0, c=0;
	float niz1[10000], niz0[10000];
	
	
	zaokruzi1(niz,n);
	for(i=0; i<n; i++) {
		
		if(niz[i]<0)
		x=niz[i]*10*(-1);
		else
		x=niz[i]*10;
		
		while(x>0)
		{
			suma=suma+x%10;
			x=x/10;
		}
		
		if(suma>=k)
		nizk[i]=1;
		else
		nizk[i]=0;
		suma=0;
	}
	
	for(i=0; i<n; i++) {
		if(nizk[i]==1)
		{
			niz1[a]=niz[i];
			a++;
		}
		else
		{
			niz0[b]=niz[i];
			b++;
		}
	}
	
	for(i=0; i<a; i++)
	{
		niz[i]=niz1[i];
	}
	
	for(i=a; i<n; i++)
	{
		niz[i]=niz0[c];
		c++;
	}

}

int main() 
{
	int i, k, n;
	float niz[10000];
	
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	
	printf("Unesite elemente niza: ");
	for(i=0; i<n; i++)
	scanf("%f", &niz[i]);
	
	printf("Unesite broj k: ");
	scanf("%d", &k);
	
	
	
	preslozi(niz,n,k);
	
	printf("Niz glasi: ");
	for(i=0; i<n; i++)
	printf("%.1f ",niz[i]);
	
	return 0;
}