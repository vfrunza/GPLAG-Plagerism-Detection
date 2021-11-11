#include <stdio.h>

int main() {
	int a,i=0,j=0;
	do{
	printf("Unesite broj N: ");
	scanf("%d",&a);
	if(a<8 || a%4!=0)printf("Neispravno N!\n");
	}while(a<8 || a%4!=0);
	printf("\n");
	for(i=0;i<a;++i){
		for(j=0;j<a;++j){
			if(i<a/2 && j<a/2 && i==j)printf("\\");
			else if(i<a/2 && j<a/2 && j==a/2-i-1) printf("/");
			else if(((j==a/2 || j==a-1) && (i==0 || i==a/2-1)) || ((j==0 || j==a/2-1) && (i==a/2 || i== a-1))) printf("+");
			else if(((i>0 && i<a/2-1) && (j==a/2 || j==a-1)) || ((i>a/2 && i<a-1) && (j==0 || j==a/2-1))) printf("|");
			else if(((j>a/2 && j<a-1) && (i==0 || i==a/2-1)) || ((j>0 && j<a/2-1) && (i==a/2 || i==a-1)))printf("-");
			else if((i==a/2+a/4-1 || i==a/2+a/4) && (j==a/2+a/4-1 || j==a/2+a/4))printf("+");
			else if((j==a/2+a/4-1 || j==a/2+a/4) && (i>a/2-1 && i<a))printf("|");
			else if((i==a/2+a/4-1 || i==a/2+a/4) && (j>a/2-1 && j<a))printf("-");
			else printf(" ");
			
		}
		printf("\n");
	}
	return 0;
}
