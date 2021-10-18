#include <stdio.h>
 

int broj_ponavljanja_clana(int m, int matrica[100][100], int visina, int sirina){
   int broj=0;
    int i,j;
    for(i=0; i<visina; i++){
        for(j=0; j<sirina; j++){ 
          if(m==matrica[i][j])  
          {
             broj++;
          }
        }
    }
return broj;
} 

int max(int A[100][100], int visina, int sirina){ 
   int i,j,matricabrojaca[100][100],matSaNajvisePonavljanja[100][100];
   for(i=0;i<visina;i++){
       for(j=0;j<sirina;j++){
           matricabrojaca[i][j]=0;
       }
   }
   for(i=0;i<visina;i++){
       for(j=0;j<sirina;j++){
           matricabrojaca[i][j]=broj_ponavljanja_clana(A[i][j],A,visina,sirina);
       }
   }
   int max_brojac=matricabrojaca[0][0];
   for(i=0;i<visina;i++){
       for(j=0;j<sirina;j++){
         if( matricabrojaca[i][j]>max_brojac) max_brojac=matricabrojaca[i][j];
       }
   }
   for(i=0;i<visina;i++){
       for(j=0;j<sirina;j++){
           matSaNajvisePonavljanja[i][j]=0;
       }
   } 
   for(i=0;i<visina;i++){
       for(j=0;j<sirina;j++){
         if( matricabrojaca[i][j]==max_brojac) matSaNajvisePonavljanja[i][j]=1;
       }
   }
 int minimumMaksimuma;
 int min;
   for(i=0;i<visina;i++){
       for(j=0;j<sirina;j++){
           if(matSaNajvisePonavljanja[i][j]==1 )
           { 
               minimumMaksimuma=matSaNajvisePonavljanja[i][j];
             min=A[i][j];
             break;}
          
       }
   }
   for(i=0;i<visina;i++){
       for(j=0;j<sirina;j++){
       
   
			if(matSaNajvisePonavljanja[i][j]==1 && A[i][j]<min) min=A[i][j];
		}}
		

   
   return min;
} 

int izbaci_kolone(int matrica[100][100], int visina,int sirina,int N) { 
    int i, j;
    for(i=0; i<visina; i++) 
    {
        for(j=0; j<sirina; j++) 
        {
            if(matrica[i][j]==N)
            {
                int k,h;
                for(k=0; k<visina; k++)
                { 
                    for (h=j; h<sirina; h++)
                    {
                        matrica[k][h] = matrica[k][h+1]; 
                    }
                } 
                if(sirina>0){
                sirina--;
            } else return 0;
                
            }
            
    }
    }
    return sirina;
    
}



int main() {
    
    int sirina, visina, i, j=0, N, kolona, k=0;
    int mat[100][100];
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d", &sirina, &visina);
    
   while(k<visina) {
   printf("Unesite elemente %d. reda: ", k+1);
    
    for(i=0;i<sirina; i++){
          scanf("%d", &mat[i][j]);
    }
    
    k++; j++;
   }
   
 N=max(mat, visina, sirina);
 kolona=izbaci_kolone(mat, visina, sirina, N);
  
  for(i=0;i<visina; i++){
      for(j=0; j<sirina; j++){
          
          printf("%d ", mat[i][j]);
      } printf("\n");
  }
return 0;}




















