#include <stdio.h>
    int main() {
	double a1,b1,a2,b2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	double D=a2-a1;
	if (D==0 && a1==a2 && b1!=b2){printf("Paralelne su"); return 0;}
	if(D==0 && a1==a2 && b1==b2){printf("Poklapaju se"); return 0;}
	double Dx=b1-b2;
	double Dy=-a1*b2+a2*b1;
	double x=Dx/D;
	double y=Dy/D;
	printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	return 0;
}
