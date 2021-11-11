#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {

double niz[500], stepeni=0, stepenip=0, minute=0, minutep=0, sekunde=0, sekundep=0;
int j, i, n1=0, n;

printf("Unesite broj uglova: ");
do {
scanf("%d", &n);
} while(n<1 || n>500);

for (i=0; i<n; i++) {
	scanf("%lf", &niz[i]); 
    stepeni=niz[i]*(180/PI);
    stepenip=(int)stepeni;
    minute=fabs((stepeni-stepenip)*60);
    minutep=(int)minute;
    sekunde=fabs((minute-minutep)*60);
    sekundep=(int)(sekunde+0.5);
    if (sekundep>=60) {minutep++; sekundep=sekundep-60; }
    if (minutep>=60)  {stepenip++; minutep=minutep-60;}
    if(sekundep>30){
        for(j=i; j<n-1;j++){ niz[j]=niz[j+1];}
        n--;
        i--;
    } 
}

n1=i;
printf("Uglovi su: \n");
for(i=0; i<n1; i++){
    stepeni=niz[i]*(180/PI);
    stepenip=(int)stepeni;
    minute=fabs((stepeni-stepenip)*60);
    minutep=(int)minute;
    sekunde=fabs((minute-minutep)*60);
    sekundep=(int)(sekunde+0.5);
    if(stepenip<0) { 
    
    if (sekundep>=60 || sekundep<=-60) {minutep++; sekundep=sekundep-60; }
    if (minutep>=60 || minutep<=-60)  {stepenip--; minutep=minutep-60;}
        
    }
        
    if (sekundep>=60 || sekundep<=-60) {minutep++; sekundep=sekundep-60; }
    if (minutep>=60 || minutep<=-60)  {stepenip++; minutep=minutep-60;}
    printf("%.f stepeni %.f minuta %.f sekundi\n", stepenip, minutep, sekundep);
}
	
	return 0;
}
