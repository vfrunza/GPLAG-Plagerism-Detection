#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int k, i = 0, x , y , w = 0, e = 0;
    printf("Unesite broj: ");
    scanf("%d", &k);
    if(k<0)
    {
    	k=abs(k);
    }
    if(k>0 && k<10)
    {
    	e = 0;
    	printf("%d",e);
    	return 0;
    }
    while(k>9){
            x = k%10;
            k = k/10;
            y = k%10;
            w = abs((x-y))*pow(10,i);
            e = e+w;
        i++;
    }
    printf("%d",e);
    return 0;
}