#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
#define duzina 500

int main() {
	int br,i,j;
	double niz[duzina],niz2[duzina];
	float deg=0, min=0, sec=0;
	printf("Unesite broj uglova: ");
	scanf("%d",&br);
	for(i=0;i<br;i++){
		scanf("%lf", &niz[i]);
		niz2[i]=niz[i];
		if(niz[i]<0) abs(niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<br;i++){
		deg=niz[i]*180/PI;
		min=deg-(int)deg;
		min=min*60;
		sec=min-(int)min;
		sec=sec*60+0.5;
		deg=(int)deg;
		min=(int)min;
		sec=(int)sec;
		if(sec>59.5){
			min++;
			sec=sec-sec;
		}
		if(min>59.5){
				deg++;
				min-=min;
			}
		if(sec>30){
			for(j=i;j<br-1;j++)
				niz[j]=niz[j+1];
			br--;
			i--;
			continue;
		}
		
		if(niz2[i]>=0){
			printf("%.f stepeni %.f minuta %.f sekundi\n", deg,min,sec);
		}
		else 
			printf("%.f stepeni %.f minuta %.f sekundi\n",deg*=-1,min,sec);
	}
	return 0;
}
