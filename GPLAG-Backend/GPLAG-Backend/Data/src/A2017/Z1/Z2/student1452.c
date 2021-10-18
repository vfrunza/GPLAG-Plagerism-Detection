#include <stdio.h>
#include <math.h>
#define e 0.0001
#define PI 3.14159

int main() {
	double x1,x2,x3,y1,y2,y3,ugao,a,b,c,najveca,m1,m2,stepeni,minute,sekunde;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);
	
	a=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	b=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
	c=sqrt(pow((x1-x3),2)+pow((y1-y3),2));
	
	    if(a>=b && a>=c){
		najveca=a;m1=b;m2=c;
	}
		if(b>=c && b>=a){
		najveca=b;m1=a;m2=c;
	}
		if(c>=b && c>=a){
		najveca=c;m1=a;m2=b;
	}
	
	ugao=acos((m1*m1+m2*m2-najveca*najveca)/(2*m1*m2))*180/PI;
	stepeni=(int)ugao;
	minute=(int)((ugao-stepeni)*60);
	sekunde=(int)(((ugao-stepeni)*60-minute)*60);
	if(stepeni==180 || stepeni==0){
		printf("Linija \n");
	
	}
	
	else if(fabs(a-b)<e && fabs(b-c)<e) printf("Jednakostranicni \n");
	else if(fabs(najveca*najveca-m1*m1-m2*m2)<e) { 
		
		if(fabs(m1-m2)<e) {printf("Pravougli \n");
			printf("Jednakokraki \n");}
			else {
				printf("Pravougli \n");
				printf("Raznostranicni \n");
			}}
	else if( fabs(a-b)<e || fabs(b-c)<e || fabs(c-a)<e)  printf("Jednakokraki \n");
	else printf("Raznostranicni \n");
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepeni,minute,sekunde);
		
	
return 0;
}
