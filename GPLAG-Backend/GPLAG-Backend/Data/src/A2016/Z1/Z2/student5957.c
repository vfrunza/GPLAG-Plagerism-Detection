#include <stdio.h>
#include <math.h>

int main() {
	float  a1,b1,a2,b2;
	int a11=1,a22=1,b11=0,b22=0;
	float x=0,y=0;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	//printf("Unijeli ste: a1:%f b1:%f a2:%f b2:%f",a1,b1,a2,b2);
	a11=a1*1000;
	a22=a2*1000;
	b11=b1*1000;
	b22=b2*1000;
	x=(b2-b1)/(a1-a2);
	y=a1*x+b1;
	if(a11==a22 && b11==b22)
	printf("Poklapaju se");
	else if(a11==a22 && b11!=b22)
	printf("Paralelne su");
	else
	printf("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
	
	return 0;
}
