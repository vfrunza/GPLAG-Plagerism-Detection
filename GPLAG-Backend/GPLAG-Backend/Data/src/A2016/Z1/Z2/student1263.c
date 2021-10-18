#include <stdio.h>

int main() {
	float a1,a2,b1,b2;
	float rez1,rez2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f",&a1);
	scanf("%f",&b1);
	scanf("%f",&a2);
	scanf("%f",&b2);
	rez1=(b2-b1)/(a1-a2);
	rez2=(a1*rez1)+b1;
	if(a1!=a2)
	{
		printf("Prave se sijeku u tacci (%.1f,%.1f)", rez1,rez2);
	}
	else if(a1==a2&&b1!=b2)
	{
		printf("Paralelne su ");
	}
	else 
	{
		printf("Poklapaju se ");
	}
	return 0;
}
