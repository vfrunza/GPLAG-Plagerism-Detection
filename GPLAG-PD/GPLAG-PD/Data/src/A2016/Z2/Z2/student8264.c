#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define broj_elemenata 500
int main() {
	double niz[broj_elemenata],sec,min,kruzic,ss,sm,r;
	int n,i,j;
	ss=0;
	sm=0;
	r=0;
	kruzic=0;
	min=0;
	sec=0;
	
		printf("Unesite broj uglova: ");
		do {
		scanf("%d",&n);
	      } while (n<=0 || n>=500);
	for (i=0;i<n;i++) {
		scanf ("%lf",&niz[i]); 
		
	}
	printf ("Uglovi su: \n");
	
	for (i=0;i<n;i++){
		r=fabs(niz[i]);
		kruzic=(int)((r*180)/PI);	
		ss=r*180/PI;
		
		min=(int)((ss-kruzic)*60);
	 	sm=(ss-kruzic)*60;
		sec=round((sm-min)*60);
			if (sec>=60) {sec-=60; min++; }
			if (min>=60) {min-=60; kruzic++; }
			if(sec>30) {
				for (j=i;j<n-1;j++)	{
					niz[j]=niz[j+1];
					}
				n--;
				i--;
			}
		else { 
			if (niz[i]<0) {
			printf("-%.lf stepeni %.lf minuta %.lf sekundi \n",kruzic,min,sec); }
			else { printf("%.lf stepeni %.lf minuta %.lf sekundi \n",kruzic,min,sec); }
			
	}
	}
	
	return 0;
}
