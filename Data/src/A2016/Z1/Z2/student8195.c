#include <stdio.h>

int main() {
	float a1, b1, a2, b2, y1,y2;
	printf("Unesite a1,b1,a2,b2:");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if ((((a1==a2)||(a1==-a2)||(-a1==a2)))&&(b1==b2)) {printf(" Poklapaju se");}
	else if (((a1==a2)||(a1==-a2))&&(b1!=b2)) printf(" Paralelne su");
    y1=(b2-b1)/(a1-a2);
    y2=a1*y1 +b1;
    if ((a1!=a2))
    printf(" Prave se sijeku u tacci (%.1f,%.1f)",y1, y2);
	return 0;
}
