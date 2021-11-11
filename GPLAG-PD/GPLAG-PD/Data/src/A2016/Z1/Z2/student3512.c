#include <stdio.h>

int main() {
	float a1,b1,a2,b2,Tp;
	printf("Unesite vrijednost a1,b1,a2,b2:");
	scanf("%f%f%f%f",&a1,&b1,&a2,&b2);
	Tp==((b2-b1)/(a1-a2),-(a1*b1)/a2);	
	if(a1==a2 && b1==b2){
		printf("Poklapaju se");
		} else if (a1==b1 && a2==b2){
			printf("Paralelne su");
			} else {
				printf("\n Prave se sijeku u tacki:",Tp);
		}


	return 0;
}
