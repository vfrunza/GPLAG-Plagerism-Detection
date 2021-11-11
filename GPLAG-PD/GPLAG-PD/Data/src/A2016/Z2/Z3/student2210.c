#include <stdio.h>

int main() {
	char Matrica[20][20];
	int i,j,n;
	int x1,x2;
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);

	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			Matrica[i][j]=' ';
		}
	}
   while(n<1 || n>10){
   	printf("Pogresan unos \n");
   	printf("Unesite broj tacaka: ");
   	scanf("%d",&n);
   }
    
    
    for(i=0;i<n;i++){
    	printf("Unesite %d. tacku: ",i+1);
        scanf("%d %d",&x1,&x2);
		Matrica[x2][x1]='*';
	}
	while((x1<0 || x1>19) || (x2<0 || x2>19)){
		printf("Pogresan unos \n");
		printf("Unesite broj tacaka: \n");
		scanf("%d %d",&x1,&x2);
	}

		for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			
			printf("%c",Matrica[i][j]);
		}
		printf("\n");
	}

	
	return 0;
}
