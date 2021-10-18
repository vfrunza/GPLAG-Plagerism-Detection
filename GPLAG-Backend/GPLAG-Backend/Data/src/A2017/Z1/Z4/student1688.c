#include <stdio.h>

int main() {
	int a,b,c,i,j;
	do {
	printf("Unesite broj redova: ");
	scanf("%d",&a);
	printf("Unesite broj kolona: ");
	scanf("%d",&b);
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&c);
		
	}while((a<=0 || b<=0 || c<=0)|| (a>10 || b>10 || c>10));

for(i=0;i<(a*2+1);i++){
	for(j=0;j<((b*c)+b+1);j++) {
		if(i%2==0 && j%(c+1)==0) 
		printf("+");
		if(i%2==0 && j%(c+1)!=0)
		printf("-");
		if(i%2!=0 && j%(c+1)==0)
		printf("|");
		if(i%2!=0 && j%(c+1)!=0)
		printf(" ");
		
	}
	printf("\n");
}

return 0;
}
