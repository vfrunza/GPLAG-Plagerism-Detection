#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main() {
	double a,b,c,x1,x2,x1im,x2im,Unos1,Unos2,D;
	int istina1=1,istina2=1,istina3=1,istina4=1;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-(4*a*c);
	if(D<0) {printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	x1im = (-b-sqrt(b*b-(4*a*c)))/(2*a);
	x2im = (-b+sqrt(b*b-(4*a*c)))/(2*a);
	if (x1im<=x2im){x1=x1im;
	x2=x2im;}
	else if (x1im>x2im) {x1=x2im;
	x2=x1im;
	}
	
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&Unos1);
		if(((x1-Unos1)<epsilon) && ((x1-Unos1)>-epsilon)) printf("Tacno\n");
		else if (fabs(x1-Unos1)<0.1 && (x1-Unos1)>=0) { istina1=0;
			printf("Priblizno manje\n");
		}
		else if (Unos1<x1 && istina1==1) printf("Manje\n");
		else if (fabs(x1-Unos1)<0.1 && (Unos1-x1)>=0) {istina2=0;
			printf("Priblizno vece\n");                    
		}
		else if ((Unos1>x1) && (istina2==1)) printf("Vece\n");
	}
		while (fabs(x1-Unos1)>=epsilon);
		do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&Unos2);
		if(((x2-Unos2)<epsilon) && ((x2-Unos2)>-epsilon)) printf("Tacno\n");
		else if (fabs(x2-Unos2)<0.1 && (x2-Unos2)>=0) { istina3=0;
			printf("Priblizno manje\n");
		}
		else if (Unos2<x2 && istina3==1) printf("Manje\n");
		else if (fabs(x2-Unos2)<0.1 && (Unos2-x2)>=0) {istina4=0;
			printf("Priblizno vece\n");
		}
		else if ((Unos2>x2) && (istina4==1)) printf("Vece\n");
	}
		while (fabs(x2-Unos2)>=epsilon);
	
	
	return 0;
}