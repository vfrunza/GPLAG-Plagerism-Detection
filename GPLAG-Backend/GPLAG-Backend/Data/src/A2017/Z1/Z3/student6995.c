#include <stdio.h>
#include <math.h>
//#define E 0.001
//#define F 0.1
double E=0.001;
double F=0.1;

int main() {
	//printf("Zadaća 1, Zadatak 3");
	int a, b, c;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%d", &a);
	scanf ("%d", &b);
	scanf ("%d", &c);
	float d;
	float x1, x2, xm, xv;
	float y1, y2;
	d= (b*b -4*a*c);
	if (d>=0) {
		x1 = ((-b-sqrt(d)) / (2*a));
		x2 = ((-b+sqrt(d)) / (2*a));
	//	printf ("x1=%f x2=%f", x1, x2);
		if (x1>x2) {
			xv=x1;
			xm=x2;
		}
		else {
			xv=x2;
			xm=x1;
		}
		int i=1;
		do {
			printf ("Unesite rjesenje x1: ");
			scanf ("%f", &y1);
			if (y1<xm + E && y1>xm - E) {
				i=0;
				printf ("Tacno\n");
			}
			else if (y1>=xm - F && y1<xm) printf ("Priblizno manje\n");
			else if (y1<=xm + F && y1>xm) printf ("Priblizno vece\n");
			else if (y1<xm - F) printf ("Manje\n");
			else if (y1>xm + F) printf ("Vece\n");

		} while (i);
		
		i=1;
		do {
			printf ("Unesite rjesenje x2: ");
			scanf ("%f", &y2);
			if (y2<xv + E && y2>xv - E) {
				i=0;
				printf ("Tacno\n");
			}
			else if (y2>=xv - F && y2<xv) printf ("Priblizno manje\n");
			else if (y2<=xv + F && y2>xv) printf ("Priblizno vece\n");
			else if (y2<=xm - F) printf ("Manje\n");
			else if (y2>=xm + F) printf ("Vece\n");

		} while (i);
	}
	else printf ("Rjesenja su imaginarni brojevi.");
	return 0;
}
