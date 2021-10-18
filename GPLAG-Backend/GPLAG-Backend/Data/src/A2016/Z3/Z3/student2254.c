#include <stdio.h>
//zadaća 3 zadatak 3
int main(){
    int vrsta,kolona,matrica[200][200];
    int i,j,k,f;
    int jeIsto=1;
    
    do{
        printf("\nUnesite brojeve M i N: ");
        scanf("%d%d",&vrsta,&kolona);
        
        if(vrsta < 1 || kolona < 1 || kolona > 200 || vrsta > 200)
            printf("Brojevi nisu u trazenom opsegu.");
        
    }while(vrsta < 1 || kolona < 1 || vrsta > 200 || kolona > 200);
    
    printf("Unesite elemente matrice: ");
    
    for(i=0; i<vrsta; i++)
        for(j=0; j<kolona; j++)
            scanf("%d", &matrica[i][j]);

//Izbacivanje ponavljajućih vrsta            
    for(i=0; i<vrsta-2; i++)
        for(j=vrsta-1; j>=i; j--){
            if(jeIsto==1 && j==vrsta-2){
               vrsta--;
               j++;
            }
               
            else if (jeIsto==1 && j<vrsta-2){
                for(f=j+1; f<vrsta-1; f++)    
                    for(k=0; k<kolona; k++)
                        matrica[f][k]=matrica[f+1][k];
            vrsta--;
            j++;
            }
                    
            jeIsto = 1;
            for(k=0; k<kolona; k++)
                if(matrica[i][k]!=matrica[j][k])
                    jeIsto = 0;
        }
        
//Kraj izbacivanja vrsta

    jeIsto=1;

//Izbacivanje ponavljajućih kolona
    for(i=0; i<kolona-2; i++)
        for(j=kolona-1; j>=i; j--){
           if(jeIsto==1 && j==kolona-2){
               kolona--;
               j++;
           }
               
            else if (jeIsto==1 && j<kolona-2){
                for(f=j+1; f<kolona-1; f++)    
                    for(k=0; k<vrsta; k++)
                        matrica[k][f]=matrica[k][f+1];
            kolona--;
            j++;
            }
           
            jeIsto = 1;
            for(k=0; k<vrsta; k++)
                if(matrica[k][i]!=matrica[k][j])
                    jeIsto = 0;
        }
//kraj izbacivanja kolona

    printf("Nakon izbacivanja redova/kolona matrica glasi:");
    for(i=0; i<vrsta; i++){
        printf("\n");
        for(j=0; j<kolona; j++){
            if(matrica[i][j] < 0)
                printf("   %d",matrica[i][j]);
                
            else if (matrica[i][j] >= 10)
                printf("   %d", matrica[i][j]);
                
            else if (matrica[i][j] >= 100)
                printf("  %d", matrica[i][j]);
                
            else
                 printf("    %d", matrica[i][j]);
        }
        
}

    
        
        return 0;
}