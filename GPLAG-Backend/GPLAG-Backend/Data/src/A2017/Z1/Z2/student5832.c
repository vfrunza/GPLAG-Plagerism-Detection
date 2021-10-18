#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define EPSILON 0.001

int main()
{
	double x1,x2,x3,y1,y2,y3,dij1,dij2,dij3,alfa,beta,gama;
	double pret=180./PI;
	float najveciugao;
	float  step,min,sec;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	dij1=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	dij2=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
	dij3=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
	
	alfa=acos((dij1*dij1+dij2*dij2-dij3*dij3)/(2*dij1*dij2))*pret;
	beta=acos((dij3*dij3+dij1*dij1-dij2*dij2)/(2*dij3*dij1))*pret;
	gama=180. - alfa - beta;


	if((alfa>beta)&&(alfa>gama))
		{
	  najveciugao=alfa;
		}
	 if((beta>alfa)&&(beta>gama))
		{
			najveciugao=beta;
		}
	 if((gama>alfa)&&(gama>beta))
		{
		najveciugao=gama;
		}
	int a,b,c;
	a=(int)(dij1);
	b=(int)(dij2);
	c=(int)(dij3);
	int ugao=(int)najveciugao;
	if((ugao==180)||(ugao==0))
		{
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
		}
	if(ugao==60)
		{
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		return 0;
		}
	if(ugao==90)
		{
		printf("Pravougli\n");	
		}
	if((dij1!=dij2)&&(dij1!=dij3)&&(dij2!=dij3)&&(fabs(dij1-dij2)>EPSILON)&&(fabs(dij1-dij3)>EPSILON)&&(fabs(dij2-dij3)>EPSILON))
		{
		printf("Raznostranicni\n");
		}
	if(((fabs(dij1-dij2)<EPSILON)&&(dij1!=dij3)&&(dij2!=dij3))||((fabs(dij2-dij3)<EPSILON)&&(dij2!=dij1)&&(dij3!=dij1))||((fabs(dij1-dij3)<EPSILON)&&(dij1!=dij2)&&(dij2!=dij3)))
		{
		printf("Jednakokraki\n");
		}
	step=najveciugao-ugao;
	min=(step*60.);
	int minuta =(int)(min);
	sec=(step - minuta/60.)*3600.;
	int sekunda=(int)(sec);
	
	printf("Najveci ugao ima %i stepeni, %i minuta i %i sekundi.",ugao,minuta,sekunda);
	
	return 0;
}
