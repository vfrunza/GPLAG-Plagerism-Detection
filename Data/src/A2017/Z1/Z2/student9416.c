#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define e 0.0001

int main() {
	double a=0,b=0,c=0,x1,x2,y1,y2,x3,y3,A=0,B=0,C=0,val,t=0;
	int st1=0,st2=0,st3=0, m1=0,m2=0,m3=0,stt=0,mt=0,s1=0,s2=0,s3=0,st=0;
	
	val= 180.0/PI;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);
	
	a= sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	b= sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
	c=sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));

	A= acos((b*b + c*c - a*a)/(2*b*c))*val;
	B= acos((a*a+c*c-b*b)/(2*a*c))*val;
	C= acos((a*a+b*b-c*c)/(2*a*b))*val;
	

	s1= (int)round(3600*A*1000)/1000;
	m1=s1/60;
	s1=s1-60*m1;
	st1=m1/60;
	m1=m1-st1*60;
	
	
	s2= (int)round(3600*B*1000)/1000;
	m2=s2/60;
	s2=s2-60*m2;
	st2=m2/60;
	m2=m2-st2*60;
	
	
	s3= (int)round(3600*C*1000)/1000;
	m3=s3/60;
	s3=s3-60*m3;
	st3=m3/60;
	m3=m3-st3*60;
	

	
	t=A;
			if(B>A) t=B;
			if(C>B) t=C;
			st= (int) round(3600*t*1000)/1000;
			mt=st/60;
			st=st-60*mt;
			stt=mt/60;
			mt=mt-stt*60;
	
	if(fabs(A-180)<e || fabs(B-180)<e || fabs(C-180)<e) {
		printf("Linija\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stt,mt,st);
	}
	else if(fabs(a-b)<e && fabs(b-c)<e && fabs(a-c)<e)
	{printf("Jednakostranicni\n");
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stt,mt,st);}
	else if(fabs(a-b)<e || fabs(a-c)<e || fabs(b-c)<e){
		if(fabs(A-90)<e||fabs(B-90)<e||fabs(C-90)<e){
			printf("Pravougli\n");
			printf("Jednakokraki\n");
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stt,mt,st);
		}else{
			printf("Jednakokraki\n");
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stt,mt,st);
		}
	}else 
	{
		if(fabs(A-90)<e || fabs(B-90)<e || fabs(C-90)<e){
			printf("Pravougli\n");
			printf("Raznostranicni\n");
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stt, mt,st);
		}
		else{
		printf("Raznostranicni\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stt,mt,st);
	}}
	
	
	return 0;
}
