#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#define PI 3.1415926
#define EPSILON 0.0001


int main()
{
	double x1,y1,x2,y2,x3,y3,a,b,c,P,alfa,beta,gama,i,j,k,x,y,z,salfa,sgama,sbeta,min1,min2,min3,minalfa,minbeta,mingama,sec1,sec2,sec3,secalfa,secgama,secbeta;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf%lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf%lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf%lf", &x3,&y3);
	a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	b=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
	c=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	i=((b*b)+(c*c)-(a*a))/(2*b*c);
	j=((a*a)+(c*c)-(b*b))/(2*a*c);
	k=((a*a)+(b*b)-(c*c))/(2*a*b);
	x=acos(i);
	y=acos(j);
	z=acos(k);
	alfa=(x*180)/PI;
	beta=(y*180)/PI;
	gama=(z*180)/PI;
	salfa=(int)alfa;
	sbeta=(int)beta;
	sgama=(int)gama;
	min1=(alfa-salfa)*60;
	minalfa=(int)min1;
	min2=(beta-sbeta)*60;
	minbeta=(int)min2;
	min3=(gama-sgama)*60;
	mingama=(int)min3;
	sec1=(min1-minalfa)*60;
	secalfa=(int)sec1;
	sec2=(min2-minbeta)*60;
	secbeta=(int)sec2;
	sec3=(min3-mingama)*60;
	secgama=(int)sec3;
	P=(fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)))/2;

	if(fabs(alfa-90)<=EPSILON || fabs(beta-90)<=EPSILON || fabs(gama-90)<=EPSILON) {
		printf("Pravougli\n");
	}
	if(fabs(P)<=EPSILON) {
		printf("Linija");
		printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");

	} else	if(fabs(a-b)<=EPSILON && fabs(a-c)<=EPSILON && fabs(b-c)<=EPSILON) {
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	}
		
	 else if(fabs(a-b)<=EPSILON  || fabs(a-c)<=EPSILON  || fabs(c-b)<=EPSILON) {
		printf("Jednakokraki");
		if(alfa>beta && alfa>gama) {
			printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.",salfa,minalfa,secalfa);
		} else if(beta>alfa && beta>gama) {
			printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.",sbeta,minbeta,secbeta);

		} else if(gama>alfa && gama>beta) {
			printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.",sgama,mingama,secgama);
		}

	} else {
		printf("Raznostranicni");
		if(alfa>beta && alfa>gama) {
			printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.",salfa,minalfa,secalfa);
		} else if(beta>alfa && beta>gama) {
			printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.",sbeta,minbeta,secbeta);

		} else if(gama>alfa && gama>beta) {
			printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.",sgama,mingama,secgama);
		}
	}




	return 0;
}
