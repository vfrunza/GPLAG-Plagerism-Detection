#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	int i=0, j, n;
	double niz[500], m1, s1;
	printf("Unesite broj uglova: ");
	do{
		scanf("%d", &n);
	}while(n<1 || n>500);
	do{
		scanf("%lf", &niz[i]);
		i++;
	}while(i<n);
	printf("Uglovi su: ");
	for(i=0; i<n; i++){
		double radijan=fabs(niz[i]);
		double degrease=floor(radijan*180/PI);
		m1=radijan*180/PI;
		double minutes=floor((m1-degrease)*60);
		s1=(m1-degrease)*60;
		double seconds=round((s1-minutes)*60);
		if(seconds>=60){
			seconds-=60;
			minutes+=1;
			if(minutes>=60){
				minutes-=60;
				degrease+=1;
			}
		}
		if(seconds>30){
			for(j=i; j<n-1; j++){
				niz[j]=niz[j+1];
			}
			i--;
			n--;
		}
		else{
			if(niz[i]<0) printf("\n-%.0f stepeni %.0f minuta %.0f sekundi", degrease, minutes, seconds);
			else printf("\n%.0f stepeni %.0f minuta %.0f sekundi", degrease, minutes, seconds);
		}
	}
	return 0;
}