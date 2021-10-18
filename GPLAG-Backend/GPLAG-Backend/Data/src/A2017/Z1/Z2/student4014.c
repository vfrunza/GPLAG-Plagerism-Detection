#include <stdio.h>
#include <math.h>
#define Pi 3.14159 
#define epsilon 0.0001

int main() {
	double ax, ay, bx, by, cx, cy;
	double a, b, c; 
	printf("Unesite koordinate t1: ");
	scanf("%lf", &ax);
	scanf("%lf", &ay); 
	printf("Unesite koordinate t2: "); 
	scanf("%lf", &bx); 
	scanf("%lf", &by); 
	printf("Unesite koordinate t3: "); 
	scanf("%lf", &cx); 
	scanf("%lf", &cy); 
	a = sqrt(((bx-cx)*(bx-cx))+((by-cy)*(by-cy))); 
	b = sqrt(((ax-cx)*(ax-cx))+((ay-cy)*(ay-cy)));
	c = sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));
	double alpha, beta, gama;
	alpha = acos((((c*c)+(b*b)-(a*a))/(2*b*c))); 
	beta = acos((((b*b)+(a*a)-(c*c)))/(2*a*c)); 
	gama = acos((((a*a)+(b*b)-(c*c)))/(2*a*b));
	
	alpha = alpha*(180/Pi);
	beta = beta*(180/Pi); 
	gama = gama*(180/Pi);
	
	if(alpha-90<epsilon || beta-90<epsilon || gama-90<epsilon) 
	printf("Pravougli");
	else if(a==b || a==c || b==c) 
	printf("Jednakostranicni");
	else if(b==b) 
	printf("Jednakokraki"); 
	else if(a!==b || a!==c || b!==c)
	printf("Raznostranicni"); 
	else if(alpha-90<epsilon || beta-90<epsilon || gama-90<epsilon || b==b)
	printf("Jednakokraki i pravougli");
	else if(a == ax || b == ax || c == ax || a == bx || b == bx || c == bx || a == cx || b == cx || c == cx)
	printf("Linija"); 
	else if(b == b || alpha-90<epsilon || beta-90<epsilon || gama-90<epsilon)
	printf("Jednakokraki i pravougli");
	return 0;
}
