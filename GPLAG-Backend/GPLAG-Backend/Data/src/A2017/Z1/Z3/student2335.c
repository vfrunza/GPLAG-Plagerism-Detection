#include <stdio.h>
#include <math.h>
#define E 0.001

int main() {
	double  a,b,c,D=0,x1,x2, manjex=0, vecex=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-4*a*c;
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
	}else{
		x1=((-b-sqrt(D))/(2*a));
		x2=((-b+sqrt(D))/(2*a));
	manjex=x1;
		if(x2<x1){
	manjex=x2;
	}
	vecex=x1;
		if(x2>x1){
	vecex=x2;
	}
	do{
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&x1);
		if(fabs(manjex-x1) < E){
			printf("Tacno");
		}
		else {
			if(fabs(x1-manjex)<0.10){
			if(manjex>x1){
				printf("Priblizno manje");}
			else{
				printf("Priblizno vece");
		}}
		else if(x1<manjex){
			printf("Manje");
		}else if(x1>manjex){
			printf("Vece");
			}		
			printf("\n");
		}
	}while(fabs(x1-manjex)>=E);
			
	
	do{
	printf("\nUnesite rjesenje x2: ");
	scanf("%lf",&x2);
		if(fabs(vecex-x2)<E){
			printf("Tacno");
		}else if(fabs(vecex-x2)<0.10){
			if(x2<vecex){
				printf("Priblizno manje");
			}else{
				printf("Priblizno vece");
			}
		}else if(x2<vecex){
			printf("Manje");
		}else if(x2>vecex){
			printf("Vece");
		}
	}while(fabs(vecex-x2)>=E);
		
	}	
	return 0;
}