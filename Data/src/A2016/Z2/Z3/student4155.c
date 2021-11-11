#include <stdio.h>

int main() {
	int matrica[20][20]={0};
	int a,b;
	int brt;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&brt);
	if(brt<1 || brt>10) printf("Pogresan unos\n");
	}
	while(brt<1 || brt>10);
	
	int koordx;
	int koordy;
	
	for(a=0;a<brt;a++){
		printf("Unesite %d. tacku: ",a+1);
		scanf("%d %d",&koordx,&koordy);
		if (koordx<0 || koordx>19 || koordy<0 || koordy>19)
		{printf("Pogresan unos\n"); 
		a--; 
		continue;
		}
		matrica[koordx][koordy]=1;
	}
	

	for(a=0;a<20;a++)
	{
		for(b=0;b<20;b++){
			if(matrica[b][a]==1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
