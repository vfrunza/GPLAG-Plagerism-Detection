#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Pi 3.1415926

int main(){
	int i,j,n,step[500],min[500],sek[500];
	double niz[500],x[500],y[500],z[500];
	do{
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	} while(n<1 || n>500);
	for(i=0;i<n;i++){
		scanf("%lf", &niz[i]);
		x[i]=niz[i]/Pi*180;
		step[i]=(int)x[i];
		y[i]=fabs(x[i]-step[i])*60;
		min[i]=(int)y[i];
		z[i]=(y[i]-min[i])*60;
		sek[i]=round(z[i]);
		if(sek[i]>=60)
		{
			sek[i]=0;
			min[i]++;
		}
		if(min[i]>=60)
		{
			min[i]=0;
			if(step[i]<0)
				step[i]--;
			else
			step[i]++;
		}
		if(sek[i]>30){
			for (j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
	}
	printf("Uglovi su: ");
	for(i=0;i<n;i++){
		printf("\n%d stepeni %d minuta %d sekundi", step[i],min[i],sek[i]);
	}
	return 0;
}