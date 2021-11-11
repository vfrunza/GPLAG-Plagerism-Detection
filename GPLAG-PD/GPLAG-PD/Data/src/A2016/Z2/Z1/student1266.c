#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i=0, a, b, j, ind=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0)
	n=-n;
	if(n/10==0){
	printf("0");
	return 0;
	}
	a=n;
	for(; ; ) {
		a=a/10;
		i++;
		if(a==0)
		break;
	}
	while(1){
		b=n;
		a=n;
		for(j=0;j<i;j++){
			if(j<i-1)
			a=a/10;
			if(j<i-2)
			b=b/10;
		}
		if(ind==0) {
			if(abs(b%10-a%10)!=0){
			printf("%d", abs(b%10-a%10));
			ind=1;
			}
		}
		else printf("%d", abs(b%10-a%10));
		i--;
		if(ind==0 && i==1)printf("0");
		if(i==1)
		break;
	}
	return 0;
}
