#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define epsilon 0.1


int main() {
	double niz[500], nizst[500], nizm[500], nizsek[500], kontrola=0;
	int i, n, j;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		scanf("%lf", &niz[i]); 
	}
	printf("Uglovi su:");
	for(i=0;i<n;i++){
		nizst[i]=niz[i]*180/PI;
		nizm[i]=(nizst[i]-(int)nizst[i])*60;
		nizsek[i]=(nizm[i]-(int)nizm[i])*60;
		nizst[i]=(int)nizst[i];
		nizm[i]=(int)nizm[i];
		if(niz[i]>=0)
			nizsek[i]=(int)(nizsek[i]+0.5);
		else
			nizsek[i]=(int)(nizsek[i]-0.5);
		if(fabs(fabs(nizsek[i])-60)<=epsilon && niz[i]>=0){
			nizm[i]+=1;
			nizsek[i]=0;
		}
		else if(fabs(fabs(nizsek[i])-60)<=epsilon && niz[i]<0){
			nizm[i]-=1;
			nizsek[i]=0;
		}
		if(fabs(fabs(nizm[i])-60)<=epsilon && niz[i]>=0){
			nizst[i]+=1;
			nizm[i]=0;
		}
		else if(fabs(fabs(nizm[i])-60)<=epsilon && niz[i]<0){
			nizst[i]-=1;
			nizm[i]=0;
		}
	}
	for(i=0;i<n;i++){
		kontrola = nizsek[i];
		if(kontrola > 30 || kontrola < -30){
			for(j=i;j<n-1;j++){
				nizst[j]=nizst[j+1];
				nizm[j]=nizm[j+1];
				nizsek[j]=nizsek[j+1];
			}
			n--;
			i--;
		}
	}
	for(i=0;i<n;i++)
		printf("\n%.f stepeni %.f minuta %.f sekundi", nizst[i], fabs(nizm[i]), fabs(nizsek[i]));
	   
		

	
	
	return 0;
}
