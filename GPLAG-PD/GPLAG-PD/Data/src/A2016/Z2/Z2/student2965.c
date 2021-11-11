#include <stdio.h>
#define PI 3.1415926
#include <stdlib.h>
#include <math.h>

int main() {
	int i,n,stepeni,min,sekunde,j;
	double niz[500], uk;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	printf("Uglovi su: \n");
	for(i=0;i<n;i++) {
		scanf("%lf",&niz[i]);
	}
	for(i=0;i<n;i++) {
		uk=(niz[i]*180)/PI;
		stepeni=(int)uk;
		uk=fabs(uk)-abs(stepeni);
		uk=uk*60;
		min=(int)uk;
		min=abs(min);
		if(min)
		uk=uk-min;
		uk=uk*60;
		sekunde=(int)(uk + 0.5);
		sekunde=abs(sekunde);
		if(stepeni>0 && (min==59 && sekunde>=59.5)) {
			stepeni++;
			min=0;
			sekunde=0;
		} else if(stepeni<0 && (min==59 && sekunde>=59.5)) {
			stepeni--;
			min=0;
			sekunde=0;
		} else if(sekunde==60 && min<59) {
			min++;
			sekunde=0;
		}
		if(sekunde>30) {
			for(j=i;j<n-1;j++)
			{
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
		if(sekunde<=30)
		printf("%d stepeni %d minuta %d sekundi\n",stepeni,min,sekunde);
	}

	
	return 0;
}
