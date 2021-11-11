#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int i,n,stepeni,j;
	double niz[500];
	double x,minute,sekunde;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	scanf("%lf",&niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++){
		x=(niz[i]*180/PI);
		stepeni=(int)x;
		minute=(x-stepeni)*60;
		sekunde=(minute-(int)minute)*60;
		if(sekunde>0)
			sekunde=(int)(sekunde+0.5);
			else if(sekunde<0)
				sekunde=(int)(sekunde-0.5);
		
		if((int)sekunde==60){
			sekunde=0;
			minute++;
			}
			else if((int)sekunde==-60){
				sekunde=0;
				minute--;
			}
		if((int)minute==60){
			minute=0;
			stepeni++;
		}
		else if((int)minute==-60){
			minute=0;
			stepeni--;
		}
		if(stepeni<0){
			minute=abs(minute);
			sekunde=abs(sekunde);
		}
			else if(stepeni==0&&minute<0)
				sekunde=abs(sekunde);
				if((int)sekunde>30||(int)sekunde<-30){
			for(j=0;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
		else
			printf("%d stepeni %d minuta %d sekundi\n",stepeni,(int)minute,(int)sekunde);
	}
	return 0;
}
