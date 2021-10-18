#include <stdio.h>
#include <math.h>

int main() {
	
	double a,b,c;
	double x1,x2;
	double korisnik;
	double eps=0.001;
	double D;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	 D=b*b-4*a*c;
	if(D<0) {printf("Rjesenja su imaginarni brojevi.");return 0;}
	
	x1=((-1)*b+sqrt(D))/(2*a);
	x2=((-1)*b-sqrt(D))/(2*a);
	
	while(1){
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&korisnik);
		if(fabs(korisnik-x1)<eps){ printf("Tacno\n");break;}
		if(fabs(korisnik-x1)<0.1){
			if(korisnik>x1) printf("Priblizno vece\n");
			else printf("Priblizno manje\n");
		}
		else if(korisnik>x1) printf("Vece\n");
		else if(korisnik<x1) printf("Manje\n");
	}
	
while(1){
	printf("Unesite rjesenje x2: ");
	scanf("%lf",&korisnik);
	if(fabs(korisnik-x2)<eps){ printf("Tacno\n");break;}
	if(fabs(korisnik-x2)<0.1){
		if(korisnik>x2) printf("Priblizno vece\n");
		else printf("Priblizno manje\n");
	}
	else if(korisnik>x2) printf("Vece\n");
	else if(korisnik<x2) printf("Manje\n");
}

return 0;
}
