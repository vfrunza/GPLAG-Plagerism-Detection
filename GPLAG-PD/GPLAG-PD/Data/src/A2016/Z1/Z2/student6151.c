#include <stdio.h>

int main() {
	
	float a,b,c,d,x=0,y=0,z,v;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a,&b,&c,&d);
	
	z=d-b;
	v=a-c;
	
	x=z/v;
	y=a*x+b;
	
	if(a==c && b==d)
	printf("Poklapaju se");
	
	else if (a==c)
	printf("Paralelne su");
	
	else 
	printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
	
	return 0;
}
