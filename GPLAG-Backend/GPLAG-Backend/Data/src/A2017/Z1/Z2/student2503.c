#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define pi 3.14159265359

int main()
{
	double x1,x2,x3,y1,y2,y3,a,b,c,u1s1,u2s1,u3s1,u1m1,u2m1,u3m1,u1se1,u2se1,u3se1,Q,W,E,u1s2,u2s2,u3s2,u1m2,u2m2,u3m2,u1se2,u2se2,u3se2,x=0,y=0,z=0;
	u1s2=0;
	u2s2=0;
	u3s2=0;
	u1m2=0;
	u2m2=0;
	u3m2=0;
	u1se2=0;
	u2se2=0;
	u3se2=0;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf%lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf%lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf%lf",&x3,&y3);
	a=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	c=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	Q=acos((b*b+c*c-a*a)/(2.*b*c));
	W=acos((a*a+c*c-b*b)/(2.*a*c));
	E=acos((b*b+a*a-c*c)/(2.*a*b));
	u1s1=180.*Q/pi;
	u2s1=180.*W/pi;
	u3s1=180.*E/pi;
	if(fabs(u1s1-round(u1s1))<epsilon) u1s2=round(u1s1);
	else u1s2=floor(u1s1);
	if(fabs(u2s1-round(u2s1))<epsilon) u2s2=round(u2s1);
	else u2s2=floor(u2s1);
	if(fabs(u3s1-round(u3s1))<epsilon) u3s2=round(u3s1);
	else u3s2=floor(u3s1);
	u1m1=60.*fabs(u1s1-u1s2);
	u2m1=60.*fabs(u2s1-u2s2);
	u3m1=60.*fabs(u3s1-u3s2);
	if(fabs(u1m1-round(u1m1))<epsilon) u1m2=round(u1m1);
	else u1m2=floor(u1m1);
	if(fabs(u2m1-round(u2m1))<epsilon) u2m2=round(u2m1);
	else u2m2=floor(u2m1);
	if(fabs(u3m1-round(u3m1))<epsilon) u3m2=round(u3m1);
	else u3m2=floor(u3m1);
	u1se1=60.*fabs(u1m1-u1m2);
	u2se1=60.*fabs(u2m1-u2m2);
	u3se1=60.*fabs(u3m1-u3m2);
	if(fabs(u1se1-round(u1se1))<epsilon) u1se2=round(u1se1);
	else u1se2=floor(u1se1);
	if(fabs(u2se1-round(u2se1))<epsilon) u2se2=round(u2se1);
	else u2se2=floor(u2se1);
	if(fabs(u3se1-round(u3se1))<epsilon) u3se2=round(u3se1);
	else u3se2=floor(u3se1);

	if(((u1s1-u2s1)>epsilon || (u1s1-u2s1)==epsilon) && ((u1s1-u3s1)>epsilon || (u1s1-u3s1)==epsilon)) {
		x=u1s2;
		y=u1m2;
		z=u1se2;
	} else if(((u2s1-u1s1)>epsilon || (u2s1-u1s1)==epsilon) && ((u2s1-u3s1)>epsilon || (u2s1-u3s1)==epsilon)) {
		x=u2s2;
		y=u2m2;
		z=u2se2;
	} else if(((u3s1-u1s1)>epsilon || (u3s1-u1s1)==epsilon) && ((u3s1-u2s1)>epsilon || (u3s1-u2s1)==epsilon)) {
		x=u3s2;
		y=u3m2;
		z=u3se2;
	} else if(fabs(u1s1-u2s1)<epsilon && fabs(u1s1-u3s1)<epsilon && fabs(u2s1-u3s1)<epsilon ) {
		x=u1s2;
		y=u1m2;
		z=u1se2;
	} else if(fabs(u1s1-u2s1)<epsilon && ((u1s1-u3s1)>epsilon || (u1s1-u3s1)==epsilon )) {
		x=u1s2;
		y=u1m2;
		z=u1se2;
	} else if(fabs(u1s1-u3s1)<epsilon && ((u1s1-u2s1)>epsilon || (u1s1-u2s1)==epsilon)) {
		x=u1s2;
		y=u1m2;
		z=u1se2;
	} else if(fabs(u2s1-u3s1)<epsilon && ((u2s1-u1s1)>epsilon || (u2s1-u1s1)==epsilon)) {
		x=u2s2;
		y=u2m2;
		z=u2se2;
	}


	if(fabs(a+b-c)<epsilon || fabs(a+c-b)<epsilon || fabs(b+c-a)<epsilon) {
		printf("Linija\n");
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",x,y,z);
	} else {
		if(((fabs(a-b)>epsilon || fabs(a-b)==epsilon) && (fabs(a-c)>epsilon || fabs(a-c)==epsilon) && (fabs(b-c)>epsilon || fabs(b-c)==epsilon)) && (fabs(a*a+b*b-c*c)<epsilon || fabs(a*a+c*c-b*b)<epsilon || fabs(b*b+c*c-a*a)<epsilon) ) {
			printf("Pravougli\n");
			printf("Raznostranicni\n");
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",x,y,z);
			return 0;
		}
		if((fabs(a*a+b*b-c*c)<epsilon && fabs(a-b)<epsilon && (fabs(a-c)>epsilon || fabs(a-c)==epsilon)) || (fabs(a*a+c*c-b*b)<epsilon && fabs(a-c)<epsilon && (fabs(a-b)>epsilon || fabs(a-b)==epsilon)) || (fabs(b*b+c*c-a*a) && fabs(c-b)<epsilon && (fabs(a-c)>epsilon || fabs(a-c)==epsilon))) {
			printf("Pravougli\n");
			printf("Jednakokraki\n");
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",x,y,z);
			return 0;
		}
		if (fabs(a-b)<epsilon && fabs(a-c)<epsilon) {
			printf("Jednakostranicni\n");
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",x,y,z);
			return 0;
		}
		if(fabs(a*a+b*b-c*c)<epsilon || fabs(a*a+c*c-b*b)<epsilon || fabs(b*b+c*c-a*a)<epsilon) {
			printf("Pravougli\n");
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",x,y,z);
			return 0;
		}
		if((fabs(a-b)<epsilon && (fabs(a-c)>epsilon || fabs(a-c)==epsilon)) || (fabs(a-c)<epsilon && (fabs(a-b)>epsilon || fabs(a-b)==epsilon)) || (fabs(c-b)<epsilon && (fabs(a-c)>epsilon || fabs(a-c)==epsilon))) {
			printf("Jednakokraki\n");
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",x,y,z);
			return 0;
		}

		if((fabs(a-b)>epsilon || fabs(a-b)==epsilon) && (fabs(a-c)>epsilon || fabs(a-c)==epsilon) && (fabs(b-c)>epsilon || fabs(b-c)==epsilon)) {
			printf("Raznostranicni\n");
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",x,y,z);
			return 0;
		}
	}
	return 0;
}
