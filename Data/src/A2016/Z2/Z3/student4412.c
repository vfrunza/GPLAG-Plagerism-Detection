#include <stdio.h>

int main() {
	int x[10], y[10];
	int i, j, z, n;
	for(;;){
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
	if(n>0 && n<11){
		break;
	}
	else{
		printf("Pogresan unos\n");
	}}
	for(i=0; i<n; i++){
		int a,b;
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &a, &b);
		if((a>19 || b>19) || a<0 || b<0){
			printf("Pogresan unos\n");
			i--;
			continue;
		}
		x[i]=a;
		y[i]=b;
	}
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			int k=0;
			for(z=0; z<n; z++){
				if(i==y[z] && j==x[z]){
					k=1;
					break;
				}
			}
			if(k==1) printf("*");
			else printf(" ");
		}
		printf("\n");
		
	}
	
	return 0;
}
