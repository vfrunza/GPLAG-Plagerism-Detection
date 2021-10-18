#include <stdio.h>
int main(){
	int n, i, j;
		printf("Unesite broj N: \n");
		do{
			scanf("%d", &n);
			if(n%4==0 && n>=8)
					break;
			printf("Greska\n");
		}while (1);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
		if(i==j && (j<n/2))
		printf("\\");
		else if((i+j==(n/2)-1))
		printf("/");
		else if(i==n/2 && (j=0 || (j==(n/2)-1)))
		printf("-");
		els
		else  
		printf("");
		
		}
		printf("\n");
	}
	return 0;
}
