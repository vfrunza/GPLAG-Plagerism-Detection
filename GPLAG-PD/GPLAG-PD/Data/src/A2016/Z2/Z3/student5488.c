#include <stdio.h>

int main() {
	int prva[10];
	int druga[10];
	int n;
	int k1,k2;
	int i; i=0;
	int j,k; k=j=0;
	int jedan,dva;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if (n>10 || n<=0) printf("Pogresan unos\n");
	} while(n>10 || n<=0);
	while (i<n){
		do{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&k1,&k2);
		if(k1<0 || k1>19 || k2>19 || k2<0) printf("Pogresan unos\n");
		}while (k1<0 || k1>19 || k2>19 || k2<0);
		prva[i]=k1;
		druga[i]=k2;
		i++;
	}
	char matrica [20][20];
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			matrica[i][j]=32;
		}
	}
	for(k=0;k<n;k++){
		jedan=prva[k];
		dva=druga[k];
		for(i=0;i<20;i++)
		   for(j=0;j<20;j++)
	          if(i==dva && j==jedan) matrica[i][j]=42;
	}
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c",matrica[i][j]);
		}
		printf("\n");
	}
	/*printf("Zadaća 2, Zadatak 3");*/
	return 0;
}
