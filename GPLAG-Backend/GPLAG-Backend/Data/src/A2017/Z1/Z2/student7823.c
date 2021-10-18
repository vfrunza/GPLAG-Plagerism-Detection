#include <stdio.h>
#include <math.h>
#define e 0.0001
#define PI 3.14159265

int main()
{
	double x1, y1, x2, y2, x3, y3, a, b, c, temp, najveca,ugao;
	double minute, sekunde;
	int stepeni;

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);

	a=sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
	b=sqrt( (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2) );
	c=sqrt( (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1) );



	if( (a+b<=c) || (a+c<=b) || (b+c<=a) )
		printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	else {

		najveca=a; /* trazi se najveca stranica od tri i ona je sada varijabla a*/
		if(b>najveca) {
			temp=a;
			a=b;
			b=temp;
		}
		if(c>a) {
			temp=a;
			a=c;
			c=temp;
		}



		if( fabs(a*a - c*c - b*b ) <= e)
			printf("Pravougli\n");

		if( fabs(a-b) <e && fabs(b-c)<e )
			printf("Jednakostranicni\n");
		else if (fabs(a-b)<e || fabs(b-c)<e || fabs(c-a)<e)
			printf("Jednakokraki\n");
		else
			printf("Raznostranicni\n");

		ugao = acos( (b*b + c*c - a*a) / (2.0*b*c) )* 180.0 / PI;
		stepeni=(int)ugao;
		minute=(ugao-(int)ugao)*60;
		sekunde=(minute-(int)minute)*60;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni, (int)minute, (int)sekunde);


	}
	return 0;
}
