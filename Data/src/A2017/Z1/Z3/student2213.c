#include <stdio.h>
#include <math.h>
#define EPS 0.001
#define E 0.1
int main() {
	double a, b,c,x1,x2,det,k;
	double _x1,_x2,temp;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf",&a,&b,&c);
	det=b*b-4.0*a*c;
	if(det<0) {printf("Rjesenja su imaginarni brojevi.\n"); return 0;}
	else if(det>0){
		k=sqrt(det);
		x1=(-b-k)/(2*a);
		x2=(-b+k)/(2*a);
	}
	else {
		k=sqrt(det);
		x1=x2=-b/(2*a);
	}
	
	if(x1 > x2){
		temp=x1;
		x1=x2;
		x2=temp;
	}
	
	//printf("%.3lf %.3lf", x1, x2);
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&_x1);
		if((x1-_x1)<=-E) printf("Vece\n");
		else if((x1-_x1)>=E) printf("Manje\n");
		else if((x1-_x1)>-E && (x1-_x1)<=-EPS) printf("Priblizno vece\n");
		else if((x1-_x1)<E && (x1-_x1)>=EPS) printf("Priblizno manje\n");
		else printf("Tacno\n");
	} while(fabs(x1-_x1)>=EPS);
	
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&_x2);
		if((x2-_x2)<=-E) printf("Vece\n");
		else if((x2-_x2)>=E) printf("Manje\n");
		else if((x2-_x2)<E && (x2-_x2)>=EPS) printf("Priblizno manje\n");
		else if((x2-_x2)>-E && (x2-_x2)<=-EPS) printf("Priblizno vece\n");
		else printf("Tacno\n");
	}while(fabs(x2-_x2)>=EPS);
	
	
	
	
	return 0;
}
