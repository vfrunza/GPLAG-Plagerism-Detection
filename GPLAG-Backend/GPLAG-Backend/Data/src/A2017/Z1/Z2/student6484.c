#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define EPSILON 0.0001
#define degrees 57.32484

int main() {
	double aa, ab, ba, bb, ca, cb, a, b, c,au,bu,ph,cu,step,min,sec;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &aa, &ab);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &ba, &bb);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &ca, &cb);
	if (aa == ab && ab == ba && ba == bb && bb == ca && ca == cb) {
		printf("Linija\n");
	}
	a = sqrt(pow(ba-aa, 2) + pow(bb-ab, 2));
	b = sqrt(pow(ca-ba, 2) + pow(cb-bb, 2));
	c = sqrt(pow(aa-ca, 2) + pow(ab-cb, 2));

	if ((fabs((pow(a,2)+pow(b,2))-pow(c,2))<EPSILON) || (fabs((pow(a,2)+pow(c,2))-pow(c,2))<EPSILON) || (fabs((pow(b,2)+pow(c,2))-pow(a,2))<EPSILON)) {
		printf("Pravougli\n");
	}
	if(a==b && b==c) {
		printf("Jednakostranicni\n");
	} else if(a==b && a!=c || a==c && a!=b || b==c && c!=a) {
		printf("Jednakokraki\n");
	} else if(a!=b && b!=c && a!=c) {
		printf("Raznostranicni\n");
	}
	au=(acos(((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c)))*degrees);
	bu=(acos(((pow(c,2)+pow(a,2)-pow(b,2))/(2*b*c)))*degrees);
	cu=(acos(((pow(a,2)+pow(b,2)-pow(c,2))/(2*b*c)))*degrees);
	step=au;
	if(step<bu) step=bu;
	if(step<cu) step=cu;
	ph=step;
//	printf("%g\n", ph);
	step = (int)step;
	min=(ph-step)/60;
	ph=min;
//	printf("%g\n", ph);
	min=(int) min;
	sec=(ph-min)/60;
	sec=(int)sec;
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",step,min,sec);
	return 0;
}
