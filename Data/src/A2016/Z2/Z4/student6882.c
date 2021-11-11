#include <stdio.h>
#include <stdlib.h>


int main() {

    int m,n,i,j,k;
    double A[100][100];
    int teplicova=1;
    int cirkularna=1;
    double pom,zadnji;
    int a;
    do{
        printf ("Unesite M i N: ");
        scanf("%d %d",&m,&n);
        if (m<=0 || n<=0 || n>100 || m>100)
		{
				printf ("Pogresan unos!\n");
				continue;
		}
		else break;

    }while(1);

    printf ("Unesite elemente matrice: ");
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            scanf("%lf",&A[i][j]); 
        }
    }

    if(m==1 && n==1) {
        printf("Matrica je cirkularna");
        return 0; 
    }
    /* teplicova */
    /* prolaz kroz matricu */
    k=0;
    i=0;
    for(j=0;j<n;j++) {
            /* glavna i iznad */
                if(j==(i+k)){
                    a=1;
                    pom=A[i][j];
                    while(a<=n-1){
                    if( ((i+a)>(m-1)) || ((j+a)>(n-1)) ) break;
                    if(pom != (A[i+a][j+a])) {
                    teplicova=0;
                    break;
                   }
                   a++; 
                }
                }
            k++; 
            if(k> n-1) break;
            if(teplicova==0) break;
            }
            
     /* ispod */
     k=1;
     j=0;
       for(i=1;i<m;i++) {
                if(i==j+k){
                    a=1;
                    pom=A[i][j];
                    while(a<=m-1){
                    if( ((i+a)>(m-1)) || ((j+a)>(n-1))) break;
                    if(pom != A[i+a][j+a]) {
                    teplicova=0;
                   }
                   a++;
                }
                }
                k++;
            if( k> m-1 ) break;
            if(teplicova==0) break;
        }
    

    /* cirkularna */
     for (i=0;i<m-1;i++){
         zadnji=A[i][n-1];
         if(A[i+1][0] != zadnji){
             cirkularna=0;
         }  /* provjera prvog i zadnjeg */

        
 	    for (j=0;j<n-1;j++){
 	        if(A[i+1][j+1] != A[i][j]){
 	           cirkularna=0; 
 	        } 
 	   	  
 	    }
    } 
  
    /* ispis */
    if (teplicova==1 && cirkularna==0)
    {
        printf ("Matrica je Teplicova");
    }
    if (cirkularna)
    {
        printf ("Matrica je cirkularna");
    }
    if (teplicova==0 && cirkularna==0)
    {printf ("Matrica nije ni cirkularna ni Teplicova");
    }

return 0;
            
        }


