#include <stdio.h>
#define PI 3.1415926
#include <math.h> 
int main() {
	int n,j,i;
	double rad[500],deg[500],min[500],sec[500];
	do {
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	if(n>500) {printf("Pogresan unos. "); continue;}
	}while(n>500);
	for (i=0; i<n; i++)
	scanf("%lf",&rad[i]);
		printf("Uglovi su:\n");

	for(i=0; i<n; i++)
	{
	sec[i]=(rad[i]*180./PI)*3600;
	deg[i]=(sec[i])/3600;
	min[i]=((fabs(deg[i])-(int)fabs(deg[i]))*60);
	sec[i]=(fabs(sec[i])-((int)fabs(deg[i])*3600)-((int)fabs(min[i])*60));
	sec[i]=(int)(sec[i]+0.5);
	deg[i]=(int)(deg[i]);
	min[i]=(int)min[i];
if (sec[i]==60) {min[i]++; sec[i]=0;}
if (min[i]==60) 
{ min[i]=0;
if (deg[i]<0) deg[i]--; 
else deg[i]++;}

	if(sec[i]>30)
	{for (j=i; j<n-1; j++)
{	rad[j]=rad[j+1];
	deg[j]=deg[j+1];
	min[j]=min[j+1];
	sec[j]=sec[j+1];}
	n--;
	i--;
	
		

	}}	for(i=0; i<n; i++)
printf("%g stepeni %g minuta %g sekundi\n",deg[i],min[i],sec[i]);

	return 0;
}
