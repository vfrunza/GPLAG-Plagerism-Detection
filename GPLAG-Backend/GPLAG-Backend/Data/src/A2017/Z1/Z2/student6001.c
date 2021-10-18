#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.14159

int main() {
double alfa=0, beta=0, gama=0, x1, x2, x3, y1, y2, y3, d1, d2, d3;
int stepen, minut, sekund;

printf("Unesite koordinate tacke t1: ");
scanf("%lf%lf", &x1, &y1);
printf("Unesite koordinate tacke t2: ");
scanf("%lf%lf", &x2, &y2);
printf("Unesite koordinate tacke t3: ");
scanf("%lf%lf", &x3, &y3);
 

d1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
d2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
d3=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));

 
	alfa=acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3));
	beta=acos((d3*d3+d1*d1-d2*d2)/(2*d3*d1));
	gama=acos((d1*d1+d2*d2-d3*d3)/(2*d1*d2));
		alfa=alfa*180/PI;
		beta=beta*180/PI;
		gama=gama*180/PI;

if(d1>=(d2+d3) || d2>=(d1+d3) || d3>=(d1+d2))
{
	printf("Linija\n");
	printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	return 0; }

else if((alfa>89&&alfa<91) || (beta>89&&beta<91) || (gama>89&&gama<91)) {
	printf("Pravougli\n");
	}

if(fabs(d1-d2)<epsilon && fabs(d1-d3)<epsilon) {
	printf("Jednakostranicni\n");
	}

else if((fabs(d1-d2)<epsilon) || (fabs(d1-d3)<epsilon) || (fabs(d2-d3)<epsilon)) {
	printf("Jednakokraki\n");
	}

else {
	printf("Raznostranicni\n");
	}


if(alfa>beta && alfa>gama) {
	stepen=(int)alfa;
	alfa=alfa-stepen;
	alfa=alfa*60;
	minut=(int)alfa;
	alfa=alfa-minut;
	alfa=alfa*60;
	sekund=(int)alfa;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minut, sekund);
}
else if(beta>alfa&&beta>gama) {
	stepen=(int)beta;
	beta=beta-stepen;
	beta=beta*60;
	minut=(int)beta;
	beta=beta-minut;
	beta=beta*60;
	sekund=(int)beta;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minut, sekund);
}
else if(gama>alfa&&gama>beta) {
	stepen=(int)gama;
	gama=gama-stepen;
	gama=gama*60;
	minut=(int)gama;
	gama=gama-minut;
	gama=gama*60;
	sekund=(int)gama;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minut, sekund);
}


	return 0;
}
