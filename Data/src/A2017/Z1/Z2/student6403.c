#include <stdio.h>
#include <math.h>



int main ()
{

	float x1,y1,x2,y2,x3,y3;
	double a,b,c,s;
	double alfa,beta,gama;
	double A,B,C;
	double MAX;
	double stepeni,minute,sekunde;
	double PI=acos(-1);
	int sekunde1;

	printf("Unesite koordinate tacke t1: ");
	scanf ("%f %f", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf ("%f %f", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf ("%f %f", &x3,&y3);

	
	a=sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
	b=sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
	c=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));


	A = (((b*b) + (c*c)) - (a*a)) / (2*b*c);
	B = (((a*a) + (c*c)) - (b*b)) / (2*a*c);
	C = (((b*b) + (a*a)) - (c*c)) / (2*b*a);
	
	
	
	alfa=(acos(A)*180.)/PI;
	beta=(acos(B)*180.)/PI;
	gama=(acos(C)*180.)/PI;
	
	s = (a + b + c) / 2;
	if (a >= s || b >= s || c >= s) {
		printf("Linija");
		printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 1;
	}
	
	if (fabs(alfa-90)<0.0001 ||	fabs(beta-90)<0.0001 || fabs(gama-90)<0.0001)
	printf("Pravougli\n");
		
	if (fabs(alfa-beta)<0.0001 && fabs(beta-gama)<0.0001 && (alfa-gama)<0.0001)
	printf("Jednakostranicni");
	
	else if (((floor(alfa)!=floor(beta)) && floor(beta)== floor(gama)) || ((floor(alfa)!=floor(gama)) && floor(gama)== floor(beta)) || ((floor(beta)!=floor(gama)) && floor(gama) == floor(alfa))){
	printf("Jednakokraki");
	}
	if (((floor(alfa)!=floor(beta) && floor(beta)!=floor(gama) && floor(alfa)!=floor(gama))))
	printf("Raznostranicni");
	

	if ((alfa>=beta) && (alfa>=gama))
		MAX=alfa;
	else if ((beta>=alfa) && (beta>=gama))
		MAX=beta;
	else
		MAX=gama;
	
	stepeni=floor(MAX);
 	minute=floor((MAX-stepeni)*3600)/60;
	sekunde1=floor((MAX-stepeni)*3600);
	sekunde=sekunde1%60;
	
	if(minute!=0 && sekunde!=0)
	printf("\nNajveci ugao ima %2.f stepeni, %2.f minuta i %2.f sekundi.",stepeni,minute,sekunde);
	else	
	printf("\nNajveci ugao ima %2.f stepeni,%2.f minuta i%2.f sekundi.",stepeni,minute,sekunde);
 

	return 0;
}