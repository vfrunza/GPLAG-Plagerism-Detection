#include <stdio.h>

int main() 

{  int M=0, N=0,i=0, j=0,tacno=0,mina=123456789, minb=123456789,minc=123456789,tempa=0,tempb=0,tempc=0, A[100]={0}, B[100]={0}, C[100]={0} ;

		do { 
			 printf ("Unesite brojeve M i N: ");
			 scanf("%d %d", &M, &N);
	       }	 
	    while (M<0 || N<0 || M>100 || N>100);
	    
	    
	    
	    printf ("Unesite clanove matrice A: ");

                 for (i=0; i<M*N; i++)  
                   {  scanf ("%d", &A[i]); }
        printf ("Unesite clanove matrice B: ");
                 for (i=0; i<M*N; i++)  
                    { scanf ("%d", &B[i]); }
	    printf ("Unesite clanove matrice C: ");
                 for (i=0; i<M*N; i++)  
                   { scanf ("%d", &C[i]); }
                   
                   
        for (i=0; i<M*N; i++) {
           mina=i;
        for (j=i+1; j<M*N; j++)
        {
            if (A[j] < A[mina])
            mina = j;
            }
        tempa = A[i];
        A[i] = A[mina];
        A[mina] = tempa;
         }            
                   
                   
                   
      for (i=0; i<M*N; i++) {
           minb=i;
        for (j=i+1; j<M*N; j++)
        {
            if (B[j] < B[minb])
            minb = j;
            }
        tempb = B[i];
        B[i] = B[minb];
        B[minb] = tempb;
         }            
                       
                   
                   
       for (i=0; i<M*N; i++) {
           minc=i;
        for (j=i+1; j<M*N; j++)
        {
            if (C[j] < C[minc])
            minc = j;
            }
        tempc = C[i];
        C[i] = C[minc];
        C[minc] = tempc;
         }
                       
              
                   

    if (M==0 && N==0) printf ("DA\n");
    else
   
   { for (i=0; i<M*N; i++)
      
       {
           if (A[i]==B[i] && A[i]==C[i]) tacno=1;
           else {printf ("NE\n"); return 1; }
       }
    if (tacno==1) printf ("DA\n");
    // else printf ("NE\n");
   }  
        
    return 0;
}