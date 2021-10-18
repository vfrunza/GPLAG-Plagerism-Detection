#include <stdio.h>
#define epsilon 0.001
#include <math.h>

int main() {
			double a,b,c,d=0,g=0,f=0;
			 double xx1,xx2,x1,x2;
			printf("Unesite koeficijente a, b i c: ");
			scanf("%lf %lf %lf", &a,&b,&c);
			g=b*b-(4*a*c);

			f=-b+sqrt(b*b-(4*a*c));
			
			if((b*b-4*a*c)<0) printf("Rjesenja su imaginarni brojevi.");
			
			else {
				x1=(-b+sqrt(b*b-(4*a*c)))/(2*a);
				x2=(-b-sqrt(b*b-(4*a*c)))/(2*a);
			
				

			
			do {
				printf("Unesite rjesenje x1: ");
				scanf("%lf", &xx1);
				if(xx1>=x1) d=xx1-x1;
				else if(x1>=xx1) d=x1-xx1;
				if(d<epsilon || d==0) {
					printf("Tacno\n");
					break;
				}
				else if(fabs(xx1-x1)<0.1 && xx1<x1) printf("Priblizno manje\n");
				else if((xx1-x1)<0.1 && xx1>x1) printf("Priblizno vece\n");
				else if(xx1<x1) printf("Manje\n");
				else if(xx1>x1) printf("Vece\n");
			} while(fabs(xx1-x1)>=epsilon);
			
			do {
				printf("Unesite rjesenje x2: ");
				scanf("%lf", &xx2);
				
				if(xx2>=x2) d=xx2-x2;
				else if(x2>=xx2) d=x2-xx2;
				if(d<epsilon || d==0) {
					printf("Tacno\n");
					break;
				}
				
				
				else if(fabs(xx2-x2)<0.1 && xx2<x2) printf("Priblizno manje\n");
				else if((xx2-x2)<0.1 && xx2>x2) printf("Priblizno vece\n");
				else if(xx2<x2) printf("Manje\n");
				else if(xx2>x2) printf("Vece\n");
				
			} while(fabs(xx2-x2)>=epsilon);
			
			}
			
			
			


		 
		 
		 
		 
		 
	return 0;
}
