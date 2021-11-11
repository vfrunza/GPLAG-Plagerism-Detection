#include<stdio.h>
int main(){int n;
	do{printf("Unesite broj N: ");scanf("%d",&n);if(n%4!=0||n<8)printf("Neispravno N!\n");else printf("\n");}while(n % 4!=0 || n<8);
	int x = n/2;
	int i,j;int g=x-1,h=0;
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			if(i==j)printf("\\");
			else if(i==h && j==g)printf("/");
			else printf(" ");
		}
		if(i==0||i==x-1){
			printf("+");
			int k=x-2;
			while(k--)printf("-");printf("+");
		}
		else{
			printf("|");
			int k=x-2;
			while(k--)printf(" ");printf("|");
		}
		printf("\n");
		g--;h++;
	}
    g=x-1,h=0;
	for(i=0;i<x;i++){
		if(i==0||i==x-1){
			printf("+");
			int k=x-2;
			while(k--)printf("-");printf("+");
			k=x/2-1;while(k--)printf(" ");printf("||");
			k=x/2-1;while(k--)printf(" ");
		}
		else{
			printf("|");
			int k=x-2;
			while(k--)printf(" ");printf("|");
			if(i==x/2-1||i==x/2){
				k=x/2-1;while(k--)printf("-");printf("++");
				k=x/2-1;while(k--)printf("-");
			}
			else{
				k=x/2-1;while(k--)printf(" ");printf("||");
				k=x/2-1;while(k--)printf(" ");
			}
		}
		printf("\n");
		g--;h++;
	}
	return 0;
}