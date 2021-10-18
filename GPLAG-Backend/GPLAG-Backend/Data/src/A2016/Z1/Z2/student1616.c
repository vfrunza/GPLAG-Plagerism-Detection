#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    float x,y,a1,b1,a2,b2,fi;
    printf("Unesite a1,b1,a2,b2:" );
    scanf("%f,%f,%f,%f", &a1,&b1,&a2,&b2);
    fi=atan((a1-a2)/(1+(b1*b2)));
    x=((b2-b1)/(a1-a2));
    y=((a1*((b2-b1)/(a1-a2)))+b1);
    if(b1==b2 && a1==a2)
    {
        printf(" Poklapaju se");
        return 0;
    }
    if(fi==0)
    {
        printf(" Paralelne su");
        return 0;
    }
    if(fi!=0)
    {
        printf(" Prave se sijeku u tacci (%.1f,%.1f)", x,y);
    }
    return 0;
}