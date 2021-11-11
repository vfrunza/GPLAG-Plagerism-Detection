#include <stdio.h>
#include <math.h>

#define eps 0.0001

int main() {
	double x1, x2, x3, y1, y2, y3, a, b, c, temp, step, min, sec;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	a = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	b = sqrt(pow(x2-x3, 2) + pow(y2-y3, 2));
	c = sqrt(pow(x3-x1, 2) + pow(y3-y1, 2));
	if(a > c && fabs(a - c) > eps){
		temp = c;
		c = a;
		a = temp;
	}
	if(b > c && fabs(b - c) > eps){
		temp = c;
		c = b;
		b = temp;
	}
	if(fabs(a + b - c) < eps) printf("Linija\n");
	else if((fabs(a - b) < eps) && (fabs(b - c) < eps)) printf("Jednakostranicni\n");
	else{
		if(fabs(pow(c,2) - pow(a,2) - pow(b,2)) < eps) printf("Pravougli\n");
		if((fabs(a - b) < eps && c - a > eps) || (c - a < eps && fabs(a - b) > eps) || (c - b < eps && fabs(a - b) > eps)) printf("Jednakokraki\n");
		else printf("Raznostranicni\n");
	}
	step = acos((pow(a,2) + pow(b,2) - pow(c,2))/(2*a*b))*180/(4*atan(1));
	min = (step - (int)step) * 60;
	sec = (min - (int)min) * 60;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)step, (int)min, (int)sec);
	return 0;
}
