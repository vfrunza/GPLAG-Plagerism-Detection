#include <stdio.h>

int main() {
	int m,n,i,j,k,a=0,istired=1,istakolona=1;
	int mat[200][200];
	printf("Unesite brojeve M i N: ");
	do {
		scanf("%d",&m);
		scanf("%d",&n);
		if(m<=0 || m>200 || n<=0 || n>200) {
			       printf("Brojevi nisu u trazenom opsegu.\n");
			       printf("Unesite brojeve M i N: ");
		}
	   
	}while (m<=0 || m>200 || n<=0 || n>200);
	

	printf("Unesite elemente matrice: ");
	
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf("%d",&mat[i][j]);
		}
	}
	
	for(i=0;i<m;i++) {
		
		for(j=0;j<m;j++) {
			     istired=1;
		    	for(k=0;k<n;k++) {
				   if(mat[i][k]!=mat[j][k] || i==j ) { istired=0;  break; } 
				   else   a=j;   
		       	}
			if(istired==1) { 
				for(j=a;j<m-1;j++) {
					for(k=0;k<n;k++) 
						mat[j][k]=mat[j+1][k];
				}
			m--;
			j=a;
		    }
			
	    }
	    
	}
	
	
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			istakolona=1;
			for(k=0;k<m;k++) {
				if(mat[k][j]!=mat[k][i] || i==j) { istakolona=0; break; }
				else{ a=j; break; }
			}
		    if(istakolona==1) {
			     for(j=a;j<n-1;j++) {
				      for(k=0;k<m;k++) 
				         mat[k][j]=mat[k][j+1];
		    	 }
			n--;
			j=a;
	    	}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	
	
	
	return 0;
}
