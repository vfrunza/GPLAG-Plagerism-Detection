#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.0001
#define PI 3.14159265353
int main() {
	int U, M, S;
	double x1, y1, x2, y2, x3, y3, a, b, c, A, B;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	a = sqrt(pow((x3-x2), 2) + pow((y3 - y2), 2));
	b = sqrt(pow((x1-x3), 2) + pow((y1 - y3), 2));
	c = sqrt(pow((x2-x1), 2) + pow((y2 - y1), 2));
	
	if(fabs(pow(a,2) - (pow(b,2) + pow(c,2)))<EPSILON || fabs(pow(b,2) - (pow(a,2) + pow(c,2)))<EPSILON || fabs(pow(c,2) - (pow(b,2) + pow(a,2)))<EPSILON) {
		printf("Pravougli\n");
	}
	if(fabs(pow(a,2) - pow((b-c), 2)) < EPSILON || fabs(pow(b,2) - pow((a-c), 2)) < EPSILON || fabs(pow(c,2) - pow((a-b), 2)) < EPSILON) {
		printf("Linija");
	}
	else if((fabs(a-b) < EPSILON) && (fabs(b-c) < EPSILON)) {
		printf("Jednakostranicni");
	}
	else if((fabs(a-b)<EPSILON && fabs(a-c)>EPSILON) || (fabs(a-c)<EPSILON && fabs(a-b)>EPSILON) || (fabs(b-c)<EPSILON && fabs(b-a)>EPSILON)) {
		printf("Jednakokraki");
	}
	else if(fabs(a-b)>EPSILON && fabs(b-c)>EPSILON && fabs(c-a)>EPSILON) {
		printf("Raznostranicni");
	}
	
	if(a>b && a>c) {
		A = (pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c);
		B = acos(A);
		U = (B*180.0)/PI;
		M = ((B*180.0)/PI - U)*60.0;
		S = ((((B*180.0)/PI - U)*60.0) - M)*60.0;
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", U, M, S);
		
	}
	else if(b>a && b>c) {
		A = (pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c);
		B = acos(A);
		U = (B*180.0)/PI;
		M = ((B*180.0)/PI - U)*60.0;
		S = ((((B*180.0)/PI - U)*60.0) - M)*60.0;
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", U, M, S);
	}
	else if(c>a && c>b) {
		A = (pow(b,2)+pow(a,2)-pow(c,2))/(2*b*a);
		B = acos(A);
		U = (B*180.0)/PI;
		M = ((B*180.0)/PI - U)*60.0;
		S = ((((B*180.0)/PI - U)*60.0) - M)*60.0;
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", U, M, S);
		
	}


	
	
	
	
	
	
	return 0;
	
}
