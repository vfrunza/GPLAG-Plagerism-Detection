#include <stdio.h>
#define epsilon 0.001
#include <math.h>

int main() {
	int a, b, c;
	double x1, x2, x, y, D;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d", &a, &b, &c);
	
	D=(b*b) - (4*a*c);
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	if(a>0){
	x1=((-1)*b-sqrt(D))/(2*a);
	x2=((-1)*b+sqrt(D))/(2*a);
	}
	else if(a<0){
	x1=((-1)*b+sqrt(D))/(2*a);
	x2=((-1)*b-sqrt(D))/(2*a);
	}
	

	
	
	while(1) {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x);
		
		if(fabs(x1-x)<epsilon) { printf("Tacno\n"); break;}
		else if(fabs(x-x1)<0.1 && fabs(x-x1)>=epsilon && (x<x1)) printf("Priblizno manje\n");
		else if(fabs(x-x1)<0.1 && fabs(x-x1)>=epsilon && (x>x1)) printf("Priblizno vece\n");
		else if(fabs(x-x1)>=0.1 && (x1>x)) printf("Manje\n");
		else if(fabs(x-x1)>=0.1 && (x1<x)) printf("Vece\n");
		
		}
	
		
	while(1) {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &y);
		
		if(fabs(x2-y)<epsilon) { printf("Tacno\n"); break;}
		else if(fabs(y-x2)<0.1 && fabs(y-x2)>=epsilon && (y<x2)) printf("Priblizno manje\n");
		else if(fabs(y-x2)<0.1 && fabs(y-x2)>=epsilon && (y>x2)) printf("Priblizno vece\n");
		else if(fabs(y-x2)>=0.1 && (x2>y)) printf("Manje\n");
		else if(fabs(y-x2)>=0.1 && (x2<y)) printf("Vece\n");
		
		}
	
	
	

	

	return 0;
}
