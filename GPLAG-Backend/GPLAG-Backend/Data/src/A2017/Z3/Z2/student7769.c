#include <stdio.h>
#include <math.h>
void zaokruzi1(float *niz, int velicina){
	
	int i=0;
	while(i<velicina){
		*(niz+i)=round(*(niz+i)*10)/10;
		i++;
	}
}
double preslozi(float *niz3, int vel, int k){
	
	double suma=0;
	int i;
	int niz[100];
	double niz1[100], niz2[100];
	int brojac=0, brojac2=0;
	double priv;
	
	zaokruzi1(niz3,vel);
	
	for (i = 0; i < vel; i++) {
		niz[i]=(int)(niz3[i]*10);
	}	
	for(i=0;i<vel;i++)
	{
		priv=niz[i]/10.;
		suma=0;
		if(niz[i]<0) niz[i]*=-1;
		while(niz[i]>0)
		{
			suma+=niz[i]%10;
			niz[i]/=10;
		}
		if(suma>=k) 
		{
			niz1[brojac]=priv;
			brojac++;
		}
		else
		{
			niz2[brojac2]=priv;
			brojac2++;
		}
		
	}
	i=0;
	while(i<brojac)
	{
		niz3[i]=niz1[i];
		i++;
	}
	
	for(i=brojac;i<brojac2+brojac;i++)
	{
		niz3[i]=niz2[i-brojac];
	}
	
	return suma;
}

int main() {

	
	return 0;
}
