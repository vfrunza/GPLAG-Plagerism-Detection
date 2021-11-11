#include <stdio.h>
#include <math.h>
#define E 0.001
int main() {
	double a,b,c,x1,x2,D,x1k,x2k;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-4*a*c;
	if(D<0){
	    printf("Rjesenja su imaginarni brojevi.");
	    return 0;
	}
	x1=(-b+sqrt(D))/(2*a);
	x2=(-b-sqrt(D))/(2*a);
	do{
	    printf("Unesite rjesenje x1: ");
	    scanf("%lf",&x1k);
	    if(fabs(x1-x1k)<E) printf("Tacno\n");
	    else if(x1k>x1){
	        if((x1k-x1)<0.1) printf("Priblizno vece\n");
	        else printf("Vece\n");
	    }
	    else if(x1>x1k){
	        if((x1-x1k)<0.1) printf("Priblizno manje\n");
	        else printf("Manje\n");
	    }
	    
	} while(fabs(x1-x1k)>=E);
	
	do{
	    printf("Unesite rjesenje x2: ");
	    scanf("%lf",&x2k);
	    if(fabs(x2-x2k)<E) printf("Tacno\n");
	    else if(x2k>x2){
	        if((x2k-x2)<0.1) printf("Priblizno vece\n");
	        else printf("Vece\n");
	    }
	    else if(x2>x2k){
	        if((x2-x2k)<0.1) printf("Priblizno manje\n");
	        else printf("Manje\n");
	    }
	    
	} while(fabs(x2-x2k)>=E);
	return 0;
}
