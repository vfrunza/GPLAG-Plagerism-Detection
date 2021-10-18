#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.141592
int main()
{

	double x1,x2,x3,y1,y2,y3,a,b,c,A,B,C,val;
	int stepeni1,stepeni2,stepeni3,minute1,minute2,minute3,sekunde1,sekunde2,sekunde3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);

	
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c=sqrt(pow(x2-x3,2)+pow(y2-y3,2));

	val=180/PI;
	C=((acos((a*a +b*b - c*c)/(2*a*b)))*val);
	A=((acos((b*b+c*c-a*a)/(2*b*c)))*val);
	B=((acos((a*a+c*c-b*b)/(2*a*c)))*val);


	stepeni1= (int) A;
	stepeni2= (int) B;
	stepeni3=(int) C;

	minute1=(int) ((A-stepeni1)*60);
	minute2= (int) ((B-stepeni2)*60);
	minute3=(int) ((C-stepeni3)*60);

	sekunde1=  ( (A-stepeni1)*60- ( (int) ((A-stepeni1)*60) )  )*60;
	sekunde2=  (  (B-stepeni2)*60 -( (int) ((B-stepeni2)*60)) )*60;
	sekunde3=  (  (C-stepeni3)*60- ( (int) ((C-stepeni3)*60)) )*60;

	if(fabs(a+b-c)<=epsilon || fabs(c+b-a)<=epsilon || fabs(a+c-b)<=epsilon) {
		printf("Linija\n");
	}

	else if(fabs(a-b)<=epsilon  && fabs(a-c)<=epsilon && fabs(b-c)<=epsilon ) {
		if((fabs(c*c-a*a-b*b)<epsilon) || (fabs(b*b-a*a-c*c)<epsilon) || (fabs(a*a-b*b-c*c)<epsilon))
			printf("Pravougli\n");
		printf("Jednakostranicni\n");

	}



	else if((fabs(a-b)<epsilon && fabs(a-c)>epsilon) || (fabs(a-c)<epsilon && fabs(a-b)>epsilon) || (fabs(c-b)<epsilon && fabs(c-a)>epsilon)) {
		if((fabs(c*c-a*a-b*b)<epsilon) || (fabs(b*b-a*a-c*c)<epsilon) || (fabs(a*a-b*b-c*c)<epsilon)) {
			printf("Pravougli\n");
		}
		printf("Jednakokraki\n");

	}


	else if(fabs(a-b)>epsilon && fabs(a-c)>epsilon && fabs(b-c)>epsilon) {
		if((fabs(c*c-a*a-b*b)<epsilon) || (fabs(b*b-a*a-c*c)<epsilon) || (fabs(a*a-b*b-c*c)<epsilon))
			printf("Pravougli\n");
		printf("Raznostranicni\n");
	}
	if(a>=b && a>=c)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni1, minute1,sekunde1);
	else 	if(b>=a && b>=c)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni2, minute2,sekunde2 );
	else if(c>=a && c>=b)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni3, minute3,sekunde3);






	return 0;
}
