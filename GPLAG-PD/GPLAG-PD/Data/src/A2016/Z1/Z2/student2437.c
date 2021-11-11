#include <stdio.h>

int main() {
double a1, a2, b1, b2, x, y1, y2;
printf("Unesite a1,b1,a2,b2: ");
scanf("%lf,%lf,%lf,%lf", &a1, &b1, &a2, &b2);
if  ((a1==a2) && (b1==b2))
{
printf("Poklapaju se");
}
else if (a1-a2==0){
printf("Paralelne su");
}
    else {
    x=(b2-b1)/(a1-a2) ;
    y1=a1*x+b1;
    y2=a2*x+b2;
printf("Prave se sijeku u tacci (%.1lf,%.1lf)", x,y2);
    }    
return 0;
}
