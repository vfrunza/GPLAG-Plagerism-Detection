#include <stdio.h>
#define VEL 100
#define VEL1 1000

int prebroji_cifre(int x){
    int brojac=0;
    if(x==0) return 1;
    while(x>0){
        brojac++;
        x/=10;
    }
    return brojac;
}

int izbroj_clan(int x, int niz[], int vel, int index_clana){
    
    
    int i=0, brojac=0;
    
    if(index_clana==vel-1) return 1;
    
    while(niz[i]!='\n' && niz[index_clana+i] == x ) {
        
                brojac++;
                
                
                i++;
               if(i==vel-1){ brojac++; return brojac; }
            
            }
   
            return brojac;
}
    
    int main () {
        
        int C[VEL], i=0, n, A[VEL1], sumacif=0;
        
        do{
            printf("Unesite velicinu niza: ");
            scanf("%d", &n);
        } while(n<=0 || n>100);
        

        
        printf("Unesite clanove niza: ");
        for(i=0; i<n; i++){
        scanf("%d", &C[i]);
        sumacif+=prebroji_cifre(C[i]);
        
        }
        
        int j=prebroji_cifre(C[0]);
        
        int dokle_je_dosao=0;
        
        for(i=0; i<n; i++) {
            
            dokle_je_dosao+=prebroji_cifre(C[i]);
            j=dokle_je_dosao;
            while((C[i]>0) &&(j>=0)) {
                A[--j]=C[i]%10;
                C[i]/=10;
            }
            A[sumacif]='\n';
        }
        
         
       
      
        
        
        printf("Finalni niz glasi:\n");
        
        for(i=0; i<sumacif; i++){
            
            printf("%d ", A[i]);
         
            int x=izbroj_clan(A[i], A, sumacif, i);
            printf("%d ", x);
            
            i+=(x-1);
          
            
            
        }
        
        
        
        
        
        return 0;
        
    }
        
        
        
        
        
        
        
        
        
        
        