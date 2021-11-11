#include <stdio.h>

void f1(int mat[200][200],int *niz,int velicina,int m){
	int i;
	for(i=0;i<velicina;i++){
		niz[i]=mat[m][i];
	}
}

int f2(int*n1,int*n2,int velicina){
	int i;
	int jednak=1;
	for(i=0;i<velicina;i++){
		if(n1[i]!=n2[i]){
			jednak=0;break;
		}
	}
	return jednak;
}

void f3(int mat[200][200],int brr,int brk,int m){
	int i,j;
	for(i=m;i<brr-1;i++){
		for(j=0;j<brk;j++){
			mat[i][j]=mat[i+1][j];
		}
	}
}

void f4(int mat[200][200],int*niz,int velicina,int n){
	int i;
	for(i=0;i<velicina;i++){
		niz[i]=mat[i][n];
	}
}

void f5(int mat[200][200],int brr,int brk,int n){
	
	int i,j;
	for(i=0;i<brr;i++){
		for(j=n;j<brk-1;j++){
			mat[i][j]=mat[i][j+1];
		}
	}
}


int main() {
	int M,N,i,j;
	int r[200]={0};
	int k[200]={0};
	int mat[200][200];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&M,&N);
		if(M<=0 || M>200 || N<=0 || N>200){printf("Brojevi nisu u trazenom opsegu.\n");}
	}while(M<=0 || M>200 || N<=0 || N>200);
	
	printf("Unesite elemente matrice: ");
    for(i=0;i<M;i++){
    	for(j=0;j<N;j++){
    		scanf("%d",&mat[i][j]);
    	}
    }
    
    for(i=0;i<M;i++){
    	for(j=0;j<M;j++){
    		if(i==j)continue;
    		else{ 
    			f1(mat,r,N,i);
    			f1(mat,k,N,j);
    			if(f2(r,k,N)==1){
    				f3(mat,M,N,j);
    				j--;M--;
    			}
    			
    			
    		}
    	}
    }
    
    for(i=0;i<N;i++){
    	for(j=0;j<N;j++){
    		if(i==j)continue;
    		else{
    			f4(mat,r,M,i);
    			f4(mat,k,M,j);
    			if(f2(r,k,M)==1){
    				f5(mat,M,N,j);
    				j--;N--;
    			}
    			
    		}
    	}
    }
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    
    for(i=0;i<M;i++){
    	for(j=0;j<N;j++){
    		if(mat[i][j]>=0 && mat[i][j]<=9){
    		printf("    %d",mat[i][j]);}
    		else{
    			printf("   %d",mat[i][j]);
    		}
    	}
    	printf("\n");
    }
	return 0;
}
