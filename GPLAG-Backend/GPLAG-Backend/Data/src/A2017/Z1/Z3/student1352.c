#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define epsilon 0.1

int main() {
	double a=0, b=0, c=0, x1=0, x2=0, rjesenje1=0, rjesenje2=0, D=0, z=0, t=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	
		D=((b*b)-(4*a*c));
		

	if (D>=0)
	{
		rjesenje1=((-b+sqrt(D))/(2*a));
		rjesenje2=((-b-sqrt(D))/(2*a));
	
		
		do
	{
		printf ("Unesite rjesenje x1: ");
		scanf("%lf", &x1); 
	
		 
		 	if (fabs(rjesenje1-x1)<EPSILON){
			printf("Tacno\n");
			t=1;
			
		}
		else if (x1<rjesenje1)
		{
			if (fabs(rjesenje1-x1)<epsilon){
			printf ("Priblizno manje\n");
		}
		else {
			printf ("Manje\n");
		}
		 }
		else if (x1>rjesenje1)
		{
			if (fabs(rjesenje1-x1)<epsilon){
			printf("Priblizno vece\n");
		}
		else {
			printf ("Vece\n");
		  }
		} 
	}
	while (t==0);
		
	t=0;
	do {
		printf ("Unesite rjesenje x2: ");
		scanf ("%lf", &x2);
	
	
		if (fabs(rjesenje2-x2)<EPSILON){
			printf("Tacno\n");
		     t=1;
		}
		else if (x2<rjesenje2)
		{
			if (fabs(rjesenje2-x2)<epsilon){
			printf ("Priblizno manje\n");
		} 
		else {
			printf ("Manje\n");
		}
		}
		else if (x2>rjesenje2)
		{
			if (fabs(rjesenje2-x2)<epsilon){
			printf("Priblizno vece\n");
		}
		else{
			printf ("Vece\n");
		}
	 }
	}
		while (t==0);

}

      if (D<0)
	{
		printf ("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	

		return 0;
}
