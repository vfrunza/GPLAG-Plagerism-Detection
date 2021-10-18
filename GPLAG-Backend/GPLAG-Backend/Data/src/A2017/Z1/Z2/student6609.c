#include <stdio.h>
#include <math.h>
#define eps 0.0001

int main() {
	
	double x1, y1, x2, y2, x3, y3;
	double x12=0, y12=0, x13=0, y13=0, x23=0, y23=0, fi_max=0, fi_ab=0, fi_ac=0, fi_bc=0, a=0, b=0, c=0;
	int pom=0, d=0, m=0, s=0;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	x12=x2-x1;
	y12=y2-y1;
	x13=x3-x1;
	y13=y3-y1;
	x23=x3-x2;
	y23=y3-y2;
	
	a=sqrt(x12*x12+y12*y12); 
	b=sqrt(x13*x13+y13*y13); 
	c=sqrt(x23*x23+y23*y23);
	
	fi_ab=(acos((-c*c+a*a+b*b)/(2*a*b)))*180/(acos(-1));
	fi_ac=(acos((-b*b+a*a+c*c)/(2*a*c)))*180/(acos(-1));
	fi_bc=(acos((-a*a+b*b+c*c)/(2*b*c)))*180/(acos(-1));
	
	fi_max=fi_ab;
	if(fi_ac>fi_max) fi_max=fi_ac;
	if(fi_bc>fi_max) fi_max=fi_bc;
	
	if(fabs(fi_ab-90)<eps || fabs(fi_ac-90)<eps || fabs(fi_bc-90)<eps) {
		printf("Pravougli");
		pom=1;
	}
	
	if(fabs(fi_max-180)<eps) printf("Linija");
	else if((fabs(a-b)<eps && fabs(a-c)>eps) || (fabs(a-c)<eps && fabs(a-b)>eps) || (fabs(b-c)<eps && fabs(b-a)>eps)) {
		if(pom==1) printf("\n");
		printf("Jednakokraki");
	}
	else if(fabs(a-b)<eps && fabs(a-c)<eps) printf("Jednakostranicni");
	else {
		if(pom==1) printf("\n");
		printf("Raznostranicni");
	}
	
	d=fi_max+eps;
	m=(fi_max-d)*60+eps;
	s=((fi_max-d)*60-m)*60+eps;
	
	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", d, m, s);

	
	return 0;
}
