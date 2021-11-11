#include <stdio.h>



int main(){
    
    int i,j,k,l,S,o;
    int mat[200][200];
    int m,n;
    int istina=1;
    int p=0;
    i=0;
    j=0;
    k=0;
do{printf("Unesite brojeve M i N: " );
    scanf("%d",&m);
    scanf("%d",&n);
    if(m<=0||n<=0||m>200||n>200){
        printf("Brojevi nisu u trazenom opsegu.\n");
        continue;}
    else p=1;
}while(p!=1);
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        scanf("%d",&mat[i][j]);
    }}
    
for(i=0;i<m-1;i++){
    istina=1;
    k=i+1;
    l=0;
    for(j=0;j<n;j++){
  while(k<m){
      
      istina=1;
        while(l<n){
            if(mat[i][j]==mat[k][l]){
                istina=1;
            }else{
                istina=0;
                break;
            }
             j++;
                l++;
        }
      if(istina==1){
          break;
      }else{
          k++;
          j=0;
      }
  }
            
        
        if(istina==1){
           
            break;
            
        }
       
            
        }
         if(istina==1){
            for(S=k;S<m-1;S++){
                for(o=0;o<n;o++){
                    mat[S][o]=mat[S+1][o];
                }
                
              
                
                 
                
            }
            i--;
            m--;
            
            
    }
}

for(i=0;i<n-1;i++){
    istina=1;
    for(k=i+1;k<n;k++){
        istina=1;
        for(j=0;j<m;j++){
            if(mat[j][i]==mat[j][k]){
                istina=1;
            }
            else{
                istina=0;
                break;
            }
        }
        if(istina==1){
            for(S=k;S<n-1;S++){
for(o=0;o<m;o++){
    mat[o][S]=mat[o][S+1];
}      


            }
            k--;
n--;
        }
    }
}

printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
for(i=0;i<m;i++){
   
    for(j=0;j<n;j++){
        
        printf("%5.d",mat[i][j]);
    }
    printf("\n");
}
    return 0;
}