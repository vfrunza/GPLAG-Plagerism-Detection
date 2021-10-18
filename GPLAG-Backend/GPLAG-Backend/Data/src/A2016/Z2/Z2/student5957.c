#include <stdio.h>
#define PI 3.1415926
#include <math.h>

int main() {
	int i,n;
	int stepeni[499]={0},minute[499]={0},sekunde[499]={0};
	float niz[499]={0.00},ukupno[499]={0};
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	scanf("%f",&niz[i]);
	ukupno[i]=((niz[i]*180.00)/PI)*3600.00;
//	printf("%f.",ukupno[i]);
	}
	
	for(i=0;i<n;i++){
		stepeni[i]=ukupno[i]/3600;
		minute[i]=(ukupno[i]-stepeni[i]*3600)/60;
		sekunde[i]=floor(0.50+(ukupno[i]-(stepeni[i]*3600.00)-minute[i]*60.00));
//		printf("%f",sekunde[i]);
		if(stepeni[i]>0.00){
	if(sekunde[i]==60){
		sekunde[i]=0;
		minute[i]=minute[i]+1;
	}
	if(minute[i]==60){
		minute[i]=0;
		stepeni[i]=stepeni[i]+1;
	}}
	else if(stepeni[i]<0.00){
	if(sekunde[i]==-60){
		sekunde[i]=0;
		minute[i]=minute[i]-1;
	}
	if(minute[i]==-60){
		minute[i]=0;
		stepeni[i]=stepeni[i]-1;
	}
		minute[i]=-minute[i];
		sekunde[i]=-sekunde[i];
	}

	}
	
	printf("Uglovi su: \n");
	for(i=0;i<n;i++){
		if(sekunde[i]<=30.00 && sekunde[i]>=-30.00)
	printf("%d stepeni %d minuta %d sekundi\n",stepeni[i],minute[i],sekunde[i]);
	
	}
	return 0;
}
