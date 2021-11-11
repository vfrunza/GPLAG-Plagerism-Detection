#include <stdio.h>
#define n 0.000001
#define m -0.00001
int main() {
	float a1,b1,a2,b2,x,y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if ((a1-a2<n) && (a1-a2>m) &&( (b1-b2>n) || (b1-b2<m))){
	printf("Paralelne su");}
	else if((a1-a2<n) && (a1-a2>m) && (b1-b2<n) && (b1-b2>m)){
	printf("Poklapaju se");}
	else if((a1-a2>n) || (a1-a2<m)) {
		x=(b2-b1)/(a1-a2);
		y=(a1*x)+b1;
	printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	}
	
	return 0;
}
