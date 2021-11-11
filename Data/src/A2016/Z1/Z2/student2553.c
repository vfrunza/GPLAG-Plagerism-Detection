#include <stdio.h>

int main() {
	double a1=0,b1=0,a2=0,b2=0,X=0,Y=0;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	if(a1==a2 && b1==b2){printf("Poklapaju se");}
	else if(a1==a2){printf("Paralelne su");}
	else {
		X=(b2-b1)/(a1-a2);
		Y=a1*X+b1;
		printf("Prave se sijeku u tacci (%.1lf,%.1lf)",X,Y);
	}
	return 0;
}
