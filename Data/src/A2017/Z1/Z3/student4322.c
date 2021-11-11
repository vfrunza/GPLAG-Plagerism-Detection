#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double a, b, c, D, x1=0, x2=0, unosx1=-100, unosx2=-100;
	printf("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a,&b,&c);
	D=b*b-4*a*c;
	if (D<0) {
		printf ("Rjesenja su imaginarni brojevi.");
	}
	else if(c!=0 && a!=0) {
		x2=(-b-sqrt(D))/(2*a);
		x1=(-b+sqrt(D))/(2*a);
	while (fabs(unosx1-x1)>EPSILON) {
		printf ("Unesite rjesenje x1: ");
		scanf ("%lf", &unosx1);
		if(x1>EPSILON){
		if(unosx1>EPSILON) {
			if(unosx1-x1>0.1) printf("Vece\n");
			else if(unosx1-x1>EPSILON && unosx1-x1<0.1) printf("Priblizno vece\n");
			else if(unosx1-x1<EPSILON && fabs(unosx1-x1)>0.1) printf("Manje\n");
			else if(fabs(unosx1-x1)>EPSILON && fabs(unosx1-x1)<0.1) printf("Priblizno manje\n");
		}
		else if(unosx1<EPSILON) printf("Manje\n");
	}
		else if(x1<EPSILON) {
			if(unosx1>EPSILON) printf("Vece\n");
			if(unosx1<EPSILON) {
				if(unosx1-x1>EPSILON && unosx1-x1<0.1 && unosx1-x1>0) printf("Priblizno vece\n");
				else if(unosx1-x1>0.1 && unosx1-x1>0) printf("Vece\n");
				else if(unosx1-x1<0 && fabs(unosx1-x1)>EPSILON && fabs(unosx1-x1)<0.1) printf("Priblizno manje\n");
				else if(unosx1-x1<0 && fabs(unosx1-x1)>0.1) printf("Manje\n");
			}
		}
	} printf ("Tacno\n");
	while (fabs(unosx2-x2)>EPSILON) {
		printf ("Unesite rjesenje x2: ");
		scanf ("%lf", &unosx2);
		if(x2>EPSILON){
		if(unosx2>EPSILON) {
			if(unosx2-x2>0.1) printf("Vece\n");
			else if(unosx2-x2>EPSILON && unosx2-x2<0.1) printf("Priblizno vece\n");
			else if(unosx2-x2<EPSILON && fabs(unosx2-x2)>0.1) printf("Manje\n");
			else if(fabs(unosx2-x2)>EPSILON && fabs(unosx2-x2)<0.1) printf("Priblizno manje\n");
		}
		else if(unosx2<EPSILON) printf("Manje\n");
	}
		else if(x2<EPSILON) {
			if(unosx2>EPSILON) printf("Vece\n");
			if(unosx2<EPSILON) {
				if(unosx2-x2>EPSILON && unosx2-x2<0.1 && unosx2-x2>0) printf("Priblizno vece\n");
				else if(unosx2-x2>0.1 && unosx2-x2>0) printf("Vece\n");
				else if(unosx2-x2<0 && fabs(unosx2-x2)>EPSILON && fabs(unosx2-x2)<0.1) printf("Priblizno manje\n");
				else if(unosx2-x2<0 && fabs(unosx2-x2)>0.1) printf("Manje\n");
			}
		}
	}   printf ("Tacno"); }
	else if(b==0 && c==0) {
		while (unosx1<=-EPSILON || unosx1>=EPSILON) {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &unosx1);
		if(unosx1>-0.1 && unosx1<-EPSILON) printf("Priblizno manje\n");
		else if(unosx1<0.1 && unosx1>0) printf("Priblizno vece\n");
		else if(unosx1>=0.1) printf("Vece\n");
		else if(unosx1<=-0.1) printf("Manje\n");
	}  printf("Tacno\n");
		while (unosx2<=-EPSILON || unosx2>=EPSILON) {
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &unosx2);
			if(unosx2>-0.1 && unosx2<-EPSILON) printf("Priblizno manje\n");
			else if(unosx2<0.1 && unosx2>EPSILON) printf("Priblizno vece\n");
			else if(unosx2>=0.1) printf("Vece\n");
			else if(unosx2<=-0.1) printf("Manje\n");
		} printf("Tacno\n");
	}
	return 0;
}
