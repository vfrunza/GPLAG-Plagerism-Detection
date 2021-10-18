#include <stdio.h>
#include <math.h>
#define pi 3.1415926




int main() {
	int i,n,j;
	do{
	printf("Unesite broj uglova: ");
	scanf("%d",&n);}
	while(n>500 || n<0);
	double niz[500];
	int stepeni[500];
	int minute[500];
	int sekunde[500];
	int negativni[500];
	
	
	for(i=0;i<n;i++){
	scanf("%lf",&niz[i]);
	negativni[i]=0;
	if(niz[i]<0){negativni[i]=1;}
	niz[i]=fabs(niz[i]);
	
	niz[i]=niz[i]*180/pi;
	stepeni[i]=floor(niz[i]);
	minute[i]=floor((niz[i]-stepeni[i])*60);
	sekunde[i]=floor(((niz[i]-stepeni[i])*60-minute[i])*60);
	if(((niz[i]-stepeni[i])*60-minute[i])*60-sekunde[i]>0.5){sekunde[i]++;}
	if(sekunde[i]==60){sekunde[i]=0;
		minute[i]++;}
	if(minute[i]==60){minute[i]=0;
		stepeni[i]++;}
	
	}
	
	
	for(i=0;i<n;i++){
		if(sekunde[i]>30){
			for(j=i;j<n-1;j++){
				stepeni[j]=stepeni[j+1];
				minute[j]=minute[j+1];
				sekunde[j]=sekunde[j+1];
			}
			n--;
			i--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0;i<n;i++){
		if(negativni[i]==1){printf("-");}
		printf("%d stepeni %d minuta %d sekundi\n",stepeni[i], minute[i], sekunde [i]);
	}
	
	
	return 0;
}
