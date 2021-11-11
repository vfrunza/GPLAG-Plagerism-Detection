#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main() {
	long int n,c,r,x,s,e;
	printf("Unesite broj: ");
	scanf("%ld",&n);
    r=0;
	c=abs(n%10);
	x=abs(n/10);
	s=0;
	e=1;
	if(x>0){
	do{
		r=abs(c-x%10);
		c=abs(x%10);
		x=abs(x/10);
		s=abs(s)+r*pow(10,e);
		e++;
	}while(x!=0);}
	if(s%10==0)
		printf("%ld",s/10);
		else
			printf("%ld",s);
		return 0;
}
