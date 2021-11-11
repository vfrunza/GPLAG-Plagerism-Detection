#include <stdio.h>
#define VISINA 200
#define SIRINA 200



int main()
    {
    int M=0, N=0, i=0, j=0, x=1,  k=0, isti=0;
    int kolona_za_izb=0, red_za_izb=0;
    int mat[200][200];
    int izbacena=0;
    
    
    do{
      printf("Unesite brojeve M i N: ");
      scanf("%d %d", &M, &N);
      if(M>200 || N>200 || N<0 || M<0)
      printf("Brojevi nisu u trazenom opsegu.\n");
      
    } while(M>200 || N>200 || N<0 || M<0);
    
    printf("Unesite elemente matrice:\n");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
          scanf("%d", &mat[i][j]); 
        }
    }
    
    
    /*
    
for(i=1; i<=M; i++){
    if (isti==1)
    break;
    for(j=1; j<=N; j++){
        
        for(k=1;k<M-i; k++){
         if(mat[i][j] !=  mat[i+k][j] ) 
         isti=0;
         else {
         isti=1;
         k--;
         j++;}
        }
    if(j==N)
    red_za_izb=i+k;
        
    }}
 */
 
    
    red_za_izb=3;
   
for(i=1; i<=M; i++){

    if(red_za_izb == M){
      M--;
      break;}
   for(j=1; j<=N; j++){
       
    mat[red_za_izb][j]=mat[red_za_izb+1][j];  
}

red_za_izb++;
}  
   printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
          printf("%5d", mat[i][j]); 
        }
        printf("\n");
    }
    
    return 0;
} 



/*#include <stdio.h>
#define VISINA 200
#define SIRINA 200


int main()
    {
    int M, N, i, j;
    int mat[200][200];
    
    do{
      printf("Unesite brojeve M i N: ");
      scanf("%d %d", &M, &N);
      if(M>200 || N>200 || N<0 || M<0)
      printf("Brojevi nisu u trazenom opsegu.\n");
      
    } while(M>200 || N>200 || N<0 || M<0);
    
    printf("Unesite elemente matrice:\n");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
          scanf("%d", &mat[i][j]); 
        }
    }
    
    int red_za_izb;
    
   for(i=0; i<M; i++){
       int m=1;
        for(j=0; j<N; j++){
           if (mat[i][j] != mat[i+m][j]){
               m++;
           break;
           }
          red_za_izb=m;
        }
   }
    
    printf("%d", red_za_izb);
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
          printf("%5d", &mat[i][j]); 
        }
        printf("\n");
    }
    
    return 0;
} 
#include <stdio.h>
#define BROJ_ELE 500


int main(){
    
    int f=0,i,k;
    int niz[]={22,31,43,62,12};
    int niz2[]={4,4,7,8,3};

    int vel=5;

int g=vel;
int l, j=0;

for(l=0; l<vel; l++){
    int m=vel;
	for(k=1; k<vel-l; k++){
		niz[m] = niz[m - 1];
		m--;
		for(i=0; i<10; i++){
	printf("%d, ", niz[i]);
	
}	
printf("\n");
	}
	niz[m+2]=niz2[j];
	j++;
	vel++;
		for(i=0; i<10; i++){
	printf("%d, ", niz[i]);}
	
}
	
//	niz[m]=niz2[f];
//	f++;
	
	


printf("\n");
	
	for(i=0; i<5; i++){
	printf("%d, ", niz2[i]);
}	 
	return 0;
}

*/