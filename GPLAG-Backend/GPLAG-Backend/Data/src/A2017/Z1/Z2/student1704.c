#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define e 0.0001
int main() {
	double x1, y1, x2, y2, x3, y3, d1, d2, d3, a1, a2, a3, najveci_ugao;
	int stepen, minuta, sekunda;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	d1=sqrt(pow((x1-x2),2) + pow((y1-y2),2));
	d2=sqrt(pow((x2-x3),2) + pow((y2-y3),2));
	d3=sqrt(pow((x1-x3),2) + pow((y1-y3),2));
	
	
	a1=acos(((d1*d1 + d2*d2 - d3*d3)/(2*d1*d2)))*180.0/PI;
	a2=acos(((d2*d2 + d3*d3 - d1*d1)/(2*d2*d3)))*180.0/PI;
	a3=acos(((d1*d1 + d3*d3 - d2*d2)/(2*d1*d3)))*180.0/PI;
	
	
	 
	 	if(fabs(a1-90.0)<e || fabs(a2-90.0)<e || fabs(a3-90.0)<e) {
	 	printf("Pravougli\n"); 
	 	}
	 	
	 	if(fabs(a1-180.0)<e || fabs(a2-180.0)<e || fabs(a3-180.0)<e) {
	 		printf("Linija\n");
	 	}
	    else if(fabs(d1-d2)<e && fabs(d1-d3)<e && fabs(d2-d3)<e) {
	 		printf("Jednakostranicni\n");
	 	}
	 	else if(fabs(d1-d2)<e || fabs(d1-d3)<e || fabs(d2-d3)<e) {
	 		printf("Jednakokraki\n");
	 	}
	 	else {
	 		printf("Raznostranicni\n");
	 	}
	 	
	 	
	 if(a1>a2 && a1>a3) {
	 	najveci_ugao=a1;
	 }
	 else if(a2>a1 && a2>a3) {
	 	najveci_ugao=a2;
	 }
	 else {
	 	najveci_ugao=a3;
	 }
	 
	stepen=(int)najveci_ugao;
	minuta=(int)((najveci_ugao-stepen)*60);
	sekunda=(int)((najveci_ugao-stepen-(minuta/60.0))*3600);
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sekunda);
	 
	return 0;
}
