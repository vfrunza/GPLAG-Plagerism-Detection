#include <stdio.h>

int main() {
	char a[20][20];
	int i=0,j=0,brt,t1,t2,l;
		for(i=0;i<20;i++){
			for(j=0;j<20;j++){
				a[i][j]=' ';
			}
		}
	
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&brt);
		if(brt<=0 || brt>10)
		printf("Pogresan unos \n");
		else
		break;
	} while(1);
	
	for(l=1;l<=brt;l++){
		do{
		printf("Unesite %d. tacku: ",l);
		scanf("%d %d", &t1,&t2);
		if (t1<0 || t2<0 || t1>19 || t2>19)
		printf("Pogresan unos \n");
		else
		break;
	} while(1);
		a[t2][t1]='*';
	}
	for(i=0;i<20;i++){
			for(j=0;j<20;j++){
				printf("%c",a[i][j]);
			}
			printf("\n");
	}
		return 0;
}
