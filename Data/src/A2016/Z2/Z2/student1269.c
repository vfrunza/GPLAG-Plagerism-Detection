#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int main(){
	double niz[500], ug,min,sec;
	int i,j,n,ugao,minuta,skunda;
	int stepeni[500],minute[500],sekunde[500];
	printf("Unesite broj uglova: ");
	scanf ("%d", &n);
	for (i=0; i<n; i++) {
		scanf ("%lf", &niz[i]);
		niz[i]*=180;
		niz[i]/=PI;
	}
	printf("Uglovi su: \n");
	for (i=0; i<n; i++) {
		ug=niz[i];
		ugao=(int)ug;
		min=fabs((ug-ugao)*60);
		minuta=fabs((int)min);
		sec=(min-minuta)*60;
		skunda=fabs((int)sec);
		sec=fabs(sec);
		if(fabs(sec-skunda)>=0.5) skunda++;
		if(skunda==60){
			 skunda=0;
			 minuta++;
		}
		if(minuta==60){
			minuta=0;
			if(ugao<=0) ugao--;
			else ugao++;
		}
		if(skunda<=30)
			printf("%d stepeni %d minuta %d sekundi\n",ugao,minuta,skunda);
		stepeni[i]=ugao;
		minute[i]=minuta;
		sekunde[i]=skunda;
	}
	for(i=0;i<n;i++){
		if(sekunde[i]>30){
			for(j=i;j<n-1;j++){
				stepeni[j]=stepeni[j+1];
				minute[j]=minute[j+1];
				sekunde[j]=sekunde[j+1];
			}
		}
	}
	return 0;
	
}