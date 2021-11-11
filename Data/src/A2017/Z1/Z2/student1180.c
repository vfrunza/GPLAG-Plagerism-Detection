#include <stdio.h>
#include <math.h>
#define epsilon 0.0001


int main() {
	double PI=4*atan(1);
	double t1x,t2x,t3x,t1y,t2y,t3y;
	double t1t2,t2t3,t3t1;
	double fi1,fi2,fi3;
	double a,b,c,max;
	int stepen,minute,sekunde;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&t1x,&t1y);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&t2x,&t2y);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&t3x,&t3y);
	//printf("\n");
	
	t1t2=pow(t2x-t1x,2)+pow(t2y-t1y,2);
	t2t3=pow(t3x-t2x,2)+pow(t3y-t2y,2);
	t3t1=pow(t1x-t3x,2)+pow(t1y-t3y,2);
	
	a=sqrt(t1t2);
	b=sqrt(t2t3);
	c=sqrt(t3t1);
	
	fi1=acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
	fi2=acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
	fi3=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b));
	
	fi1=fi1*180/PI;
	fi2=fi2*180/PI;
	fi3=fi3*180/PI;
	
	//printf("%f %f %f \n",fi1,fi2,fi3);
	if(fi1==180 || fi2==180 || fi3==180)
		printf("Linija\n");
	else 
	{
	
		if(fabs((int)fi1-90)<epsilon || fabs((int)fi2-90)<epsilon || fabs((int)fi3-90)<epsilon)
		{
			printf("Pravougli\n");
		}
		
		if(fabs(t1t2-t2t3)<epsilon && fabs(t1t2-t3t1)<epsilon)
		{
			printf("Jednakostranicni\n");
		}
		
		if(fabs(t1t2-t2t3)>epsilon && fabs(t1t2-t3t1)>epsilon && fabs(t2t3-t3t1)>epsilon)
		{
			printf("Raznostranicni\n");
		}
		 if(fabs(t1t2-t2t3)<epsilon && fabs(t1t2-t3t1)>epsilon)
		{
			printf("Jednakokraki\n");
		}
	   
	    if(fabs(t1t2-t3t1)<epsilon && fabs(t1t2-t2t3)>epsilon)
		{
			printf("Jednakokraki\n");
		}
	   
	    if(fabs(t2t3-t3t1)<epsilon && fabs(t2t3-t1t2)>epsilon)
		{
			printf("Jednakokraki\n");
		}
		
	}

	max=fi1;
	if(fi2>max)max=fi2;
    if(fi3>max)max=fi3;
	
	//printf("%f",max);
	stepen=(int)max;
	minute=(int)((max-stepen)*60);
	sekunde=((((max-stepen)*60))-minute)*60;
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen,minute,sekunde);
	return 0;
}
