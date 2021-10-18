#include <stdio.h>

int main() {
	int sistem[20][20];
	int brojTacaka,a,b,i,j,maxb=0,maxa=0;
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			sistem[i][j]=0;
		}
	}
	
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&brojTacaka);
	if(brojTacaka>10 || brojTacaka<=0) printf("Pogresan unos\n");
	}while(brojTacaka>10 || brojTacaka<=0);
	
	for(i=0;i<brojTacaka;i++){
		do{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&a,&b);
		if((a<0 || a>19) || (b<0 || b>19)) printf("Pogresan unos\n");
		}while((a<0 || a>19) || (b<0 || b>19));
		if(b>maxb) maxb=b;
		if(a>maxa) maxa=a;
		sistem[b][a]=1;
	}
	
	for(i=0;i<=maxb;i++){
		for(j=0;j<=maxa;j++){
			if(sistem[i][j]) printf("*"); else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
