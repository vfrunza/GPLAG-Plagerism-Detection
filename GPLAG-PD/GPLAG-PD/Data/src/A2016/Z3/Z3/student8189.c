#include <stdio.h>
#define A 201
#define B 201
int main ()
{ int M,N,i,j,k,g,h,p,r,s,t,l;
  int mat[A][B];
/*Unosimo matricu tako da osiguramo da ce biti u datom opsegu sa do-while petljom. */
    do {
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&M,&N);
        if(M>200 || M<1 || N>200 || N<1)  
        printf("Brojevi nisu u trazenom opsegu.\n");
    } while(M>200 || M<1 || N>200 || N<1);
    
    printf("Unesite elemente matrice: ");
     for(i=0;i<M;i++){
        for(j=0;j<N;j++){
        scanf("%d",&mat[i][j]);
    }
 }  
 /*Ako je broj redova veci od jedan onda je potrebno izbacivanje dok ako ima jedan red nije.*/
         if(M>1){
       for(i=0;i<=M-1;i++){ /*i ide kroz redove.*/
        int brojkolona=N;
   
        for(j=i+1;j<=M-1;j++){ /*j takodjer kroz redove tako da uporedjuje drugi red sa prvim.*/
            int provjera=1; /*Postavljamo logicku varijablu provjera na 1 tako da kada naidje na razlicite redove onda ce postati 0.*/
            
            for(k=0;k<=brojkolona-1;k++){
                int red=i;
                int reddrugi=j;
                int kolona=k;
                
             if(mat[red][kolona]!=mat[reddrugi][kolona])  provjera=0;
            }

         if(provjera==1){ /* A ako je ipak logicka varijabla provjera 1 onda su redovi isti pa ih treba izbaciti tako da opet kroz dvije for petlje vrsimo provjeru izbacivanja.*/
         for(g=j;g<M-1;g++){
         for(h=0;h<brojkolona;h++){
             int red=g;
             int kolona=h;
             int sljedecired=red+1;
       
         mat[red][kolona]=mat[sljedecired][kolona];
                  }
              }
              if(M>1){
               M--;
               j--;
             }
             
         }
      }
   }
}
/*Analogno prethodnom sta smo ucinili za redove to ucinimo za kolone.*/
   if(N>1){
       int brojredova=M;
   
   for(p=0;p<=N-1;p++){
      for(r=p+1;r<=N-1;r++){
             int  provjera=1;
             for(s=0;s<=brojredova-1;s++){
                 int red=s;
                 int kolona=p;
                 int drugakolona=r;
                if(mat[red][kolona]!=mat[red][drugakolona]) provjera=0;
             }
                
        if(provjera==1) {
        for(t=r;t<N-1;t++){
            for(l=0;l<brojredova;l++){
                mat[l][t]=mat[l][t+1];
                   } 
                }   
                if(N>1){
                N--;
                r--;
                }
        }
     }
  }       
}
 printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
 for(i=0;i<M;i++){ 
     for(j=0;j<N;j++){ 
         printf("%5d",mat[i][j]);
      }    
     printf("\n");
 }

    return 0;
}
    
    
    
    
    
    
    
