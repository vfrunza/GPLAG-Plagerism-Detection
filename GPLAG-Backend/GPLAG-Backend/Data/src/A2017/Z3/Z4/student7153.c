#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
    int i,j,k=0;
    int niz[1000];
    int temp, niz1[1000],p=0,brojac=0, maxim, broj;
    
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            niz[k]=matrica[i][j];
            k++;
        }
    }
    
    for(i=0; i<k; i++) {
        for(j=0; j<k; j++) {
            if(niz[i]>niz[j])
            {
                temp=niz[i];
                niz[i]=niz[j];
                niz[j]=temp;
            }
        }
    }
    
    for(i=0; i<k; i++) {

        niz1[p]=niz[i];
        p++;
        
        for(j=i; j<k; j++) {
            
            if(niz[i]==niz[j])
            {
                brojac++;
            }
            else
            {
                niz1[p]=brojac;
                p++;
                break;
            }
           
            
            if(j==k-1)
            {
                niz1[p]=brojac;
                p++;
                break;
            
            }
        }
        i=i+brojac-1;
        brojac=0;
    }
    
    maxim=niz1[1];
    broj=niz[0];
    
    for(i=1; i<p; i=i+2) {
        if(maxim<niz1[i])
        {
            maxim=niz1[i];
            broj=niz1[i-1];
        }
    
    }
    return broj;
}

int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N)
{
    int i,j,k,z, kolone, logicko=0;
    

    
    for(i=0; i<visina; i++) {
        if(sirina==1){
        logicko=1;
        break;}
        
        for(j=0; j<sirina; j++) {
            if(matrica[i][j]==N)
            
            {
                if (j==sirina-1){
                sirina--;
                continue;
                }
                for(k=0; k<visina; k++) {
                    for(z=j; z<sirina-1; z++) {
    

                        matrica[k][z]=matrica[k][z+1];
                    }
                }
                sirina--;
                j--;
            }
        }
    }
    
    if (logicko==0)
    kolone=sirina;
    else kolone=0;
    
   
    
    return kolone;
    
    
    
}

int main() {
    
    int i,j,sirina,visina, a=0, matrica[100][100],N, kolone, b=1;
    
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d", &sirina, &visina);
    
    do
    {
        printf("Unesite elemente %d. reda: ", a+1);
        {
            for(i=0; i<sirina; i++)
            scanf("%d",&matrica[a][i]);
        }
        a++;
    } while(a<visina);
    
    

    do {
       N=max(matrica,visina,sirina);
      kolone= izbaci_kolone(matrica,visina,sirina,N);
       
       if(kolone!=0)
       {
           
           printf("Nakon %d. prolaza matrica glsi:\n",b);
           for(i=0; i<visina; i++) {
               for(j=0; j<kolone; j++) {
                   printf("%d ",matrica[i][j]);
               }
               printf("\n");
           }
           b++;
       }
       
       
       else
       {
           printf("Nakon %d. prolaza matrica je prazna!",b);
       }
       
    }while(kolone>0);
    
    return 0;
    
}












