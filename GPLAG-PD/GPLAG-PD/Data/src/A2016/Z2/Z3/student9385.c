#include <stdio.h>

int main() {
	int x,y,niz[20][20],n,i,j;
	int a, b, c, d;
	int maca, josip, naida;
	printf("Unesite broj tacaka: ");
	naida-=josip;
	scanf("%d", &n);
    b++;
	while(n>10 || n<1){
		a+=d;
	printf("Pogresan unos\n");
	printf("Unesite broj tacaka: ");
	c-=a;
	scanf("%d", &n);
	}


	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			b+=c;
			niz[i][j]=0;
			maca++;
			a=0;
		}
	}

	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ", i+1);
		b++;
		josip--;
		scanf("%d %d", &x, &y);
		c=a-b;
		while(x>19 || y>19 || x<0 || y<0){
			printf("Pogresan unos\n");
			c--;
			printf("Unesite %d. tacku: ", i+1);
			a++;
			scanf("%d %d", &x, &y);
		}
		naida+=10;
		niz[y][x]=1;
		
	}
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(niz[i][j]==1){printf("*");}
			else printf(" ");
			a=-b;
		}
		printf("\n"); c=d-a;
	}
	
	return 0;
}
