#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int poredi(float x,float y){
	if((fabs(x - y) <= 0.1) && (fabs(x - y) >= EPSILON)){
		return 1;
	}else{
		return 0;
	}
}

int main() {
	double a,b,c,diskriminanta,x1,x2,pogodi1,pogodi2,temp;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	diskriminanta = (b*b) - (4*a*c);
	if(diskriminanta < 0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	x1 = (-b - sqrt(diskriminanta))/(2*a);
	x2 = (-b + sqrt(diskriminanta))/(2*a);
	if(x1 > x2){
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&pogodi1);
		if(fabs(pogodi1-x1) >= EPSILON){
			if(poredi(pogodi1,x1) && pogodi1 < x1){
				printf("Priblizno manje\n");
			}else if(poredi(pogodi1,x1) && pogodi1 > x1){
				printf("Priblizno vece\n");
			}else if(pogodi1 < x1){
				printf("Manje\n");
			}else if(pogodi1 > x1){
				printf("Vece\n");
			}
		}else{
			break;
		}
	}while(fabs(pogodi1-x1) >= EPSILON);
	if(fabs(pogodi1-x1) < EPSILON){
		printf("Tacno\n");
	}
	
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&pogodi2);
		if(fabs(pogodi2-x2) >= EPSILON){
			if(poredi(pogodi2,x2) && pogodi2 < x2){
				printf("Priblizno manje\n");
			}else if(poredi(pogodi2,x2) && pogodi2 > x2){
				printf("Priblizno vece\n");
			}else if(pogodi2 < x2){
				printf("Manje\n");
			}else if(pogodi2 > x2){
				printf("Vece\n");
			}
		}else{
			break;
		}
	}while(fabs(pogodi2-x2) >= EPSILON);
	if(fabs(pogodi2-x2) < EPSILON){
		printf("Tacno\n");
	}
	return 0;
	/*es*/
}
