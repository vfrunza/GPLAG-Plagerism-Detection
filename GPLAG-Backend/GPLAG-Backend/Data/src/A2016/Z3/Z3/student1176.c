#include<stdio.h>

int main()
{ 
    int m, n, mat[200][200], i, j, k, p, q, br;
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &m, &n); 
        if(m<1 || n<1 || m>200 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
    }while(m<1 || n<1 || m>200 || n>200);
    printf("Unesite elemente matrice: ");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }  
    i=0;
    if(m==1) goto jednodimenz;
    while(i<m){ 
        
        for(j=i+1; j<m; j++){ 
            br=0;
            for(k=0; k<n; k++){
                if(mat[i][k]!=mat[j][k]) br++;
            } 
            if(br==0){
                for(p=j; p<m-1; p++){
                    for(q=0; q<n; q++){
                        mat[p][q]=mat[p+1][q];
                        
                    }
                } 
                m--; 
                j--;
            }
    }  
    i++;
    }   
    if(m==1) goto jednodimenz;
    j=0;
    while(j<n){ 
        for(i=j+1; i<n; i++){
            br=0; 
            for(k=0; k<m; k++){
                if(mat[k][j]!=mat[k][i]) br++;
            } 
            if(br==0){
                for(p=i; p<n-1; p++){
                    for(q=0; q<m; q++){
                        mat[p][q]=mat[p][q+1];
                    }
                } 
                n--; 
                i--;
            }
        } 
        j++;
    }
    jednodimenz:
    if(m==1) {
        for(i=0; i<n-2; i++){
            for(j=i+1;j<n-1;j++){
                if(mat[0][i]==mat[0][j]){
                    for(k=j; k<n; k++){
                        mat[0][k]=mat[0][k+1];
                    }
                    n--;
                    i--;
                }
            }
        }
        
    }
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%5d", mat[i][j]);
        } 
        printf("\n");
    } 
    return 0;
}