#include <stdio.h>
#include <math.h>
#define epsilon 0.001
#define priblizno 0.1
int main() {
	double a,b,c,d,x1,x2,r1,r2,temp1,temp2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf",&a,&b,&c);
	d=b*b-4*a*c;
	if(d<0) { printf("Rjesenja su imaginarni brojevi."); return 0; }
	else {
		temp=(-b-sqrt(d)) / (2*a);
		temp2=(-b+sqrt(d)) / (2*a);
		if(temp1>temp2) { x2=temp; x1=temp2; }
		else { x2=temp2; x1=temp1; }
	}
	for(;;) {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&r1);
		if(fabs(x1-r1)<priblizno && fabs(x1-r1)>=epsilon) {
			if (x1<r1)printf("Priblizno vece\n");
			else if (x1>r1) printf("Priblizno manje\n");
		} 
		else if((x1-r1)>epsilon) printf("Manje\n");
		else if((r1-x1)>epsilon) printf("Vece\n");
		else { printf("Tacno\n"); break; }
	}
	for(;;) {
		printf("Unesite rjesenje x2: ");	
		scanf("%lf",&r2);
		if(fabs(x2-r2)<priblizno && fabs(x2-r2)>=epsilon) {
			if(x2<r2) printf("Priblizno vece\n");
			else if(x2>r2) printf("Priblizno manje\n");
		}
		else if((x2-r2)>epsilon) printf("Manje\n");
		else if((r2-x2)>epsilon) printf("Vece\n");
		else { printf("Tacno\n"); break; }
	}
	return 0;
}