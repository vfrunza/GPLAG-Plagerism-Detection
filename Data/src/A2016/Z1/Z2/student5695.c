#include <stdio.h>
int main() {
	float a1,b1,a2,b2,x,y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f%f%f%f",&a1,&b1,&a2,&b2);
	if (a1==a2 && b1==b2) printf("Prave se poklapaju.\n");
	else if (a1==a2 && b1!=b2) printf("Prave su paralelne.\n");
	else {
		x=(b1-b2)/(a2-a1);
		y=a1*x+b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)\n",x,y);
	}
	return 0;
}
