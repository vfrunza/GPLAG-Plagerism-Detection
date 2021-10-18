#include <stdio.h>

int main() {
	int a;
	int maxX=0;
	int maxY=0;
	int x,y;
	char matrica[20][20];
	int i,j;
	int brojac=1;
	c:	
		printf("Unesite broj tacaka: ");
	 	scanf("%d",&a);
		if(a<1 || a>10) {
			printf("Pogresan unos \n"); 
			goto c;
		}

	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			matrica[i][j]=' ';
		}
	}
		
		
	for(i=0;i<a;i++) {
	
		a:	printf("Unesite %d. tacku: ", brojac);
			scanf("%d", &x); 
			if(x>maxX && x<20 && x>0) {
				maxX=x;
			}
			scanf("%d", &y);
			if(y>maxY && y<20 && y>0) {
				maxY=y;
			}
			
			if(y>=20 || y<0 || x>=20 || x<0){ 
				printf("Pogresan unos \n"); 
				goto a;
			}
			matrica[y][x]='*';
			brojac++;
	}
			
	for(i=0;i<=19;i++) {
		for(j=0;j<=19;j++) {
			printf("%c", matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}
