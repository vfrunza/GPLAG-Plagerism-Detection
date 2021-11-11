#include <stdio.h>
#include <math.h>
#define EPS 0.0001
#define PI 3.14159

int main()
{
	double x1, x2, x3, y1, y2, y3, stepeni, minute, sekunde, alfa, beta, gama, ostatak1, ostatak2, a, b, c;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	/* racunanje duzina stranica */
	a = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	b = sqrt(pow((x2-x3),2)+pow((y2-y3),2));
	c = sqrt(pow((x1-x3),2)+pow((y1-y3),2));
	
	/* trazenje najveceg ugla na osnovu duzina stranica */
	/* najveci ugao je nasuprot najduze stranice */
	if (a>=b && a>=c)
	{
		alfa = acos((b*b+c*c-a*a)/(2*b*c));  /* kosinusna teorema */
		stepeni = alfa*(180/PI);
		ostatak1 = stepeni-(int)stepeni;
		minute = ostatak1*60;
		ostatak2 = minute-(int)minute;
		sekunde = ostatak2*60;
	}
	else if (b>=a && b>=c)
	{
		beta = acos((a*a+c*c-b*b)/(2*a*c));  /* kosinusna teorema */
		stepeni = beta*(180/PI);
		ostatak1 = stepeni-(int)stepeni;
		minute = ostatak1*60;
		ostatak2 = minute-(int)minute;
		sekunde = ostatak2*60;
	}
	else if (c>=a && c>=b)
	{
		gama = acos((a*a+b*b-c*c)/(2*a*b));  /* kosinusna teorema */
		stepeni = gama*(180/PI);
		ostatak1 = stepeni-(int)stepeni;
		minute = ostatak1*60;
		ostatak2 = minute-(int)minute;
		sekunde = ostatak2*60;
	}
	
	/* ispitivanje vrste trougla na osnovu izracunatih duzina stranica */
	if (fabs(a-b)<EPS && fabs(b-c)<EPS)
	{
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)stepeni, (int)minute, (int)sekunde);
	}
	else if (fabs(c*c-a*a-b*b)<EPS || fabs(a*a-b*b-c*c)<EPS || fabs(b*b-a*a-c*c)<EPS)
	{
		printf("Pravougli\n");
		if (fabs(a-b)<EPS || fabs(b-c)<EPS || fabs(a-c)<EPS)
		{
			printf("Jednakokraki\n");
		}
		else if (fabs(a-b)>EPS && fabs(b-c)>EPS)
		{
			printf("Raznostranicni\n");
		}
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	}
	else if (fabs(a-b)<EPS || fabs(b-c)<EPS || fabs(a-c)<EPS)
	{
		printf("Jednakokraki\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)stepeni, (int)minute, (int)sekunde);
	}
	else if (fabs(a-b)>EPS && fabs(b-c)>EPS)
	{
		printf("Raznostranicni\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)stepeni, (int)minute, (int)sekunde);
	}
	
	else if (fabs(x1-x2)<EPS && fabs(x2-x3)<EPS && fabs(x1-x3)<EPS)
	{
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	}
	else if (fabs(y1-y2)<EPS && fabs(y2-y3)<EPS && fabs(y1-y3)<EPS)
	{
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	}
	else if (fabs(x1*y2 + y1*x3 + x2*y3 - x3*y2 - y3*x1 - x2*y1)<EPS)
	{
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	}
	
	
	return 0;
}