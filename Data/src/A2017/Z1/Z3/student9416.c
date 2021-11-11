#include <stdio.h>
#include <math.h>

int main() {
	
	double a, b, c, x1=0, x11=0, x2=0, x22=0, D=0,k=0, e=0.001;

	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a, &b, &c);
	
	D=b*b-4*a*c;
	
	if(D<0){printf("Rjesenja su imaginarni brojevi.");}

	else{

	x1=(-b-sqrt(D))/(2*a);
	x2=(-b+sqrt(D))/(2*a);
	k=x1;
	if(x1>x2){
		x1=x2;
		x2=k;
	}
	

	
	
while (1)
{
	printf("Unesite rjesenje x1: ");
	scanf("%lf", &x11);
	
	if(fabs(x1-x11)<e){printf("Tacno\n");
		break;
	}
	else if(fabs(x1-x11)<100*e && fabs(x1-x11)>=e && x1<x11) {printf("Priblizno vece\n");}
	else if(fabs(x1-x11)<100*e && fabs(x1-x11)>=e && x1>x11) {printf("Priblizno manje\n");}
	else if(x11<x1){printf("Manje\n");}
	else {printf("Vece\n");}

}	

	
	while (1) {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x22);
		
		if(fabs(x2-x22)<e){printf("Tacno\n");
			break;
		}
		else if(fabs(x2-x22)<100*e && fabs(x2-x22)>=e && x2<x22) {printf("Priblizno vece\n");}
		else if(fabs(x2-x22)<100*e && fabs(x2-x22)>=e && x2>x22){printf("Priblizno manje\n");}
		else if(x22<x2){printf("Manje\n");}
		else {printf("Vece\n");}
		
	}
	
}
	return 0;
}
