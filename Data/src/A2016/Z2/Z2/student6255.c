#include <stdio.h>
#define PI 3.1415926

int main() {
	int n,i,j;
	double niz[500],sekundi=0,min,stepeni=0,minute=0;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	if(n<=0 || n>500) return 0;
	for(i=0;i<n;i++) {
		scanf("%lf",&niz[i]);
	}
	printf("Uglovi su: ");
	for(i=0;i<n;i++){
		stepeni=niz[i]*(180./PI);
		minute=(stepeni-(int)stepeni)*60;
		sekundi=(minute-(int)minute)*60;
		if(sekundi>0) sekundi=sekundi+0.5;
		else sekundi=sekundi-0.5;
		sekundi=(int)sekundi;
		if(sekundi>=60){
			minute++;
			sekundi=sekundi-60;
		}
		if(sekundi<=-60){
			minute--;
			sekundi=sekundi+60;
		}
		if(minute>=60){
			stepeni++;
			minute=minute-60;
		}
		if(minute<=-60){
			stepeni--;
			minute=minute+60;
		}
		stepeni=(int)stepeni;
		minute=(int)minute;
		sekundi=(int)sekundi;
		if(sekundi>30 || sekundi<-30){        
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
		
		else {
			if(minute<0)minute*=-1; 
			if(sekundi<0) sekundi*=-1;
			printf("\n%g stepeni %g minuta %g sekundi",stepeni,minute,sekundi);
		}
	}
	return 0;
}
