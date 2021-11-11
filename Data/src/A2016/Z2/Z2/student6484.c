#include <stdio.h>
#include <math.h>
#define  PI 3.1415926

int main() {


	double radijani[500];
   double minute[500], sekunde[500],stepeni[500];
   int minute1[500], sekunde1[500], stepeni1[500];
	int n,i,j,brojac;
	do{
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	} while(n<1 || n>500);

	for(i=0; i <n; i++) {


		scanf("%lf", &radijani[i]);

		sekunde[i] = ((180/PI)*3600*radijani[i]);
		sekunde[i] = (int)(sekunde[i] + 0.5);
		stepeni1[i] = sekunde[i]/3600;
		minute1[i] = (sekunde[i] - stepeni1[i]*3600)/60;
        sekunde1[i] = sekunde[i]-stepeni1[i]*3600-minute1[i]*60;

        if (sekunde1[i]>=60) {minute1[i]++; sekunde1[i]-=60;}
        if (minute1[i]>=60) {stepeni1[i]++; minute[i]-=60;}

	}
	  brojac=0;
	for(i=0; i<n; i++) {
		if(sekunde1[i]>=30) {
			brojac++;
			for(j=i; j<n-1;j++ ) {
				stepeni1[j] = stepeni1[j+1];
				minute1[j]=minute1[j+1];
				sekunde1[j]=minute1[j+1];
                radijani[i]=radijani[j+1];

		}
		n--;
		i--;
	}
	}


  printf("Uglovi su:\n");

	for(i=0; i<brojac; i++){
		printf("%d stepeni %d minuta %d sekundi\n", stepeni1[i], minute1[i], sekunde1[i]);
	}






	return 0;
}
