#include <stdio.h>
#include <math.h>

void zaokruzi1(float* niz,int duz)
{
	int i;
	float* p=niz;
	
	for(i=0;i<duz;i++)
		p[i]=roundf(p[i]*10)/10;
		
}


void preslozi(float* niz,int duz,int k)
{
	zaokruzi1(niz,duz);
	int i,j;
	float* p=niz;
	float nizmin[1000],nizmax[1000];
	int minbr=0,maxbr=0;
	int temp,suma=0;
	int brojac=0;
	float tempfloat;
	
	for(i=0;i<duz;i++)
	{
		//Sumiram cifre preko %-a
		suma=0;		
		temp=(fabs)((int)(p[i]*10));
		for(j=0;temp!=0;j++)
		{
			suma+=temp%10;
			temp/=10;
		}
		
	//Ako je suma >=k pomjera taj element desno do brojaca, gdje brojac predstavlja koliko se vec clanova pomjerilo, da se nebi redoslijed pokvario
		if(suma>=k)
		{
			for(j=i;j>brojac;j--)
			{
				tempfloat=niz[j];
				niz[j]=niz[j-1];
				niz[j-1]=tempfloat;
			}
			brojac++;
		}	
	}
}


int main() {
	

 

	return 0;
}
