#include <stdio.h>

int main() {
	int a,b,c,red,kolona;
	int i,j;
	do{
		printf("Unesite broj redova: ");
		scanf("%d",&a);
		
	}while(a<1 || a>10);
	do{
		printf("Unesite broj kolona: ");
		scanf("%d",&b);
	}while(b<1 || b>10);
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&c);
	}while(c<1 || c>10);
	
	red=a+(a+1);
	kolona=b*c+(b+1);
	for(i=0;i<red;i++){
		for(j=0;j<kolona;j++){
			if(i%2==0 && j%(c+1)==0) printf("+");
			else if(i%2!=0 && j%(c+1)==0) printf("|");
			else if(i%2==0) printf("-");
			
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
