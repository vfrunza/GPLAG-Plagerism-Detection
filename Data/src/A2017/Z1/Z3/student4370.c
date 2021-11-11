#include <stdio.h>
#include <math.h>
#define EPSI 0.001

int main() {
	float D,a,b,c,x1,x2,x1p,x2p,pomx1;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%f %f %f", &a,&b,&c);
	x1 =( -b + sqrt((b*b) - (4.0*a*c)))/(2*a);
	x2 =( -b - sqrt((b*b) - (4.0*a*c)))/(2*a);
	D = b*b - (4.0*a*c);


	if(D>=0){
	for(;;){
	printf("Unesite rjesenje x1: ");
	scanf("%f",&x1p);
	if(fabs(x1p - x1) <EPSI) {
		printf("Tacno\n");
		break;
		}
	 if(fabs(x1p - x1) < 0.1 && x1p < x1) printf("Priblizno manje\n");
	 else if(fabs(x1p - x1) < 0.1 && x1p > x1) printf("Priblizno vece\n");
	else if(x1p < x1) printf("Manje\n");
	else if(x1p > x1) printf("Vece\n");
	}
		for(;;){
	printf("Unesite rjesenje x2: ");
	scanf("%f",&x2p);
	if(fabs(x2p - x2) <EPSI){
		printf("Tacno\n");
		break;
	} 
	 if(fabs(x2p - x2) < 0.1 && x2p < x2) printf("Priblizno manje\n");
	else if(fabs(x2p - x2) <0.1 && x2p > x2) printf("Priblizno vece\n");
	else if(x2p < x2) printf("Manje\n");
	else if(x2p > x2) printf("Vece\n");
	}

	}
	else if(D < 0) printf("Rjesenja su imaginarni brojevi.");
	return 0;
}
