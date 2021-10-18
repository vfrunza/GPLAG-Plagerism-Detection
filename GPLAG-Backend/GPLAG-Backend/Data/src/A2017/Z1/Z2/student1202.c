#include <stdio.h>
#include <math.h>
#define E 1e-4
#define R_D (180.0 / 3.1415926)
int main()
{
	double x1, y1, x2, y2, x3, y3, a, b, c, alfa, beta, gama, max, i, j;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
	c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	if (fabs((y1 - y2) / (x1 - x2) - (y2 - y3) / (x2 - x3)) < E)
	    printf("Linija\n");
	else if (fabs(a - b) < E && fabs(b - c) < E)
	    printf("Jednakostranicni\n");
	else 
	{
	    if (fabs(a*a - b*b - c*c) < E || fabs(b*b - a*a - c*c) < E || fabs(c*c - b*b - a*a) < E)
	        printf("Pravougli\n");
	    if (fabs(a - b) < E || fabs(b - c) < E || fabs(c - a) < E)
	        printf("Jednakokraki\n");
	    else 
	        printf("Raznostranicni\n");
	}
    alfa = acos((c*c+b*b-a*a) / 2 / b / c);
	beta = acos((a*a+c*c-b*b) / 2 / a / c);
	gama = acos((a*a+b*b-c*c) / 2 / a / b);
	max = alfa;
	if (beta > max) max = beta;
	if (gama > max) max = gama;
	max *= R_D; 
	i = floor(max);
	j = floor((max - i) * 60);
	printf("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.", i, j, floor(((max - i) * 60 - j) * 60));
	return 0;                                                                                                          
}
