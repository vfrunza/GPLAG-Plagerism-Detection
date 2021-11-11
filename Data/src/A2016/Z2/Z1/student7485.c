#include <stdio.h>
#include <stdlib.h>


int main() {
	int x,k,c1,c2,j,br=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	if (x>-10 && x<10){
		printf("0");
		return 0;
	}
	else if (x<0) x=abs(x);
	j=1;
	while (x>=10){
		c1=x%10;
		c2=(x/10)%10;
		k=(abs(c1-c2))*j;
		j=j*10;
		x=x/10;
		br=br+k;
	}
	printf("%d", br);
	return 0;
}

