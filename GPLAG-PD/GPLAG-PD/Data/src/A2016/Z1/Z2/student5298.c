#include <stdio.h>

int main() {
	float a1,b1,a2,b2;
	char z=44;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f%c%f%c%f%c%f",&a1,&z,&b1,&z,&a2,&z,&b2);
	if(a1!=a2)printf("Prave se sijeku u tacci (%.1f,%.1f)", (b2-b1)/(a1-a2),a1*(b2-b1)/(a1-a2)+b1);
	else if(a1==a2 && b1==b2)  printf("Poklapaju se");
	else  printf("Paralelne su ");
	
	return 0;
}