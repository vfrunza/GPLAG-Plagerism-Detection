#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	double niz[500];
	int n,s,i,j=0,m,h;
	double ts;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	    scanf("%lf",&niz[i]);
	}
	for(i=0;i<n;i++){
		ts=niz[i]*360*60*60/(2*PI);
		if(ts-(int)ts>=0.5)ts+=1.0;
		s=(int)ts%60;
		if(abs(s)>30 && s!=-59){
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0;i<n;i++){
		ts=niz[i]*360*60*60/(2*PI);
		if(ts-(int)ts>=0.5)ts+=1.0;
		if (ts < 0 && fabs(ts) - fabs((int)ts) >= 0.5) ts -= 1.0; 
		s=(int)ts%60; 
		m=(int)(ts/60)%60;
		h=(int)ts/(60*60);
		if(abs(s)==59 && abs(m)==59){
			m=0;s=0;
			if(h>0)h++;
			else h--;
		}
		if(h<0){
			m=-m;s=-s;
		}
		printf("%d stepeni %d minuta %d sekundi\n",h,m,s);
	}
	return 0;
}
