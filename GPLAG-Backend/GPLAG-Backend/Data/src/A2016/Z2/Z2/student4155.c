#include <stdio.h>
#include <math.h>
#define pi 3.1415926

int main() {
	printf("Unesite broj uglova: ");
	int brojugl,i;
	scanf("%d",&brojugl);
	double uglovi[500];
	int stepeni[500],minute[500],sekunde[500];

	int neg[500]={0};

	for(i=0;i<brojugl;i++){
		scanf("%lf",&uglovi[i]);
		if(uglovi[i]<0) {neg[i]=1;
		uglovi[i]=-uglovi[i];}
		uglovi[i]=uglovi[i]*180/pi;
		stepeni[i]=floor (uglovi[i]);
		minute[i]=floor( (uglovi[i]-stepeni[i])*60);
		sekunde[i]=floor( ((uglovi[i]-stepeni[i])*60-minute[i])*60+0.5);
		if(sekunde[i]==60) {minute[i]++; sekunde[i]=0;}
		if(minute[i]==60) {stepeni[i]++; minute[i]=0;}
		
	}
	
	int j;
	
	for(i=0;i<brojugl;i++){
		if(sekunde[i]>30){
			for(j=i;j<brojugl;j++){
				stepeni[j]=stepeni[j+1];
				minute[j]=minute[j+1];
				sekunde[j]=sekunde[j+1];
			}
		brojugl--;
		i--;
		}
	}
	
	printf("Uglovi su:\n");
	for(i=0;i<brojugl;i++){
		if(neg[i]==1)printf("-");
		printf("%d stepeni %d minuta %d sekundi\n",stepeni[i],minute[i],sekunde[i]);
	}
	return 0;
}
