#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	
	double niz[500]={0};
	int step[500]={0}, min[500]={0}, sek[500]={0}, i=0, j=0;
	double unos=0;
	int n=0;
	do 
	{
printf("Unesite broj uglova: ");
scanf("%d", &n);
if(n < 1 || n > 500)
printf("Pogresan unos\n");
}
while(n < 1 || n > 500);
for(i = 0; i < n; i++)
{
scanf("%lf", &unos);
niz[i] = unos * 180 / PI;
step[i] = niz[i];
min[i] = (niz[i] - step[i]) * 60;
sek[i] = (niz[i] - step[i] - (double)min[i] / 60) * 3600;
if (step[i] >=0)
sek[i] = (niz[i] - step[i] - (double)min[i] / 60) * 3600 + 0.5;
else  
sek[i] = (niz[i] - step[i] - (double)min[i] / 60) * 3600 - 0.5;
if(sek[i] == 60)
{
	sek[i] = 0;
	min[i]++;
}
else if (sek[i] == -60)
{ 
sek[i] = 0;
min[i]--;
}
if(min[i] == 60) 
{
	min[i] = 0;
	step[i]++;
}
	else if(min[i] == -60)
	{
	min[i] = 0;
	step[i]--;
	}
}
for(i = 0; i < n; i++)
if(sek[i] > 30 || sek[i] <-30)
{
	for(j = i; j < n-1; j++)
{
step[j] = step[j+1];
min [j] = min[j+1];
sek[j] = sek [j+1];
}
i--;
n--;
}
printf("Uglovi su:\n");
for(i = 0; i < n; i++)
printf("%d stepeni %d minuta %d sekundi\n", step[i], abs(min[i]), abs(sek[i]));
return 0;
}





