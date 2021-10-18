#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define broj 500
#include <math.h>
#define E 1e-3
int main () {
	int n, i, j;
	double niz[broj], tniz[broj], min[broj], sek[broj];
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%lf", &niz[i]);
		niz[i]=niz[i]*180/PI;
		tniz[i]=niz[i];
		
	}
	printf("Uglovi su: \n");
	for(i=0; i<n; i++) {
		min[i]=fabs((tniz[i]-(int)tniz[i])*60);
		sek[i]=fabs(((fabs(tniz[i])-fabs((int)tniz[i]))*60-(int)((fabs(tniz[i])-fabs((int)tniz[i]))*60))*60+0.0449);
		tniz[i]=(int)tniz[i];
		if(sek[i]>=59 && ((sek[i]-(int)sek[i]))>=0.55 && min[i]>=59 && ((min[i]-(int)min[i]))>=0.55){
			sek[i]=0;
			min[i]=0;
			if(tniz[i]<0) {
				tniz[i]-=1;
				continue;
			}
			tniz[i]+=1;
			continue;
		}

		if(fabs(sek[i])>30) {
			for(j=i; j<n-1; j++)
				tniz[j]=tniz[j+1];
			n--;
			i--;
		}
	}
	for(i=0; i<n; i++) {
		printf("%.0lf stepeni %.0lf minuta %.0lf sekundi\n",tniz[i],min[i],sek[i]);
	}
	return 0;
}