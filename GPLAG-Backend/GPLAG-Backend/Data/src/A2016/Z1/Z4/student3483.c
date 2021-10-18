#include <stdio.h>

int main() {
	int n, i, j, x, l, k, r, p, m;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while(n<=0 || n>50){
		printf("Pogresan unos \n");
		printf("Unesite broj n: ");
		scanf("%d", &n);
	}
	x=1+4*(n-1);
	l=2*n-3;
	if(n==1)
		printf("***");
	else	
		for(i=1; i<=n; i++){
			k=(i+1)+l-2*(i-1);
			p=1+(i-2)*2;
			r=k+p+1;
			m=r+1+l-2*(i-1);
			for(j=1; j<=x; j++){
				if(j==i || j==k || j==r || j==m)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
	return 0;
}
