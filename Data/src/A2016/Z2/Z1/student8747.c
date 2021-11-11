#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n,s1,s2,i=0,a=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n/10==0){
		printf("0");
		return 0;
	}
	if(n<0)
		n=n*(-1);
	while(n!=0){
		s1=n%10;
		n/=10;
		s2=n%10;
		if(n!=0)
			a+=abs(s1-s2)*pow(10,i);
		i++;
	}
	printf("%d",a);
	return 0;
}