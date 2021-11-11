#include<stdio.h>

int main(){
	int a = 11,b = 11,c = 11;char d;
	do{
		again:printf("Unesite broj redova: ");
		scanf("%d", &a);
		scanf("%c", &d);
		if(a == 0)goto again;
	}while(a < 0 || a > 10);
	do{
		again1:printf("Unesite broj kolona: ");
		scanf("%d", &b);
		scanf("%c", &d);
		if(b == 0)goto again1;
	}while(b < 0 || b > 10);
	do{
		again2:printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &c);
		scanf("%c", &d);
		if(c == 0)goto again2;
	}while(c < 0 || c > 10);
	for(int i = 0;i < a * 2;i++){
		if(i % 2 == 0){
			for(int j = 0;j < b;j++){
				printf("+");
				for(int k = 0;k < c;k++)printf("-");
			}
			printf("+\n");
		}
		else{
			for(int j =0; j < b;j++){
				printf("|");
				for(int k = 0;k < c;k++)printf(" ");
			}
			printf("|\n");
		}
	}
	for(int j = 0;j < b;j++){
			printf("+");
			for(int k = 0;k < c;k++)printf("-");
	}printf("+\n");
	return 0;
}