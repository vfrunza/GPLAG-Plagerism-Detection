#include <stdio.h>

int main() {
	float a,b,c,d,xp,yp;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a,&b,&c,&d);
	if((a==c) && (b==d)){
		printf("Poklapaju se");
		return 0;
	}
	if(a==c){
		printf("Paralelne su");
		return 0;
	}
	
	else {
	xp=(d-b)/(a-c);
	yp=a*xp + b;
	if(yp==0.0 && xp==0.0) {
		printf("Prave se sijeku u tacci (0.00,0.00)");
		return 0;
	}
	
	printf("Prave se sijeku u tacci (%.1f,%.1f)",xp,yp);
	}
	return 0;

}
