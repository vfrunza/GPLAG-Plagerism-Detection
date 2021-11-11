#include <stdio.h>
#include <math.h> //koristimo ovu biblioteku za funkcije sqrt i fabs koje koristimo u programu 
#define e 0.001 //definisemo e radi preglednosti 
int main() {
	double a,b,c,d=0,g=0,f=0;
	double x1,x2,xx1,xx2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf", &a,&b,&c);
	g=b*b-(4*a*c);
	f=-b+sqrt(b*b-(4*a*c));
	if((b*b-4*a*c) < 0) printf("Rjesenja su imaginarni brojevi."); //provjeravamo je li diskriminanta < 0 sto nam pokazuje da su rj imaginarna
	else {
			x1=(-b+sqrt(b*b-(4*a*c)))/(2*a); //izracunavamo x1 i x2
			x2=(-b-sqrt(b*b-(4*a*c)))/(2*a); 
			do { // do petlju uzimamo jer unosimo x1 na pocetku bez ikakvog uslova
				printf("Unesite rjesenje x1: ");
				scanf("%lf", &xx1);
				if(xx1>=x1) d=xx1-x1; //uslovi su dati da bi radili sa pozitivnim brojevima 
				else if(x1>=xx1) d=x1-xx1;
				if(d<e || d==0) { //gledamo da li je njihova razlika manja od e ili su rj jednaka 
					printf("Tacno\n");
					break;
				}
				else if(fabs(xx1-x1)<0.1 && xx1<x1) printf("Priblizno manje\n"); //koristimo fabs u ovom uslovu jer je xx1<x1, a mogli smo i staviti x1-xx1, svejedno je
				else if((xx1-x1)<0.1 && xx1>x1) printf("Priblizno vece\n");
				else if(xx1<x1) printf("Manje\n");
				else if(xx1>x1) printf("Vece\n");
			} while(fabs(xx1-x1)>=e); //uslov je ovakav jer ce se petlja ponavljati sve dok se ne stekne da je uneseno rj tacno 
				do {
				printf("Unesite rjesenje x2: ");
				scanf("%lf", &xx2);
				if(xx2>=x2) d=xx2-x2; //uslovi su dati da bi radili sa pozitivnim brojevima 
				else if(x2>=xx2) d=x2-xx2;
				if(d<e || d==0) {
					printf("Tacno\n");
					break;
				}
				else if(fabs(xx2-x2)<0.1 && xx2<x2) printf("Priblizno manje\n");
				else if((xx2-x2)<0.1 && xx2>x2) printf("Priblizno vece\n");
				else if(xx2<x2) printf("Manje\n");
				else if(xx2>x2) printf("Vece\n");
			} while(fabs(xx2-x2)>=e); //analogno prvom uslovu 
	}
	return 0;
}

