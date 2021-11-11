#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double a,b,c,x1,x2,xj,xd,D,t;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-4*a*c;
	if(D<0){
        printf("Rjesenja su imaginarni brojevi.");
    return 0;
    }
	if(D>0)
	{
		t=sqrt(D);
		x1=(-b+t)/(2*a);
		x2=(-b-t)/(2*a);
	}
	else if(D==0){
	x1=-b/(2*a);
	x2=x1;
	}

	do{
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&xj);
	 if(fabs(xj-x1)<EPSILON){
        printf("Tacno\n");
        break;
        }
     else if(xj<x1 && fabs(xj-x1)<0.1){
            printf("Priblizno manje\n");
            }
    else if( xj>x1 && fabs(xj-x1)<0.1){
            printf("Priblizno vece\n");}
    else if(xj<x1){
        printf("Manje\n");
        }
    else if(xj>x1){
        printf("Vece\n");
        }
	}while(xj!=x1);
        
        do{
        
       printf("Unesite rjesenje x2: ");
       scanf("%lf",&xd);
       
    if(fabs(xd-x2)<EPSILON){
        printf("Tacno");
        break;
        }
    else if(xd<x2 && fabs(xd-x2)<0.1){
            printf("Priblizno manje\n");
            }
    else if(xd>x2 && fabs(xd-x2)<0.1){
            printf("Priblizno vece\n");}
    else if(xd<x2){
        printf("Manje\n");
        }
    else if(xd>x2){
        printf("Vece\n");
        }
	}while(xd!=x2);
	
	
	return 0;}
	
	
	