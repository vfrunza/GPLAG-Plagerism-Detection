#include <stdio.h>
#include <math.h>
#define epsilon 0.001
#define razlika 0.1

int main() {
	
	double a,b,c,x3,x4,D,x1=0,x2=0;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	
	D=(b*b-4*a*c);
	
	if(D>=0){
		
	if(a<0){
	x3=(-b+sqrt(D))/(2*a);
	x4=(-b-sqrt(D))/(2*a);
	
	while(1){
		x1++;
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);
		if(fabs(x3-x1)<epsilon){
			printf("Tacno\n");
			break;
		}
		else if((x1-x3)<0.1 && x1>x3){
			printf("Priblizno vece\n");
		}
		else if((x3-x1)<0.1 && x3>x1){
			printf("Priblizno manje\n");
		}
		else if(x1<x3){
			printf("Manje\n");
		}
		else if(x1>x3){
			printf("Vece\n");
		}
	}
	
	while(1){
		x2++;
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x2);
		if(fabs(x4-x2)<epsilon){
			printf("Tacno");
			break;
		}
		else if((x2-x4)<0.1 && x2>x4){
			printf("Priblizno vece\n");
		}
		else if((x4-x2)<0.1 && x4>x2){
			printf("Priblizno manje\n");
		}
		else if(x2<x4){
			printf("Manje\n");
		}
		else if(x2>x4){
			printf("Vece\n");
		}
	}
	}
	else if(a>0){
	x3=(-b-sqrt(D))/(2*a);
	x4=(-b+sqrt(D))/(2*a);

	while(1){
		x1++;
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);
		if(fabs(x3-x1)<epsilon){
			printf("Tacno\n");
			break;
		}
		else if((x1-x3)<0.1 && x1>x3){
			printf("Priblizno vece\n");
		}
		else if((x3-x1)<0.1 && x3>x1){
			printf("Priblizno manje\n");
		}
		else if(x1<x3){
			printf("Manje\n");
		}
		else if(x1>x3){
			printf("Vece\n");
		}
	}
	
	while(1){
		x2++;
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x2);
		if(fabs(x4-x2)<epsilon){
			printf("Tacno");
			break;
		}
		else if((x2-x4)<0.1 && x2>x4){
			printf("Priblizno vece\n");
		}
		else if((x4-x2)<0.1 && x4>x2){
			printf("Priblizno manje\n");
		}
		else if(x2<x4){
			printf("Manje\n");
		}
		else if(x2>x4){
			printf("Vece\n");
		}
	}
		
	}
	
	}
	else if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
	}
	
	return 0;
}
