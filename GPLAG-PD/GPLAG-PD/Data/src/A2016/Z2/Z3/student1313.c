#include <stdio.h>

int main() {
	char a[20][20];
	int n,i,x,y;
	
	do{ /*broj tacaka*/
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n>10 || n<=0) printf("Pogresan unos\n");
		
	}while(n>10 || n<=0);
	
		for (x=0;x<20;x++){
		for(y=0;y<20;y++)
		a[x][y]=' ';
	}
	

	/*tacke*/
	for (i=0;i<n;i++){ do{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&x,&y); /*mora izbacivati ako koordinate nisu dobre tj od 0 do19*/
		
		if(x<0 || x>19 || y<0 || y>19)
		printf("Pogresan unos\n");
	}while(x<0 || x>19 || y<0 || y>19);	
	    a[x][y]='*';
	}
	
	for (x=0;x<20;x++) {
		for(y=0;y<20;y++){
			printf("%c",a[y][x]);
		}
		printf("\n");
	}
	return 0;
}
