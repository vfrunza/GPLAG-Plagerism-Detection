#include <stdio.h>
#include <math.h>

int main() {
double a, b, c, x1, x2, k, k2, ux1, ux2, diff_x1, diff_x2, x1c;


do{
printf("Unesite koeficijente a, b i c: ");
scanf("%lf %lf %lf", &a, &b, &c);
} while(a == 0);


k2 = b * b - 4 * a * c;


/*U slucaju da je pod korijenom negativan broj*/
if(k2 < 0){
	printf("Rjesenja su imaginarni brojevi.");
	return 1;
}

/*Rjesenja kvadratne jednacine*/
k = sqrt(k2);
x1 = (-b - k) / (2 * a);
x2 = (-b + k) / (2 * a);


/*Obrniti rjesenja ukoliko nisu sortirana pravilno*/
if(x1 > x2){
	x1c = x1;
	x1 = x2;
	x2 = x1c;
}

/*Provjera prvog rjesenja x1*/
do {

printf("Unesite rjesenje x1: ");
scanf("%lf", &ux1);


diff_x1 = x1 - ux1;


if(fabs(diff_x1) < 0.001) {
	printf("Tacno\n");
} else if(fabs(diff_x1) < 0.1 && ux1 < x1) {
	printf("Priblizno manje\n");
} else if(fabs(diff_x1) < 0.1 && ux1 > x1) {
	printf("Priblizno vece\n");
} else if(ux1 < x1) {
	printf("Manje\n");
} else if(ux1 > x1) {
	printf("Vece\n");
}
} while(fabs(diff_x1) >= 0.001);


do {

printf("Unesite rjesenje x2: ");
scanf("%lf", &ux2);


diff_x2 = x2 - ux2;


if(fabs(diff_x2) < 0.001) {
	printf("Tacno\n");
} else if(fabs(diff_x2) < 0.1 && ux2 < x2) {
	printf("Priblizno manje\n");
} else if(fabs(diff_x2) < 0.1 && ux2 > x2) {
	printf("Priblizno vece\n");
} else if(ux2 < x2) {
	printf("Manje\n");
} else if(ux2 > x2) {
	printf("Vece\n");
}
} while(fabs(diff_x2) >= 0.001);



return 0;

	
}
