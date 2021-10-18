#include <stdio.h>
#include <math.h>
int main() {
	int x,c,c1,max,rez=0,k=1;
	printf("Unesite broj: ");
	scanf("%d", &x);
	while(x!=0){
		c=x%10;
		x=x/10;
		if(x==0) break;
	    c1=x%10;
	    max=fabs(c-c1);
	    rez=rez+max*k;
	    k*=10;
	} 
	printf("%d\n", rez);
	return 0;
}
