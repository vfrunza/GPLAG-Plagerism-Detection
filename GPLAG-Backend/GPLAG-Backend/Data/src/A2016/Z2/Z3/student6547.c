#include <stdio.h>
#define SIRINA 20

int main() {
	int n,i,j,prvibr,drugibr;
	char mat[SIRINA][SIRINA];
	do { 
		printf("Unesite broj tacaka: ");
		scanf("%d",&n); 
		if(n>10 || n<=0) printf("Pogresan unos\n");
	} while(n>10 || n<=0);
	
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			mat[i][j]=' ';
		}
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			printf("Unesite %d. tacku: ",j+1);
			scanf("%d %d",&prvibr,&drugibr);
			if(prvibr<0 || prvibr>=20 || drugibr<0 || drugibr>=20) {
				printf("Pogresan unos\n"); j--;
			}
			 else mat[drugibr][prvibr]='*';
	}
	break;
	}
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			
			printf("%c",mat[i][j]);
		}
		printf("\n");
		
	}
	
	return 0;
}
