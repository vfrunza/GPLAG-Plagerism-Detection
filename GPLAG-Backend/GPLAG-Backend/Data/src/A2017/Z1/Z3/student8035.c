#include <stdio.h>
#include <math.h>
#define EPS 0.001

int main() {
	double a,b,c,x1,x2,r1,r2;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	if ((b*b-4*a*c)<0){
	printf ("Rjesenja su imaginarni brojevi.");
	return 1;}
	r1 = (-b - sqrt(b*b-4*a*c))/(2*a);
	r2 = (-b + sqrt(b*b-4*a*c))/(2*a);
	
	if (r1>r2){
    r2 = (-b - sqrt(b*b-4*a*c))/(2*a);
	r1 = (-b + sqrt(b*b-4*a*c))/(2*a);
	}
	
	do {
		printf ("Unesite rjesenje x1: ");
		scanf ("%lf", &x1);
	    if ((x1<(r1+EPS)) && (x1>(r1 - EPS)))
	    break;
	    if ((fabs(x1-r1))<0.1) {
	    if (x1>=r1)
	    printf ("Priblizno vece\n");
	    else if (x1<=r1)
	    printf ("Priblizno manje\n");
	    continue;
	    }
     	if (x1 > r1)
        printf ("Vece\n");
	    else if (x1 < r1)
	    printf ("Manje\n");
	   
	}
	while ( ((x1 >= (EPS + r1))  ||  (x1 <= (r1 - EPS))));
	if ((x1<(r1+EPS)) && (x1>(r1 - EPS)))
	printf ("Tacno \n");
	
	do {
		printf ("Unesite rjesenje x2: ");
		scanf ("%lf", &x2);
	    if ((x2 < (EPS + r2))  &&  (x2 > (r2 - EPS)))
	    break;
	    if ((fabs(x2-r2))<0.1){
	    if (x2>=r2)
	    printf ("Priblizno vece\n");
	    else if (x2<=r2)
	    printf ("Priblizno manje\n");
	    continue;}
		if (x2 > r2)
        printf ("Vece\n");
	    else if (x2 < r2)
	    printf ("Manje\n");
	 
	}
	while ( ((x2 >= (EPS + r2))  ||  (x2 <= (r2 - EPS))));
	if ((x2<(r2+EPS)) && (x2>(r2 - EPS)))
	printf ("Tacno");
	
	return 0;
}	
