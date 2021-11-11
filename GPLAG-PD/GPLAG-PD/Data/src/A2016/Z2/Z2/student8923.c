#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define CON 180
#define SEK 60
#define MIN 30

int main() {
	int br,i,j;
	double Array[500],temp;
	int St=0,Min=0,Sec=0;
	printf("Unesite broj uglova: ");
	scanf("%d", &br);
	
	for(i=0;i<br;i++){
		scanf("%lf", &Array[i]);
	}
	
	printf("Uglovi su: \n");
	for(i=0;i<br;i++){
		/*pretvaranje*/
		Array[i]=Array[i]*(CON/PI);
		St=Array[i];
		temp=fabs((Array[i]-St)*SEK);
		Min=(int)temp;
		Sec=(int)(((temp-Min)*SEK)+0.5); /* +0.5 zbog zaokruzivanja*/
		if(Sec==60){
			Sec=0; Min++;
			if(Min==60){
				Min=0;
				if(St<0) St--;
				else St++;
			}
		}
		
		/*izbacivanje iz niza*/
		if(Sec>MIN){
			for(j=i;j<br-1;j++){
				Array[j]=Array[j+1];
			}
			br--; i--;
			continue;
		}
		printf("%d stepeni %d minuta %d sekundi \n",St,Min,Sec);
	}
	
	return 0;
}
