#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.14159265

int main() {
	
	double x1=0, y1=0, x2=0, y2=0, x3=0, y3=0;
	double a=0, b=0, c=0;
	int stepeni=0, minute=0, sekunde=0;
	double ugao=0;
	/*za svaki slucaj nek' je sve inicijalizovano.. */
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	
	/*if(a==0 && b==0 & c==0) {
		printf("Tacka\n");
		return 0;
	}*/
	
	if(a>=b && a>=c) ugao=acos((b*b+c*c-a*a)/(2*b*c));
	else if(b>=c && b>=a) ugao=acos((a*a+c*c-b*b)/(2*a*c));
	else ugao=acos((a*a+b*b-c*c)/(2*a*b));
	ugao*=180.0/PI;
	stepeni=(int)(ugao);
	minute=(int)((ugao-stepeni)*60);
	sekunde=(int)(((ugao-stepeni)*60-minute)*60);
	
	
	if(fabs(x1*y2+x2*y3+x3*y1-(x2*y1+x3*y2+x1*y3))<epsilon)		/*ako je površina trougla == nula*/	
		printf("Linija");
	
		       /*b==a*/			   /*b==c*/
	else if(fabs(b-a)<epsilon && fabs(b-c)<epsilon){
		printf("Jednakostranicni");
	}		
				/*b==a*/			/*c==a*/			 /*b==c*/
	else if(fabs(b-a)<epsilon || fabs(c-a)<epsilon || fabs(b-c)<epsilon){
		if((fabs(ugao-90))<epsilon)	
			printf("Pravougli\n");
		printf("Jednakokraki");
	}
	else {
		if((fabs(ugao-90))<epsilon) printf("Pravougli\n");
		printf("Raznostranicni");
	}
	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		
	return 0;
}
