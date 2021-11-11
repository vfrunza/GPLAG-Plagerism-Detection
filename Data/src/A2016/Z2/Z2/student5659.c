#include <stdio.h>
#include<math.h>
#define pi 3.1415926
#define m 0.1

int main() {
	int i,j,n;
	double niz[500],sec[500],step[500],min[500];
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%lf",&niz[i]);
	}
	for(i=0;i<n;i++){
	
		niz[i]=niz[i]*(180/pi);
		step[i]=(int)niz[i];
		min[i]=(niz[i]-(int)niz[i])*60;
		sec[i]=(min[i]-(int)min[i])*60;
		min[i]=(int)min[i];
		if(niz[i]<0) {
			sec[i]=-(int)(sec[i]-0.5);
			min[i]=-min[i];
		}
		if(min[i]==-0) min[i]=0;
		sec[i]=(int)(sec[i]+0.5);
		
	}
	for(i=0;i<n;i++){
		if(sec[i]>30 || sec[i]<-30) {
			for(j=i;j<n;j++){
			sec[j]=sec[j+1];
			min[j]=min[j+1];
			step[j]=step[j+1];
		}
		n--;
		i--;
		}
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++) {
		printf("%g stepeni %g minuta %g sekundi \n",step[i],min[i],sec[i]);
		}
	return 0;
}
