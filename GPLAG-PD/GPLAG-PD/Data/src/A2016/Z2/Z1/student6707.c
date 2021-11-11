#include <stdio.h>
#include <math.h>
int main() {
	int n;
	
	int a,e=0,b, d, i=1;
	int brojac=0;

	scanf("%d",&n);
	
	if(n/10==0) 
	{
		a=0;
	}
	else{
	
	if(n<0) n=fabs(n);
	b=n;
	while(b!=0)
	{
		b=b/10;
		brojac++;
	}
	while(brojac!=1){
		a=n%10;
		n=n/10;
		b=n%10;
		d=a-b;
		if(d<0) d=fabs(d);
		e=e+d*i;
		i=i*10;
		brojac--;
	}
		
	}
	
	printf("Unesite broj: %d", e);
	
	return 0;
}
