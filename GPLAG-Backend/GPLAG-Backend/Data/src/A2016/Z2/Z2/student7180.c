#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n, i, j;
	int negativan=0;
	double niz[500];
	double n1;
	int step, min, sek;
	printf ("Unesite broj uglova: ");
	scanf("%d", &n); 
	for (i=0; i<n; i++)
		scanf("%lf", &niz[i]);
	for(i=0; i<n; i++)
	{
		negativan=0;
		n1=niz[i];
		if(n1<0) {negativan=1; n1=-n1;}
		n1*=(180/PI);
		step=n1;
		n1-=step;
		if(negativan==1) step=-step;
		n1*=60;
		min=n1;
		n1-=min;
		n1*=60;
		sek=n1;
		n1-=sek;
		if(n1>=0.5) sek+=1;
		if(sek==60) {sek=0; min++;}
		if(min==60)
		{
			min=0;
			if(negativan==1) step-=1;
			else step+=1;
		}
		if(sek>30)
		{
			for(j=i; j<n-1; j++)
			{
				niz[j]=niz[j+1];
			}
			i--;
			n--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0; i<n; i++)
	{
		negativan=0;
		n1=niz[i];
		if(n1<0) {negativan=1; n1=-n1;}
		n1*=(180/PI);
		step=n1;
		n1-=step;
		if(negativan==1) step=-step;
		n1*=60;
		min=n1;
		n1-=min;
		n1*=60;
		sek=n1;
		n1-=sek;
		if(n1>=0.5) sek+=1;
		if(sek==60) {sek=0; min++;}
		if(min==60) 
		{
			min=0;
			if(negativan==1) step-=1;
			else step+=1;
		}
		printf("%d stepeni %d minuta %d sekundi\n", step, min, sek);
	}
	
	
	return 0;
}
