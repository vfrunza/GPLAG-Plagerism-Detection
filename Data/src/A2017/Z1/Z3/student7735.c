#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main() {
	double a,b,c,x1,x2,x1i,x2i,x1Unos,x2Unos,D;
	int istina1=1,istina2=1,istina3=1,istina4=1;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-(4*a*c);
	if(D<0) {printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	x1i = (-b-sqrt(b*b-(4*a*c)))/(2*a);
	x2i = (-b+sqrt(b*b-(4*a*c)))/(2*a);
	if (x1i<=x2i){x1=x1i;
	x2=x2i;}
	else if (x1i>x2i) {x1=x2i;
	x2=x1i;
	}
	
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&x1Unos);
		if(((x1-x1Unos)<epsilon) && ((x1-x1Unos)>-epsilon)) printf("Tacno\n");
		else if (fabs(x1-x1Unos)<0.1 && (x1-x1Unos)>=0) { istina1=0;
			printf("Priblizno manje\n");
		}
		else if (x1Unos<x1 && istina1==1) printf("Manje\n");
		else if (fabs(x1-x1Unos)<0.1 && (x1Unos-x1)>=0) {istina2=0;
			printf("Priblizno vece\n");                    
		}
		else if ((x1Unos>x1) && (istina2==1)) printf("Vece\n");
	}
		while (fabs(x1-x1Unos)>=epsilon);
		do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&x2Unos);
		if(((x2-x2Unos)<epsilon) && ((x2-x2Unos)>-epsilon)) printf("Tacno\n");
		else if (fabs(x2-x2Unos)<0.1 && (x2-x2Unos)>=0) { istina3=0;
			printf("Priblizno manje\n");
		}
		else if (x2Unos<x2 && istina3==1) printf("Manje\n");
		else if (fabs(x2-x2Unos)<0.1 && (x2Unos-x2)>=0) {istina4=0;
			printf("Priblizno vece\n");
		}
		else if ((x2Unos>x2) && (istina4==1)) printf("Vece\n");
	}
		while (fabs(x2-x2Unos)>=epsilon);
	
	
	return 0;
}
