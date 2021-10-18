#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main() {
	int i,j,br;
	double step,min,sek,ug;
	double niz[500];

printf ("Unesite broj uglova: ");
scanf ("%d", &br);
for (i=0; i<br; i++)
{ 
	scanf ("%lf", &niz[i]);}

for (i=0;i<br;i++)
{
	ug=fabs((niz[i]*180)/PI);
	min=(ug-(int)ug)*60;
	sek=round((min-(int)min)*60); 
	if (sek==60)
	{sek=0; min++;}
   if (sek>30)
   { 
   	for (j=i; j<br-1;j++) {
   		niz [j]= niz[j+1];
   	}
   	br--;
   	i--;
   }}
	


printf ("Uglovi su:\n");
for (i=0;i<br;i++)
{
	ug=(niz[i]*180)/PI;
	min=fabs ((ug-(int)ug)*60);
	sek=round ((min-(int)min)*60);
		
	    step=(int)ug;
	    min=(int)min;
		sek=round(sek);


if (step>=0){
	if (sek==60) {sek=0;min++;}
	if (min==60) {min=0;step++;}}

	if (step<0){
	if (sek==60) {sek=0;min++;}
	if (min==60) {min=0;step--;}}
	
	printf ("%.f stepeni %.f minuta %.f sekundi\n", step, min, sek);
}
	return 0;
}
