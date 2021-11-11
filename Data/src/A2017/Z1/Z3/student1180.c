#include <stdio.h>
#include <math.h>
#define epsilon 0.001

int main() {
	
	int i;
	double a,b,c,x1,x2,D,n,m,t;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	
	D=pow(b,2)-4*a*c;

	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	t=sqrt(D);
	
	x1=(-b-t)/(2*a);
	x2=(-b+t)/(2*a);
//	printf("%f %f",x1,x2);
	for(i=0;i<10;){
		
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&n);
	//	printf("%f %f",x1,n);
		if(fabs(x1-n)<epsilon){
			printf("Tacno\n");
			break;
		}
		else if(fabs(n-x1)<0.1 && n<x1)
			printf("Priblizno manje\n");
		else if(fabs(n-x1)<0.1 && n>x1)
			printf("Priblizno vece\n");
		else if(x1<n)
			printf("Vece\n");
		else if(x1>n)
			printf("Manje\n");
	}
	for(i=0;i<10;){
		
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&m);
		if(fabs(x2-m)<epsilon){
			printf("Tacno\n");
			break;
		}
		else if(fabs(m-x2)<0.1 && m<x2)
			printf("Priblizno manje\n");
		else if(fabs(m-x2)<0.1 && m>x2)
			printf("Priblizno vece\n");
		else if(x2<m)
			printf("Vece\n");
		else if(x2>m)
			printf("Manje\n");
	}
	return 0;
}
