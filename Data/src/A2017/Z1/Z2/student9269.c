#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.141592

int main() {
	
	double x1, x2, x3, y1, y2, y3, d1, d2, d3, ugao1, ugao2, ugao3;
	int stepeni1, stepeni2, stepeni3, minute1, minute2, minute3, sekunde1, sekunde2, sekunde3;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);
	
	d1=sqrt(pow(x2-x1, 2)+(pow(y2-y1, 2)));
	d2=sqrt(pow(x2-x3, 2)+(pow(y2-y3, 2)));
	d3=sqrt(pow(x3-x1, 2)+(pow(y3-y1, 2)));
	
	ugao1=acos((d2*d2 + d3*d3 - d1*d1) / (2*d3*d2))*(180/PI);
	ugao2=acos((d3*d3 + d1*d1 - d2*d2) / (2*d3*d1))*(180/PI);
	ugao3=acos((d2*d2 + d1*d1 - d3*d3) / (2*d1*d2))*(180/PI);
	
	stepeni1=(ugao1);
	minute1=((ugao1-stepeni1)*60);
	sekunde1=(((ugao1-stepeni1)*60-minute1)*60);
	
	stepeni2=(ugao2);
	minute2=((ugao2-stepeni2)*60);
	sekunde2=(((ugao2-stepeni2)*60-minute2)*60);
	
	stepeni3=(ugao3);
	minute3=((ugao3-stepeni3)*60);
	sekunde3=(((ugao3-stepeni3)*60-minute3)*60);
	
	if (fabs(d1-(d2+d3))<epsilon || fabs(d2-(d1+d3))<epsilon || fabs(d3-(d1+d2))<epsilon) 
	{
		printf ("Linija\n");
	} else {
		if (fabs(pow(d3, 2)-pow(d2, 2)-pow(d1, 2))<epsilon || fabs(pow(d1, 2)-pow(d2, 2)-pow(d3, 2))<epsilon || fabs(pow(d2, 2)-pow(d3, 2)-pow(d1, 2))<epsilon)
	{
		printf ("Pravougli\n");
	} if ( fabs(d1-d2)<epsilon && fabs(d2-d3)<epsilon && fabs(d3-d1)<epsilon)
	{
		printf ("Jednakostranicni\n");
	} else if ( fabs(d1-d2)<epsilon || fabs(d2-d3)<epsilon || fabs(d3-d1)<epsilon)
	{
		printf ("Jednakokraki\n");
	}  else if (fabs(d1-d2)>epsilon && fabs(d2-d3)>epsilon && fabs(d3-d1)>epsilon)
	{
		printf ("Raznostranicni\n");
	}
	} if(ugao1>=ugao2 && ugao1>=ugao3)
	{
		printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", stepeni1, minute1, sekunde1);
	} else if (ugao2>=ugao3 && ugao2>=ugao1)
	{
		printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", stepeni2, minute2, sekunde2);
	} else if (ugao3>=ugao1 && ugao3>=ugao2)
	{
		printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", stepeni3, minute3, sekunde3);
	}
	return 0;
}