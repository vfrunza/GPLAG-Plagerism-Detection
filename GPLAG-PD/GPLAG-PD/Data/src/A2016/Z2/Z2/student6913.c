#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() 
{ 
	int bu,i,j;
	double n[500],u,min,sec,st,c=0.5,temp;
	printf("Unesite broj uglova: ");
	scanf("%d",&bu);
	if (bu>500) {
		printf("Prevelik unos");
		return 0;
	}
	for(i=0;i<bu;i++) {
		scanf("%lf",&n[i]);
	}
	printf("Uglovi su: ");
	for(j=0; j<bu; j++) {
		u=n[j]*180/PI*3600;
		if(u>0)
		u=(int)(u+c);
		else u=(int)(u-c);
		int st=(int)(u/3600);
		u=fabs(u);
		temp=fabs(st);
		int min=(u-temp*3600)/60;
		int sec=u-temp*3600-min*60;
			while (min>=60) {
			st++;
			min=min-60;
		}
		while (min<=-60) {
			st--;
			min=min+60;
		}
		while(sec>=60) {
			min++;
			sec=sec-60;
		}
		while(sec<=-60) {
			min--;
			sec=sec+60;
		}
		if(sec>30) {
			for(i=j;i<bu-1;i++) {
				n[i]=n[i+1];
			}
			j--;
			bu--;
			continue;
		}
		if (sec<-30) {
			for(i=j;i<bu-1;i++) {
				n[i]=n[i+1];
				}
				j--;
				continue;
		}
		printf("\n%d stepeni %d minuta %d sekundi",st,min,sec);
			}
			return 0;
		}