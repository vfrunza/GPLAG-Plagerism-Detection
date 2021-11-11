#include <stdio.h>

int main() {
	int m,n,i,j,k,l,o,a,mat[200][200];
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&m,&n);
        if(m<=0 || m>200 || n<=0 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
        else break;
    }while(1);
    
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    
	for(i=0;i<m-1;i++){
	    for(k=i+1;k<m;k++){
	        a=0;
	        for(j=0;j<n;j++){
	            if(mat[i][j]==mat[k][j]) a++;
	        }
	            if(a==n) {
	            	
	            	for(l=k;l<m-1;l++){
	            		for(o=0;o<n;o++){
	                mat[l][o]=mat[l+1][o];
	               }
	            	}
	            m--;
	            k--;
	    }
	   }
	            
	    }
	    
	    
		for(i=0;i<n-1;i++){
	    for(k=i+1;k<n;k++){
	        a=0;
	        for(j=0;j<m;j++){
	            if(mat[j][i]==mat[j][k]) a++;
	        }
	            if(a==m) {
	            	
	            	for(l=k;l<m-1;l++){
	            		for(o=0;o<n;o++){
	                mat[o][l]=mat[o][l+1];
	               }
	            	}
	            n--;
	            k--;
	    }
	   }
	            
	    }
	  
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++){
	     for(j=0;j<n;j++){
	         printf("%5d",mat[i][j]);
	     }
	     printf("\n");
	  }
	return 0;
}
