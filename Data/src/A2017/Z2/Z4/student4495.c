#include <stdio.h>

int main (void)
{
    
    int m=0, n=0;
    int i , j;
    do
    {
        printf ("Unesite brojeve M i N: ");
        scanf ("%d", &m);
        scanf ("%d", &n);
   
   
    } while (m<0 || m>100 || n<0 || n>100 );
    
    int A[100][100];
     int B[100][100];
      int C[100][100];
      
      
      printf ("Unesite clanove matrice A: ");
      for (i=0; i<m ; i++)
      {
          for (j=0; j<n ; j++)
          {
              scanf ("%d", &A[i][j]);
          }
      }
       printf ("Unesite clanove matrice B: ");
      for (i=0; i<m ; i++)
      {
          for (j=0; j<n ; j++)
          {
              scanf ("%d", &B[i][j]);
          }
      }
       printf ("Unesite clanove matrice C: ");
      for (i=0; i<m ; i++)
      {
          for (j=0; j<n ; j++)
          {
              scanf ("%d", &C[i][j]);
          }
      }
      
      
       int nizA[10000];
     int nizB[10000];
      int nizC[10000];
      
      int brojac= 0;
      
        for (i=0; i<m ; i++)
      {
          for (j=0; j<n ; j++)
          {
             nizA[brojac++]=A[i][j];
          }
      }
      brojac=0;
      
       for (i=0; i<m ; i++)
      {
          for (j=0; j<n ; j++)
          {
             nizB[brojac++]=B[i][j];
          }
      }
      brojac=0;
      
       for (i=0; i<m ; i++)
      {
          for (j=0; j<n ; j++)
          {
             nizC[brojac++]=C[i][j];
          }
      }
     
     
     
     
     
     for (i=0; i<brojac; i++)
     {
         int min=i;
         for (j=i+1; j<brojac ; j++)
         {
             if(nizA[j]<nizA[min])
             min=j;
         }
         
     
     
     if (i!=min)
     {
        int temp= nizA[i];
        nizA[i]= nizA[min];
        nizA[min]=temp;
     }
}
         
      for (i=0; i<brojac; i++)
     {
         int min=i;
         for (j=i+1; j<brojac ; j++)
         {
             if(nizB[j]<nizB[min])
             min=j;
         }
         
     
     
     if (i!=min)
     {
        int temp= nizB[i];
        nizB[i]= nizB[min];
        nizB[min]=temp;
     }
}    
       for (i=0; i<brojac; i++)
     {
         int min=i;
         for (j=i+1; j<brojac ; j++)
         {
             if(nizC[j]<nizC[min])
             min=j;
         }
         
     
     
     if (i!=min)
     {
        int temp= nizC[i];
        nizC[i]= nizC[min];
        nizC[min]=temp;
     }
}   
         
         
     for (i=0; i<brojac; i++)
     if (nizA[i]!= nizB[i] || nizA[i]!= nizC[i])
         {
             printf ("NE");
             return 0;
         }
         
        printf ("DA");
        return 0;
         
         
     }
     
     
     
     
     
     
     
     
     
     
     
     
     
    