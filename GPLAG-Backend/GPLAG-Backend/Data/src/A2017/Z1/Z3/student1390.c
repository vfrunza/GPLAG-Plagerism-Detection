#include <stdio.h>
#include <math.h>
#define epsilon 0.001
#define priblizno 0.1

int main() {
	int a,b,c;
	double D,x1,x2,x11,x22,temp;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d",&a,&b,&c);
	D=b*b-(4*a*c);
	x1=(-b+sqrt(D))/(2*a);
	x2=(-b-sqrt(D))/(2*a);
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	if(x1>x2){
		temp=x1;
		x1=x2;
		x2=temp;
	}
	for(;;){
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&x11);
		if(fabs(x11-x1)<epsilon)
		{
			printf("Tacno\n");
			break;
		}
		else { 
			if(x11-x1<0){
				if(fabs(x11-x1)<priblizno)
				printf("Priblizno manje");
				else 
				printf("Manje");
			}
			else if(x11-x1>0) {
				if(fabs(x11-x1)<priblizno)
				printf("Priblizno vece");
				else 
				printf("Vece");
			}
		}
		printf("\n");
	}
	for(;;){
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&x22);
		if(fabs(x22-x2)<epsilon){
		printf("Tacno");
		break;
		}
		else {
			if(x22-x2<0){
				if(fabs(x22-x2)<priblizno)
				printf("Priblizno manje");
				else 
				printf("Manje");
			}
			else if(x22-x2>0){
				if(fabs(x22-x2)<priblizno)
				printf("Priblizno vece");
				else
				printf("Vece");
			}
		}
		printf("\n");
	}
	return 0;
	
}
