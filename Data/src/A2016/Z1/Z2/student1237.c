#include <stdio.h>
#include <math.h>
int main() {
double a1,b1,a2,b2,x,y,x1;
printf("Unesite a1,b1,a2,b2: ");
scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
if(a1==a2 && b1==b2){
	printf("Poklapaju se");
	
}
else if(a1==a2 ){
	printf("Paralelne su");

}
else {
	x1=a1-a2;
	x=(b2-b1)/x1;
	y=a1*x+b1;
printf("Prave se sijeku u tacci (%.1lf,%.1lf)",x,y);}

	return 0;
}
