#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.1415926
int main() {
	int n,i,j;
	double niz[500],step[500],min[500],sec[500];
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0; i<n;i++){
	scanf("%lf",&niz[i]);
	}
	for(i=0; i<n;i++){
	step[i]=niz[i]*(180./pi)-(int)(niz[i]*(180./pi));
	min[i]=((step[i]*60)-(int)(step[i]*60));
	sec[i]=(int)(round((min[i]*60)));
	step[i]=niz[i]*(180./pi)-(int)(niz[i]*(180./pi));
	min[i]=(int)(step[i]*60);
	step[i]=(int)(niz[i]*(180./pi));
	if(sec[i]==60){
		sec[i]=0;
		min[i]++;
	}
	if(min[i]==60){
		min[i]=0;
		step[i]++;
	}
	if(sec[i]==-60){
		sec[i]=0;
		min[i]--;
	}
	if(min[i]==-60){
		min[i]=0;
		step[i]--;
	}
	sec[i]=abs(sec[i]);
	min[i]=abs(min[i]);
	}
	
	for(i=0;i<n;i++)
	if(sec[i]>30){
		for(j=i;j<n-1;j++){
		sec[j]=sec[j+1];
		min[j]=min[j+1];
		step[j]=step[j+1];
		}
		i--;
		n--;
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++)
	printf("%g stepeni %g minuta %g sekundi\n",step[i],min[i],sec[i]);
	return 0;
}
