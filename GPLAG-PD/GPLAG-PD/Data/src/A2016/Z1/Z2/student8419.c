#include <stdio.h>

int main() {
	float a1,b1,a2,b2;
	float A,B;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
	if(a1==a2 && b1==b2) {
	printf("Poklapaju se \n");
	}
	else 
	if(a1==a2 && b1!=b2){
    printf("Paralelne su \n");
	}
    else
    {
	A=(b2-b1)/(a1-a2);
	B=(a1*A)+b1;
	printf("Prave se sijeku u tacci (%.1f,%.1f)", A,B);
}
	return 0;
}