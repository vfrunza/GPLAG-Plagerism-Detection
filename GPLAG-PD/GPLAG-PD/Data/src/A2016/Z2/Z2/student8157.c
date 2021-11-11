#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
int x, i, j;
double 	niz[500], stepen, minuta, sekundi;

printf("Unesite broj uglova: ");
do
{
	scanf("%d", &x);
} while (x<1 || x>500);
for(i=0;i<x;i++)
scanf("%lf", &niz[i]);
for(i=0;i<x;i++)
{
	niz[i]*=180/PI;
	stepen=(int)niz[i];
	minuta=(int)((niz[i]-stepen)*3600)/60;
	sekundi=(int)((niz[i]-stepen)*3600)%60;

		if(sekundi>30){
			niz[i]=niz[x-1];
			x--;
			i--;
		}
	

for(i=0;i<x;i++){
	niz[i]*=180/PI;
	stepen=(int)niz[i];
	minuta=(int)((niz[i]-stepen)*3600)/60;
	sekundi=(int)((niz[i]-stepen)*3600)%60;
	printf("%lf stepeni %lf minuta %lf sekundi\n", stepen, minuta, sekundi);
}
}
	return 0;
}
