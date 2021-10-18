#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define epsilon 0.001
#define epsilon1 0.1

int main() {
	double a,b,c,D,K,x1,x2,x11,x22,r1,r2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf", &a,&b,&c);
	D=b*b-4*a*c;
	K=sqrt(D);
	if(D<0) {printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	if (a>0){
	x1=(-b - K)/(2*a);
	x2=(-b + K)/(2*a);	
	}
	else if (a<0)	{
	x1=(-b + K)/(2*a);
	x2=(-b - K)/(2*a);}
	loop1:printf("Unesite rjesenje x1: ");
	scanf("%lf", &x11);
    if (x11>x1){
    	r1=x11-x1;
    }
    else if(x11<x1){
    	r1=fabs(x11-x1);
    }
    else r1=0;
    if(r1<epsilon){
    	printf("Tacno\n");
    }
    else if(x11<x1){
    	if(r1<epsilon1){
    		printf("Priblizno manje\n"); goto loop1;
    	}
    	else if(r1>=epsilon){
    		printf("Manje\n"); goto loop1;
    	}
    }
    else if(x11>x1){
    	if(r1<epsilon1){
    		printf("Priblizno vece\n"); goto loop1;
    	}
    	else if(r1>=epsilon1){
    		printf("Vece\n"); goto loop1;
    	}
    }
    loop2:printf("Unesite rjesenje x2: ");
	scanf("%lf", &x22);
    if (x22>x2){
    	r2=x22-x2;
    }
    else if(x22<x2){
    	r2=fabs(x22-x2);
    }
    else r2=0;
    if(r2<epsilon){
    	printf("Tacno");
    }
    else if(x22<x2){
    	if(r2<epsilon1){
    		printf("Priblizno manje\n"); goto loop2;
    	}
    	else if(r2>=epsilon){
    		printf("Manje\n"); goto loop2;
    	}
    }
    else if(x22>x2){
    	if(r2<epsilon1){
    		printf("Priblizno vece\n"); goto loop2;
    	}
    	else if(r2>=epsilon1){
    		printf("Vece\n"); goto loop2;
    	}
    }
	return 0;
}
