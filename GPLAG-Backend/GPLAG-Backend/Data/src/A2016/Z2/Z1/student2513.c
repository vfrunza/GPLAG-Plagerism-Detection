#include <stdio.h>
#include <math.h>
#include<stdlib.h>
int main() {
	int n,a,b,br=0,c=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0) 
	n=abs(n);
	if(n<10) 
	printf("0");
	else { do 
	{
		a=n%10;
		b=(n/10)%10;
		br=br+abs(b-a)*c;
		c=c*10;
		n=n/10;
	}
	while(n>=10);
	printf("%d",br);}
	
	return 0;
}
