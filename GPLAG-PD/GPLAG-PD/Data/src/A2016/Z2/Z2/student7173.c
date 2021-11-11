#include <stdio.h>
#define pi 3.1415926

int main() {
	int i,j,n;
	double step[500],min[500],sek[500],niz[500];

	printf("Unesite broj uglova: ");
	scanf("%d", &n);
    
	
	for(i=0; i<n; i++) {
	scanf("%lf", &niz[i]);
	}
	
	for(i=0; i<n; i++) {
	if (niz[i]>0){
	niz[i]=niz[i]*180/pi;
    step[i]=(int)niz[i];
	niz[i]=niz[i]-step[i];
	niz[i]=niz[i]*60;
	min[i]=(int)niz[i];
	niz[i]=(niz[i]-min[i]);
	niz[i]=niz[i]*60;
	sek[i]=(int)(niz[i]+0.5);
	
	
		if (sek[i]==60) {
		min[i]++;
		sek[i]=0; }
		if (min[i]==60) {
		step[i]++;
		min[i]=0; }
	
		}
		
	
	else {
	niz[i]=niz[i]*180/pi;
    step[i]=(int)niz[i];
	niz[i]=step[i]-niz[i];
	niz[i]=niz[i]*60;
	min[i]=(int)niz[i];
	niz[i]=niz[i]-min[i];
	niz[i]=niz[i]*60;
	sek[i]=(int)(niz[i]+0.5);
	
	if (sek[i]==60) {
		min[i]++;
		sek[i]=0; }
		if (min[i]==60) {
		step[i]--;
		min[i]=0; }
	
	
	}
	}
	

	for(i=0; i<n; i++) {
		if(sek[i]>30) {
			for (j=i; j<n-1; j++) {
			step[j]=step[j+1];	
			min[j]=min[j+1];
			sek[j]=sek[j+1];
			}
			
		n--;
		i--;
		}
	}
	
	printf("Uglovi su:");
	for(i=0; i<n; i++) 
    printf("\n%g stepeni %g minuta %g sekundi",step[i], min[i], sek[i]);
	
	return 0;
}
