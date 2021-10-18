#include <stdio.h>

int main() {
/*	printf("Zadaća 2, Zadatak 1");*/
	int n,i,j,pola,po;
	do{
	printf("Unesite broj N: ");
	scanf("%d",&n);
	if(n<8 || n%4!=0) printf("Neispravno N!\n");
	} while(n<8 || n%4!=0);
	pola=n/2;
	po=pola+pola/2;
	printf("\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(i>=1 && i<=pola && j>=1 && j<=pola){
				if(i==j) printf("\\");
				else if(pola-j==i-1) printf("/");
				else printf(" ");
			}
			if((j>pola && i<=pola)||(i>pola && j<=pola)){
				if(i==1 || i==pola+1 || i==pola || i==n){
					if(j==pola+1 || j==n || j==1 || j==pola) printf("+");
					else printf("-");
				}
				else{
					if(j==pola+1 || j==n || j==1 || j==pola) printf("|");
					else printf(" ");
				}
			}
			if(i>pola && j>pola){
					if((i==po && (j==po || j==po+1)) || (i==po+1 && (j==po || j==po+1))) printf("+");
					else if(j==po || j==po+1) printf("|");
					else if(i==po || i==po+1) printf("-");
					else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
