#include <stdio.h>
#include <math.h>
#define E 0.000001
double a1, a2, b1, b2, x, y, r, z;
int main() {
 printf("Unesite a1,b1,a2,b2: ");
 scanf("%lf, %lf, %lf, %lf", &a1, &b1, &a2, &b2);
 if((fabs(a2-a1))<E  && (fabs(b2-b1))<E) {
 printf("Poklapaju se");
 }
 else if((fabs(a1-a2))<E && (fabs(b1-b2))>E)
 {
 printf("Paralelne su");
 }
 else{
  r=b2-b1;
  z=a1-a2;
 	x=r/z;
 	y=(a1*x)+b1;
 	printf("Prave se sijeku u tacci (%.1lf,%.1lf)", x, y);
 }
 return 0;
}
