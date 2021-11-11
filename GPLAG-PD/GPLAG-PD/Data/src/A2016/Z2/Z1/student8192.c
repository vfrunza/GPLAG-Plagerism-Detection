#include <stdio.h>
#include <math.h>

int main() 
{
	int i, n, j, m, h=0, x=1;
	
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	if(n<0) n = fabs(n);
	if(n<10) {printf("0"); return 0;}
	
	while(n != 0)
	{
	    if(n<10) break;
		i = n % 10;
		n/= 10;
		j = n % 10;
		m = fabs(i-j);
		h+= m * pow(10, x++);
	}	
	
	printf("%d", h/10);
    
    return 0;
}
