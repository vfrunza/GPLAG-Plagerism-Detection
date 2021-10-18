#include <stdio.h>

int main() {
	int n;
	int i, j, k;
	do{
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(n%4!= 0 || n<8) printf("Neispravno N!\n");
		else break;
	}while(1);
	printf("\n");
	for(i=0; i<n/2; i++){
		for(j=0; j<n; j++){
			if(j<n/2){
				if(i==j) printf("\\");
				else if(i==-j+n/2-1) printf("/");
				else printf (" ");
			}
			else if(j==n/2){
				if(i==0 || i==n/2-1) {
					printf("+");
					for(k=0; k<n/2-2; k++) printf("-");
					printf("+");
				}
				else printf("|%*c", n/2-1, '|');
			}
		}
		printf("\n");
	}
	
	for(i=0; i<n/2; i++){
		for(j=0; j<n; j++){
			if(j==0){
				if(i==0 || i==n/2-1){
					printf("+");
					for(k=0; k<n/2-2; k++) printf("-");
					printf("+");
				}
				else printf("|%*c", n/2-1, '|');
			}
			else if(j==n/2){
				if(i==n/4 || i==n/4-1)
					for(k=0; k<n/2; k++){
						if(k==n/4 || k==n/4-1) printf("+");
						else printf("-");
					}
				else{
					printf("%*c%-*c", n/4, '|', n/4, '|');
				}
			}
		}
		printf("\n");
	}
	return 0;
}
