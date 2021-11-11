#include <stdio.h>
#define PI 3.1415926
int main () {
	int i,y,broj;
	int STEP[500],MIN[500],SEC[500];
	double ugao;
	printf("Unesite broj uglova: ");
	scanf("%d", &broj);
	for (i=0; i<broj; i++){
		scanf("%lf", &ugao);
		if(ugao>0)
		y=(ugao*180*3600)/PI+0.5;
		if(ugao<0)
		y=(ugao*180*3600)/PI-0.5;
		STEP[i]=y/3600;
		if(y<0){ y*=-1;
		}
		SEC[i]=y%60;
		y/=60;
		MIN[i]=y%60;
		if(SEC[i]>30){
		   broj--;
		    i--;
		}
	}
			printf("Uglovi su:\n");
			for(i=0;i<broj;i++)
			printf("%d stepeni %d minuta %d sekundi\n", STEP[i],MIN[i],SEC[i]);
			
	return 0;
}
