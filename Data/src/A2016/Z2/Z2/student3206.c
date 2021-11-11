#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n,i,st,sek,min,j;
	double niz[500],ug;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	scanf("%lf",&niz[i]);
	}
	for(i=0;i<n;i++){
		ug=niz[i]*(180./PI);
		st=ug;
		min=(ug-st)*60;
		sek=(int)(fabs(((((ug-st)*60)-min)*60))+0.5);
		if(sek==60)
		sek=0;
		if(sek>30){
			for(j=i;j<n-1;j++)
			niz[j]=niz[j+1];
			n--;
			i--;
		}
	}
		printf("Uglovi su:");
		for(j=0;j<n;j++){
			ug=niz[j]*(180./PI);
		st=ug;
		min=(ug-st)*60;
		sek=(int)(fabs(((((ug-st)*60)-min)*60))+0.5);
		if(sek==60){
			sek=0;
			if(min>=0)
			min=min+1;
			else
			min=min-1;
		}
		if(min==60 || min==-60){
			min=0;
			if(st>=0)
			st=st+1;
			else
			st=st-1;
		}
		min=fabs(min);
	    	printf("\n%d stepeni %d minuta %d sekundi",st,min,sek);
		}
	return 0;
}
