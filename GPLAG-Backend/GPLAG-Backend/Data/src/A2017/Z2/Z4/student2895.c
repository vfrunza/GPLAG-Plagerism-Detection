/*#include <stdio.h>

int main() {
 
 int i,j,g,h,matA[100][100], matB[100][100], matC[100][100],M,N,temp,min;
 do{
 printf("Unesite brojeve M i N: ");
 scanf("%d%d",&M,&N);
 }
 while(M<0 || M>100 || N<0 || N>100);
 
 printf("Unesite clanove matrice A: ");
 for(i=0; i<M; i++){
  for(j=0; j<N; j++){
   scanf("%d", &matA[i][j]);
  }
 }
  printf("Unesite clanove matrice B: ");
  for(i=0; i<M; i++){
  for(j=0; j<N; j++){
   scanf("%d", &matB[i][j]);
  }
 }
 printf("Unesite clanove matrice C: ");
 for(i=0; i<M; i++){
  for(j=0; j<N; j++){
   scanf("%d", &matC[i][j]);
  }
 }
 for(i=0; i<M; i++){
 for(j=0; j<N; j++){
  min=matA[i][j];
  for(g=0; g<M; g++){
   for(h=0; h<N; h++){
    if (matA[g][h]<min){
     min=matA[g][h];
     temp=matA[g][h];
     matA[g][h]=matA[i][j];
     matA[i][j]=temp;
    }
   }
  }
 }
 }
  for(i=0; i<M; i++){
 for(j=0; j<N; j++){
  min=matB[i][j];
  for(g=0; g<M; g++){
   for(h=0; h<N; h++){
    if (matB[g][h]<min){
     min=matB[g][h];
     temp=matB[g][h];
     matB[g][h]=matB[i][j];
     matB[i][j]=temp;
    }
   }
  }
 }
 }
  for(i=0; i<M; i++){
 for(j=0; j<N; j++){
  min=matC[i][j];
  for(g=0; g<M; g++){
   for(h=0; h<N; h++){
    if (matC[g][h]<min){
     min=matC[g][h];
     temp=matC[g][h];
     matC[g][h]=matC[i][j];
     matC[i][j]=temp;
    }
   }
  }
 }
 }
 for(i=0; i<M; i++){
  for(j=0; j<N; j++){
   if(matA[i][j]!=matB[i][j] || matA[i][j]!=matC[i][j] ){
   printf("NE");
   return 0;
  }
  }
 }
      printf("DA");
	return 0;
}*/
/*#include <stdio.h>
//OVDJE JE URADJENA VARIJANTA ZADATKA KAO SA ZADACE, ZA SLUCAJ DA ELEMENTI MATRICE MOGU BITI SAMO POZITIVNI BROJEVI
int main(){
      
 int i,j,g,h,matA[100][100], matB[100][100], matC[100][100],M,N,temp,min;
 do{
 printf("Unesite brojeve M i N: ");
 scanf("%d%d",&M,&N);
 }
 while(M<0 || M>100 || N<0 || N>100);
 
 printf("Unesite clanove matrice A: ");
 for(i=0; i<M; i++){
  for(j=0; j<N; j++){
   scanf("%d", &matA[i][j]);
  }
 }
  printf("Unesite clanove matrice B: ");
  for(i=0; i<M; i++){
  for(j=0; j<N; j++){
   scanf("%d", &matB[i][j]);
  }
 }
 printf("Unesite clanove matrice C: ");
 for(i=0; i<M; i++){
  for(j=0; j<N; j++){
   scanf("%d", &matC[i][j]);
  }
 }
 
 int brojaciA[10000]= {}, brojaciB[10000] = {}, brojaciC[10000] = {};
 
 for(i = 0; i < M; i++){
  for(j = 0; j < N; j++){
   brojaciA[matA[i][j]]++;
  }
 }
 
  for(i = 0; i < M; i++){
  for(j = 0; j < N; j++){
   brojaciB[matB[i][j]]++;
  }
 }
  for(i = 0; i < M; i++){
  for(j = 0; j < N; j++){
   brojaciC[matC[i][j]]++;
  }
 }
 int jednakeBA = 1, jednakeCA = 1;
 for(i = 0; i < 10000; i++){
  if(brojaciA[i] != brojaciB[i]) {
   jednakeBA = 0; 
   break;
  }
 }
  
   for(i = 0; i < 10000; i++){
  if(brojaciA[i] != brojaciC[i]) {
   jednakeCA = 0; 
   break;
  }
 }
 
 if(jednakeCA == 0 || jednakeBA == 0) printf("NE");
 else
 printf("DA");

 return 0;
}*/
#include <stdio.h>

int main(){
 
 int matA[100][100], matB[100][100], matC[100][100];
 int i, j, k, M , M
 
 do{
  printf("Unesite brojeve M i N: ");
  scanf("%d %d", &M, &N);
 }while(M <= 0 || M > 100 || N <= 0 || N > 100);
 
 printf("Unesite clanove matrice A: ");
 for(i = 0 ; i < M; i++){
  for(j = 0; j < N; j++){
   scanf("%d", &matA[i][j]);
  }
 }
 
 printf("Unesite clanove matrice B: ");
 for(i = 0 ; i < M; i++){
  for(j = 0; j < N; j++){
   scanf("%d", &matB[i][j]);
  }
 }
 printf("Unesite clanove matrice C: ");
 for(i = 0 ; i < M; i++){
  for(j = 0; j < N; j++){
   scanf("%d", &matC[i][j]);
  }
 }
 
 int min, tmp, k, l;
 for(i = 0; i < M; i++){
  for(j = 0; j < M; j++){
   min = matA[i][j];
   for(k = 0; k < M; k++){
    for(l = 0; l < N; l++){
     if(matA[k][l] < min){
      min = matA[k][l];
      temp = matA[k][l];
      matA[k][l] = mat[i][j];
      matA[i][j] = temp;
     }
    }
   }
  }
 }
 
 
 
 
 return 0;
}