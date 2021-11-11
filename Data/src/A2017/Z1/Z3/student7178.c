#include <stdio.h>
#include <math.h>
#define E 0.001

int main(){
double a,b,c,D,x1,x2,n,m;

printf("Unesite koeficijente a, b i c: ");
scanf("%lf %lf %lf", &a, &b, &c);

D=b*b-4*a*c;
x1=(-b+sqrt(D))/(2*a);
x1=(-b-sqrt(D))/(2*a);

if( D<0 ) { 
	    printf("Rjesenja su imaginarni brojevi.\n" );
        }

else if( D>=0 ) { 
				do
					{
			  		printf("Unesite rjesenje x1: ");
			  		scanf("%lf", &n);
			  		
			  		if( fabs(n-x1<=E)){ printf("Tacno\n"); }
			  		
			  		else if((n-x1)>0.1){ printf("Vece\n"); }
			  		
			  		else if(fabs(n-x1)<0.1 && n>x1){ printf("Priblizno vece\n"); }
			  		
			  		else { printf("Priblizno manje\n"); }
			  		
			        }
			   while( fabs(n-x1)>=E);
	           
	           
	           do
	           {	printf("Unesite rjesenje x2: ");
			  		scanf("%lf", &m);
			  		
			  		if( fabs(m-x2<=E)){ printf("Tacno\n"); }
			  		
			  		else if((m-x2)>0.1){ printf("Vece\n"); }
			  		
			  		else if(fabs(m-x2)<0.1 && m>x2){ printf("Priblizno vece\n"); }
			  		
			  		else { printf("Priblizno manje\n"); }
	           }
	           while(fabs(m-x2)>=E);
			}
return 0;
}
