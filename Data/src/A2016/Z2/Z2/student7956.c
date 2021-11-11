#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
#define br_elem 500

int main() {
	double niz[br_elem], uk_s=0;
	int br_ugl,i,stepen,min,sek,j=0;
	printf("Unesite broj uglova: ");
	do{	scanf("%d", &br_ugl);
	}
	while(br_ugl<1 || br_ugl>500);
	for(i=0;i<br_ugl;i++){
		scanf("%lf", &niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<br_ugl;i++)
	{
		uk_s=((niz[i]*180)/PI)*3600;
		if(uk_s<0)uk_s=(int) (uk_s-0.5);
		else uk_s=(int) (uk_s+0.5);
		stepen=uk_s/3600;
		min=(uk_s-stepen*3600)/60;
		sek=uk_s-stepen*3600-min*60;
		if(uk_s>0){
			if(sek>=60){
				min+=1;
				sek-=60;
			}
			if(min>=60){
				stepen+=1;
				min-=60;
			}
			if(sek>30){
				for(j=i;j<br_ugl-1;j++){
					niz[j]=niz[j+1];
				}
				br_ugl--;
				i--;
			}
		}
		else if(uk_s<0){
			if(sek<=-60){
				min-=1;
				sek+=60;
			}
			if(min<=-60){
				stepen-=1;
				min+=60;
			}
			if(sek<-30){
				for(j=i;j<br_ugl-1;j++){
					niz[j]=niz[j+1];
				}
				br_ugl--;
				i--;
			}
		}
	}
	for(i=0;i<br_ugl;i++){
		uk_s=((niz[i]*180)/PI)*3600;
		if(uk_s<0) uk_s=(int) (uk_s-0.5);
		else uk_s=(int) (uk_s+0.5);
		stepen=uk_s/3600;
		min=(uk_s-stepen*3600)/60;
		sek=(uk_s-stepen*3600-min*60);
		printf("%d stepeni %d minuta %d sekundi\n", stepen, abs(min), abs(sek));
	}
	return 0;
}