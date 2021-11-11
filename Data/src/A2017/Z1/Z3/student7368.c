#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main() {
	double a,b,c,D=0,korijen=0,rjesenje1=0,rjesenje2=0,x1,x2,aps;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf",&a,&b,&c);
	
	D=b*b-4*a*c;
	korijen=sqrt(D);
	if (D<0) {
		printf ("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	if (fabs(D-D)<epsilon) {
		rjesenje1=-(b/(2*a));
		rjesenje2=-(b/(2*a));
	}
	if (b<epsilon){
		if((a<0 && c>0) || (a>0 && c<0)) {
			if (a<0) a=-a;
			if (c<0) c=-c;
			rjesenje1=-sqrt(c/a);
			rjesenje2=sqrt(c/a);
		}
		else if ((a<0 && b<0) || (a>0 && b>0)){
			if (a<0) a=-a;
			if (b<0) b=-b;
			rjesenje1=-sqrt(c/a);
			rjesenje2=sqrt(c/a);
		}

	}
	else {
	rjesenje1=((-b)+korijen)/2;
	rjesenje2=((-b)-korijen)/2;
	}
	while (1) {
		printf ("Unesite rjesenje x1: ");
		scanf("%lf",&x1);
		aps=fabs(rjesenje1-x1);
		if (aps<epsilon){
			printf ("Tacno\n");
			break;
		}
		else if (x1>rjesenje1 && aps<0.1) printf ("Priblizno vece\n");
		else if (x1<rjesenje1 && aps<0.1) printf ("Priblizno manje\n");
		else if (x1>rjesenje1) printf ("Vece\n");
		else if (x1<rjesenje1) printf ("Manje\n");
	}
    while (1) {
    	printf ("Unesite rjesenje x2: ");
    	scanf ("%lf",&x2);
    	aps=fabs(rjesenje2-x2);
    	if (aps<epsilon){
    		printf ("Tacno\n");
    		break;
    	}
    	else if (x2>rjesenje2 && aps<0.1) printf ("Priblizno vece\n");
		else if (x2<rjesenje2 && aps<0.1) printf ("Priblizno manje\n");
		else if (x2>rjesenje2) printf ("Vece\n");
		else if (x2<rjesenje2) printf ("Manje\n");
    }
	return 0;
}
