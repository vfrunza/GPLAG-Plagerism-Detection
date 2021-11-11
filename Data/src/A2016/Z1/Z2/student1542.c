#include <stdio.h>

int main() {
	 float a1, b1, a2, b2, x=0, y=0;
	 char c1, c2, c3;
	 printf("Unesite a1,b1,a2,b2: ");
	 scanf("%f", &a1); scanf("%c", &c1);
	 scanf("%f", &b1); scanf("%c", &c2);
	 scanf("%f", &a2); scanf("%c", &c3);
	 scanf("%f", &b2);
	 
	 if(a1==a2 && b1==b2)
	 printf("Poklapaju se");
	 
	 else if(a1==a2)
	 printf("Paralelne su");
	 
	 else {
	 x=(b2-b1)/(a1-a2);
	 y=a1*x+b1;
	 printf("Prave se sijeku u tacci (%.1f,%.1f)",x, y);
	 }
	 
	return 0;
}
