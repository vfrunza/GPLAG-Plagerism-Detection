#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
int main(){
	double x1=0,x2=0,pokusaj1=0,pokusaj2=0,a,b,c,d=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	d=b*b-4.0*a*c;
	if(d<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}x1=(-b-sqrt(d))/(2.*a);
	x2=(-b+sqrt(d))/(2.*a);
	if(x2<x1){
		double temp=x1;
		x1=x2;
		x2=temp;
	}
	pokusaj1=2*x1;
	pokusaj2=2*x2;
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&pokusaj1);
		if(fabs(pokusaj1-x1)<=5*EPSILON) break;
		if(pokusaj1-x1>=0.1) printf("Vece\n");
		else if((pokusaj1-x1)>EPSILON && pokusaj1-x1<0.1) printf("Priblizno vece\n");
		else if(pokusaj1-x1<=-0.1) printf("Manje\n");
		else if(pokusaj1-x1>-0.1 && pokusaj1-x1<0) printf("Priblizno manje\n");
	}while(fabs(pokusaj1-x1)>EPSILON);
	printf("Tacno\n");
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&pokusaj2);
		if(fabs(pokusaj2-x2)<=5*EPSILON) break;
		if(pokusaj2-x2>=0.1) printf("Vece\n");
		else if((pokusaj2-x2)>EPSILON && pokusaj2-x2<0.1) printf("Priblizno vece\n");
		else if(pokusaj2-x2<=-0.1) printf("Manje\n");
		else if(pokusaj2-x2>-0.1 && pokusaj2-x2<0) printf("Priblizno manje\n");
	}while(fabs(pokusaj2-x2)>EPSILON);
	printf("Tacno");
	return 0;
}