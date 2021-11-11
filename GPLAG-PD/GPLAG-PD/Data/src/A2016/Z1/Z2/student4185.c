#include <stdio.h>
#include <math.h>
int main() {
	
		float a,b,c,d,x,y,k,z;
	printf("Unesite a1,b1,a2,b2: ");

	scanf("%f,%f,%f,%f", &a,&b,&c,&d);

        k=d-b;
		z=a-c;
		x=k/z;
		y=a*x+b;

	if ((a!=c)) {
		
		printf("Prave se sijeku u tacci (%0.1f,%0.1f)", x,y);
		
	} else {
		
		if (a==c && b==d) {
			printf("Poklapaju se");
		} else {
			if (a==c && b!=d) {
				
	
		
		printf("Paralelne su");}
		}
	}
	
	return 0;
}
