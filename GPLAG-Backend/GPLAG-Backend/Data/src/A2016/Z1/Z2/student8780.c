#include <stdio.h>

int main() {

float a,b,c,d,x,y;

printf ("Unesite a1,b1,a2,b2: ");
scanf ("%f,%f,%f,%f",&a,&b,&c,&d);

if (a==c && b!=d) {printf ("Paralelne su");} 
else if (a==c && b==d) {printf ("Poklapaju se");} 
else if (a!=c && b!=d){

x=(d-b)/(a-c);
y=a*x+b;
printf ("Prave se sijeku u tacci (%.1f,%.1f)",x,y);


}


























	return 0;
}
