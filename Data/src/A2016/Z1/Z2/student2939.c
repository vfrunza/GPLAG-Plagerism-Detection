#include <stdio.h>
#include <math.h>
#define e 0.001
int main() {
	float a1, b1, a2, b2, y2, x;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
	if (fabs(a1-a2)<e && fabs(b1-b2)>e){
		printf("Paralelne su\n");
	} else {
		if (fabs(a1-a2)<e && fabs(b1-b2)<e){
			printf("Poklapaju se\n"); }
	else{
	x=(b2-b1)/(a1-a2);
	y2=a2*x+b2;
			printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y2);}}
			return 0;
}
		
	
	
