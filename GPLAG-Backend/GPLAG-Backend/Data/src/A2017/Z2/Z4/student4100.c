#include <stdio.h>
   
int main() {

    int A[100][100],B[100][100],C[100][100];
    int A1[10000],B1[10000],C1[10000];
    int i,j,k,m,n,br1=0,br2=0,br3=0,s;
    
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&m,&n);
        
        if(m<0 || m>100 || n<0 || n>100) continue;
        else break;
    }while(1==1);
    
    printf("Unesite clanove matrice A: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    
    printf("Unesite clanove matrice B: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&B[i][j]);
        }
    }
    
     printf("Unesite clanove matrice C: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&C[i][j]);
        }
    }
     
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            A1[i*n+j]=A[i][j];
        }
    }
 
    
   for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            B1[i*n+j]=B[i][j];
        }
    }
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            C1[i*n+j]=C[i][j];
        }
    }
    
    k=0;
    s=m*n;
    
    while (k<s) {
        
        for(i=0;i<s;i++){
            if(A1[k]==B1[i])br1++;
            }
        for(i=0;i<s;i++){
            if(A1[k]==B1[i])br2++;
        }
        for(i=0;i<s;i++){
            if(A1[k]==C1[i])br3++;
        }
        k++;
        if(br1!=br2 || br1!=br3){
            printf("NE\n");
            return 0;
        }
    }
  
    printf("DA\n");
    
	return 0;
}
