#include <stdio.h>
#include <math.h>
#define E 0.00000001

int main() {
	int i,j,k,m,n,kruzna=1,T=1,temp,brojac,tmp;
	double mat[100][100],ispit[100][200];
	do {
	    printf("Unesite M i N: ");
	    scanf("%d %d",&m,&n);
	    if(m<1 || m>100 || n<1 ||n>100)printf("Pogresan unos!\n");
	}while(m<1 || m>100 || n<1 || n>100);
	printf("Unesite elemente matrice: ");
    for( i=0;i<m;i++){
    for(j=0;j<n;j++)
    scanf("%lf",&mat[i][j]);}
	for(  i=0;i<m;i++){
	    for(j=0;j<n;j++)
	    ispit[i][j]=mat[i][j];
	    for(k=n;k<2*n;k++)
	    ispit[i][k]=mat[i][k-n];
	}
	for(i=0;i<m;i++){
    	for(j=0;j<n/2;j++){
	    temp=mat[i][j];
	    mat[i][j]=mat[i][n-1-j];
	    mat[i][n-1-j]=temp;
	    }
	}for(k=0;k<m+n-2;k++){
	    brojac=0;
    	for(i=0;i<m;i++){
    	    for(j=0;j<n;j++){
    	        if(i+j==k && brojac==0){brojac=1; temp=i;tmp=j;continue;}
    	       else if(i+j==k){
    	           if(fabs(mat[i][j]-mat[temp][tmp])>E){T=0;break;}
    	       }
    	    }if(T==0)break;
    	}if(T==0)break;
	}
	for( i=1;i<m;i++){
	    for(j=0;j<2*n-1;j++){
	        if(fabs(ispit[i-1][j]-ispit[i][j+1])>E){kruzna=0;break;}
	    }if(kruzna==0) break;
	}
	if(kruzna==1)printf("Matrica je cirkularna");
	else if(kruzna==0 && T==1)printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
