#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	double x1, x2, x3, y1, y2, y3, d1, d2, d3, alfa, beta, gama, max, k, n;
	int stepen, minuta, sekunda;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf\n", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf\n", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf\n", &x3, &y3);
	
	k=(y1-y2)/(x1-x2);
	n=y1-(((y1-y2)/(x1-x2))*x1);
	
	if(fabs(y3-k*x3-n)<EPSILON){
		printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 10;
	}
	
	d1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	d2=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	d3=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	
	if (((fabs(x1-x2)<EPSILON) && (fabs(x1-x3)<EPSILON) && (fabs(x2-x3)<EPSILON)) || ((fabs(y1-y2)<EPSILON) && (fabs(y1-y2)<EPSILON) && (fabs(y2-y3)<EPSILON))) 
	{
		printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 1;
	}
	
	else if((fabs(d1-d2)<EPSILON) && (fabs(d2-d3)<EPSILON) && (fabs(d1-d3)<EPSILON))
	{
		printf("Jednakostranicni\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		return 2;
	}
	
	else
	{
		if(((fabs(d3*d3-d2*d2-d1*d1)<EPSILON) || (fabs(d2*d2-d1*d1-d3*d3)<EPSILON) || (fabs(d1*d1-d2*d2-d3*d3)<EPSILON)) && ((fabs(d1-d2)<EPSILON) || (fabs(d2-d3)<EPSILON) || (fabs(d1-d3)<EPSILON)))
		{
			printf("Pravougli\nJednakokraki\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
			return 3;
		}
		
		else if((fabs(d3*d3-d2*d2-d1*d1)<EPSILON) || (fabs(d2*d2-d1*d1-d3*d3)<EPSILON) || (fabs(d1*d1-d2*d2-d3*d3)<EPSILON))
		{	
			printf("Pravougli\nRaznostranicni\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
			return 4;
		}	
		else if((fabs(d1-d2)<EPSILON) || (fabs(d2-d3)<EPSILON) || (fabs(d1-d3)<EPSILON))
		{
			alfa=acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3));
			beta=acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3));
			gama=acos((d1*d1+d2*d2-d3*d3)/(2*d1*d2));
			
			alfa=(alfa*180)/(3.1415926);
			max=alfa;
			beta=(beta*180)/(3.1415926);
			if(beta>max)
			max=beta;
			gama=(gama*180)/(3.1415926);
			if(gama>max)
			max=gama;
			
			if(fabs(max-alfa)<EPSILON)
			{
			stepen=(int) alfa;
			minuta=(int) ((alfa-stepen)*60);
			sekunda=(int) (((alfa-stepen)*60-minuta)*60);
			
			printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sekunda);
			return 5;
			}
			
			else if(fabs(max-beta)<EPSILON)
			{
			stepen=(int) beta;
			minuta=(int) ((beta-stepen)*60);
			sekunda=(int) (((beta-stepen)*60-minuta)*60);	
			
			printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sekunda);
			return 6;	
				}
				
			else if(fabs(max-gama)<EPSILON)
			{
			stepen=(int) gama;
			minuta=(int) ((gama-stepen)*60);
			sekunda=(int) (((gama-stepen)*60-minuta)*60);	
			
			printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sekunda);
			return 7;	
			}
		}
		else if(fabs(d1-d2)>EPSILON && fabs(d1-d3)>EPSILON && fabs(d2-d3)>EPSILON)
		{
			alfa=acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3));
			beta=acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3));
			gama=acos((d1*d1+d2*d2-d3*d3)/(2*d1*d2));
			
			alfa=(alfa*180)/(3.1415926);
			max=alfa;
			beta=(beta*180)/(3.1415926);
			if(beta>max)
			max=beta;
			gama=(gama*180)/(3.1415926);
			if(gama>max)
			max=gama;
			
			if(fabs(max-alfa)<EPSILON)
			{
			stepen=(int) alfa;
			minuta=(int) ((alfa-stepen)*60);
			sekunda=(int) (((alfa-stepen)*60-minuta)*60);
			
			printf("Raznostranicni\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sekunda);
			return 8;
			}
			
			else if(fabs(max-beta)<EPSILON)
			{
			stepen=(int) beta;
			minuta=(int) ((beta-stepen)*60);
			sekunda=(int) (((beta-stepen)*60-minuta)*60);	
			
			printf("Raznostranicni\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sekunda);
			return 9;	
				}
				
			else if(fabs(max-gama)<EPSILON)
			{
			stepen=(int) gama;
			minuta=(int) ((gama-stepen)*60);
			sekunda=(int) (((gama-stepen)*60-minuta)*60);	
			
			printf("Raznostranicni\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sekunda);
			return 10;	
		}
		}
	}
	return 0;
}
