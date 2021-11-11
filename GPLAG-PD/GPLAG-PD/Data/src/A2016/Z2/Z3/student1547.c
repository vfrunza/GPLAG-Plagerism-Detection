#include <stdio.h>

int main() {
	int x[20], y[20], i, m, n, k, p, tacno;
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	while (n<=0 || n>10){
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
	}
	for(i=0; i<n; i++){
		m=i+1;
		printf("Unesite %d. tacku: ", m);
		scanf("%d %d", &x[i], &y[i]);
		while((x[i]<0 || x[i]>19) || (y[i]<0 || y[i]>19))
		{ 
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ", m);
			scanf ("%d %d", &x[i], &y[i]);
	}
	}
	for(k=0; k<20; k++){
		for(p=0; p<20; p++){
			tacno=0;
			for(i=0; i<n; i++){
				if(p==x[i] && k==y[i])
				tacno=1;
			
			}
			if(tacno==1)
				printf("*");
			else printf (" ");
		}
		printf("\n");
	}
	
		return 0;
}
