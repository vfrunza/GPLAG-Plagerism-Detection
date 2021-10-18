#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int n,i,j,min,sek,s;
	double niz[500],a;
	do{
		printf("Unesite broj uglova: ");
		scanf("%d", &n);
	}
	while(n<1 || n>500);
	for(i=0;i<n;i++){
		scanf("%lf",&niz[i]);
		
	}
	printf("Uglovi su:");
	for(i=0;i<n;i++){
		a=(((niz[i]*180)/PI)*3600);
		if(a<0){
			a=(int)(fabs(a)+0.5);
			s=-a/3600;
			min=(fabs(a)-abs(s)*3600)/60;
			sek=(fabs(a)-abs(s)*3600-abs(min)*60);
			if(sek>=60){
				min++;
				sek=sek-60;
			}
			if(min>=60){
				s++;
				min=min-60;
		}}
		else{
			a=(int)(a+0.5);
			s=a/3600;
			min=(fabs(a)-abs(s)*3600)/60;
			sek=(fabs(a)-abs(s)*3600-abs(min)*60);
			if(sek>=60){
				min++;
				sek=sek-60;
			}
			if(min>=60){
				s++;
				min=min-60;
			}}
		if(sek>30){
			for(j=0;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
		else printf("\n%d stepeni %d minuta %d sekundi",s,abs(min),abs(sek));
	}
	return 0;
}
