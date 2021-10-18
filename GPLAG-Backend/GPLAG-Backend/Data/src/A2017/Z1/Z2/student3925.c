#include <stdio.h>
#include <math.h>
#define eps 0.0001
#define PI 3.14159265359
int main() {
	double x1, y1, x2, y2, x3, y3, d1, d2, d3, P, alfa, beta, gama;
	int  alfa1, beta1, gama1, sec1, sec2, sec3, stepeni1, stepeni2, stepeni3, min1, min2, min3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	d1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	d3=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	d2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	P=(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
	
	if(fabs(P)<=eps)
		printf("Linija\n"); else
		{
	 if(fabs((d3)-(sqrt(d1*d1+d2*d2)))<=eps || fabs((d2)-(sqrt(d3*d3+d1*d1)))<=eps || fabs((d1)-(sqrt(d3*d3+d2*d2)))<=eps)
		printf("Pravougli\n");
     if(fabs(d1-d2)<=eps && fabs(d2-d3)<=eps)
		printf("Jednakostranicni\n");
     if((fabs(d1-d2)<=eps && fabs(d1-d3)>eps) || (fabs(d1-d3)<=eps && fabs(d1-d2)>eps) || (fabs(d2-d3)<=eps && fabs(d2-d1)>eps))
		printf("Jednakokraki\n");
     if (fabs(d1-d2)>eps && fabs(d2-d3)>eps && fabs(d1-d3)>eps)
		printf("Raznostranicni\n");
		}
	alfa=acos(((d2*d2+d3*d3)-(d1*d1))/(2*d2*d3))*(180/PI)*3600*1000;
	beta=acos(((d1*d1+d3*d3)-(d2*d2))/(2*d1*d3))*(180/PI)*3600*1000;
	gama=acos(((d1*d1+d2*d2)-(d3*d3))/(2*d1*d2))*(180/PI)*3600*1000;
	alfa1=(int)round(alfa)/1000;
	beta1=(int)round(beta)/1000;
	gama1=(int)round(gama)/1000;
	sec1=alfa1%60;
	sec2=beta1%60;
	sec3=gama1%60;
	min1=(alfa1/60)%60;
	min2=(beta1/60)%60;
	min3=(gama1/60)%60;
	stepeni1=alfa1/3600;
	stepeni2=beta1/3600;
	stepeni3=gama1/3600;
	if((alfa<gama) && (beta<gama)){
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni3, min3, sec3);
	}
	if((beta<alfa) && (gama<alfa)){
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni1, min1, sec1);
	}
	if(alfa<beta && gama<beta){
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni2, min2, sec2);
	}
	return 0;
	}

