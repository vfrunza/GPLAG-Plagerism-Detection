#include <stdio.h>
#include <math.h>
#define PI 3.1415926


int main()
{
	double niz[500];
	 int predznak[500]={0};
	double ukupan_broj_sekundi[500];
	double stepeni[500];
	double minute[500];
	double sekunde[500];
	
	int n,i,j;
	do {
		printf("Unesite broj uglova: ");
		scanf("%d",&n);
	} while(n<1 || n>500);
	for(i=0; i<n; i++) {
		scanf("%lf",&niz[i]); if(niz[i]<0) predznak[i]=-1; if(niz[i]>0) predznak[i]=1;
		niz[i]=fabs(niz[i]);
		ukupan_broj_sekundi[i]=(niz[i]*180/PI)*3600;
		ukupan_broj_sekundi[i]=(int)(ukupan_broj_sekundi[i]+0.5);
		stepeni[i]=ukupan_broj_sekundi[i]/3600;
		stepeni[i]=(int)stepeni[i];
		minute[i]=(ukupan_broj_sekundi[i]-stepeni[i]*3600)/60; 
		minute[i]=(int)minute[i];
		sekunde[i]=ukupan_broj_sekundi[i]-stepeni[i]*3600-minute[i]*60;
		if(sekunde[i]>=60) {
			minute[i]++;
			sekunde[i]-=60;
		}
		if(minute[i]>=60) {
			stepeni[i]++;
			minute[i]-=60;
		} 	if(sekunde[i]>30) {
			for(j=i; j<n-1; j++) {
				niz[j]=niz[j+1];
				stepeni[j]=stepeni[j+1];
				minute[j]=minute[j+1];
				sekunde[j]=sekunde[j+1];
				predznak[j]=predznak[j+1];

			}
			n--;
			i--;

		}
	}


	printf("Uglovi su:\n");

	for(i=0; i<n; i++) {
		if(predznak[i]==-1){
		printf("-%g stepeni %g minuta %g sekundi\n",stepeni[i],minute[i],sekunde[i]); 
	} else if(predznak[i]=1){
		printf("%g stepeni %g minuta %g sekundi\n",stepeni[i],minute[i],sekunde[i]);}}
	return 0;
}
