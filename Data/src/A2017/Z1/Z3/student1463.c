#include <stdio.h>
#include <math.h>

#define eps 0.001

int main() {
	double a, b, c, x1, x2, D, x1_uneseno, x2_uneseno, razlika; 
	
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	
	D = b * b - 4 * a * c;
	
	if (D < 0.0)
		printf ("Rjesenja su imaginarni brojevi.");
	else {	
		
		/* Racunanje rjesenja kvadratne jednacine za koeficijente koje unosi korisnik */
		x1 = (-b + sqrt(D)) / (2. * a);
		x2 = (-b - sqrt(D)) / (2. * a);
		
		/* Ispitivanje tacnosti rjesenja x1, koje unosi korisnik */
		
		do {
			printf ("Unesite rjesenje x1: ");
			scanf ("%lf", &x1_uneseno);
			
			razlika = x1_uneseno - x1;
			
			if (fabs(razlika) < eps)
				printf ("Tacno\n");
			else if (razlika <= -0.1)
				printf ("Manje\n");
			else if (razlika >= 0.1)
				printf ("Vece\n");
			else if (razlika > -0.1 && razlika < 0.0)
				printf ("Priblizno manje\n");
			else if (razlika > 0.0 && razlika < 0.1)
				printf ("Priblizno vece\n");
					
		} while (fabs(razlika) >= eps);
			
				
		/* Ispitivanje tacnosti rjesenja x2, koje unosi korisnik */
		
		do { 
			printf ("Unesite rjesenje x2: ");
			scanf ("%lf", &x2_uneseno);
			
			razlika = x2_uneseno - x2;
			
			
			if (fabs(razlika) < eps)
				printf ("Tacno\n");
			else if (razlika <= -0.1)
				printf ("Manje\n");
			else if (razlika >= 0.1)
				printf ("Vece\n");
			else if (razlika > -0.1 && razlika < 0.0)
				printf ("Priblizno manje\n");
			else if (razlika > 0.0 && razlika < 0.1)
				printf ("Priblizno vece\n");
				
		} while (fabs(razlika) >= eps);
			
				
	}
			
	return 0;
}
