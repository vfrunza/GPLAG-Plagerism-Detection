#include <stdio.h>
#include <math.h>
#define epsilon1 0.001
#define epsilon2 0.1
int main()
{
	double a,b,c,x1,x2,D,x01,x02,y,y1,y2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf", &a,&b,&c);
	D=b*b-4.*a*c;
	y=floor(D);
	if(y<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	y1=(-b-sqrt(D))/(2*a);
	y2=(-b+sqrt(D))/(2*a);
	if(y1<y2) {
		x01=y1;
		x02=y2;
	} else if (y2<y1) {
		x01=y2;
		x02=y1;
	} else if(fabs(y1-y2)<epsilon1) {
		x01=y1;
		x02=y1;
	}
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&x1);
		if(fabs(x1-x01)<epsilon1) printf("Tacno\n");
		else if((x1-x01)>epsilon2 || (x1-x01)==epsilon2) printf("Vece\n");
		else if((x1-x01)<(-epsilon2) || (x1-x01)==(-epsilon2)) printf("Manje\n");
		else if((x1-x01)>epsilon1 && (x1-x01)<epsilon2 || (x1-x01)==epsilon1) printf("Priblizno vece\n");
		else if((x1-x01)<(-epsilon1) && (x1-x01)>(-epsilon2) || (x1-x01)==(-epsilon1)) printf("Priblizno manje\n");
	} while (fabs(x1-x01)>=epsilon1);
	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&x2);
		if(fabs(x2-x02)<epsilon1) printf("Tacno\n");
		else if((x2-x02)>epsilon2 || (x2-x02)==epsilon2) printf("Vece\n");
		else if((x2-x02)<=(-epsilon2) || (x2-x02)==(-epsilon2)) printf("Manje\n");
		else if((x2-x02)>epsilon1 && (x1-x01)<epsilon2 || (x2-x02)==epsilon1) printf("Priblizno vece\n");
		else if((x2-x02)<=(-epsilon1) && (x2-x02)>(-epsilon2) || (x2-x02)==(-epsilon1)) printf("Priblizno manje\n");
	} while (fabs(x2-x02)>=epsilon1);

	return 0;
}
