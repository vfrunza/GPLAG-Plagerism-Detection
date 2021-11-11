#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main() {
	double a,b,c,x1,x2,a1,b1,y1,y2,D;
	int istina1=1,istina2=1,istina3=1,istina4=1;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-(4*a*c);
	if(D<0) {printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	a1 = (-b-sqrt(b*b-(4*a*c)))/(2*a);
	b1 = (-b+sqrt(b*b-(4*a*c)))/(2*a);
	if (a1<=b1){x1=a1;
	x2=b1;}
	else if (a1>b1) {x1=b1;
	x2=a1;
	}
	
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&y1);
		if(((x1-y1)<epsilon) && ((x1-y1)>-epsilon)) printf("Tacno\n");
		else if (fabs(x1-y1)<0.1 && (x1-y1)>=0) { istina1=0;
			printf("Priblizno manje\n");
		}
		else if (y1<x1 && istina1==1) printf("Manje\n");
		else if (fabs(x1-y1)<0.1 && (y1-x1)>=0) {istina2=0;
			printf("Priblizno vece\n");                    
		}
		else if ((y1>x1) && (istina2==1)) printf("Vece\n");
	}
		while (fabs(x1-y1)>=epsilon);
		do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&y2);
		if(((x2-y2)<epsilon) && ((x2-y2)>-epsilon)) printf("Tacno\n");
		else if (fabs(x2-y2)<0.1 && (x2-y2)>=0) { istina3=0;
			printf("Priblizno manje\n");
		}
		else if (y2<x2 && istina3==1) printf("Manje\n");
		else if (fabs(x2-y2)<0.1 && (y2-x2)>=0) {istina4=0;
			printf("Priblizno vece\n");
		}
		else if ((y2>x2) && (istina4==1)) printf("Vece\n");
	}
		while (fabs(x2-y2)>=epsilon);
	
	
	return 0;
}