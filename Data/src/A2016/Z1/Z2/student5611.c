#include <stdio.h>

int main() {
	float a1,b1,a2,b2,p,q;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
	
	if(a1!=a2){
		p=(b2-b1)/(a1-a2);
		q=a2*p+b2;
		printf("Prave se sijeku u tacci (%.1f,%.1f)",p,q);
		
	}
	else if(a1==a2 && b1==b2){
		printf("Poklapaju se");
	}
	else{
		printf("Paralelne su");
	}
	return 0;
}
