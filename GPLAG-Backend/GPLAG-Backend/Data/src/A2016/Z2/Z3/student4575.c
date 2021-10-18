#include <stdio.h>

int main() {
	int a, x, y, i=0, j=0;
	char niz[20][20];
	for (i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			niz [i][j]=' ';
		}
	}
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d", &a);
		if(a<=0 || a>10) {
			printf("Pogresan unos\n");
		}
	}
		while(a<=0 || a>10);
	for(i=0;i<a;i++){
		do{
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d", &x);
			scanf("%d", &y);
			if(x<0 || x>19 || y<0 || y>19) {
				printf("Pogresan unos\n");
			}
		    else niz[y][x]='*';
		} 
		while (x<0 || x>19 || y<0 || y>19);
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c", niz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
