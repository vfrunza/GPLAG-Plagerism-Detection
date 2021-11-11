#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265
int main() {
	double x1,x2,x3,y1,y2,y3,x,y,z,a1,a2,a3,b,c,A,B,C,X,Y,Z,ugao,usec;
	int dgr,min,sec;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	x=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	y=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	z=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	a1=(x*x)+(y*y);
	a2=(y*y)+(z*z);
	a3=(x*x)+(z*z);
	b=(x2-x1)*(y3-y1);
	c=(y2-y1)*(x3-x1);
	if(fabs(x-y)<EPSILON && fabs(y-z)<EPSILON){
		printf("Jednakostranicni\n");
	}if(fabs((z*z)-a1)<EPSILON || fabs((x*x)-a2)<EPSILON || fabs((y*y)-a3)<EPSILON){
		printf("Pravougli\n");
	}if(((fabs(b-c)>EPSILON ) && (fabs(x-y)<EPSILON && fabs(y-z)>EPSILON))||(fabs(y-z)<EPSILON && fabs(y-x)>EPSILON )||(fabs(x-z)<EPSILON && fabs(y-x)>EPSILON)){
		printf("Jednakokraki\n");
	}if(fabs(b-c)<EPSILON){
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}if(fabs(x-y)>EPSILON && fabs(x-z)>EPSILON && fabs(y-z)>EPSILON){
		printf("Raznostranicni\n");
	}A=((y*y+z*z-x*x)/(2*y*z));
	B=((x*x+z*z-y*y)/(2*x*z));
	C=((x*x+y*y-z*z)/(2*x*y));
	X=acos(A); Y=acos(B); Z=acos(C);
	if(X>=Y && X>=Z){
		ugao = X*180.0 /PI;
		usec = ugao*3600;
		min = ((int)usec/60)%60;
		dgr = (int)ugao;
		sec = usec-(dgr*3600)-min*60;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",dgr,min,sec);
	}else if(Y>=X && Y>=Z){
		ugao=Y*180.0/PI;
		usec = ugao*3600;
		min=((int)usec/60)%60;
		dgr= usec/3600;
		sec=usec-(dgr*3600)-min*60;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",dgr,min,sec);
	}else if(Z>=X && Z>=Y){
		ugao=Z*180.0/PI;
		usec=ugao*3600;
		min=((int)usec/60)%60;
		dgr = (int)ugao;
		sec = usec-(dgr*3600)-min*60;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",dgr,min,sec);
	}
	return 0;
}
