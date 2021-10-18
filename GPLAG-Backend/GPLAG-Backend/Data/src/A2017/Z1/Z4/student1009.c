
#include <stdio.h>

int main() {
	int red,kolone,sirina,i,j,k;
	do { printf("Unesite broj redova: ");
		scanf("%d",&red);
	}while (red<=0 || red>10);
	do { printf("Unesite broj kolona: ");
		scanf("%d",&kolone);
	}while (kolone<=0 || kolone>10);
	do { printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sirina);
	}while (sirina<=0 || sirina>10);
	


for (k=0;k<=red;k++){
	for(i=0;i<=kolone;i++){
	printf("+");
	if(i==kolone) break;
		for(j=1;j<=sirina;j++){
printf("-");
			}
	}
printf("\n");
	if(k==red) break;
for(j=0;j<=kolone;j++){
	printf("|");
	for(i=1;i<=sirina;i++){
		printf(" ");
	
		}
}
printf("\n");
}
return 0;

}