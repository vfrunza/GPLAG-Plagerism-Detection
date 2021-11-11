#include <stdio.h>

int main()
{
	float a1,b1,a2,b2;
	char zarez;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f%c%f%c%f%c%f", &a1,&zarez,&b1,&zarez,&a2,&zarez,&b2);
	if(a1==a2 && b1==b2) printf("Poklapaju se");
	else if(a1==a2) printf("Paralelne su");
	else printf("Prave se sijeku u tacci (%.1f,%.1f)", (b2-b1)/(a1-a2), a1*(b2-b1)/(a1-a2)+b1);
	return 0;
}
