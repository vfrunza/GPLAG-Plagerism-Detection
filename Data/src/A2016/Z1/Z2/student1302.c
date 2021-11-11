#include <stdio.h>

int main() {
	/*printf("Zadaća 1, Zadatak 2");*/
	float a1,b1,a2,b2,xc,yc,nesto;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
	nesto=(-a1)*1+a2*1;
	if (a1==a2 && b1==b2) printf ("Poklapaju se\n");
	else if(a1==a2) printf ("Paralelne su\n");
	else {
		xc=(b1-b2)/nesto;
		yc=(-(a1)*b2+a2*b1)/nesto;
		printf("Prave se sijeku u tacci (%.1f,%.1f)\n", xc,yc);
	}
	return 0;
}
