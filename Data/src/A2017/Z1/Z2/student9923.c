#include <stdio.h>
#define e 0.0001
#define h -0.0001
int main() {
float a1,b1,a2,b2;
float x,y;
printf("Unesite a1,b1,a2,b2: ");
scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
if((a1-a2<e) && (a1-a2>h) && ((b1-b2>e) || (b1-b2<h)))
{
printf("Paralelne su");
 
}
else if((a1-a2<e) &&(a1-a2>h) && ((b1-b2<e) && (b1-b2>h)))
{
 printf("Poklapaju se");
 
}

if((a1-a2>e) || (a1-a2<h)) {
 x=(b2-b1)/(a1-a2);
 y=(a1*x)+b1;
 printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
}
	return 0;
}
