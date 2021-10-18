#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265
int main() {
	int stepeni, minute, sekunde; 
	double x1, y1,  x2, y2,  x3, y3,  d1, d2, d3, maxugao;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3); 
	d1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	d2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	d3=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	
	//Uslov kolinearnosti 
	if(fabs(d1+d2-d3)<EPSILON || fabs(d2+d3-d1)<EPSILON || fabs(d3+d1-d2)<EPSILON) {
		printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi."); 
		return 0;
	}
	else if(fabs(d1-d2)<EPSILON && fabs(d2-d3)<EPSILON) {
		printf("Jednakostranicni\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	else if(fabs(d1*d1+d2*d2-d3*d3)<EPSILON) {
	printf("Pravougli");
		if(fabs(d1-d2)>EPSILON && fabs(d2-d3)>EPSILON && fabs(d3-d1)>EPSILON)
		printf("\nRaznostranicni");
		else printf("\nJednakokraki");
	printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	return 0;
	}
	else if(fabs(d1-d2)>EPSILON && fabs(d2-d3)>EPSILON && fabs(d3-d1)>EPSILON) 
		printf("Raznostranicni\n"); 
		
	else printf("Jednakokraki\n");
		
		//RACUNJANJA UGLA
		if(d1>d2 && d1>d3) 
		maxugao=acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3))*180/PI;
		else if(d2>d3 && d2>d1) 
		maxugao=acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3))*180/PI;	
		else 
		maxugao=acos((d1*d1+d2*d2-d3*d3)/(2*d1*d2))*180/PI;
	
			stepeni=(int)maxugao;
			minute=(int)((maxugao-stepeni)*60);
			sekunde=(int)((((maxugao-stepeni)*60-minute))*60);
		
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
	
			return 0;
}
