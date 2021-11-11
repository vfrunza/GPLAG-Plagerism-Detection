#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define epsilon 0.0001
int main() {
	double PI=acos(-1), val=180.0/PI, t11=0, t12=0, t21=0, t22=0, t31=0, t32=0, d12=0, d23=0, d13=0, u2=0, u1=0, u3=0, m1=0, m2=0, m3=0, s1=0, s2=0, s3=0;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &t11, &t12);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &t21, &t22);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &t31, &t32);
	d12 = sqrt(pow((t11 - t21), 2) + pow((t12 - t22), 2));
	d23 = sqrt(pow((t21 - t31), 2) + pow((t22 - t32), 2));
	d13 = sqrt(pow((t11 - t31), 2) + pow((t12 - t32), 2));
	u2 = acos((pow(d23, 2) + pow(d12, 2) - pow(d13, 2))/(2*d23*d12))*val;
	u1 = acos((pow(d12, 2) + pow(d13, 2) - pow(d23, 2))/(2*d12*d13))*val;
	u3 = acos((pow(d13, 2) + pow(d23, 2) - pow(d12, 2))/(2*d13*d23))*val;
	m1 = (u1 - (int)u1)*60;
	s1 = (m1 - (int)m1)*60;
	m2 = (u2 - (int)u2)*60;
	s2 = (m2 - (int)m2)*60; 
	m3 = (u3 - (int)u3)*60;
	s3 = (m3  - (int)m3)*60;
	if((fabs)(u1 - 90.0)<epsilon || (fabs)(u2 - 90.0)<epsilon || (fabs)(u3 - 90.0)<epsilon)
	{
		printf("Pravougli\n");
	}
	if((fabs)(u1 - 180.0)<epsilon || (fabs)(u2 - 180.0)<epsilon || (fabs)(u3 - 180.0)<epsilon)
	{
		printf("Linija\n");
	}
	else if((fabs)(d12 - d13)<epsilon && (fabs)(d12 - d23)<epsilon && (fabs)(d23 - d13)<epsilon)
	{
		printf("Jednakostranicni\n");
	}
	else if((fabs)(d12 - d13)<epsilon || (fabs)(d13 - d23)<epsilon || (fabs)(d23 - d12)<epsilon)
	{
		printf("Jednakokraki\n");
	}
	else
	{
		printf("Raznostranicni\n");
	}
	if(u1 > u2 && u1 > u3)
	{
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)u1, (int)m1, (int)s1);
	}
	if(u2 > u1 && u2 > u3)
	{
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)u2, (int)m2, (int)s2);
	}
	if(u3 > u2 && u3 > u1)
	{
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)u3, (int)m3, (int)s3);
	}

	return 0;
}
