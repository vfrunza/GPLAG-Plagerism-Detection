#include <stdio.h>
#include <math.h>
int main() {
	double a,b,c,D,x1,x2,r1,r2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D= b*b - 4*a*c;
	 if (D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
   x1=(((-1)*b - sqrt(D))/(2*a));
	x2=(((-1)*b + sqrt(D))/(2*a));
	if(x1 > x2){
		double n = x1;
		x1 = x2;
		x2 = n;
	}
	do{ 
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&r1);
	if((fabs(r1-x1))<0.001){
		printf("Tacno\n");
		break;
	}
	else if (r1<x1 && fabs(r1-x1)<0.1){									
		printf("Priblizno manje\n");
	}
	else if (r1>x1 && fabs(r1-x1)<0.1){
		printf("Priblizno vece\n");
	}
	 else if (r1<x1 && fabs(r1-x1)>=0.1){
		printf("Manje\n");
	}
	else if (r1>x1 && fabs(r1-x1)>=0.1){
		printf("Vece\n");
	}}
	while(1);
	
		
	do {
	printf("Unesite rjesenje x2: ");
	scanf("%lf",&r2);
	 	if ((fabs(r2-x2))<0.001){
		printf("Tacno\n");
		break;
	}
	 else if (r2<x2 && fabs(r2-x2)<0.1){
		printf("Priblizno manje\n");
	}
	else if (r2>x2 && fabs(r2-x2)<0.1){
		printf("Priblizno vece\n");
	}	
	else if (r2<x2 && fabs(r2-x2)>=0.1){
		printf("Manje\n");
	}
	else if (r2>x2 && fabs(r2-x2)>=0.1){
		printf("Vece\n");
	}

	}
		while(1);

	
	
	return 0;
}
