#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415925
#include <math.h>
#define g 0.0000000000000000000000000000000000000000000001
int main() {
	int i,j,n,sec,st,min;
	double niz[500]={0},sekunda,m,b=0.5;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%lf",&niz[i]);
		niz[i]*=180./PI;
	}
	for(i=0;i<n;i++){
		m=((60*(niz[i]-(int)(niz[i])))-(int)(60*(niz[i]-(int)(niz[i]))));
		sekunda=fabs(60*m);
		sekunda+=b;
		sec=sekunda;
		if(sec==60){
			sec=0;
		}
		if(sec>30){
			for(j=i;j<n;j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++){
		st=niz[i];
		min=abs((60*(niz[i]-(int)niz[i])));
		if(niz[i]>=0){
			sekunda=fabs((int)((60*((60*(niz[i]-(int)(niz[i])))-(int)(60*(niz[i]-(int)(niz[i])))))+b));
		}
		else{
			sekunda=fabs((int)((60*((60*(niz[i]-(int)(niz[i])))-(int)(60*(niz[i]-(int)(niz[i])))))-b));
		}
		if(fabs(sekunda-60)<g){
			min++;
			sekunda=0;
		}
		if(niz[i]>=0)
		{
			if(min>=60){
				st++;
				min=0;
			}
		}
		else{
			if(min>=60){
				st--;
				min=0;
			}
		}
		sec=sekunda;
		printf("%d stepeni %d minuta %d sekundi\n",st,min,sec);
	}
	return 0;
}