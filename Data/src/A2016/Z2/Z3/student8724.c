#include <stdio.h>

int main() {
	int k;
	unos:
	printf("Unesite broj tacaka: ");
	
	scanf("%d",&k);
	if(k>10 || k<=0){
		printf("Pogresan unos\n");
		goto unos;
	}
	int nizi[10], nizj[10];
	int q,w,i;
	for(i=0;i<k;i++){
		
		unos1:
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&q,&w);
		if(q<0 || q>19 || w<0 || w>19){
			printf("Pogresan unos\n");
			goto unos1;
			
		}else{
			nizi[i]=w;
			nizj[i]=q;
		}
	}
	
	int m[20][20]={0};
	int j;
	for(i=0;i<k;i++){
	m[nizi[i]][nizj[i]]=1;
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(m[i][j]==1)
			printf("*");
		    else
		    printf(" ");
			
		}
		printf("\n");
	}
	return 0;
}
