#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() 
{
	int n, i, j, stepeni[500], minute[500], sekunde[500];
	double niz[500], min;
	do{
		printf("Unesite broj uglova: ");
		scanf("%d", &n);
	} while(n<1 || n>500);
	for(i=0; i<n; i++) scanf("%lf", &niz[i]);
	for(i=0; i<n; i++) niz[i]*=180/PI;
	for(i=0; i<n; i++){ 
		if(fabs((int)(fabs(((((niz[i]-(int)(niz[i]))*60)-((int)((niz[i]-(int)(niz[i]))*60)))*60))+0.5))>30 && fabs((int)(fabs(((((niz[i]-(int)(niz[i]))*60)-((int)((niz[i]-(int)(niz[i]))*60)))*60))+0.5)) != 60){
			for(j=i; j<n-1; j++){
				niz[j] = niz[j+1];
			}
			n--;
			i--;
		}
	}
	for(i=0; i<n; i++){
		stepeni[i] = (int)niz[i];
		min = fabs(((niz[i]-(int)(niz[i]))*60));
		minute[i] = (int)min;
		sekunde[i] = (int)(((min-minute[i])*60)+0.5);
		if(sekunde[i]==60){sekunde[i]=0; minute[i]+=1;}
	}
	for(i=0; i<n; i++)
		if(minute[i]==60){
			if(stepeni[i]<0){
				minute[i] = 0;
				stepeni[i]-=1;
			}
			else
				minute[i]=0;
				stepeni[i]+=1;
		}
	
	printf("Uglovi su: \n");
	for(i=0; i<n; i++) printf("%d stepeni %d minuta %d sekundi\n", stepeni[i], minute[i], sekunde[i]);
	
	
	return 0;
}
