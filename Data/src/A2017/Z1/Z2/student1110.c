#include <stdio.h>
#include <math.h>

#define E 0.0001
#define PI 3.14159265359

int main() 
{
	int U1, U2, U3, M1, M2, M3, S1, S2, S3, s=0;
	float x1, x2, x3, y1, y2, y3, a, b, c, u1, u2, u3, m1, m2, m3, s1, s2, s3;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%f %f", &x1, &y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%f %f", &x2, &y2);
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%f %f", &x3, &y3);
	
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	
	u1=acos((b*b+c*c-a*a)/(2*b*c));
	u2=acos((c*c+a*a-b*b)/(2*c*a));
	u3=acos((a*a+b*b-c*c)/(2*a*b));

	u1=(u1*180)/PI;
	u2=(u2*180)/PI;
	u3=(u3*180)/PI;
	
	if((u1>=0 && u1<E) || (u2>=0 && u2<E) || (u3>=0 && u3<E))
	{
		printf("Linija");
		s++;
	}
	else if(u1-u2<E && u2-u3<E && u3-u1<E) printf("Jednakostranicni");
	else if((u1-90<E && u1-90>=0 && u2-u3<E && u2-u3>=0) || (u2-90<E && u2-90>=0 && u3-u1<E && u3-u1>=0) || (u3-90<E && u3-90>=0 && u1-u2<E && u1-u2>=0)) printf("Pravougli\nJednakokraki");
	else if((u1-90<E && u1-90>=0) || (u2-90<E && u2-90>=0) || (u3-90<E && u3-90>=0)) printf("Pravougli\nRaznostranicni");
	else if((u1-u2<E && u1-u2>=0) || (u2-u3<E && u2-u3>=0) || (u3-u1<E && u3-u1>=0)) printf("Jednakokraki");
	else printf("Raznostranicni");
	
	m1=u1-(int)u1;
	m2=u2-(int)u2;
	m3=u3-(int)u3;
	
	u1=(int)u1;
	u2=(int)u2;
	u3=(int)u3;
	
	m1=m1*60;
	m2=m2*60;
	m3=m3*60;
	
	s1=m1-(int)m1;
	s2=m2-(int)m2;
	s3=m3-(int)m3;
	
	m1=(int)m1;
	m2=(int)m2;
	m3=(int)m3;
	
	s1=s1*60;
	s2=s2*60;
	s3=s3*60;
	
	s1=(int)(s1+0.45);
	s2=(int)(s2+0.45);
	s3=(int)(s3+0.45);
	
	U1=u1;
	U2=u2;
	U3=u3;
	M1=m1;
	M2=m2;
	M3=m3;
	S1=s1;
	S2=s2;
	S3=s3;
	
	printf("\n");
	
	if(s==1) printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	else
	{	if((U1>U2 && U1>U3) || (U1>=U2 && U1>=U3 && M1>=M2 && M1>=M3 && S1>=S2 && S1>=S3)) printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", U1, M1, S1);
		else if((U2>U1 && U2>U3) || (U2>=U1 && U2>=U3 && M2>=M1 && M2>=M3 && S2>=S1 && S2>=S3)) printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", U2, M2, S2);
		else if((U3>U2 && U3>U1) || (U3>=U2 && U3>=U1 && M3>=M2 && M3>=M1 && S3>=S2 && S3>=S1)) printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", U3, M3, S3);
	}
	
	return 0;
}