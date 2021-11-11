#include <stdio.h>
      
      int daj_prost(){
          static int S=1;
          int pro,n,m;
          for (n=S+1;  ; n++){
              pro=1;
              for (m=n/2; m>1; m--) {
                  
              if (n%m==0){ pro=0;
              break;}
          }
          
          if (pro==1) {S=n; break;}
          }
          
          return S;
      }
      
int main() {
    int A,B,s,O,i;
    s=0;
      do {
      printf("Unesite brojeve A i B: ");
      scanf("%d %d", &A,&B);
      if (A<1) printf("A nije prirodan broj.\n");
      if (A>=B) printf("A nije manje od B.\n");
     }
       while(((A<1)||(B<1)) || (A>=B));
       
       for (i=0; i<B; i++){
           O=daj_prost();
              if (O<B && O>A){ s=s+O; }  
       }
     
       
    printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,s);
	return 0;
}
