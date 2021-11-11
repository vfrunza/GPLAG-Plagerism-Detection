#include <stdio.h>
#include <math.h>
#define EPSILON 0.001


int main() {
double a,b,c,x1,x2,max,min,iks1,iks2;
int i=0;
printf("Unesite koeficijente a, b i c: ");
scanf("%lf %lf %lf",&a,&b,&c);

if((b*b-4*a*c)<0) {
	printf("Rjesenja su imaginarni brojevi.");
	return 0;
}

x1=(-1*b+sqrt(b*b-4*a*c))/(2*a);
x2=(-1*b-sqrt(b*b-4*a*c))/(2*a);

min=x1;
max=x2;

if(x1>max){
	max=x1;
	min=x2;
}

do{
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&iks1);
	
	if(fabs(iks1-min)<EPSILON){
		printf("Tacno\n");
		break;
	}
	else if(min-iks1<0.1 && min>iks1) printf("Priblizno manje\n");
	else if(iks1-min<0.1 && iks1>min) printf("Priblizno vece\n");
	else if(iks1<min) printf("Manje\n");
	else if(iks1>min) printf("Vece\n");
} while(i==0);

do{
	printf("Unesite rjesenje x2: ");
	scanf("%lf",&iks2);
	
	if(fabs(iks2-max)<EPSILON){
		printf("Tacno\n");
		break;
	}
	else if(max-iks2<0.1 && max>iks2) printf("Priblizno manje\n");
	else if(iks2-max<0.1 && iks2>max) printf("Priblizno vece\n");
	else if(iks2<max) printf("Manje\n");
	else if(iks2>max) printf("Vece\n");
} while(i==0);

	return 0;
}
