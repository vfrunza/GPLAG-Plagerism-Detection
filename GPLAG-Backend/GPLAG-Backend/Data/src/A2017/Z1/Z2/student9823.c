#include <stdio.h>
#include <math.h>

int main()
{
#define epsilon 0.0001
#define pi 3.14159
	double x1,x2,x3,y1,y2,y3;
	double P;
	double d1,d2,d3,c;
	double alfa,beta,gama,najveci;
	double stepeni, minute, sekunde;
	//d1-udaljenost izmedju tacke 1 i 2, d2 udaljenost izmedju tacke 1 i 3, d3 udaljenost izmedju tacke 2 i 3
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	c=(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	if(c<0) c=-c;
	P=(1./2)*c;
	if(P<epsilon) {
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	} else {
		d1=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
		d2=sqrt(pow((x1-x3),2)+pow((y1-y3),2));
		d3=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
		if((fabs(d1-d2)<epsilon) && (fabs(d2-d3)<epsilon)) {
			printf("Jednakostranicni\n");
			printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		} else {

			alfa=acos((d1*d1+d2*d2-d3*d3)/(2*d1*d2));
			beta=acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3));
			gama=acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3));
			alfa=alfa*180/pi;
			beta=beta*180/pi;
			gama=gama*180/pi;

			if(fabs(floor(alfa)-90)<epsilon ||fabs(floor(beta)-90)<epsilon || fabs(floor(gama)-90)<epsilon)printf("Pravougli\n");
			if(alfa>beta) {
				if(alfa>gama) najveci=alfa;
				else najveci=gama;
			} else {
				if(beta>gama) najveci=beta;
				else najveci=gama;
			}
			stepeni=floor(najveci);
			minute=floor((najveci-stepeni)*60);
			sekunde=floor(((najveci-stepeni)*60-minute)*60);
			if((fabs(d1-d2)<epsilon) || (fabs(d2-d3)<epsilon) || (fabs(d3-d1)<epsilon)) printf("Jednakokraki\n");
			else printf("Raznostranicni\n");
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",stepeni,minute,sekunde);

		}
	}
	return 0;
}
