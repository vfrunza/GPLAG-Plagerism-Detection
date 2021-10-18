#include <stdio.h>
#include<math.h>


int main ()
{
     
    const float Eps = 1e-10;
    float a1,a2,b1,b2,x,y;
    char zarez;
    printf("Unesite a1,b1,a2,b2: ");
    scanf("%f%c%f%c%f%c%f",&a1,&zarez,&b1,&zarez,&a2,&zarez,&b2);
   
    if(fabs(a1-a2)<=Eps*(fabs(a1)+fabs(a2)) && b1!=b2) printf("Paralelne su");
    else if(fabs(a1-a2)<=Eps*(fabs(a1)+fabs(a2))) printf("Poklapaju se");
    else
    {
         x=((b2-b1)/(a1-a2));
    y=((a1*(b2-b1)/(a1-a2))+b1);
    
    printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
    }
    
    
    return 0;
}