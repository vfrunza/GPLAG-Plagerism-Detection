#include <stdio.h>
#include <stdlib.h>

int main() {
	int Xosa[10],Yosa[10],i,j,n;
	char koordsistem[20][20];
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			koordsistem[i][j]=' ';
		}
	}
	
        while(1){
		printf("Unesite broj tacaka: ");
	    scanf("%d",&n);
	    if(n>0 && n<=10) break;
	    else  
	    printf("Pogresan unos\n");
		}
	    
	
	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&Xosa[i],&Yosa[i]);
		if(Xosa[i]<0 || Xosa[i]>19 || Yosa[i]<0 || Yosa[i]>19){
				printf("Pogresan unos\n");
				i--;
		}
	}
	for(i=0;i<n;i++){
		koordsistem[Yosa[i]][Xosa[i]]='*';
		}
		for(i=0;i<20;i++){
			for(j=0;j<20;j++){
				printf("%c",koordsistem[i][j]);
			}
			printf("\n");
		}
		
	return 0;
}
	