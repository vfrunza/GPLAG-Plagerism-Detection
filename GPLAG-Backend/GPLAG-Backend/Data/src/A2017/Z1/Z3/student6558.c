#include <stdio.h>
#include <math.h>
#define epsilon 0.001
#define priblizno 0.1
int main() {
	double a,b,c,x1,x2,D,t,i,y,z,rx1,rx2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-(4*a*c);
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else if(D>0 || fabs(D-0)<0);
	t=sqrt(D);
	rx1=((-b+t)/(2*a));
	rx2=((-b-t)/(2*a));
	if(rx1>=rx2){
		x1=rx2;
		x2=rx1;
	}
	else if(rx2>=rx1){
		x1=rx1;
		x2=rx2;
	}
	for(i=0; ; i++){
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&y);
		if(fabs(y-x1)<epsilon){
			printf("Tacno\n");
			break;
		}
		else if(y>x1){
			if(fabs(x1-y)<priblizno){
				printf("Priblizno vece\n");
			}
			else if(fabs(x1-y)>=priblizno){
				printf("Vece\n");
			}
		}
			
		else if(y<x1){
			if(fabs(x1-y)<priblizno){
				printf("Priblizno manje\n");
			}
			else if(fabs(x1-y)>=priblizno){
				printf("Manje\n");
			}
			
		}	
		
	}
	for(i=0; ; i++){
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&z);
		if(fabs(z-x2)<epsilon){
			printf("Tacno\n");
			break;
		}
		else if(z>x2){
			if(fabs(x2-z)<priblizno){
				printf("Priblizno vece\n");
			}
			else if(fabs(x2-z)>=priblizno){
				printf("Vece\n");
			}
		}
		
		else if(z<x2){
			if(fabs(x2-z)<priblizno){
				printf("Priblizno manje\n");
			}
			if(fabs(x2-z)>=priblizno){
				printf("Manje\n");
			}
			
		}	
		
	}

	
	return 0;
}
