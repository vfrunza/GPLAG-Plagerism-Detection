#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265
int main() {
	double x1, y1, x2, y2, x3, y3, d12, d13, d23, u12, u13, u23;
	int su12, mu12, sku12, su13, mu13, sku13, su23, mu23, sku23;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	d12=sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
	d13=sqrt(pow(x3-x1, 2)+pow(y3-y1, 2));
	d23=sqrt(pow(x3-x2, 2)+pow(y3-y2, 2));
	
	u12=acos((pow(d13,2) + pow(d23, 2) - pow(d12, 2))/(2.*d13*d23))*180/PI;
	u13=acos((pow(d12,2) + pow(d23, 2) - pow(d13, 2))/(2.*d12*d23))*180/PI;
	u23=acos((pow(d13,2) + pow(d12, 2) - pow(d23, 2))/(2.*d13*d12))*180/PI;
	
	su12=floor(u12);
	mu12=floor((u12-su12)*60);
	sku12=floor(((u12-su12)*60-mu12)*60);
	
	su13=floor(u13);
	mu13=floor((u13-su13)*60);
	sku13=floor(((u13-su13)*60-mu13)*60);
	
	su23=floor(u23);
	mu23=floor((u23-su23)*60);
	sku23=floor(((u23-su23)*60-mu23)*60);
	
	if (fabs(d12-(d13+d23))<EPSILON || fabs(d13-(d12+d23))<EPSILON || fabs(d23-(d13+d12))<EPSILON) {
		printf("Linija");
		printf("\n");
	} else {
		if ((fabs(d12-sqrt(pow(d13, 2) + pow(d23, 2)))<EPSILON) || (fabs(d13-sqrt(pow(d12, 2) + pow(d23, 2)))<EPSILON) || (fabs(d23-sqrt(pow(d13, 2) + pow(d12, 2)))<EPSILON)) {
		printf("Pravougli");
		printf("\n");
		}
		if (fabs(d12-d23)<=EPSILON && fabs(d12-d13)<=EPSILON) {
			printf("Jednakostranicni");
			printf("\n");
		} else if(fabs(d12-d13)<=EPSILON || fabs(d12-d23)<=EPSILON || fabs(d13-d23)<=EPSILON) {
			printf("Jednakokraki");
			printf("\n");
		} else if(d12!=d13 && d12!=d23 && d13!=d23) {
		printf("Raznostranicni");
		printf("\n");
		}
	}
	if(u12>=u13 && u12>=u23) {
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", su12, mu12, sku12);
	} else if(u13>=u12 && u13>=u23) {
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", su13, mu13, sku13);
	} else if(u23>=u12 && u23>=u13) {
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", su23, mu23, sku23);
	}
	
	return 0;
}
