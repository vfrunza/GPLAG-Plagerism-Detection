#include <stdio.h>
#include<math.h>
#define e 0.001

int main() {
	double a,b,c,d;
	double x_1,x_2,x1,x2,r1,r2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	d=pow(b,2)- 4*a*c;
	if(d<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else {

	r1= (-b+sqrt(d))/(2*a);
	r2= (-b-sqrt(d))/(2*a);
	if(r1>=r2){
		x_1=r2;
		x_2=r1;
	}
	else{
			x_1=r1;
			x_2=r2;
		}
 do { 
 	printf("Unesite rjesenje x1: ");
 	scanf("%lf",&x1);
 	if(fabs(x1-x_1)<e){
 		printf("Tacno\n");
 	}
 	else if(x1<x_1 && fabs(x1-x_1)<0.1){
 		printf("Priblizno manje\n");
 	}
 	else if(x1>x_1 && fabs(x1-x_1)<0.1){
 		printf("Priblizno vece\n");
 	}
 	else if(x1<x_1){
 		printf("Manje\n");
 	}
 	else if(x1>x_1){
 		printf("Vece\n");
 	}
 	
 } while(fabs(x1-x_1)>=e);
 do {
 	printf("Unesite rjesenje x2: ");
 	scanf("%lf",&x2);
 	if(fabs(x2-x_2)<e){
 		printf("Tacno\n");
 	}
 	else if(x2<x_2 && fabs(x2-x_2)<0.1){
 		printf("Priblizno manje\n");
 	}
 	else if(x2>x_2 && fabs(x2-x_2)<0.1){
 		printf("Priblizno vece\n");
 	}
 	else if(x2<x_2){
 		printf("Manje\n");
 	}
 	else if(x2>x_2){
 		printf("Vece\n");
 	}
 	
 } while(fabs(x2-x_2)>=e);
	}
return 0;
	}