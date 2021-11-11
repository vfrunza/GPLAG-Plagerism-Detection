#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.1415926

int main() {
	double t1x,t1y,t2x,t2y,t3x,t3y,a,b,c,d1,d2,alfa,beta,gama,rad1,rad11,rad111,rad2,rad22,rad222,rad3,rad33,rad333;
	int step1,min1,sek1,step2,min2,sek2,step3,min3,sek3;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&t1x,&t1y);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&t2x,&t2y);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&t3x,&t3y);
	
	a=sqrt((t1x-t2x)*(t1x-t2x) + (t1y-t2y)*(t1y-t2y));
	b=sqrt((t2x-t3x)*(t2x-t3x) + (t2y-t3y)*(t2y-t3y));
	c=sqrt((t3x-t1x)*(t3x-t1x) + (t3y-t1y)*(t3y-t1y));
	d1=t1x*t2y+t2x*t3y+t3x*t1y;
	d2=t2x*t1y+t3x*t2y+t1x*t3y;
	
	alfa=acos((b*b+c*c-a*a)/(2*b*c));
	beta=acos((a*a+c*c-b*b)/(2*a*c));
	gama=acos((a*a+b*b-c*c)/(2*a*b));
	
	rad1=(alfa*180.0)/PI;
	step1=(int)rad1;
	rad11=fabs(rad1-step1)*60;
	min1=(int)rad11;
	rad111=fabs(rad11-min1)*60;
	sek1=(int)rad111;
	
	if (sek1>=60)
	{
		sek1=0;
		min1++;
	}
	if (min1>=60)
	{
		min1=0;
		step1++;
	}
	
	rad2=(beta*180.0)/PI;
	step2=(int)rad2;
	rad22=fabs(rad2-step2)*60;
	min2=(int)rad22;
	rad222=fabs(rad22-min2)*60;
	sek2=(int)rad222;
	
	if (sek2>=60)
	{
		sek2=0;
		min2++;
	}
	if (min2>=60)
	{
		min2=0;
		step2++;
	}
	
	rad3=(gama*180.0)/PI;
	step3=(int)rad3;
	rad33=fabs(rad3-step3)*60;
	min3=(int)rad33;
	rad333=fabs(rad33-min3)*60;
	sek3=(int)rad333;
	
	if (sek3>=60)
	{
		sek3=0;
		min3++;
	}
	if (min3>=60)
	{
		min3=0;
		step3++;
	}
	
	if (fabs(a-b)<EPSILON && fabs(b-c)<EPSILON)
		printf("Jednakostranicni\n");
	if (fabs(d1-d2)<EPSILON)
		printf("Linija\n");
	if ((fabs(alfa-PI/2)<EPSILON) || (fabs(beta-PI/2)<EPSILON) || (fabs(gama-PI/2)<EPSILON))
		printf("Pravougli\n");
	if (fabs(a-b)>EPSILON && fabs(a-c)>EPSILON && fabs(b-c)>EPSILON)
		printf("Raznostranicni\n");
	if ((fabs(b-c)<EPSILON && fabs(a-b)>EPSILON && fabs(d1-d2)>EPSILON) || (fabs(a-c)<EPSILON && fabs(b-a)>EPSILON && fabs(d1-d2)>EPSILON) || (fabs(a-b)<EPSILON && fabs(c-a)>EPSILON && fabs(d1-d2)>EPSILON))
		printf("Jednakokraki\n");

	if (step1>=step2 && step1>=step3)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",step1,min1,sek1);
	else if (step2>=step1 && step2>=step3)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",step2,min2,sek2);
	else if (step3>=step1 && step3>=step2)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",step3,min3,sek3);
	
	

	return 0;
}
