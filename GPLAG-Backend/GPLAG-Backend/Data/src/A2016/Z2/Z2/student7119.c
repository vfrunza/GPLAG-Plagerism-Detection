#include <stdio.h>
#define PI 3.1415926
int main() {
	long int n,i, stepeni, minute, sekunde,j;
	double poms,pomm,sekundeP,a;
	double niz[500];
	do {
	printf("Unesite broj uglova: ");
	scanf("%ld",&n);
	}
	while (n<0 || n>500);

	for(i=0;i<n;i++) {
		scanf("%lf",&niz[i]);
	}
	for(i=0;i<n;i++) {
		a=niz[i];
		if(a<0) {
			a=-a;
		}
		stepeni=(int)(a*180/PI);
	
		poms=a*180/PI;
		
		minute=(int)((poms-stepeni)*60);
		pomm=(poms-stepeni)*60;
		sekundeP=(pomm-minute)*60;
		sekunde=(int)(sekundeP+0.5);
	
		if(sekunde>30 && sekunde!=60) {
			for(j=i;j<n-1;j++) {
				niz[j]=niz[j+1];
			}
	
		n--;
		i--;
		}
	}
	printf("Uglovi su:") ;
	for(i=0;i<n;i++) {
		a=niz[i];
		if(a<0) {
			a=-a;
		}
		stepeni=(int)(a*180/PI);
		poms=a*180/PI;
		minute=(int)((poms-stepeni)*60);
		pomm=(poms-stepeni)*60;
		sekundeP=(pomm-minute)*60;
		sekunde=(int)(sekundeP+0.5);
		if(sekunde<0) {
			sekunde=-sekunde;
		}
		if(minute<0) {
			minute=-minute;
			
		}
		if(sekunde==60) {
			minute+=1;
			sekunde=0;
		}
		if(minute==60) {
			stepeni+=1;
			minute=0;
		}
		if(niz[i]<0) printf("\n-%ld stepeni %ld minuta %ld sekundi",stepeni,minute,sekunde);
	else	printf("\n%ld stepeni %ld minuta %ld sekundi",stepeni,minute,sekunde);
			
		}

	
	
	return 0;
}
