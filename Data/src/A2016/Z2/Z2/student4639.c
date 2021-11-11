#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	int n,st[500],min[500],sek[500],j,i;
	double x,niz[500];
	printf("Unesite broj uglova: ");
	scanf ("%d",&n);
	printf ("Uglovi su: ");
	for (i=0;i<n;i++)
	scanf ("%lf",&niz[i]);
	for (i=0;i<n;i++){
		x=niz[i]*180/PI;
		st[i]=(int)x;
		min[i]=(int)fabs(60*(x-st[i]));
		sek[i]=(int)((60*(fabs(60*(x-st[i]))-min[i]))+0.5);
		if (sek[i]==60) {
			min[i]++;
			sek[i]=0;
		}
		if (min[i]==60) {
			if (st[i]>0)
			st[i]++;
			else st[i]--;
			min[i]=0;
		}
	}
	for (i=0;i<n;i++){
		if (sek[i]>30){
			for(j=i;j<n-1;j++) {
				niz[j]=niz[j+1];
				sek[j]=sek[j+1];
			}
			n--;
			i--;
		}
	}
	for (i=0;i<n;i++) {
		x=niz[i]*180/PI;
		st[i]=(int)x;
		min[i]=(int)fabs(60*(x-st[i]));
		sek[i]=(int)((60*(fabs(60*(x-st[i]))-min[i]))+0.5);
		if (sek[i]==60) {
			min[i]++;
			sek[i]=0;
		}
		if (min[i]==60) {
			if (st[i]>0)
			st[i]++;
			else st[i]--;
			min[i]=0;
		}
		printf ("\n%d stepeni %d minuta %d sekundi",st[i],min[i],sek[i]);
	}
	return 0;
}
