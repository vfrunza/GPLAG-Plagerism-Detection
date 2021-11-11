#include <stdio.h>

int main() {
	
	int broj_tacaka, tacka=0, x, y, i, j;
	char sistem[20][20];
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			sistem[i][j]=' ';
		}
	}
	
	ponovo1:
	printf("Unesite broj tacaka: ");
	scanf("%d", &broj_tacaka);
	if(broj_tacaka>10 || broj_tacaka<1){
		printf("Pogresan unos\n");
			goto ponovo1;
	}
	
	while(tacka<broj_tacaka){
		
		ponovo2:
		printf("Unesite %d. tacku: ", tacka+1);
		scanf("%d %d",&x,&y);
		if(x<0 || x>19 || y<0 || y>19){
			printf("Pogresan unos\n");
			goto ponovo2;
		}
		
		sistem[y][x]='*';
		
		tacka++;
	}
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c", sistem[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
