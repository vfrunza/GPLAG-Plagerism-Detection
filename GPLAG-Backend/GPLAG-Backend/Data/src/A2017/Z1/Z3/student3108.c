#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define GRK2 0.1

int main() {
	
	double x1, x2, D, t, a, b, c, pogodak1=0, pogodak2=0;
	
	/*--------------------------------------------*/
	/*             ULAZNI DIO ZADATKA             */
	/*--------------------------------------------*/
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	/*--------------------------------------------*/
	/*        RACUN KVADRATNE JEDNACINE           */
	/*--------------------------------------------*/
	
	D=(pow(b, 2)) - 4.0 * a *c;
	t=sqrt(D);
	x1=(-b + t) / (2 * a);
	x2=(-b - t) / (2 * a);
	
	/*--------------------------------------------*/
	/*      SLUCAJ ZA IMAGINARAN REZULTAT         */
	/*--------------------------------------------*/
	
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	/*--------------------------------------------*/
	/*           POGADJANJE REZULTATA             */
	/*--------------------------------------------*/
	
	/*---------------------------------*/
	/*        POGADJANJE ZA X1         */
	/*---------------------------------*/
	
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &pogodak1);
		
		if(fabs(pogodak1-x1) < EPSILON) {
			printf("Tacno\n");
		}
		else {
			if(pogodak1 > x1) {
				if(fabs(pogodak1-x1) < GRK2) {
					printf("Priblizno vece\n");
				}
				else {
					printf("Vece\n");
				}
			}
			else if(pogodak1 < x1) {
				if(fabs(pogodak1-x1) < GRK2) {
					printf("Priblizno manje\n");
				}
				else {
					printf("Manje\n");
				}
			}
		}
		
	} while(fabs(pogodak1-x1) >= EPSILON);
	
	/*-----------------------------------*/
	/*         POGADJANJE ZA X2          */
	/*-----------------------------------*/
	
	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &pogodak2);
		
		if(fabs(pogodak2-x2) < EPSILON) {
			printf("Tacno\n");
		}
			else {
			if(pogodak2 > x2) {
				if(fabs(pogodak2-x2) < GRK2) {
					printf("Priblizno vece\n");
				}
				else {
					printf("Vece\n");
				}
			}
			else if(pogodak2 < x2) {
				if(fabs(pogodak2-x2) < GRK2) {
					printf("Priblizno manje\n");
				}
				else {
					printf("Manje\n");
				}
			}
		}
	} while(fabs(pogodak2-x2) > EPSILON);
	
	return 0;
}
