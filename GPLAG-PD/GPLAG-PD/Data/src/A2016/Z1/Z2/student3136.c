#include <stdio.h>

int main() {
	float a1,a2,b1,b2 ;
	printf("Unesite a1,b1,a2,b2: ") ;
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2) ;
	if(a1==a2 && b1==b2) printf("Poklapaju se\n") ;
	else if(a1==a2 && b1!=b2) printf("Paralelne su\n") ;
	else {
		float x=(b2-b1)/(a1-a2) ;
		float y=a1*x+b1 ;
		printf("Prave se sijeku u tacci (%.1f,%.1f)\n",x,y) ;
		
		
		
	}
	
	return 0;
}
