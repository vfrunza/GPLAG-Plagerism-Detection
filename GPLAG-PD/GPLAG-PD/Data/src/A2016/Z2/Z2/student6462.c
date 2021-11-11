#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n, i, j, stepeni[500], minute[500], sekunde[500];
	double niz[500];
	double x;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%lf", &niz[i]);
	}
	for(i=0; i<n; i++){
		x=niz[i]*(180./PI);
		x*=3600;
		stepeni[i]=(int)x/3600;
		x=x-stepeni[i]*3600;
		minute[i]=(int)x/60;
		
		if(niz[i]>0){
		sekunde[i]=(x+0.5)-minute[i]*60;
		if(sekunde[i]==60){
			minute[i]=minute[i]+1;
			sekunde[i]=0;
			if(minute[i]==60){
				minute[i]=0;
				stepeni[i]=stepeni[i]+1;
			}
		}
		if(minute[i]==60){
			minute[i]=0;
			stepeni[i]=stepeni[i]+1;
		}
		}
		else{
			sekunde[i]=(x-0.5)-minute[i]*60;
			sekunde[i]=fabs(sekunde[i]);
			minute[i]=fabs(minute[i]);
			if(sekunde[i]==60){
			minute[i]=minute[i]+1;
			sekunde[i]=0;
			if(minute[i]==60){
				minute[i]=0;
				stepeni[i]=stepeni[i]-1;
			}
		}
		if(minute[i]==60){
			minute[i]=0;
			stepeni[i]=stepeni[i]-1;
		}
		}
	}
	for(i=0; i<n; i++){
		
		if(sekunde[i]>30){
			for(j=i; j<n-1; j++){
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
		printf("%d stepeni %d minuta %d sekundi\n", stepeni[i], minute[i], sekunde[i]);
	}
	return 0;
}
