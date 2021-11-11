#include <stdio.h>
#include <math.h>
int main() {
	int a,c1,c2,suma=0,k=1;
	printf("Unesite broj: ");
	scanf("%d",&a);
	
	c1=a%10;
    a/=10;
 
	while(a!=0)
    {	
    	c2=a%10;
    	suma+=fabs((c1-c2))*k;
	    k*=10;
	    c1=c2;
     	a/=10;
    }
    
    
	
	printf("%d",suma );
	return 0;
}
