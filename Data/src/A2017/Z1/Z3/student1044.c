#include <stdio.h>
#include <math.h>
#define E 0.001

int main() {
	double a, b, c, x1, x2, d, R1, R2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	if(fabs(a-0)<E) return 0;
	
	else{
		d=sqrt(pow(b,2)-(4*a*c));
		x1=(-b+d)/(2*a);
		x2=(-b-d)/(2*a);
	if(d!=d) {
		printf("Rjesenja su imaginarni brojevi.");
	  return 0;
	}
		
		printf("Unesite rjesenje x1: ");
			scanf("%lf", &R1);
		do{	
			if(x1>0){
			if(R1==x1) {
				printf("Tacno"); break;}
			
			if(R1>x1) {
				if((R1-x1)<0.1)
					printf("Priblizno vece");
				else printf("Vece");
			}
			
			if(R1<x1){
			  if((x1-R1)<E){
			    printf("Tacno");
			    break;
			  }
				if((x1-R1)<0.1)
					printf("Priblizno manje");
				else printf("Manje");
			}}
			else{
			  if(R1==x1){ printf("Tacno"); break;};
				if(R1>x1){
			  	if(R1-x1<E){
					printf("Tacno"); break;};
			    if((R1-x1)<0.1)
			        printf("Priblizno vece");
			    else printf("Vece");
			}
			if(R1<x1){
			  if((x1-R1)<=E){
			    printf("Tacno");
			    break;
			  }
			    if((R1-x1)*-1<0.1)
			        printf("Priblizno manje");
			    else printf("Manje");
			}
			}
			printf("\nUnesite rjesenje x1: ");
			scanf("%lf", &R1);
		}while(1);

		while(1){
			printf("\nUnesite rjesenje x2: ");
			scanf("%lf", &R2);
			if(x2>0){
			if(R2==x2) {
				printf("Tacno"); break;}
				
			if(R2>x2){
			  if(R2-x2<E){
			    printf("Tacno"); break;};
				if((R2-x2)<0.1)
					printf("Priblizno vece");
				else printf("Vece");
			}
			if(R2<x2){
			  if((x2-R2)<E){
			    printf("Tacno");
			    break;
			  }
				if((R2-x2)*-1<0.1)
					printf("Priblizno manje");
				else printf("Manje");
			} 			}
			else{
			   if(R2==x2) {printf("Tacno"); break;};
			if(R2>x2){
			  if(R2-x2<E){
			    printf("Tacno"); break;};
			    if((R2-x2)<0.1)
			        printf("Priblizno vece");
			    else printf("Vece");
			}
			if(R2<x2){
			    if((R2-x2)*-1<0.1)
			        printf("Priblizno manje");
			    else printf("Manje");
			}
			}
		}
}
	return 0;
}