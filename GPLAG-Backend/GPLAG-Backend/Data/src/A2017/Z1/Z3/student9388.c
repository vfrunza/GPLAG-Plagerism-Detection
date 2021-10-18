#include <stdio.h>
#include <math.h>
#define E 0.001
int main() {
	
	/*printf("Zadaća 1, Zadatak 3");*/
	
	double a,b,c,D,x1,x2,x1n,x2n,f,X1,X2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	
	D=b*b-4.0*a*c;
	
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else if(D==0){
		x1n=-b/(2*a);
		x2n=x1n;
		
	}
	else{
		f=sqrt(D);
		x1n=(-b+f)/(2*a);
		x2n=(-b-f)/(2*a);
		if(x1n>x2n) {X1=x1n;
			X2=x2n;
		}
		else{
			X1=x2n;
			X2=x1n;
		}
		
	}
	for(;;){
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&x1);
	
	if(x1==X1||x1-E==X1||x1+E==X1){
		printf("Tacno\n"); break;
	}
	if(x1<X1) {printf("Vece\n"); }
	if(x1>X1){
		printf("Manje\n"); 
	}
	
	
	
	}
	for(;;){
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&x2);
		if((x2==X2)||(x2==X2-E)||(x2==X2+E)){
			printf("Tacno");return 0;
		}
		if(x2<X2) printf("Vece\n");
		if(x2>X2) printf("Manje\n");
		
	}
	
	
	
	return 0;
}
