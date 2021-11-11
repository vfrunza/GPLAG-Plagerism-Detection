#include <stdio.h>
#include <math.h>

int main() {
    double a1,b1,a2,b2,y,x;
printf("Unesite a1,b1,a2,b2: ");
scanf("%lf,%lf,%lf,%lf",&a1,&b1,&a2,&b2);
if(b1==b2 && a1==a2 ){ printf("Poklapaju se");return 0;} 
else
if(a2==a1) { printf("Paralelne su"); return 0;}

else{
x=(b2-b1)/(a1-a2);
y=a1*x+b1;

printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
    
}

return 0;
}
