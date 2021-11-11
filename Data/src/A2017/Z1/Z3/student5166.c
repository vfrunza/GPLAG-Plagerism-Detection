#include <stdio.h>
#include <math.h>
#define eps 0.001

int main() {
	
	double a,b,c;
	double X1,X2;
	double x1Re,x2Re,x1Im,x2Im;
	double t,D,unos1,unos2;
	
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	D=b*b - 4.0*a*c; /* diskriminanta*/
	
	if (D>=0){
		t=sqrt(D);
		/* t = broj koji dobijemo korjenovanjem*/
		X1=(-b + t) / (2*a);
		X2=(-b - t ) / (2*a);
		int brojac1,brojac2;
		brojac1=0;
		brojac2=0;
		
		do {
		printf ("Unesite rjesenje x1: ");
		scanf ("%lf", &unos1);
		
		if (fabs(X1-unos1)<eps) {
			printf ("Tacno\n");
			brojac1++;
			}
		else if(fabs(X1-unos1)<0.1) { 
			if ((X1-unos1)>0) 
			printf("Priblizno manje\n");
			else if ((X1-unos1)<0) 
			printf ("Priblizno vece\n");
	        }
		else { 
			if ((X1-unos1)>0)
			printf("Manje\n");
			else if ((X1-unos1)<0)
			printf ("Vece\n");
	        } 
		} while (brojac1==0);
		
	do {
	    printf ("Unesite rjesenje x2: ");
		scanf ("%lf", &unos2);
		
		if (fabs(X2-unos2)<eps) {
			printf ("Tacno\n");
			brojac2++;
			}
		else if(fabs(X2-unos2)<0.1) {
			if ((X2-unos2)>0) 
			printf("Priblizno manje\n");
			else if ((X2-unos2)<0)
			printf ("Priblizno vece\n");
	        }
		else { 
			if ((X2-unos2)>0) 
			printf("Manje\n");
			else if ((X2-unos2)<0) 
			printf ("Vece\n");
	        }
	} while (brojac2==0);
}
	
	else if (D<0){
		t=sqrt (-D);
		x1Re = -b / (2*a);
		x2Re = x1Re;
		x1Im = t / (2*a);
		x2Im = -x1Im;
		printf ("Rjesenja su imaginarni brojevi.");
	    }
	return 0;
}