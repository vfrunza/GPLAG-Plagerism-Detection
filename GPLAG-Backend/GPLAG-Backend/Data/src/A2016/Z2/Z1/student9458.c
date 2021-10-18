#include <stdio.h>
#include<stdlib.h>
#include <math.h>
int main() {
	int a=0;
	int	b=0,i=0,j=0,kon=10;
	printf("Unesite broj: ");
	scanf("%d",&a);
	if(a<0)a=abs(a);
	if(a>=0 && a<=9){
		printf("0");
		return 0;
	}
	while(a>0){
		if(a>=0 && a<=9)break;
		i=a%10;
		a=a/10;
		j=a%10;
		b=kon*(abs(i-j))+b;
		kon*=10;
	}
	b/=10;
	printf("%d",b);
	return 0;
}
