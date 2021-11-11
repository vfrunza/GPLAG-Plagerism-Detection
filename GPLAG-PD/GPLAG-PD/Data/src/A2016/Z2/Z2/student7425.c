#include <stdio.h>

int main() {
	int n;
	int e, f, g, h;
	int negativno=0;
	double pi=3.1415926;
	double pom;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	if(n>500) {
		printf("Pogresan unos.\n");
		return 0;
	}
	int i;
	double niz[500];
	int stepen[500], minuta[500], sekunda[500];
	for(i=0;i<n;i++)
		scanf("%lf", &niz[i]);
	for(i=0;i<n;i++) {
		negativno=0;
		stepen[i]=niz[i]*(180/pi);
		e++;
		f+=g;
		if(stepen[i]<0) {negativno=1; stepen[i]=-stepen[i]; niz[i]=-niz[i];}
		h-=stepen[i];
		pom=(niz[i]*(180/pi))-stepen[i];
		minuta[i]=pom*60;
		f=e+g+h;
		pom=(pom*60)-minuta[i];
		/*if((niz[i]/(180/pi)-stepen[i])*60>=59.5) {
			minuta[i]=0;
			stepen[i]++;
		} */
		sekunda[i]=pom*60;
		pom=pom*60-sekunda[i];
		if(pom>=0.5) sekunda[i]++;
		/*if((((niz[i]*(180/pi)-stepen[i])*60-minuta[i])*60)-sekunda[i]>=0.5 && ((niz[i]*(180/pi)-stepen[i])*60-minuta[i])*60<59.5)
			sekunda[i]++; */
		if(sekunda[i]==60) {
			f--;
			sekunda[i]=0;
			minuta[i]++;
		}
		if(minuta[i]==60) {
			minuta[i]=0;
			g++;
			stepen[i]++;
		}
		if(negativno==1) stepen[i]=-stepen[i];
		/*if(((niz[i]*(180/pi)-stepen[i])*60-minuta[i])*60>=59.5) {
			sekunda[i]=0;
			minuta[i]++;
		} */
		
		
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++){
		if(sekunda[i]<=30)
			printf("%d stepeni %d minuta %d sekundi\n", stepen[i], minuta[i], sekunda[i]);
	}
	return 0;
}
