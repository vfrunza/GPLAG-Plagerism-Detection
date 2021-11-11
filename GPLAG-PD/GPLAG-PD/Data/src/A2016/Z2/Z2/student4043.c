#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
#define BR_EL 100

int main() {
	float niz[BR_EL], s=0;
	int br_ugl,i,stepen,min,sek,j=0;
	printf("Unesite broj uglova: ");
	do{
		scanf("%d", &br_ugl);
	}while(br_ugl<1 || br_ugl>500);
	for(i=0;i<br_ugl;i++){
		scanf("%f", &niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<br_ugl;i++){
		s=((niz[i]*180)/PI)*3600;
		if(s<0) s=(int) (s-0.5);
		else s=(int) (s+0.5);
		stepen=s/3600;
		min=(s-stepen*3600)/60;
		sek=s-stepen*3600-min*60;
		if(s>0){
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
		else if(s<0){
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
		/*printf("%d stepeni %d minuta %d sekundi\n", stepen, min, sek);*/
	}
	for(i=0;i<br_ugl;i++){
		s=((niz[i]*180)/PI)*3600;
		if(s<0) s=(int) (s-0.5);
		else s=(int) (s+0.5);
		stepen=s/3600;
		min=(s-stepen*3600)/60;
		sek=(s-stepen*3600-min*60);
		printf("%d stepeni %d minuta %d sekundi\n", stepen, abs(min), abs(sek));
	}
	/*printf("Zadaća 2, Zadatak 2");*/
	return 0;
}
