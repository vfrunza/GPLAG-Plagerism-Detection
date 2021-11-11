#include <stdio.h>
#include <math.h>
const double EPSILON=0.001;
int main()
{

	int a,b,c;
	double D;
	double x1,x2;
	double z1,z2;
	float N;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d", &a,&b,&c);

	D=(b*b)-(4*a*c);
	N=sqrt(D);
	x1=(-b+sqrt(b*b-4*a*c))/(2*a);
	x2=(-b-sqrt(b*b-4*a*c))/(2*a);

	if (D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}


while(1==1){
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&z1);
	if ((z1-x1)>=0.1) {
		printf("Vece\n");
		continue;
		
	}

	 if ((x1-z1)>=0.1) {
		printf("Manje\n");
		continue;
	
	
	}


	 if ((z1-x1) >= EPSILON && (z1-x1)<= 0.1) {
		printf("Priblizno vece\n");
		continue;
	
	}

	 if ((x1-z1)>=EPSILON && (x1-z1)<=0.1) {
		printf("Priblizno manje\n");
		continue;
	
	}




	 if ((x1-z1)<EPSILON ) {
		printf("Tacno\n");
		break;
		
	}
}
while(1==1) {
	printf("Unesite rjesenje x2: ");
	scanf("%lf",&z2);

	if ((z2-x2)>0.1) {
		printf("Vece\n");
		continue;
	}

	if ((x2-z2)>=0.1) {
		printf("Manje\n");
		continue;
	}


	if ((x2-z2)>0.001 && (x2-z2)<0.1) {
		printf("Priblizno manje\n");
		continue;
	}
	if ((z2-x2)>0.001 && (z2-x2)<0.1) {
		printf("Priblizno vece\n");
		continue;
	}

	if (fabs(x2-z2)<EPSILON) {
		printf("Tacno\n");
		break;
	}
}
	return 0;
}