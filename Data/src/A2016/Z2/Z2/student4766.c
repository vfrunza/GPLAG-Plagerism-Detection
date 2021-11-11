#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define MAX_SIZE 500
int main(){
	double ugao[MAX_SIZE], stepeni[MAX_SIZE],minute[MAX_SIZE],sekunde[MAX_SIZE];
	int n,i,j,sgn;
	double stepsec, minsec, sec;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	if(n>MAX_SIZE)
	n=MAX_SIZE;
	//unos
	for(i=0; i<n; i++){
		scanf("%lf", &ugao[i]);
		ugao[i] = ugao[i]*(180/PI);
	
	}
	//dodjela vrijednosti
	for(i=0;i<n;i++){
		sec = ugao[i]*3600;
		
		stepeni[i] = ((int)sec)/3600;
		stepsec = (stepeni[i]*3600);
		minute[i] =(int)(((int)(sec-stepsec))/60);
		minsec = minute[i]*60;
		sekunde[i]= sec -stepsec-minsec;
	}
	//zaokruzivanje
	for(i=0; i<n; i++){
		sgn=1;
		if(sekunde[i]<0)
		sgn=-1;
		sekunde[i]= (int) (sekunde[i]+ sgn*0.5);
		if(fabs(sekunde[i])==60){
			sekunde[i]=0;
			minute[i]+=sgn*1;
			if(fabs(minute[i])==60){
				minute[i]=0;
				stepeni[i]+=sgn*1;
			}
		}
		if(fabs(sekunde[i])>30){
		for(j=i; j<n-1; j++){
			ugao[j]=ugao[j+1];
			stepeni[j]=stepeni[j+1];
			minute[j]=minute[j+1];
			sekunde[j]=sekunde[j+1];
			
		}
		i--;
		n--;
		}
	}

		printf("Uglovi su: \n");
		for(i=0; i<n; i++){
			printf("%d stepeni %d minuta %d sekundi \n", (int)stepeni[i],abs(minute[i]), abs(sekunde[i]));
		}
	
	return 0;
}


