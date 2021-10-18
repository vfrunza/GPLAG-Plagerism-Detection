#include <stdio.h>
#include <math.h>

int main() {
	double a,b,c,epsilon=0.001,D,x1,x2,X1,X2;
	//Unos
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	//Diskriminanta"
	D=b*b-4*a*c;
	//Ne zelimo kompleksna rjesenja
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
	return 0;
}
//Racunanje nula kvadratne jednacine
x1=(-b+sqrt(D))/(2*a);
x2=(-b-sqrt(D))/(2*a);
//Korisnik unosi rjesenje X1 sve dok ne bude tacno (mi ga porukama na ekranu navodimo na rjesenje)
do{
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&X1);
	if(fabs(x1-X1)<epsilon)
	{
		printf("Tacno\n");
		break;
	}
	else if(fabs(x1-X1)<0.1 && x1>X1)
	{
		printf("Priblizno manje\n");
	}
	else if(fabs(x1-X1)<0.1 && x1<X1)
	{
	printf("Priblizno vece\n");
	}
	else if(x1>X1)
	{
		printf("Manje\n");
	}
	else if(x1<X1)
	{
		printf("Vece\n");
	}
	}while(fabs(x1-X1)>=epsilon);
	//Sada samo za rjesenje X2
	do{
		printf("Unesite rjesenje x2: ");
	scanf("%lf",&X2);
	if(fabs(x2-X2)<epsilon)
	{
		printf("Tacno\n");
		break;
		}
	else if(fabs(x2-X2)<0.1 && x2>X2)
	{
		printf("Priblizno manje\n");
	}
	else if (fabs(x2-X2)<0.1 && x2<X2)
	{
		printf("Priblizno vece\n");
	}
	else if(x2>X2)
	{
		printf("Manje\n");
	}
	else if(x2<X2)
	{
		printf("Vece\n");
	}
	}while(fabs(x2-X2)>=epsilon);
	return 0;
	}







