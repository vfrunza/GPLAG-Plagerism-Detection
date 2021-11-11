#include <stdio.h>

int main() {
	double a1,a2,b1,b2,y,x;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf", &a1,&b1,&a2,&b2);
	if(a1==a2&&b1==b2)
	printf("Poklapaju se");
	else if(a1==a2&&b1!=b2){
	printf("Paralelne su");}
	else{
	x=(b1-b2)/(a2-a1);
	y=a1*x+b1;
	printf("Prave se sijeku u tacci (%.1lf,%.1lf)",x,y);}
	
	
	return 0;
}
