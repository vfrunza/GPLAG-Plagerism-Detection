#include <stdio.h>
#include <math.h>
#define eps 0.0001
#define PI 3.14159265
int main() {
	double x1, y1, x2, y2, x3, y3;
	double d1, d2, d3, najduza, str1, str2;
	double  gama;
	/*double ugao1, ugao2, ugao3;*/
	int stepeni, minute, sekunde;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	
	if((fabs(x1-x2)<eps && fabs(x2-x3)<eps) || (fabs(y1-y2)<eps && fabs(y2-y3)<eps)){
		printf("Linija");
	}
	
	d1 = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));  /*izmedju tacaka t1 i t2*/
	d2 = sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));  /*izmedju tacaka t1 i t3*/
	d3 = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));  /*izmedju tacaka t2 i t3*/
	
	if(fabs(d1-d2)<eps && fabs(d2-d3)<eps) 
		printf("Jednakostranicni");
	else {
		if(fabs(d1*d1 - (d2*d2+d3*d3))<eps || fabs(d2*d2 - (d1*d1+d3*d3))<eps || fabs(d3*d3 - (d2*d2+d1*d1))<eps)
			printf("Pravougli");
		if((fabs(d1-d2)<eps || fabs(d1-d3)<eps) ||fabs(d2-d3)<eps)
			printf("\nJednakokraki");
		else printf("\nRaznostranicni");
	}
	
	if(d2<d1 && d3<d1) {najduza=d1; str1=d2; str2=d3;}
	else if(d1<d2 && d3<d2){najduza=d2; str1=d1; str2=d3;}
	else {najduza=d3; str1=d1; str2=d2;}
	
	gama =  acos((str1*str1 + str2*str2 -najduza*najduza)/2*str1*str2);
	gama = gama * (180.0/PI);
	

	stepeni = (int)gama;
	minute = (int)((gama-stepeni)*60);
	sekunde = (int)(gama*3600);
	sekunde = sekunde%60;

	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
	return 0;
}
