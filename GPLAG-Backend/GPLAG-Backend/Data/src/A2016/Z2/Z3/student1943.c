#include <stdio.h>

int main() {
	int n,i,j,k,a=0,trebaispisati=0;
	int niz[20];
	int mat[20][20];
	printf("Unesite broj tacaka: ");
    do{
	scanf("%d",&n);
	if(n<=0 || n>10) { printf("Pogresan unos");
	                  printf("\nUnesite broj tacaka: "); }
	}while(n<=0 || n>10);
	for(i=0;i<20;i++){
	if(i==n) break;
	printf("Unesite %d. tacku: ",i+1);
	a=i;
	if(i!=0 )  a=i+i; 
	do{
	scanf("%d %d",&niz[a],&niz[a+1]);
	if(niz[a]<0 || niz[a]>19 || niz[a+1]<0 || niz[a+1]>19) { printf("Pogresan unos");
	                                                         printf("\nUnesite %d. tacku: ",i+1);
	}
	}while(niz[a]<0 || niz[a]>19 || niz[a+1]<0 || niz[a+1]>19);
	}	
    for(i=0;i<20;i++) {
        for(j=0;j<20;j++) {
        	trebaispisati=0;
            for(k=0;k<n*2;k+=2) {
                if(j==niz[k] && i==niz[k+1]) { trebaispisati=1; }
            }
            if(trebaispisati==1) { printf("*"); }
            else printf(" ");
        }
        printf("\n");
    }
	return 0;
}
