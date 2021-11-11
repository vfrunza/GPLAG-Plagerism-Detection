#include <stdio.h>

int main() {
	int N;
	do{
		printf("Unesite broj N: ");
		scanf("%d", &N);
		if(N<8 || N%4!=0) printf("Neispravno N!\n");
	} while(N<8 || N%4!=0);
	int i,j,k,a;
	printf("\n");
	a=N/2-1;
	for(i=0;i<N/2;i++){
		for(j=0;j<N/2;j++){
			if(i==j) printf("\\");
			else if (a==j){
				printf("/");
				a--;
			}
			else printf (" ");
		}			
		if(i==0 || i==N/2-1){
					printf("+");
					for(k=1;k<=N/2-2;k++) {
						printf("-");}
					printf("+");
				} else {
					printf("|");
					for(k=1;k<=N/2-2;k++) printf(" ");
					printf("|");
				}
		printf("\n");
	}
	for(i=0;i<N/2;i++){
		if(i==0 || i==N/2-1){
			printf("+");
			for(k=1;k<=N/2-2;k++) {
				printf("-");
			}
			printf("+");
		} else {
			printf("|");
			for(k=1;k<=N/2-2;k++) printf(" ");
				printf("|");
		}
		for(k=1;k<N/4;k++) {
				if(i==N/4 || i==N/4-1) printf("-");
				else printf(" ");
			}
			if(i==N/4 || i==N/4-1) printf("++");
			else printf("||");
		
			for(k=1;k<N/4;k++) {
				if(i==N/4 || i==N/4-1) printf("-");
				else printf(" ");
			}
		
		printf("\n");
	}
	return 0;
}
