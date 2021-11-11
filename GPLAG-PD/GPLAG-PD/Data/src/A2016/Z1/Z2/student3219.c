#include <stdio.h>

int main() {
	float a1=0,b1=0,a2=0,b2=0;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	float a=a1-a2;
	float b=b2-b1;
	float x=b/a;
	float y=a1*x+b1;
	if(a1==a2 && b1!=b2)
	{
		printf("Paralelne su");
	}
	
	else if(a1==a2 && b1==b2)
	{
		printf("Poklapaju se");
	}
	else
	   printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
	   
	return 0;
}
