#include <stdio.h>

int main() {
	double x1,x2,x3,y1,y2,y3;
	printf("Unesite koordinaate tacke t1: ");
	scanf("%lf %lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	if(x1==x2==x3 || y1==y2==y3) {
		printf("Linija")
	}
	return 0;
}
