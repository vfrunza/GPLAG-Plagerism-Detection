#include <stdio.h>
#define PI 3.1415926
#include<math.h>
#include<stdlib.h>
int main() {
	double radijan[500],temp[500],temp2[500],temp3[500];
	int stepen[500],minuta[500],sekunda[500];
	int i,n;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);

for(i=0;i<n;i++){
		scanf("%lf",&radijan[i]);
	}
	for(i=0;i<n;i++){
	temp[i]=radijan[i]*180/PI-(int)(radijan[i]*180/PI);
	stepen[i]=(int)(radijan[i]*180/PI);
	temp2[i]=temp[i]*60;
	minuta[i]=(int)temp2[i];
	temp3[i]=temp2[i]-(int)(temp2[i]);
	sekunda[i]=(int)round(temp3[i]*60);
	if(stepen[i]>0){
		if(sekunda[i]==60){
			sekunda[i]=0;
			minuta[i]++;
	}
		if(minuta[i]==60){
			minuta[i]=0;
			stepen[i]++;
	}
	} else if (stepen[i]<0){
		if(sekunda[i]==-60){
			sekunda[i]=0;
			minuta[i]--;
		}
		if(minuta[i]==-60){
			minuta[i]=0;
			stepen[i]--;
		}
	}
	}
	int j;
	for(i=0;i<n;i++){
	if(sekunda[i]>30 || sekunda[i]<-30){
		
		//brojac2++;
		for(j=i;j<n;j++){
		stepen[j]=stepen[j+1];
		minuta[j]=minuta[j+1];
		sekunda[j]=sekunda[j+1];
		radijan[j]=radijan[j+1];
		
		}
		i--;
		n--;
	}
	}
	printf("Uglovi su:\n");
	for(i=0;i<(n);i++){
		if(radijan[i]<0 && stepen[i]==0){
			printf("-%d stepeni %d minuta %d sekundi\n",stepen[i],abs(minuta[i]),abs(sekunda[i]));
		} else {
			printf("%d stepeni %d minuta %d sekundi\n",stepen[i],abs(minuta[i]),abs(sekunda[i]));
		}
	}
	return 0;
}
