#include <stdio.h>

int main() {
	int a,b,c,i,j,m,n;
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&a);
	}while(a<=0 || a>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&b);
	}while(b<=0 || b>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&c);
	}while(c<=0 || c>10);
	m=2*a+1;
	n=b*(c+1)+1;
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(i%2==0){
				if(j%(c+1)==0)
			printf("+");
			else
			printf("-");
		}
		if(i%2==1){
			if(j%(c+1)==0)
			printf("|");
			else
			printf(" ");
		}
		}
		printf("\n");
	}
	return 0;
}
