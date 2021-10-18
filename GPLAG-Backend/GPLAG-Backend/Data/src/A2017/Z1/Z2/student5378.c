#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define PI 3.1415926
int main() {
	double x1,y1,x2,y2,x3,y3;
	double a,b,c,najveci_ugao,alfa,beta,gama;
	int najveciugao;
	int step, min,sek;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);

	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	
	alfa=(b*b+c*c-a*a)/(2*b*c);
	beta=(a*a+c*c-b*b)/(2*a*c);
	gama=(a*a+b*b-c*c)/(2*b*a);
	
	alfa=acos(alfa)*(180./PI);
	beta= acos(beta)*(180./PI);
	gama = acos(gama)*(180./PI);
	
	
	if (alfa<=beta && gama<=beta) {
	 	najveci_ugao=beta;
	} else if(beta<=alfa && gama<=alfa) {
		najveci_ugao=alfa;
	} else if(alfa<=gama && beta<=gama) {
		najveci_ugao=gama;
	} 
	
	if (fabs(najveci_ugao-90)<EPSILON) {
		printf("Pravougli\n");
	}
	if ((fabs(a-b)<EPSILON) && (fabs(a-c)<EPSILON)) {
		printf("Jednakostranicni\n");
	}  else if (fabs(najveci_ugao-180)<EPSILON) {
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	} else if (((fabs(a-b)<EPSILON) && (fabs(b-c)>EPSILON)) || ((fabs(a-c)<EPSILON) && (fabs(c-b)>EPSILON)) || ((fabs(b-c)<EPSILON) && (fabs(c-a)>EPSILON))) {
		printf("Jednakokraki\n");
	}else if ((fabs(a-b)>EPSILON) && (fabs(b-c)>EPSILON) && (fabs(c-a)>EPSILON)) {
		printf("Raznostranicni\n");
	} 

	step=(int)(najveci_ugao);
	min=(int)((najveci_ugao -(int)najveci_ugao)*60);
	sek=(int)((najveci_ugao-step - min/60.)*3600);
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step,min,sek);
return 0;
}

	





