#include <stdio.h>

int main() 
{
   int m, n, k, x, y, i, j, h, l, cirk, tep;
   double mat[100][100];
  
   k=0;
   cirk=0;
   tep=0;
   while (k==0)
   {
     printf ("Unesite M i N: ");
     scanf ("%d %d", &m, &n);
     if (m>100 || m<=0 || n>100 || n<=0)
     {
        printf ("Pogresan unos!\n");
     }
     else 
     {k=-1;}
   }
   
   printf ("Unesite elemente matrice: ");
   for (i=0; i<m; i++)
   {
      for (j=0; j<n; j++)
      {
         scanf ("%lf", &mat[i][j]);
      }
   }
   
   for (x=0; x<(m-1); x++)
   {
      for (y=0; y<(n-1); y++)
      {
         
         if (mat[x][y]==mat[x+1][y+1])
         {
            tep=1;
         }
         
         else
         {
            tep=0;
            y=n-2;
            x=m-2;
         }
         
      }
   }
   
  
   for (h=0; h<(m-1); h++)
   {
      
      for (l=0; l<(n-1); l++)
      {
       
         if (tep==1 && mat[h][n-1]==mat[h+1][0])
         {
            cirk=1;
         }
         
         else
         {
            cirk=0;
            l=n-2;
            h=m-2;
         }
       
      }
     
   }
   
   
   
   if (cirk==1)
   {
      printf ("Matrica je cirkularna");
   }
   
   else if (tep==1)
   {
      printf ("Matrica je Teplicova");
   }
   
   if (m==1 && n==1)
   {
      printf ("Matrica je cirkularna");
   }
   
   else if (m==1)
   {
      printf ("Matrica je cirkularna");
   }
   
   else if (n==1)
   {
      printf ("Matrica je Teplicova");
   }
   
   else if (tep==0 && cirk==0)
   {
      printf ("Matrica nije ni cirkularna ni Teplicova");
   }
   

	return 0;
}
