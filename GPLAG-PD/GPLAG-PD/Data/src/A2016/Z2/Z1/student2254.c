#include <stdio.h>
#include <math.h>

int main() {
	int abs(int x);
	int a,k=0,i=0,m=0,o,j=1;
	printf("Unesite broj: ");
	scanf("%d",&a);
    if(a<0)
	a=abs(a);
	if(a<10 && a>0)
	printf("0");
	else{
    o=a;
//num of digits
	while(o>0)
	{
		o/=10;
		i++;
	}
//actual stuff
  while(a/10>0)
		{
		    k=abs(a%10-((a/10)%10));
		    if(j<i)
		    m += pow(10,j-1)*k;
			a/=10;
			j++;
		}
			printf("%d",m);
		
	}
		
	return 0;
}
