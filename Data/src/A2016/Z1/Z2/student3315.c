#include <stdio.h>

int main() {
float m, n, a1, a2, b1, b2, y1, y2, x; 
printf("Unesite a1,b1,a2,b2: ");
scanf("%f, %f, %f, %f", &a1,&b1,&a2,&b2);
y1=a1*x+b1;
y2=a2*x+b2;
if ((a1==a2) && (b1!=b2)) {
    printf("Paralelne su");
}
if((a1==a2) && (b1==b2)) {
    printf("Poklapaju se");
}
if((a1!=a2) && (b1!=b2)) {
m=(b2-b1)/(a1-a2);
n=a2*m+b2;
printf("Prave se sijeku u tacci (%.1f,%.1f)",m,n);
}
return 0;  
}


