#include <stdio.h>

int main() {
	int a[10],b[10],n,i,j,k=0;
	char matrica[20][20];
	printf("Unesite broj tacaka: ");
	do{
		int k=scanf("%d",&n);
		if(n<=0 || n>10 || k!=1) {
			printf("Pogresan unos\n");
			printf("Unesite broj tacaka: ");
		} 
	}while((n<=0 || n>10) && k!=1);
	for(i=0;i<10;i++){
		a[i]= -1;
		b[i]= -1;
	}
	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ",i+1);
			do{
				scanf("%d%d",&b[i],&a[i]);
				if(a[i]<0 || a[i]>19 || b[i]<0 || b[i]>19) printf("Pogresan unos\nUnesite %d. tacku: ",i+1);
			}while(a[i]<0 || a[i]>19 || b[i]<0 || b[i]>19 );
		
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			matrica[i][j]=' ';
		}
	}
	for(i=0;i<n;i++){
		matrica[a[i]][b[i]]='*';
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c",matrica[i][j]);
		}
		printf("\n");
	}
	/*for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			m=0;
			for(k=0;k<n;k++){
				if(i==a[k] && j==b[k]){
					m=1;
					printf("*");
					break;
				}
			}
			if(m==0) printf(" ");
		}
	}*/
	return 0;
}
