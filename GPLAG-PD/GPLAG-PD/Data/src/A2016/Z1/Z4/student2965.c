#include <stdio.h>

int main() {
	int n,i,j;
	do {
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n>50 || n<=0) {
			printf("Pogresan unos\n");
		}
	}
	while (n<=0 || n>50);
	if(n==1) {
		printf("***");
	}
	else {
		for(i=1;i<=n;i++) {
			for(j=1;j<=(4*n-3);j++) {
				if((i==j) || (i+j)==(2*n) || (i+j)==(4*n-2) || (j-i)==(2*n-2)) {
					printf("*");
			    } else printf(" ");
		    }
		    printf("\n");
	    }
	}
	return 0;
}
