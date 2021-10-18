#include <stdio.h>
#include <math.h>
int main() {
	
	int n, a, b, c, m=0, k=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0)n*=-1;
	if(n<10)
	{
		m=0;
	}
	else
	{
	    while(n!=0 || n<=9)
	    {
		    a=n%10;
		    n/=10;
		    b=n%10;
		    if(b>a) c=b-a;
            else c=a-b;
		    m+=c*k;
		    k*=10;
		    if(n<10) break;
		    else continue;
	    }
	}
	printf("%d",m);
	return 0;
}
