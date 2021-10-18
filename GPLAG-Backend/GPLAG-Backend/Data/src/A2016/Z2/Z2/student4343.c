#include <stdio.h>
#define PI 3.1415926
#include <math.h>
int main() {
	double  niz[500], ugao, sek;
	int n,i, stepen, min, s,l,j;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{	scanf("%lf",&ugao);
		niz[i]=(ugao*180)/PI;
	}
	printf("Uglovi su: \n");
	for (i=0; i<n; i++)
	{	if(niz[i]<0) l=-1;
		else l=1;
		niz[i]=fabs(niz[i]);
		stepen=niz[i]; 
		niz[i]=(niz[i]-stepen)*60;
		min=niz[i];
		niz[i]=(niz[i]-min)*60;
		sek=niz[i]; s=sek;
		if (sek-s<0.4999999) 	 sek=s;
		else sek=s+1;
		if(sek>59)
		{ 	sek=0; min++;
		}
		if(min>59)
		{	min=0; stepen++;
		}
		if (sek>30)
		{ 
			for (j=i; j<n-1; j++) {
				niz[j] = niz[j+1];
				
			}
			n--; i--;
}
		else if(l==-1)	printf("-%d stepeni %d minuta %.0f sekundi\n", stepen, min, sek);
			else 		 printf("%d stepeni %d minuta %.0f sekundi\n", stepen, min, sek);
	}
	
	return 0;
}
