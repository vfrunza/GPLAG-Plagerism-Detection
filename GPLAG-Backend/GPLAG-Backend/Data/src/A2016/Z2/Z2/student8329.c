#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
#define BR 500

int main() {
	int i,j,brugl,stepen,minuta,sekunda;
	double niz[BR];
	double us=0;
	do
	{
		printf("Unesite broj uglova: ");
		scanf("%d",&brugl);
	}
	while(brugl<1);
	
	for(i=0;i<brugl;i++)
	{
		scanf("%lf",&niz[i]);
	}
	printf("Uglovi su:\n");
	for(j=0;j<brugl;j++)
	{
	us=(fabs(niz[j])*180/PI)*3600;
	us=(int)(us+0.5);
	stepen=us/3600;
	minuta=(us-stepen*3600)/60;
	if(us-floor(us)>0.5)
	{
		us=ceil(us);
		sekunda=us-(stepen*3600)-(minuta*60);
	}
	else 
	{
	    us=floor(us);
	    sekunda=us-(stepen*3600)-(minuta*60);
	}
	if(sekunda>=60)
	{
		minuta++;
		sekunda=60;
	}
	if(minuta>=60)
	{
		stepen++;
		minuta=60;
	}
	if(niz[j]<0)
	{
	if(sekunda>30)
	continue;
	else printf("-%d stepeni %d minuta %d sekundi\n",stepen,minuta,sekunda);
	}	
	if(niz[j]>=0)
	{
	if(sekunda>30)
	continue;
	else printf("%d stepeni %d minuta %d sekundi\n",stepen,minuta,sekunda);
	}
	}
	return 0;
	
	
}
