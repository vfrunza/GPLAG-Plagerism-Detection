#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define E 0.0001

int main() {
	double x1, x2, x3, y1, y2, y3, ABx, ABy, BCx, BCy, ACx, ACy;
	double AB, BC, AC, a, b, c;
	double max;
	int step, min, sek;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	ABx=x2-x1;
	ABy=y2-y1;
	BCx=x3-x2;
	BCy=y3-y2;
	ACx=x3-x1;
	ACy=y3-y1;
	AB=sqrt(ABx*ABx+ABy*ABy);
	BC=sqrt(BCx*BCx+BCy*BCy);
	AC=sqrt(ACx*ACx+ACy*ACy);
	a=acos((AC*AC + BC*BC -AB*AB)/(2.*BC*AC));
	b=acos((AB*AB + AC*AC - BC*BC)/(2.*AB*AC));
	c=acos((BC*BC+AB*AB -AC*AC)/(2*AB*BC));
	a=180./PI*a;
	b=180./PI*b;
	c=180./PI*c;
	
	if(AB >= BC + AC || BC >= AB + AC ||  AC >= AB + BC) {
		printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	else if(fabs(AB - BC) < E && fabs(BC - AC) < E && fabs(AB - AC) < E) {
		printf("Jednakostranicni\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
			return 0; 
		
	}
	
	if(fabs(AB*AB - BC*BC - AC*AC) < E || fabs(AC*AC - BC*BC - AB*AB) < E || fabs(BC*BC - AB*AB - AC*AC) < E) printf("Pravougli\n");
	
	if((fabs(AB- BC) < E && AB != AC) || (fabs(BC - AC) < E && BC != AB) || (fabs(AC - AB) < E && AC != BC)) printf("Jednakokraki\n");
	
	else printf("Raznostranicni\n");

	if(a > b && a > c)
		max = a;
	else if(b > a && b > c)
		max = b;
	else
		max = c;
	step = max;
	max -= step;
	max *= 60;
	min = max;
	max -= min;
	max *= 60;
	sek = max;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step, min, sek);
	return 0;
}
