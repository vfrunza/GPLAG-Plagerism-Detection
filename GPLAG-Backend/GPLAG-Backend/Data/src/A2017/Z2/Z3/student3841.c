#include <stdio.h>

int main() {
	int brojTacaka,i,j,x,y;
	char koordinatniSistem[20][20];
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			koordinatniSistem[i][j]=' ';
		}
	}
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &brojTacaka);
	if(brojTacaka<=0 || brojTacaka>10) {
		printf("Pogresan unos\n");
		}
	}
	while(brojTacaka<=0 || brojTacaka >10);
	
	for(i=0;i<brojTacaka; i++) {
		do{
			printf("Unesite %d. tacku: ",(i+1));
			scanf("%d %d", &x, &y);
			if(x<0 || x>19 || y<0 || y>19) {
				printf("Pogresan unos\n");
				}
		} while(x<0 || x>19 || y<0 || y>19);
		koordinatniSistem[x][y] = '*';
		
	}
		for(i=0;i<20;i++) {
			for(j=0;j<20;j++) {
				printf("%c", koordinatniSistem[j][i]); 
			}
			printf("\n");
		}
		
	
	return 0;
}
