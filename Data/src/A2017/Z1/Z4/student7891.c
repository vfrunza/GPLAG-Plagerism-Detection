#include <stdio.h>

int main()

{   int r, k, s, i, j, z;
     
    
    
        do { printf ("Unesite broj redova: ");
                        scanf ("%d", &r);}   
            while (r<=0 || r>10);
            
       do { printf ("Unesite broj kolona: ");
                        scanf ("%d", &k);}   
            while (k<=0 || k>10);     
           
        do { printf ("Unesite sirinu jedne kolone: ");
                        scanf ("%d", &s);}   
            while (s<=0 || s>10); 
            
            
             for  (i=1; i<=r+1; i++ ) 
             { {  for  (j=1; j<=k; j++ )    
                   {  printf ("+");
               
                            for  (z=1; z<=s; z++ ) printf ("-");
			       }   printf ("+");     
                         printf ("\n"); 
                 }  if (i==r+1) break;
              
               {  for  (j=1; j<=k; j++ )    
                   {  printf ("|");
               
                      for  (z=1; z<=s; z++ ) printf (" ");
			         }       
                  printf ("|");printf ("\n");
                }
               
              }
   
    
		
	return 0;
}

