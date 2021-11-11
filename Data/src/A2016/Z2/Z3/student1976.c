#include <stdio.h>

int main() {
	int n,i,j,k,brojac1=0,brojac2=0;
	int x[20],y[20];
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n<1 || n>10) printf("Pogresan unos\n");
	else if(n>0 && n<10)break;
	}while(n<1 || n>10);
	
	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&y[i],&x[i]);
		if((x[i]<0 || x[i]>19) || (y[i]<0 || y[i]>19)){
			 printf("Pogresan unos\n");
			 i--;
			 continue;
		}
	}
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			for(k=0;k<n;k++){
					if(x[k]==i && y[k]==j){
					if((k>0 && x[k]==x[k-1] && y[k]==y[k-1])||(k>1 && x[k]==x[k-2] && y[k]==y[k-2])){
						continue; 
					}
						printf("*");
						brojac1=1;
					}else{
						brojac2=0;
					}
				
				
			}
			if(brojac1==1){
				brojac2=1;
				brojac1=0;
			}
			if(brojac2==0){
				printf(" ");
				brojac2=1;
			}
		}
		printf("\n");
	}
	return 0;
}
