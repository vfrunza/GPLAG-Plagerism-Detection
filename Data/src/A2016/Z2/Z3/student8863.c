#include <stdio.h>

int main() {
	
	int i, j=0, x, n, a[20], b[20], min, z, raz=0;
	
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	while(n<1 || n>10){
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
	}
	
	for(x=0; x<n; x++){
		printf("Unesite %d. tacku: ", x+1);
		scanf("%d %d", &a[x], &b[x]);
		while((a[x]<0 || a[x]>19) || (b[x]<0 || b[x]>19)){
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ", x+1);
			scanf("%d %d", &a[x], &b[x]);
		}
	}
	
		for(i=0; i<20; i++){
			for(j=0; j<20; j++){
				for(x=0; x<n; x++){
					if(a[x]==j && b[x]==i)
						{
							printf("*");
							raz=1;	
							break;
						}
				}
				if(raz==0)
						printf(" ");
				raz=0;
			}
		printf("\n");
	}

	return 0;
}
