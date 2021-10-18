#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	
	double a,b,c,x1,x2,Tx1,Tx2,D;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	
	D=(b*b)-(4*a*c);
	
	if(D<0){
	printf("Rjesenja su imaginarni brojevi.\n");
	return 0;
	}
	
	Tx1=((-b)+sqrt(D))/(2*a);
	Tx2=((-b)-sqrt(D))/(2*a);
	
	
	while (1==1) {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&x1);
		
		if(fabs(x1-Tx1)<EPSILON){
			printf("Tacno\n");
			break;
		}
		
		else if(fabs(x1-Tx1)<0.1 && x1>Tx1)printf("Priblizno vece\n");
		else if(fabs(x1-Tx1)<0.1 && x1<Tx1)printf("Priblizno manje\n");
		else if(fabs(x1-Tx1)>EPSILON && x1>Tx1)printf("Vece\n");
		else if(fabs(x1-Tx1)>EPSILON && x1<Tx1)printf("Manje\n");
	
	}
	
	
		while (1==1) {
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&x2);
		
		if(fabs(x2-Tx2)<EPSILON){
			printf("Tacno\n");
			break;
		}
		
		else if(fabs(x2-Tx2)<0.1 && x2>Tx2)printf("Priblizno vece\n");
		else if(fabs(x2-Tx2)<0.1 && x2<Tx2)printf("Priblizno manje\n");
		else if(fabs(x2-Tx2)>EPSILON && x2>Tx2)printf("Vece\n");
		else if(fabs(x2-Tx2)>EPSILON && x2<Tx2)printf("Manje\n");
	
	}
	
	
	return 0;
}
