#include <stdio.h>

int main() {
	int n,k=1,b=0,l,m,t;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if((n>=0 && n<10)){printf("0");return 0;}
	if(n<0)n=-n;
	
	while(n!=0){
		if(n>0 && n<10)break;
		m=n%10;
		l=(n%100)/10;
		t=m-l;
		if(t<0)t=-t;
		b+=t*k;
		k*=10;
		n/=10;
		
	}
	printf("%d",b);
	
	
	
	return 0;
}
