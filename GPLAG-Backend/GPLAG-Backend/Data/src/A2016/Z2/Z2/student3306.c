#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
int main() {
	/*printf("Zadaća 2, Zadatak 2");*/
	int n,i,j;
	double stepen[500],minut[500],sekund[500], niz[500];
	printf ("Unesite broj uglova: ");
	scanf ("%d", &n);
	for (i=0;i<n;i++){
		scanf ("%lf", &niz[i]);
	}
	
	for (i=0;i<n;i++){
		if (niz[i]>0){
			niz[i]=niz[i]*180/PI;
			stepen[i]=(int)(niz[i]);
			niz[i]=niz[i]-stepen[i];
			niz[i]*=60;
			minut[i]=(int)(niz[i]);
			niz[i]=(niz[i]-minut[i]);
			niz[i]*=60;
			sekund[i]=(int)(niz[i]+0.5);
			
			if (sekund[i]==60){
			minut[i]++;
			sekund[i]=0;
			}
			
			if (minut[i]==60){
			stepen[i]++;
			minut[i]=0;
			}
		}
		else {
			niz[i]=niz[i]*180/PI;
			stepen[i]=(int)(niz[i]);
			niz[i]=stepen[i]-niz[i];
			niz[i]*=60;
			minut[i]=(int)(niz[i]);
			niz[i]=(niz[i]-minut[i]);
			niz[i]*=60;
			sekund[i]=(int)(niz[i]+0.5);
			
			if (sekund[i]==60){
			minut[i]++;
			sekund[i]=0;
			}
			if (minut[i]==60){
			stepen[i]--;
			minut[i]=0;
			}
		}
		
	}


	for (i=0;i<n;i++){
		if (sekund[i]>30){
			for (j=i;j<n-1;j++){
				stepen[j]=stepen[j+1];
				minut[j]=minut[j+1];
				sekund[j]=sekund[j+1];

			}
			n--;
			i--;
		}
	}
	
	printf ("Uglovi su: ");
	for (i=0;i<n;i++)
		printf ("\n%g stepeni %g minuta %g sekundi",stepen[i],minut[i],sekund[i]);
	return 0;
}
