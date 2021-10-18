#include <stdio.h>

int main() {
	char m[20][20];
	int i,l,j,n,k,prv[10],dru[10];
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			m[i][j]=' ';
		}
	}
     for(i=0;i<1;i++){
     	printf("Unesite broj tacaka: ");
     	scanf("%d",&n);
     	if(n<1 || n>10){
     		printf("Pogresan unos\n");
     		i--;
     	}
     }
	for(i=0;i<n;i++){
	printf("Unesite %d. tacku: ",i+1);
	scanf("%d%d",&prv[i],&dru[i]);
	if((prv[i]>19 || prv[i]<0) || (dru[i]>19 || dru[i]<0)){
		printf("Pogresan unos\n");
		i--;
	}
	}
	for(k=0;k<n;k++){
	  for(l=0;l<20;l++){
	  	for(j=0;j<20;j++){
	  		if(j==prv[k] && l==dru[k]){
	  			m[l][j]='*';
	  		}
	  	}
	  }	
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c",m[i][j]);
		}
		printf("\n");
	}
	
	
	
	return 0;
}
