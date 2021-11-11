#include <stdio.h>
#include <stdlib.h>

int main() {
	int m,s=0,k,p1,p2;
	printf("Unesite broj: ");
	scanf("%d",&m);
	if(m<0) m*=-1;
	p1=m%10;
	m/=10;
	k=1;

	while(m!=0) {
		p2=m%10;
		s=s+k*abs(p2-p1);
		k*=10;
		m/=10;
		p1=p2;
	}
    printf("%d",s);
    return 0;
	
		
		
		
	}
	
