#include <stdio.h>
#include <math.h>

int main() {
    
    int b;
    int n;
    int br=0;
    int b2, b3;
    int l=1;
    int cifra=0;
    int novo;
    int i;
    
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	b=n;
	
	while (n!=0){
	    n/=10;
	    br++;
	}
	int m;
	m=br-1;
	for (i=0; i<m;i++){
	    b2=b%10;
	    b3=(b/10)%10;
	    novo=fabs(b2-b3);
	    cifra=novo*l+cifra;
	    b/=10;
	    l*=10;
	    
	}
	printf("%d", cifra);
	return 0;
}
