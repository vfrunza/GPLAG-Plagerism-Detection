#include <stdio.h>
#include <stdlib.h>

int main() {
	int x,a,b,y=0,d=1;
	printf("Unesite broj: ");
	scanf("%d",&x);
    if(x<0) goto modul;
	
 while(x>=10)
	{
modul: x=abs(x);
    a=x%10;
	b=(x/10)%10;
	y=y+abs(a-b)*d;
	d=d*10;
	x=x/10;
    }
   
	printf("%d",y);
	return 0;
}

