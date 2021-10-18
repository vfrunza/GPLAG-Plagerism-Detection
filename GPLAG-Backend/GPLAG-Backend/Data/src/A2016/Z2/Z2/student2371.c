#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define MAX 500
int main() {
	int i, j, n;
	float niz[MAX], kon=0, sekunda=0, minuta=0;
	int stepeni[MAX], minute[MAX], sekunde[MAX];
	
	printf("Unesite broj uglova: ");
	scanf ("%d", &n);
	for (i=0; i<n; i++){
		scanf ("%f", &niz[i]);
	}
	
	kon=180/PI;
	for (i=0; i<n; i++){
		niz[i]=niz[i]*kon;
	}
	for(i=0; i<n; i++){
		stepeni[i]=(int) (niz[i]);
		minuta=fabs((niz[i]-stepeni[i])*60);
		minute[i]=(int)(minuta);
		sekunda=(minuta-minute[i])*60;
		sekunde[i]=(int)((fabs(sekunda))+ 0.5);
		if (sekunde[i]>=60) {minute[i]++; sekunde[i]=0;}
		if (minute[i]>=60) {
			if (stepeni[i]<0){ 
				stepeni[i]--; 
				minute[i]=0;
			
		}
			else {
				stepeni[i]++;
				minute[i]=0;
			}
	}
	}
	
	for (i=0; i<n; i++){
		if(sekunde[i]>30){
			for (j=i; j<n-1; j++){
				sekunde[j]=sekunde[j+1];
				minute[j]=minute[j+1];
				stepeni[j]=stepeni[j+1];
			}
			n--;
			i--;
		}
		else continue;
		} 
    printf("Uglovi su: \n");
	for (i=0; i<n; i++){
		printf("%d stepeni %d minuta %d sekundi\n", stepeni[i], minute[i], sekunde[i] );
		
	}
	
	return 0;
}
