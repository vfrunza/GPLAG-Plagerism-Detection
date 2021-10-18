#include <stdio.h>
#include <math.h>
#define eps 0.0001

int main() {
	int H,M,S,pomocna;
	double x1,x2,x3,y1,y2,y3,a,b,c,tester,pomocna1,PI;
	PI= 4*atan(1);
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1 );
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2 );
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3 );
	
	a=acos((pow(sqrt(pow(x3-x1,2)+pow(y3-y1,2)),2)+pow(sqrt(pow(x1-x2,2)+pow(y1-y2,2)),2)-pow(sqrt(pow(x3-x2,2)+pow(y3-y2,2)),2))/(2*sqrt(pow(x3-x1,2)+pow(y3-y1,2))*sqrt(pow(x1-x2,2)+pow(y1-y2,2))))*180/PI;
	b=acos((pow(sqrt(pow(x3-x2,2)+pow(y3-y2,2)),2)+pow(sqrt(pow(x1-x2,2)+pow(y1-y2,2)),2)-pow(sqrt(pow(x3-x1,2)+pow(y3-y1,2)),2))/(2*sqrt(pow(x3-x2,2)+pow(y3-y2,2))*sqrt(pow(x1-x2,2)+pow(y1-y2,2))))*180/PI;
	c=180-a-b;

	if(fabs(a-180)<eps|| fabs(b-180)<eps || fabs(c-180)<eps) printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	else
	{
		if((fabs(a-90)<eps|| fabs(b-90)<eps || fabs(c-90)<eps )&& (fabs(sqrt(pow(x3-x2,2)+pow(y3-y2,2))-sqrt(pow(x3-x1,2)+pow(y3-y1,2)))<eps || fabs(sqrt(pow(x3-x1,2)+pow(y3-y1,2))-sqrt(pow(x1-x2,2)+pow(y1-y2,2)))<eps || fabs(sqrt(pow(x3-x2,2)+pow(y3-y2,2))-sqrt(pow(x1-x2,2)+pow(y1-y2,2)))<eps)) 
		{
			printf("Pravougli\n");
			printf("Jednakokraki\n");
		}
		
		else if(fabs(a-90)<eps|| fabs(b-90)<eps || fabs(c-90)<eps )
		{
			printf("Pravougli\n");
			printf("Raznostranicni\n");
		}
		
		else if((fabs((sqrt(pow(x1-x2,2)+pow(y1-y2,2))-sqrt(pow(x3-x1,2)+pow(y3-y1,2)))<eps && fabs(sqrt(pow(x3-x1,2)+pow(y3-y1,2))-sqrt(pow(x3-x2,2)+pow(y3-y2,2)))<eps && fabs(sqrt(pow(x3-x2,2)+pow(y3-y2,2))-sqrt(pow(x1-x2,2)+pow(y1-y2,2)))<eps))|| (fabs(a-60)<eps && fabs(b-60)<eps && fabs(c-60)<eps))
		printf("Jednakostranicni\n");
		
		else if(fabs(sqrt(pow(x3-x2,2)+pow(y3-y2,2))-sqrt(pow(x1-x2,2)+pow(y1-y2,2)))<eps || fabs(sqrt(pow(x3-x2,2)+pow(y3-y2,2))-sqrt(pow(x3-x1,2)+pow(y3-y1,2)))<eps || fabs(sqrt(pow(x1-x2,2)+pow(y1-y2,2))-sqrt(pow(x3-x1,2)+pow(y3-y1,2)))<eps)
		printf("Jednakokraki\n");
		
		else printf("Raznostranicni\n");
		
		if(a>b && a>c)
		{
			H=a; pomocna=a;
			M=(a-H)*60; pomocna1=(a-pomocna)*60;
			pomocna=pomocna1;
			S=(pomocna1-pomocna)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", H, M, S);
		}
		
		else if(b>a && b>c)
		{
			H=b; pomocna=b;
			M=(b-H)*60; pomocna1=(b-pomocna)*60;
			pomocna=pomocna1;
			S=(pomocna1-pomocna)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", H, M, S);
		}
		
		else
		{
			H=c; pomocna=c;
			M=(c-H)*60; pomocna1=(c-pomocna)*60;
			pomocna=pomocna1;
			S=(pomocna1-pomocna)*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", H, M, S);
		}
		
		
	}
	
	return 0;
}
