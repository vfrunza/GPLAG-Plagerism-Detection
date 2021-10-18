#include <stdio.h>
#include <math.h>

int main() {
double a1, a2, b1, b2, x, y;
const double eps=1e-10;
printf("Unesite a1,b1,a2,b2: ");
scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
if(fabs(a1-a2)<=eps && fabs(b1-b2)>eps)
 {
	printf("Paralelne su");
	return 0;
}

if(fabs(a1-a2)<=eps && fabs(b1-b2)<=eps)
{
	printf("Poklapaju se");
	return 0;
}
x=(b2-b1)/(a1-a2);
y=a1*x+b1;
printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);

	return 0;
}
