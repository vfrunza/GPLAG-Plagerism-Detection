#include <stdio.h>
#define e 0.0001
#include <math.h>
int main() {
	
	double x1,x2,x3,y1,y2,y3;
	double d1,d2,d3;
	double min,max;
	double angle=0,m=0,s=0;
	double temp=0;
	printf("Unesite koordinate tacke t1: ");scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");scanf("%lf %lf",&x3,&y3);
			
	d1=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	d2=sqrt(pow((x3-x2),2)+pow((y3-y2),2));	
	d3=sqrt(pow((x1-x3),2)+pow((y1-y3),2));
			
			min=d1;max=d1;
			
			if(d2<min)min=d2;
			if(d3<min)min=d3;
			if(d2>max)max=d2;
			if(d3>max)max=d3;
			
			if(fabs(max-d1)<=e)//ako je a najveca ugao a
			{
					angle=acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3))*(180/3.14159265);
			}
			
				if(fabs(max-d2)<=e)//za b
				{
					angle=acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3))*(180/3.14159265);
				}
				
					if(fabs(max-d3)<=e)//za c
					{
						angle=acos((d1*d1+d2*d2-d3*d3)/(2*d1*d2))*(180/3.14159265);
					}
					
					if(angle<e || fabs(angle-180)<e)printf("Linija\n");
					else{
					if(fabs(angle-90)<=e)printf("Pravougli\n");
					if(fabs(d1-d2)<e && fabs(d2-d3)<e) printf("Jednakostranicni\n");
					else if(fabs(d1-d2)<e || fabs(d1-d3)<e || fabs(d2-d3)<e)printf("Jednakokraki\n");
					else printf("Raznostranicni\n");
					
					}
					//u min i sec
				
					if(angle-(int)angle>e)
					{
						
					temp=(angle-(int)angle)*60;
					m=(int)temp;
					temp=temp-(int)temp;
					s=temp*60;
					s=(int)s;
					
					}
					angle=(int)angle;
					
				printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",fabs(angle),fabs(m),fabs(s));	
	return 0;
}
