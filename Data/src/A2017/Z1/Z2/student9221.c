#include <stdio.h>
#include <math.h>

int main()
{
	const double epsilon = 0.0001;
	double x1,y1;
	double x2,y2;
	double x3,y3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);

	double a;
	double b;
	double c;

	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));

	double alfa;
	double beta;
	double gama;

	alfa=acos((b*b+c*c-a*a)/(2*b*c));
	beta=acos((a*a+c*c-b*b)/(2*a*c));
	gama=acos((b*b+a*a-c*c)/(2*b*a));

	alfa*=180/3.14159265359;
	beta*=180/3.14159265359;
	gama*=180/3.14159265359;

	double najveciugao;
	if(alfa>=beta && alfa>=gama) najveciugao=alfa;
	else if(beta>=alfa && beta>=gama) najveciugao=beta;
	else najveciugao=gama;

	if(fabs(najveciugao-90)<epsilon) printf("Pravougli\n");
	if(fabs(najveciugao-180)<epsilon) printf("Linija\n");
	else if(fabs(a-b)<epsilon && fabs(a-c)<epsilon) printf("Jednakostranicni\n");
	else if(fabs(a-b)<epsilon || fabs(a-c)<epsilon || fabs(b-c)<epsilon) printf("Jednakokraki\n");
	else printf("Raznostranicni\n");

	int stepeni;
	int minute;
	int sekunde;
	stepeni = najveciugao+epsilon;
	minute = (najveciugao-stepeni)*60;
	sekunde = (((najveciugao-stepeni)*60)-minute)*60;

	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);

	return 0;
}
