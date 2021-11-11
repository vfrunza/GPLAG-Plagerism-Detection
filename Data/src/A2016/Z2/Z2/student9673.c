#include <stdio.h>
#define PI 3.1415926
#include <math.h>
int main() {
int broj,i,j,br=0;
double rad[500],uksek[500];
int h[500],min[500],sek[500];
printf("Unesite broj uglova: ");
scanf("%d",&broj);
while(broj<=0 || broj>500)
	{
	printf("Pogresan unos! \n");
	printf("Unesite broj uglova: ");
	scanf("%d",&broj);
	if(broj<=0 || broj>500)
	{
	continue;
	}
	else
	{
	break;
	}
	}
while(br<broj)
{
scanf("%lf",&rad[br]);
br++;
}
printf("Uglovi su: \n");
for(i=0;i<broj;i++)
{
uksek[i]=((rad[i]*180)/PI)*3600;

uksek[i]=(int)(uksek[i]+0.5);

h[i]=(uksek[i]/3600);

min[i]=(uksek[i]-h[i]*3600)/60;

sek[i]=uksek[i]-h[i]*3600-min[i]*60;


if(h[i]<0)
{
sek[i]=(sek[i]-1)*(-1);
if(sek[i]>=60){min[i]--;sek[i]=60-sek[i];}
min[i]=(min[i])*(-1);
if(min[i]>=60){h[i]--;min[i]=60-min[i];}
}
else if(h[i]>0){
if(sek[i]>=60)
	{min[i]++;
	sek[i]=sek[i]-60;}
if(min[i]>=60)
	{h[i]++
	;min[i]=min[i]-60;}
}
if(sek[i]>30)
{
for(j=i;j<broj-1;j++)
{
sek[j]=sek[j+1];
}
}
else{
printf("%d stepeni %d minuta %d sekundi\n",h[i],min[i],sek[i]);}
}
return 0;
}