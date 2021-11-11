#include <stdio.h>
#include<math.h>
#define epsilon 0.000001

int main() {
    double a1,a2,b1,b2,x,y;
    char c,h,a;
    printf("Unesite a1,b1,a2,b2: ");
    scanf("%lf%c%lf%c%lf%c%lf",&a1,&c,&b1,&h,&a2,&a,&b2);
    if(fabs(a1-a2)<epsilon && fabs(b1-b2)<epsilon){
        printf("Poklapaju se");
    }
    else if(fabs(a1-a2)<epsilon && fabs(b1-b2)>epsilon){
        printf("Paralelne su");
    }
    else{
        x=(b2-b1)/(a1-a2);
        y=a2*x+b2;
        printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
    }
	return 0;
}
