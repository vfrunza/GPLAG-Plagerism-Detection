#include <stdio.h>

int main() {
	int i=0, j=0, br1=0,br2=0,br=0;
	char mat[20][20];
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			mat[i][j]= ' ';
		}
	}
	do {
	printf("\nUnesite broj tacaka: ");
	scanf("%d", &br);
	if(br<=0 || br>10) printf("Pogresan unos\n");
		
	} while (br<=0 || br>10);
	for(i=0;i<br;i++) {
	        printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &br1, &br2);
			
			if(br1<0 || br1>19 || br2<0 || br2>19) {
				printf("Pogresan unos\n");
				i--;
			
			}
			else {
				mat[br2][br1] = '*';
			}
	}
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
