#include <stdio.h>

int main() {
	int x,y,z,i,j,k;
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&x);
	}
	while(x<=0 || x>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&y);
	}
	while(y<=0 || y>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&z);
	}
	while(z<=0 || z>10);
	for(i=1; i<=2*x+1; i++){
		if(i%2!=0){
		for(j=1; j<=y; j++){
				for(k=1;k<=z+1;k++)
				{
					if(k%(z+1)==1)
					printf("+");
					else
					printf("-");
				}
		}
		printf("+");
		printf("\n");
		}
		if(i%2==0){
			for(j=1; j<=y; j++){
				for(k=1;k<=z+1;k++)
				{
					if(k%(z+1)==1)
					printf("|");
					else
					printf(" ");
				}
		}
		
			printf("|");
			printf("\n");
		}}
	return 0;
}
