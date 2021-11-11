/*Potrebno je napraviti program koji pomaže učenicima da nauče rješavati zadatke iz matematike sa kvadratnom 
jednačinom.

Kvadratna jednačina (polinom drugog stepena) je jednačina oblika:
ax2+bx+c=0, a0
(za a=0 u pitanju bi bila linearna jednačina). Jednačina u opštem slučaju ima dva korijena (dva rješenja) 
koja označavamo sa x1 i x2 . U ovom zadatku x1 će biti manje rješenje, a x2 veće rješenje kvadratne jednačine.

Napisati program koji omogućuje unos koeficijenata a, b i c. Ako su rješenja imaginarni brojevi, treba ispisati
odgovarajuću poruku i prekinuti program:
	Unesite koeficijente a, b i c: 1 1 1
	Rjesenja su imaginarni brojevi.

Ako su koeficijenti realni brojevi, postoje dva rješenja (koja mogu biti jednaka ali to za ovaj zadatak nije bitno). 

Korisnik najprije treba da unese rješenje x1. Ako se vrijednost koju je korisnik unio razlikuje od tačnog rješenja
za manje od ε=0.001, program ispisuje poruku "Tacno" i prelazi se na unos rješenja x2. U suprotnom, ako je rješenje
manje od tačnog ispisuje se poruka "Manje", a ako je veće ispisuje se "Vece". Ako je razlika između unesenog i
tačnog rješenja manja od 0.1 ispisuje se "Priblizno manje" odnosno "Priblizno vece". U svakom od ovih slučajeva 
traži se da korisnik ponovo unese rješenje x1.

Isti princip koristi se za rješenje x2 te se unos ponavlja dok korisnik ne unese tačno rješenje. Primjer ulaza i izlaza:
	Unesite koeficijente a, b i c: 1 2 1
	Unesite rjesenje x1: 1
	Vece
	Unesite rjesenje x1: -2
	Manje
	Unesite rjesenje x1: -0.95
	Priblizno vece
	Unesite rjesenje x1: -1
	Tacno
	Unesite rjesenje x2: 0
	Vece
	Unesite rjesenje x2: -0.9999
	Tacno

Napomena: Koristiti vrijednost ε=0.001 i tip double.*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define epsilon 0.001

int main() {
	
	double x1,x2,z,r1,r2,a,b,c,A,B;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	z=(b*b-4*a*c);
	if (z<0){
		printf ("Rjesenja su imaginarni brojevi.");
	} else {
	
	A=(-b-(sqrt(z)))/(2*a);
	B=(-b+(sqrt(z)))/(2*a);
	
	if (A<B){
		x1=A;
		x2=B;
	} else{
		x1=B;
		x2=A;
	}
	
	do {
		 printf("Unesite rjesenje x1: ");
		 scanf("%lf", &r1);
		 
		   if (fabs(r1-x1)>=0.1 && r1<x1){
		 	printf ("Manje\n");
		 } else if (fabs(r1-x1)>=epsilon && r1<x1){
		 	printf ("Priblizno manje\n");
		 } else if (fabs(r1-x1)>=0.1 && r1>x1){
		 	printf("Vece\n");
		 } else if (fabs(r1-x1)>=epsilon && r1>x1){
		 	printf ("Priblizno vece\n");
		 } else {
		 	printf ("Tacno");
		 }
	}	while (fabs(r1-x1)>=epsilon);
	
	do {
		 printf("\nUnesite rjesenje x2: ");
		 scanf("%lf", &r2);
		 
		   if (fabs(r2-x2)>=0.1 && r2<x2){
		 	printf ("Manje\n");
		 } else if (fabs(r2-x2)>=epsilon && r2<x2){
		 	printf ("Priblizno manje\n");
		 } else if (fabs(r2-x2)>=0.1 && r2>x2){
		 	printf("Vece\n");
		 } else if (fabs(r2-x2)>=epsilon && r2>x2){
		 	printf ("Priblizno vece\n");
		 } else {
		 	printf ("Tacno");
		 }
	} 	 while (fabs(r2-x2)>=epsilon);
	
	}
	
	return 0;
}
