#include <stdio.h>
#include <math.h>
#define PI 3.14159265359
#define e 0.0001
int main() {
	double a, b, c, x1, x2, x3, y1, y2, y3;
	double alfa,beta,gama;
	int sec1,sec2,sec3,min,mid,max,t;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf%lf",&x1,&y1);/*123.45 543.21*/
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf%lf",&x2,&y2);/*312.43 54.345*/
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf%lf",&x3,&y3);/*234.24 423.54*/
	
	c = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	a = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	b = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));

alfa=acos(0.5*(b*b+c*c-a*a)*(1/b)*(1/c));
beta=acos(0.5*(a*a+c*c-b*b)*(1/a)*(1/c));
gama=acos(0.5*(a*a+b*b-c*c)*(1/a)*(1/b));

sec1=((int)round( ( 3600*360*alfa / (2*PI) ) * 1000 )/1000);
sec2=((int)round( ( 3600*360*beta / (2*PI) ) * 1000 )/1000);
sec3=((int)round( ( 3600*360*gama / (2*PI) ) * 1000 )/1000);

min=sec1;
mid=sec2;
max=sec3;

if(min>mid)
{
	t=min;
	min=mid;
	mid=t;
}
if(mid>max)
{
	t=mid;
	mid=max;
	max=t;
}
if(min>mid)
{
	t=min;
	min=mid;
	mid=t;
}
if(mid>max)
{
	t=mid;
	mid=max;
	max=t;
}

printf("\n%d\n%d\n%d\n",min,mid,max);/*Gubim jednu sekundu */

if(min<=0){
	
	printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	
}
else
{
	if(max==60*3600)
	{
		printf("Jednakostranicni");
		
	}
	
	else if(min==mid/*fabs(a-b)<e||fabs(a-c)<e||fabs(b-c)<e*/)
	{
	if(max==90*3600)printf("Pravougli\nJednakokraki");
	else printf("Jednakokraki");
	}
	else
	{
		if(max==90*3600)printf("Pravougli\nRaznostranicni");
		else
		printf("Raznostranicni");
	}
	
	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",max/3600,max/60-60*(max/3600),max-60*(max/60));
}


	return 0;
}
