#include <stdio.h>
#include <math.h>

int main() {
	float a, b, c, d, x1, x2, m, n, test;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%f%f%f", &a,&b,&c);
	d=b*b-4*a*c;
	if (d<0)
	{
		printf ("Rjesenja su imaginarni brojevi.");
	}
	else
	{
		d=b*b-4*a*c;
		x1=(-b+sqrt(d))/(2*a);
		x2=(-b-sqrt(d))/(2*a);
		test = 1;
		while (test==1) { 
				  printf ("Unesite rjesenje x1:");
	  			  scanf ("%f", &m);
	 			 if(fabs(m-x1)<0.001) {
	 			 	printf (" Tacno");
	 			 	test = 0;
	 			 }
	 			 else if (m<x1 && (x1-m)>=0.1) 
	 			 printf (" Manje\n");
	 			 else if (m>x1 && (m-x1)>=0.1) 
	 			 printf (" Vece\n");
	 			 else if ((m-x1)>0 && (m-x1)<0.1) 
	 			 printf (" Priblizno vece\n");
	 			 else if ((x1-m)>0 && (x1-m)<0.1) 
	 			 printf (" Priblizno manje\n");
	 			 
		}
		test=1;
		while (test==1){
	  printf (" \nUnesite rjesenje x2:");
	  scanf ("%f", &n);
	 if(fabs(n-x2)<0.001) {
	 			 	printf (" Tacno\n");
	 			 	test = 0;
	 			 }
	 			 else if (n<x2 && (x2-n)>=0.1) 
	 			 printf (" Manje\n");
	 			 else if (n>x2 && (n-x2)>=0.1) 
	 			 printf (" Vece\n");
	 			 else if ((n-x2)>0 && (n-x2)<0.1) 
	 			 printf (" Priblizno vece\n");
	 			 else if ((x2-n)>0 && (x2-n)<0.1) 
	 			 printf (" Priblizno manje\n");
	 			 
	}
	
	}
	return 0;
}