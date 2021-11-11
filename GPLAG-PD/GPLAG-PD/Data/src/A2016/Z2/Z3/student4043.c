#include <stdio.h>
#define BR_EL 20

int main() {
	int a[BR_EL][BR_EL]={0};
	int br_tac,n,i,j,x,y;
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &br_tac);
		if(br_tac<1 || br_tac>10) printf("Pogresan unos\n");
	} while(br_tac<1 || br_tac>10);
	for(n=1;n<=br_tac;n++){
		do{
			printf("Unesite %d. tacku: ", n);
			scanf("%d %d", &y, &x);
			//a[x][y]='*';
			if(x<0 || x>19 || y<0 || y>19) printf("Pogresan unos\n");
			else a[x][y]='*';
		} while(x<0 || x>19 || y<0 || y>19);
	}
	for(i=0;i<BR_EL;i++){
		for(j=0;j<BR_EL;j++){
			if(a[i][j]=='*') printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	/*printf("Zadaća 2, Zadatak 3");*/
	return 0;
}
