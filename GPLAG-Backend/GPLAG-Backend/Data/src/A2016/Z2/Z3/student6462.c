#include <stdio.h>

int main() {
	int n, matrica[20][20]={0}, i, j, k, t1, t2;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n>0 && n<11){
	for(i=0; i<n; i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &t1, &t2);
		if((t1>=0 && t1<=19) && (t2>=0 && t2<=19)){
			for(j=0; j<20; j++){
				for(k=0; k<20; k++){
					if(j==t1 && k==t2){
					  matrica[j][k]=1;
					}
				}
			}
		}
		else{
			printf("Pogresan unos\n");
			i--;
		}
	}
	break;
	}
	else printf("Pogresan unos\n");
	}while(n<=0 || n>10);
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if(matrica[j][i]==1){
				printf("%c", '*');
			}
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
