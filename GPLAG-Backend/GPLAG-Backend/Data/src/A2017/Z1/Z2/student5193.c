#include <stdio.h>
#include <math.h>
#define e 0.0001 
#define PI 3.14159265
int main() 
{
	int ukupnesekunde,sekunde,minute,stepeni;
	double stepen=0;
	double d1,d2,d3;
	double x1,x2,x3,y1,y2,y3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	d1=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	
	d2=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	
	d3=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
	
	if(d1>=(d2-e) && d1<=(d2+e) && d2>=(d3-e) && d2<=(d3+e)) 
	{
		printf("Jednakostranicni\n");
		stepen=60;
	}
	else
	{
		
		double val = (180.0 / PI);
		double L=acos((d1*d1+d2*d2-d3*d3)/(2*d1*d2))*val;
		double B=acos((d3*d3+d1*d1-d2*d2)/(2*d3*d1))*val;
		double G=180.0-L-B;
		if(L>B && L>G) stepen=L;
		else if(B>L && B>G) stepen=B;
		else stepen=G;
		if(90>=(stepen-e) && 90<=(stepen+e)) printf("Pravougli\n");
		if(fabs(stepen-180)<e)
		{
			printf("Linija\n");
		}
		else if((d1>=(d2+e) || d1<(d2-e)) && (d2>=(d3+e) || d2<=(d3-e)) && (d1>=(d3+e) || d1<=(d3-e)))
		{
			printf("Raznostranicni\n");
		}
		else
		{
			printf("Jednakokraki\n");
		}
	}
	ukupnesekunde=stepen*60*60;
	sekunde = ukupnesekunde % 60;
    minute = (ukupnesekunde / 60) % 60;
    stepeni = ukupnesekunde / (60 * 60);
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	return 0;
}