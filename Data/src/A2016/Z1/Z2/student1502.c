#include <stdio.h>
#include <math.h>
#define ups 0.00001
int main() {
	
	double a1,b1,a2,b2,x,y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
	
	if(fabs(a1-a2)<ups && fabs(b1-b2)<ups){
		
		printf("Poklapaju se");
		return 0;
		
	}else if(fabs(a1-a2)<ups){
		printf("Paralelne su");
		return 0;
	}
	else{
			x=((b2-b1)/(a1-a2));
		y=(a1*(b2-b1)/(a1-a2))+b1;
	}
	printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	return 0;
}
