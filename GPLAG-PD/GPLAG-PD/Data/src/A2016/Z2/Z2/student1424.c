#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define EPS 0.5

int main() {
	int bu,i,j;
	float uglovi[500],step,min,sek;
	do{
	printf("Unesite broj uglova: ");
	scanf("%d",&bu);
	}while(bu>500);
	for(i=0;i<bu;i++){
		scanf("%f",&uglovi[i]);
	}
	printf("Uglovi su:\n");
	for(i=0;i<bu;i++){
		step=uglovi[i]*180/PI;
		if(step<0){
			step=(-1)*step;
		}
		min=(step-(int)step)*60;
		sek=(min-(int)min)*60;
		if(sek>=60){
			min++;
			sek=sek-60;
		}
		if(min>=60){
			step++;
			min=min-60;
		}
	if(((int)(sek+EPS))>30){
		for(j=i;j<bu-1;j++){
			uglovi[j]=uglovi[j+1];
			
		}
		bu--;
		i--;
	}
	}
	for(i=0;i<bu;i++){
		step=uglovi[i]*180/PI;
		if(step<0){
			step=(-1)*step;
			min=(step-(int)step)*60;
			sek=((min-(int)min)*60)+EPS;
			step=(-1)*step;
		}
		if(step>0){
			min=(step-(int)step)*60;
			sek=((min-(int)min)*60)+EPS;
		}
		if(step==0){
			printf("0 stepeni 0 minuta 0 sekundi\n");

		}
		printf("%d stepeni %d minuta %d sekundi\n",(int)step,(int)min,(int)sek);
	}
	return 0;
}