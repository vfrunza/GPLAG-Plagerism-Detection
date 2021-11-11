#include <stdio.h>

int main() {
	float a1,b1,a2,b2,Tx,Ty;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if(a1==a2 && b1==b2){
		printf("Poklapaju se");
	}else
	if(a1==a2 && b1!=b2){
		printf("Paralelne su");
	}else{
		Tx=((b2-b1)/(a1-a2));
		Ty=(a1*Tx)+b1;
		printf("Prave se sijeku u tacci (%.1f,%.1f)",Tx,Ty);
	}
	return 0;
}
