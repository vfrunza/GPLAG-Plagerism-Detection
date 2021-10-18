#include <stdio.h>
#include <math.h>
int main ()
{
	float x1,x2,y1,y2,z1,z2,d12,d13,d23;
	printf("Unesite koordinate tacke t1:\n");
	scanf("%f %f" ,&x1,&x2);
	printf("Unesite koordinate tacke t2:\n");
	scanf("%f %f" ,&y1,&y2);
	printf("Unesite koordinate tacke t3:\n");
	scanf("%f %f",&z1,&z2);
	d12=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	d13=sqrt((z1-x1)*(z1-x1)+(z2-x2)*(z2-x2));
	d23=sqrt((z1-y1)*(z1-y1)+(z2-y2)*(z2-y2));
	if(d12==d13==d23 && cos (60)=0.5)
	printf("Jednakostranicni");
	else
	if(d13==d12!=d23 || d13==d23=!d12 || d23==d12=!d13)
	printf("jednakokraki");
	else 
	if((sin(α)=d12/d13 || cos(α)=d23/d13);
	printf("Pravougli");
	return 0;
}