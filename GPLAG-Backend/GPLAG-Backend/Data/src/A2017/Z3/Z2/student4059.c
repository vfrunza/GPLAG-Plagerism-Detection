#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz, int n)
{
	int i;
	
	for (i = 0; i < n; i++) {
		*(niz+i)=round(*(niz+i)*10)/10;
	}
}

double preslozi(float *niz1, int vel, int k)
{
	double s=0;
	int i;
	int niz[100];
	double nizv[100],nizm[100];
	int brojac1=0,brojac2=0;
	double temp;
	
	zaokruzi1(niz1, vel);
	
	for (i = 0; i < vel; i++) {
		niz[i]=(int)(niz1[i]*10);
	}
	for(i = 0; i < vel; i++)
	{
		temp=niz[i]/10.;
		s=0;
		if(niz[i]<0) niz[i]*=-1;
		while(niz[i]>0)
		{
			s+=niz[i]%10;
			niz[i]/=10;
		}
		if(s>=k) 
		{
			nizv[brojac1]=temp;
			brojac1++;
		}
		else 
		{
			nizm[brojac2]=temp;
			brojac2++;
		}
	}
	for(i = 0; i < brojac1; i++)
	{
		niz1[i]=nizv[i];
	}
	for(i = brojac1; i < brojac2 + brojac1; i++)
	{
		niz1[i]=nizm[i-brojac1];
	}

	return s;
}

int main() {

	return 0;
}
