#include <stdio.h>
#include <math.h>
#define E 0.001
#define O 0.1

int main() {
	int t1=0,t2=0;
	double D,a,b,c,x1,x2,X1,X2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-4*a*c;
	x1=((-b)+(sqrt(D)))/(2*a);
	x2=((-b)-(sqrt(D)))/(2*a);
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
 do { 
 	t1=0;
 	printf("Unesite rjesenje x1: ");
		scanf("%lf",&X1);
	if(fabs(X1-x1)<E) {
		    printf("Tacno\n");
		    t1=1;	
		    break;
		    }
		    
		else if (X1>x1) {
			if(fabs(X1-x1)>=O) {
				printf("Vece\n");
			}
				else {
					printf("Priblizno vece\n");
				}
			t1=0;
		}
		else if(X1<x1) {
			if(fabs(x1-X1)<O && fabs(X1-x1)>E) {
				printf("Priblizno manje\n");
			}
				else {
			printf("Manje\n");
				}
			t1=0;
		}
		}
	while(t1==0);
		
 do { 
 	printf("Unesite rjesenje x2: ");
		scanf("%lf",&X2);
		t2=0;
	 if(fabs(X2-x2)<E ) {
		    printf("Tacno\n");
		    t2=1;	
		    break;
		    }
		    
	else if (X2>x2) {
			if(X2-x2<=O) {
				printf("Priblizno vece\n");
			}
				else {
					printf("Vece\n");
				}
			t2=0;
		}
		else if(X2<x2) {
			if(x2-X2<O) {
				printf("Priblizno manje\n");
			}
				else {
			printf("Manje\n");
				}
			t2=0;
		}
		}
	while(t2==0);
	return 0;
}
