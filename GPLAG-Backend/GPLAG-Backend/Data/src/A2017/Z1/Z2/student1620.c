#include <stdio.h>
#include <math.h>
#define PI 3.14159265
int main() {
	double x1,y1,x2,y2,x3,y3,d1,d2,d3,A,B,C,L,D,M,S,a,b,c,q,w,e;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	a = pow((x2-x1),2) + pow((y2-y1),2);
	d1 = sqrt (a);
	b = pow((x3-x2),2) + pow((y3-y2),2);
	d2 = sqrt (b);
	c = pow((x3-x1),2) + pow((y3-y1),2);
	d3 = sqrt (c);
	q = (pow(d2,2) + pow(d3,2) - pow(d1,2)) / (2*d2*d3)  ;
	A = acos(q) * 180.0 / PI ;
	w = (pow(d1,2) + pow(d3,2) - pow(d2,2)) / (2*d1*d3)  ;
	B = acos(w )* 180.0 / PI;
	e =(pow(d2,2) + pow(d1,2) - pow(d3,2)) / (2*d2*d1)  ;
	C = acos (e)* 180.0 / PI;
	if (A >= B && A >= C) {
		L = A;
	} else if (B >= A && B >= C) {
		L = B;
	} else if (C >= A && C >=B ) {
		L = C;
	}
	D = floor(L);
	M = floor ((L - D) * 60);
	S = floor ((((L - D) * 60) - M) * 60);
	if (D == 180) {
		printf ("Linija");
		printf ("\nNajveci ugao ima %g stepeni, 0 minuta i 0 sekundi.",D);
	} else if (((x1 == x2) && (y2 == y3)) || ((x1==x3) && (y3 == y2))) {
		printf ("Pravougli");
		if ((d1 == d2) || (d1 == d3) || (d2 == d3)) {
			printf("\nJednakokraki");
			printf("\nNajveci ugao ima %g stepeni, 0 minuta i 0 sekundi.",D);
		} else {
			printf("\nRaznostranicni");
			printf("\nNajveci ugao ima %g stepeni, 0 minuta i 0 sekundi.",D);
		}
	} else if (d1 == d2 == d3) {
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima %g stepeni, 0 minuta i 0 sekundi.\n",D);
	} else if (floor(e) != floor(q) != floor(w)) {
		printf ("Raznostranicni\n");
		if (A >= B && A >= C) {
			L = A;
		} else if (B >= A && B >= C) {
			L = B;
		} else if (C >= A && C >=B ) {
			L = C;
		}
		D = floor(L);
		M = floor ((L - D) * 60);
		S = floor ((((L - D) * 60) - M) * 60);
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",D,M,S) ;
	} else {
		printf ("Jednakokraki\n");
		if (A >= B && A >= C) {
			L = A;
		} else if (B >= A && B >= C) {
			L = B;
		} else if (C >= A && C >=B ) {
			L = C;
		}
		D = floor(L);
		M = floor ((L - D) * 60);
		S = floor ((((L - D) * 60) - M) * 60);
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",D,M,S);
	}
	
	return 0;
}
