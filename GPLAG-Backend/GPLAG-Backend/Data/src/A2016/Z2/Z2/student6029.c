#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n,i,j;
	int st[500]={0},min[500]={0},sek[500]={0};
	double rad=0;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		int neg=0;
		scanf("%lf",&rad);
		rad*=180/PI;
		if(rad<0) {
			rad*=-1;
			neg=1;
		}
		st[i]= (int)rad;
		rad-=(int)rad;
		min[i]=(int)(rad*60);
		rad*=60;
		rad-=(int)rad;
		sek[i]=(int)(round(rad*60));
		if(sek[i]==60) {
			sek[i]=0;
			min[i]++;
		}
		if(min[i]==60) {
			min[i]=0;
			st[i]++;
		}
		if (neg==1)
			st[i]*=-1;
	}
	for(i=0;i<n;i++) {
		if(sek[i]>30) {
			for(j=i;j<n-1;j++) {
				st[j]=st[j+1];
				min[j]=min[j+1];
				sek[j]=sek[j+1];
			}
		i--;
		n--;
		}
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++) {
		printf("%d stepeni %d minuta %d sekundi \n",st[i],min[i],sek[i]);
	}
	return 0;
}
