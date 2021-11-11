#include <stdio.h>
#define EPSILON 0.0001
#define EPSILON1 0.1
#include <math.h>
int main()
{
	double a, b, c, x1=0, x2=0, D=0, kx1, kx2;
	/*Ulaz programa*/
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	x1=(-b+sqrt(b*b-4*a*c))/2*a; /* Prvo rjesenje kvadratne jednacine*/
	x2=(-b-sqrt(b*b-4*a*c))/2*a; /* Drugo rjesenje kvadratne jednacine*/
	D=b*b-4*a*c;	/*Diskriminanta koja se koristi za analizu prirode rjesenja kvadratne jednacine*/
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
	} /*Ako je diskriminanta manja od nule kvadratna jednacina nema rjesenja u skupu realnih brojeva*/

	else {
		do {	/*Pomocu do-while petlje osigurat cemo da se unos ponavlja dok korisnik ne pogodi tacnu vrijednost prvog rjesenja*/
			printf("Unesite rjesenje x1: "); /*Korisnik unosi svoju vrijednost prvog rjesenja*/
			scanf("%lf", &kx1);

			if(fabs(x1-kx1)<EPSILON) {	/*Pomocu if-else usporedit cemo vrijednost prvog rjesenja koju korisnik unosi sa rjesnjem programa*/
				printf("Tacno\n");
			} else if(fabs(kx1-x1)<EPSILON1 && kx1>x1) {
					printf("Priblizno vece\n");
				} else if(fabs(kx1-x1)<EPSILON1 && kx1<x1) {
					printf("Priblizno manje\n");
				}  else if(kx1>x1) {
					printf("Vece\n");
				} else if(kx1<x1) {
					printf("Manje\n");
				}
			

		} while(fabs(x1-kx1)>EPSILON);

		do { /*Pomocu do-while petlje osigurat cemo da se unos ponavlja dok korisnik ne pogodi tacnu vrijednost drugog rjesenja*/
			printf("Unesite rjesenje x2: "); /*Korisnik unosi svoju vrijednost drugog rjesenja*/
			scanf("%lf", &kx2);
			if(fabs(x2-kx2)<EPSILON) { /*Pomocu if-else usporedit cemo vrijednost drugog rjesenja koju korisnik unosi sa rjesnjem programa*/
				printf("Tacno\n");
			}else if(fabs(kx2-x2)<EPSILON1 && kx2>x2) {
					printf("Priblizno vece\n");
				}  else if(fabs(kx2-x2)<EPSILON1 && kx2<x2) {
					printf("Priblizno manje\n");
				} else  if(kx2>x2) {
					printf("Vece\n");
				} else if(kx2<x2) {
					printf("Manje\n");
				}
			
		} while(fabs(x2-kx2)>EPSILON);

	}
	return 0;
}
