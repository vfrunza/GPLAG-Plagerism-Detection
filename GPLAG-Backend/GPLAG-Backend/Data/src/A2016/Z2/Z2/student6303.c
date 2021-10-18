#include <stdio.h>
#include <math.h>
#define BROJ_PI 3.1415926
#define VEL 500

int main() {
	double  U[VEL]={0};
	int i, j, c, stepeni_p, minute_p, sekunde_p, S[VEL], M[VEL],SE[VEL],minus=0;
	do{
	printf("Unesite broj uglova: ");
	scanf("%d", &c);
	if(c<0 || c>500)printf("Pogresan unos!\n");
	}while(c<0 || c>500);
	for(i=0; i<c; i++) {
	    scanf("%lf", &U[i]);
	}
	for(i=0;i<c;i++){
		minus=0;
	   if(U[i]<0){minus++;U[i]=-U[i];}
	   stepeni_p=U[i]*180/BROJ_PI;
	   minute_p=((U[i]*180/BROJ_PI)-stepeni_p)*60;
	   sekunde_p=((U[i]*180/BROJ_PI-stepeni_p)*60-minute_p)*60+.5;
	   if(sekunde_p>=60){sekunde_p=sekunde_p-60;minute_p++;}
	   if(minute_p>=60){minute_p=minute_p-60; stepeni_p++;}
	  
	   	if(sekunde_p>30) {
	   		for(j=i; j<c-1; j++)
	   		U[j]=U[j+1];
	   		c--;
	   		i--;
	   		continue;
	   	}
	   	if(minus==1){S[i]=-stepeni_p; M[i]=minute_p;SE[i]=sekunde_p;}
	   	else {S[i]=stepeni_p;M[i]=minute_p;SE[i]=sekunde_p;}
	}
	printf("Uglovi su: \n");
	for(i=0;i<c;i++)
	printf("%d stepeni %d minuta %d sekundi\n",S[i], M[i], SE[i]);
	return 0;
}
