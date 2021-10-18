#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main(){
	int brojuglova,i,j;
	double uglovi[500],stepen[500],minuta[500],sekunda[500];
	printf("Unesite broj uglova: ");
	scanf("%d",&brojuglova);
	printf("Uglovi su:\n");
	for(i=0;i<brojuglova;i++){
		scanf("%lf",&uglovi[i]);
	}
	
	for(i=0;i<brojuglova;i++){
			stepen[i]=uglovi[i]*(180/PI);
			minuta[i]=(stepen[i]-(int)stepen[i])*60;
			sekunda[i]=round((minuta[i]-(int)minuta[i])*60);
			stepen[i]=(int)stepen[i];
			minuta[i]=(int)minuta[i];
			if(sekunda[i]>59){
				minuta[i]++;
				sekunda[i]=0;
			}
			if(minuta[i]>59){
				stepen[i]++;
				minuta[i]=0;
			}
			if(sekunda[i]<-59){
				minuta[i]--;
				sekunda[i]=0;
			}
			if(minuta[i]<-59){
				stepen[i]--;
				minuta[i]=0;
			}
		}
		for(i=0;i<brojuglova;i++){
			if(sekunda[i]>30 || sekunda[i]<-30){
			for(j=0;j<brojuglova-1;j++){
			sekunda[j]=sekunda[j+1];
			minuta[j]=minuta[j+1];
			stepen[j]=stepen[j+1];
			}
			brojuglova--;
			i--;
			continue;
			}
				printf("%g stepeni %g minuta %g sekundi\n",stepen[i],fabs(minuta[i]),fabs(sekunda[i]));
}
	return 0;
}