#include <stdio.h>

int main() {
	int i,n,j,k,b[20][20],c,d,br;
	br=0;
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			b[i][j]=0;
		}
	}
	
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n<=0 || n>10){
			printf("Pogresan unos\n");
		}
	}
	while (n<=0 || n>10);
	
	do{
		jump:
		printf("Unesite %d. tacku: ",br+1);
		scanf("%d %d",&c,&d);
		if(c<0 || c>19 || d<0 || d>19){
			printf("Pogresan unos\n");
			goto jump;
		}
	
		for(i=0;i<20;i++){
			for(j=0;j<20;j++){
				if(d==j){
					for(k=0;k<20;k++){
						if(c==k){
							b[j][k]='*';
						}
					}
				}
			}
		}
		br++;
	}
	while(br<n);
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(b[i][j]==0){
				printf(" ");
			}
			else
			printf("%c",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
