#include <stdio.h>
#include <stdlib.h>
int main() {
int i,j,k,K,R,S;
do{
	printf("Unesite broj redova: ");
	scanf("%d",&R);
}while(R>10||R<1);
do{
	printf("Unesite broj kolona: ");
	scanf("%d",&K);
}while(K>10||K<1);

do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&S);
	}while(S>10||S<1);

for(i=0;i<R;i++){
	for(j=0;j<K;j++){
		printf("+");
		for(k=0;k<S;k++){
			printf("-");
		}
	}
	printf("+");
	printf("\n");
	if(i==R) break;
	for(k=0;k<K;k++){
		printf("|");
		for(j=0;j<S;j++){
			printf(" ");
		}
	}
	printf("|");
	printf("\n");
}
for(j=0;j<K;j++){
	printf("+");
	for(k=0;k<S;k++){
		printf("-");
	}
}
printf("+");
	return 0;
}
