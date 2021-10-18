#include <stdio.h>
#include <math.h>
#define d 0.01
int main(){
    float a1,a2,b1,b2,x,y;
    printf("Unesite a1,b1,a2,b2: ");
    scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
   if((fabs(a1-a2)<d && fabs(b1-b2)<d) ){
       printf("Poklapaju se");
       
   }
   else if(fabs(a1-a2)<d ){
       printf("Paralelne su");
      
   }
   else {
   x=(b2-b1)/(a1-a2);
   y=x*a1+b1;
   printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
   }
    return 0;
}
