#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define PI (4 * atan(1.0))

int main() {
	double x1, y1;
	double x2, y2;
	double x3, y3;
	
	/* a: 1 - 2 */
	/* b: 2 - 3 */
	/* c: 1 - 3 */
	double a, b, c;
	double angle1, angle2, angle3, maxangle;
	int degrees, minutes, seconds;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf%lf", &x1, &y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf%lf", &x2, &y2);
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf%lf", &x3, &y3);
	
	a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
	c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	
	angle1 = acos((a * a + b * b - c * c) / (2.0 * a * b)) * 180.0 / PI;
	angle2 = acos((a * a + c * c - b * b) / (2.0 * a * c)) * 180.0 / PI;
	angle3 = acos((b * b + c * c - a * a) / (2.0 * b * c)) * 180.0 / PI;
	maxangle = (angle1 > angle2) ? angle1 : angle2;
	maxangle = (maxangle < angle3) ? angle3 : maxangle;
	
	if (fabs(maxangle - 90.0) < EPSILON)
		printf("Pravougli\n");
	
	if (fabs(maxangle - 180.0) < EPSILON)
		printf("Linija\n");
	else if (fabs(maxangle - 60.0) < EPSILON)
		printf("Jednakostranicni\n");
	else if (fabs(a - b) < EPSILON || fabs(b - c) < EPSILON || fabs(a - c) < EPSILON)
		printf("Jednakokraki\n");
	else
		printf("Raznostranicni\n");
	
	degrees = (int)maxangle;
	
	angle1 = maxangle - (double)degrees;
	angle1 *= 60.0;
	minutes = (int)angle1;
	
	angle2 = angle1 - (double)minutes;
	angle2 *= 60.0;
	seconds = (int)angle2;
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", degrees, minutes, seconds);
	
	return 0;
}
