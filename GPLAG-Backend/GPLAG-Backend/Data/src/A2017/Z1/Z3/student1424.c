#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	double a,b,c,D,x1,x2,x1_nase, x2_nase,x_nase1,x_nase2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a-0)
	D=(b*b-4*a*c);
	if(D<0){
		printf("Rjesenja su imaginarni brojevi. ");
		return 0;
	}
	
	else if(D>=0){
		x1_nase=((-b)+ sqrt(D))/(2*a);
		x2_nase=((-b)-sqrt (D))/(2*a);
		if(fabs(x1_nase-x2_nase)<EPSILON) {
			x_nase2=x2_nase;
			x_nase1=x1_nase;
		}else{
			x_nase2=x2_nase;
			x_nase1=x1_nase;
		}
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x1);
			if((x_nase1<x1)&& fabs(x1-x_nase1)>=0.1){
				printf("Vece\n");
			}
			else if (fabs(x1-x_nase1)<0.1 && x1>x_nase1 && fabs(x1-x_nase1)>=EPSILON){
				printf("Priblizno vece\n");
			}
			else if((x_nase1>x1) && fabs(x_nase1-x1)>=0.1){
				printf("Manje\n");
			}
			else if (fabs(x_nase1-x1)<0.1 && (x_nase1-x1>=EPSILON)){
				printf("Priblizno manje\n");
			}
		}while(fabs(x_nase1-x1)>=EPSILON);
			printf("Tacno\n");
			
			
			
			
			
			do{
				printf("Unesite rjesenje x2: ");
				scanf("%lf", &x2);
				if(x_nase2<x2 && fabs(x2-x_nase2)>= 0.1){
					printf("Vece\n");
					
				}
				else if(fabs(x2-x_nase2)<0.1 &&x2>x_nase2&& fabs(x2-x_nase2)>=EPSILON){
					printf("Priblizno vece\n");
				
				}
				else if(x_nase2>x2 && fabs(x_nase2-x2)>=0.1){
					printf("Manje \n");
				}
				else if(fabs(x_nase2-x2)<0.1 && fabs(x_nase2-x2)>=EPSILON){
					printf("Priblizno manje\n");
				}
			}while(fabs(x_nase2-x2)>=EPSILON);
			printf("Tacno\n");}
	
	

       return 0;
        }
