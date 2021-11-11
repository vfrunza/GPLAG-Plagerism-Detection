#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	
	double stepeni_tmp[500], minute_tmp[500], sekunde_tmp[500], radijani[500];
	int  i, j, broj_uglova, sekunde[500], minute[500], stepeni[500];
	printf("Unesite broj uglova: ");
	scanf("%d", &broj_uglova);
	
	for(i=0; i<broj_uglova; i++)
	scanf("%lf", &radijani[i]);
	
	printf("Uglovi su:\n");
	
	for(i=0; i<broj_uglova; i++){
		
			
		stepeni_tmp[i]=(radijani[i]*180)/PI;
		stepeni[i]=(int)stepeni_tmp[i];
		minute_tmp[i]=fabs((stepeni_tmp[i]-stepeni[i])*60);
		minute[i]=((int)minute_tmp[i]);
		sekunde_tmp[i]=fabs((minute_tmp[i]-minute[i])*60+0.5);
		sekunde[i]=((int)sekunde_tmp[i]);
	}
	for(i=0; i<broj_uglova; i++){
		if(sekunde[i]>=60){
					minute[i]++;
					sekunde[i]=0;
		}
		if(minute[i]>=60){
				if(stepeni[i]>=0) {
					stepeni[i]++;
					minute[i]=0;
				}
				if(stepeni[i]<0) {
					stepeni[i]--;
					minute[i]=0;
				}
		}
	}
		for(i=0; i<broj_uglova; i++){
				if(sekunde[i]>30){
				for(j=i; j<broj_uglova-1; j++){
					stepeni[j]=stepeni[j+1];
					minute[j]=minute[j+1];
					sekunde[j]=sekunde[j+1];
				}
				broj_uglova--;
				i--;
			}
		}
	

		
	for(i=0; i<broj_uglova; i++)
		printf("%d stepeni %d minuta %d sekundi\n", stepeni[i], minute[i], sekunde[i]);
	
	
	return 0;
}
