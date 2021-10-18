#include <stdio.h>
#include <math.h>
#define PI 3.141592
#define EPSILON 0.0001

int main() {
	/*printf("Zadaća 1, Zadatak 2");*/
	double x1,x2,x3,y1,y2,y3,alfa,beta,gama,a,b,c,najveci_ugao;
	int stepeni,minute,sekunde;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	
	alfa=acos((b*b+c*c-a*a)/(2*b*c));
	beta=acos((a*a+c*c-b*b)/(2*a*c));
	gama=acos((a*a+b*b-c*c)/(2*a*b));
	
	najveci_ugao=alfa;
	if(beta>najveci_ugao) najveci_ugao=beta;
	if(gama>najveci_ugao) najveci_ugao=gama;
	
	najveci_ugao=najveci_ugao*(180/PI);
	stepeni=(int)(najveci_ugao);
	minute=(int)((najveci_ugao-stepeni)*60);
	sekunde=(int)(((najveci_ugao-stepeni)*60-minute)*60);
	
	if(stepeni==180 && minute==0 && sekunde==0) printf("Linija\n");
	else if((fabs((a*a+b*b)-c*c)<EPSILON || fabs((c*c-a*a)-b*b)<EPSILON || fabs((c*c-b*b)-a*a)<EPSILON) && (fabs(a-b)<EPSILON || fabs(b-c)<EPSILON || fabs(a-c)<EPSILON)){
		printf("Pravougli\n");
		printf("Jednakokraki\n");
	}
	else if((fabs((a*a+b*b)-c*c)<EPSILON || fabs((c*c-a*a)-b*b)<EPSILON || fabs((c*c-b*b)-a*a)<EPSILON) && (fabs(a-b)>EPSILON && fabs(b-c)>EPSILON)){
		printf("Pravougli\n");
		printf("Raznostranicni\n");
	}
	else if(fabs(a-b)<EPSILON && fabs(b-c)<EPSILON) printf("Jednakostranicni\n");
	else if(fabs(a-b)>EPSILON && fabs(b-c)>EPSILON) printf("Raznostranicni\n");
	else if (fabs(a-b)<EPSILON || fabs(b-c)<EPSILON || fabs(a-c)<EPSILON) printf("Jednakokraki\n");
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	
	
	return 0;
}
