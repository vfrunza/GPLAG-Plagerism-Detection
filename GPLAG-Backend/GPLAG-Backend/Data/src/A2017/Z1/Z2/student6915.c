#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.1415926535

int main() {
	double x1, x2, x3, y1, y2, y3, a, b, c, P, ug1, ug2, ug3, min1, sek1, min2, sek2, min3, sek3;
	int ugao1, ugao2, ugao3, min11, sek11, min22, sek22, min33, sek33;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	P=(1/2.)*(fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	if(P==0){
		printf("Linija\n");
	}else
	{
	if((fabs(a-b)<EPSILON) && (fabs(b-c)<EPSILON)&&(fabs(a-c)<EPSILON)){
		printf("Jednakostranicni\n");
	}
	if((fabs(a*a-b*b-c*c)<EPSILON) || (fabs(b*b-c*c-a*a)<EPSILON) || (fabs(c*c-a*a-b*b)<EPSILON)){
		printf("Pravougli\n");
	}
	if(((fabs(a-b)<EPSILON)&&(fabs(b-c)>EPSILON)&&(fabs(a-c)>EPSILON)) || ((fabs(b-c)<EPSILON)&&(fabs(a-c)>EPSILON)&&(fabs(b-a)>EPSILON)) || ((fabs(c-a)<EPSILON)&&(fabs(b-c)>EPSILON)&&(fabs(b-a)>EPSILON))){
		printf("Jednakokraki\n");
	}
	if((fabs(a-b)>EPSILON) && (fabs(b-c)>EPSILON) && (fabs(c-a)>EPSILON)){
		printf("Raznostranicni\n");
	}
}
	
 	ug1=acos((a*a +b*b-c*c)/(2*a*b))*180/PI+EPSILON;
	ug2=acos((b*b+c*c-a*a)/(2*b*c))*180/PI+EPSILON;
	ug3=acos((c*c+a*a-b*b)/(2*c*a))*180/PI+EPSILON;
	
	ugao1=ug1/1;
	ugao2=ug2/1;
	ugao3=ug3/1;

	min1=(ug1-ugao1)*60;
	min11=min1/1;
	sek1=(min1-min11)*60;
	sek11=sek1/1;
	
	min2=(ug2-ugao2)*60;
	min22=min2/1;
	sek2=(min2-min22)*60;
	sek22=sek2/1;
	
	min3=(ug3-ugao3)*60;
	min33=min3/1;
	sek3=(min3-min33)*60;
	sek33=sek3/1;
	
	if(ug1>ug2 && ug1>ug3){
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", ugao1, min11, sek11);
	} else if(ug2>ug1 && ug2>ug3){
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", ugao2, min22, sek22);
	} else if(ug3>ug1 && ug3>ug2){
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", ugao3, min33, sek33);
	}
	
	return 0;
}
