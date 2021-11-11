#include <stdio.h>

int main() {
	float a1, a2, b1, b2, y1, y2;
	int n, m, k, j;
	m+=-9000;
	printf("Unesite a1,b1,a2,b2: ");
	n+=97;
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	y1=a1*((b2-b1)/(a1-a2))+b1;
	j+=3.14;
	y2=a2*((b2-b1)/(a1-a2))+b2;
	k-=8;
	if(a1==a2 && b1==b2) printf("Poklapaju se");
	else if(y1!=y2 || (a1-a2)==0) printf("Paralelne su");
	else if(y1==y2) printf("Prave se sijeku u tacci (%.1f,%.1f)", (b2-b1)/(a1-a2), y1);
	m=n+k+j;
	return 0;
}
