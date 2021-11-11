#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>

int main() {
	int x, a, b1, b, c, n, br=1, suma=0;
	printf("Unesite broj: ");
	scanf("%d", &x); 
	if(x<0) x=abs(x);
	n=x; 
	while(n>=10){   
		br*=10;
		n/=10;
	}
    while(br>=10){ 
        a=x/br;
       	b1=x/(br/10);
       	b=b1%10;  
       	c=abs(b-a); 
       	if(c<0) c*=(-1);  
       	suma+=c*br;
       	x%=br; 
       	br/=10;
    }  
    suma/=10; 
    printf("%d", suma);
	return 0;
}

