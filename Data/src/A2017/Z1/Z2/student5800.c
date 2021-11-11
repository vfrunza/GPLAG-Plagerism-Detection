#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

int main() {
	double x1, x2, x3, y1, y2, y3, d1, d2, d3, max, kk, ugao, stepeni, minute, sekunde, a, b;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: \n");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: \n");
	scanf("%lf %lf", &x3, &y3);
	d1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	d2=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	d3=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	max=d1;
	if(max<=d2){
		max=d2;
		kk=d1*d1+d3*d3;}
	else if(max<=d3){
		max=d3;
		kk=d1*d1+d2*d2;}
	else
		kk=d2*d2+d3*d3;
	if((fabs(x1-x2)<epsilon && fabs(x2-x3)<epsilon) || (fabs(y1-y2)<epsilon && fabs(y2-y3)<epsilon))
		printf("Linija\n");
	else if(fabs(max-sqrt(kk))<epsilon){
		printf("Pravougli\n");
		if(fabs(d1-d2)<epsilon || fabs(d2-d3)<epsilon){
			printf("Jednakokraki\n");
			printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
		}
	}
	else if((fabs(d1-d2)<epsilon || fabs(d2-d3)<epsilon) && fabs(max-sqrt(kk))<epsilon){
		printf("Jednakokraki");
		if(d1==max){
			ugao=acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3));
			stepeni= (int) ugao;
			a=(ugao-int(ugao))*60;
			minute= (int) a;
			b=(minute-(int) a)*60
			sekunde= (int) b;
			printf("Najveci ugao ima %f stepeni, %f minuta i %f sekundi\n", stepeni, minute, sekunde);
			
			
		}
	}
	
	
	return 0;
}
