#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
#define EPSILON 0.0001

int main() {
	double x1,x2,x3,y1,y2,y3,d12,d23,d13,P=0, cosalfa1,ugaorad1,ugaos1,cosalfa2,ugaos2,ugaorad2,cosalfa3,ugaos3,ugaorad3;
	double step1,min1,min11,sek1,sek11,step2,min2,min22,sek2,sek22,step3,min3,min33,sek3,sek33;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);


	d12=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	d23=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	d13=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	
    P=fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
	
	if (fabs(P-0)<EPSILON)
	{
		printf ("Linija\n");
		printf ("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}

	if (fabs(d12-d23)<EPSILON && fabs(d12-d13)<EPSILON)
	{
		printf ("Jednakostranicni\n");
		printf ("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	
	if (fabs(d13-d23)<EPSILON || fabs(d13-d12)<EPSILON || fabs(d12-d23)<EPSILON)
	{
		
		cosalfa1=(pow(d13,2)+pow(d23,2)-pow(d12,2))/(2*d13*d23);
		ugaorad1=acos(cosalfa1);
	    ugaos1=(ugaorad1*180)/PI;
	    
	    step1=(int) ugaos1;
		min1=(ugaos1-step1)*60;
		min11=(int) min1;
		sek1=(min1-min11)*60;
		sek11=(int) sek1;
	    
	    cosalfa2=(pow(d13,2)+pow(d12,2)-pow(d23,2))/(2*d13*d12);
		ugaorad2=acos(cosalfa2);
		ugaos2=(ugaorad2*180)/PI;
		
		step2=(int) ugaos2;
		min2=(ugaos2-step2);
		min22=(int) min2;
		sek2=(min2-min22)*60;
		sek22=(int) sek2;
		
		cosalfa3=(pow(d12,2)+pow(d23,2)-pow(d13,2))/(2*d12*d23);
		ugaorad3=acos(cosalfa3);
		ugaos3=(ugaorad3*180)/PI;
		
		step3=(int) ugaos3;
		min3=(ugaos3-step3)*60;
		min33=(int) min3;
		sek3=(min3-min33)*60;
		sek33=(int) sek3;
	
	
		if (fabs(ugaos1-90)<EPSILON || fabs(ugaos2-90)<EPSILON || fabs(ugaos3-90)<EPSILON)
		{
			printf ("Pravougli\n");
		}
		
		printf ("Jednakokraki\n");
		
		if (fabs(ugaos1-ugaos2)<EPSILON && ugaos3>ugaos1)
		{
			printf ("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.", step3,min33,sek33);
		}
		else if (fabs(ugaos1-ugaos2)<EPSILON && ugaos3<ugaos1)
		{
			printf ("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.", step1, min11, sek11);
		}
		else if (fabs(ugaos1-ugaos3)<EPSILON && ugaos2>ugaos1)
		{
			printf ("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.", step2, min22, sek22);
		}
		else if (fabs(ugaos1-ugaos3)<EPSILON && ugaos2<ugaos1)
		{
			printf ("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.", step1, min11, sek11);
		}
		else if (fabs(ugaos2-ugaos3)<EPSILON && ugaos1>ugaos2)
		{
			printf ("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.", step1, min11, sek11);
		}
		else if (fabs(ugaos2-ugaos3)<EPSILON && ugaos1<ugaos2)
		{
			printf ("Najveci ugao ima %.lf stepeni, %.lf minuta, %.lf sekundi", step2, min22, sek22);
		}
		return 0;
	}
	
		
		
		cosalfa1=(pow(d13,2)+pow(d23,2)-pow(d12,2))/(2*d13*d23);
		ugaorad1=acos(cosalfa1);
	    ugaos1=(ugaorad1*180)/PI;
	    
	    step1=(int) ugaos1;
		min1=(ugaos1-step1)*60;
		min11=(int) min1;
		sek1=(min1-min11)*60;
		sek11=(int) sek1;
	    
	    cosalfa2=(pow(d13,2)+pow(d12,2)-pow(d23,2))/(2*d13*d12);
		ugaorad2=acos(cosalfa2);
		ugaos2=(ugaorad2*180)/PI;
		
		step2=(int) ugaos2;
		min2=(ugaos2-step2);
		min22=(int) min2;
		sek2=(min2-min22)*60;
		sek22=(int) sek2;
		
		cosalfa3=(pow(d12,2)+pow(d23,2)-pow(d13,2))/(2*d12*d23);
		ugaorad3=acos(cosalfa3);
		ugaos3=(ugaorad3*180)/PI;
	
    	step3=(int) ugaos3;
		min3=(ugaos3-step3)*60;
		min33=(int) min3;
		sek3=(min3-min33)*60;
		sek33=(int) sek3;
	
	
		if (fabs(ugaos1-90)<EPSILON || fabs(ugaos2-90)<EPSILON || fabs(ugaos3-90)<EPSILON)
		{
			printf ("Pravougli\n");
		}
		printf ("Raznostranicni\n");
		
		if (ugaos1>ugaos2 && ugaos1>ugaos3)
		{
			printf ("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.", step1,min11,sek11);
		}
		else if (ugaos2>ugaos1 && ugaos2>ugaos3)
		{
			printf ("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.", step2,min22,sek22);
		}
		else if (ugaos3>ugaos1 && ugaos3>ugaos2)
		{
			printf ("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.", step3,min33,sek33);
		}
		
	
	return 0;
}
