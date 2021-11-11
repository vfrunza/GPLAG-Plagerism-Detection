#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

int main()
{

 int N=12,i,j,k,m;

 for(i=0;i<N/2;i++)
 {
     for(j=0;j<N/2;j++)
     {
         if(i==j)
         {
            printf("\\");
         }

         else if(i+j==N/2-1)
         {
             printf("/");
         }
         else
         {
             printf(" ");
         }

     }
     if(i==0 || i==N/2-1)
     {
         printf("+");
         for(k=0;k<N/4;k++)
         {
            printf("-");
         }
         printf("+");
     }
     else
     {
         printf("|");
         for(k=0;k<N/4;k++)
         {
             printf(" ");
         }
         printf("|");
     }
     printf("\n");

     }
     printf("+");
     for(i=0;i<N/4;i++)
     {
         printf("-");
     }
     printf("+\n");
     for(i=0;i<N/4;i++)
     {
         printf("|");
         for(k=0;k<N/4;k++)
         {
             printf(" ");
         }
         printf("|\n");

     }
     printf("+");
     for(i=0;i<N/4;i++)
     {
         printf("-");
     }
     printf("+\n");
     
     
     
 
//DODANO
 
              for(j=0;j<N/4-1;j++)
              {
               printf(" ");
              }
              for(j=0;j<2;j++)
              {
               printf("|");
              }
              for(j=0;j<N/4-1;j++)
              {
               printf(" ");
              }
      
         printf("\n");
       for(i=0;i<N/4;i++)
       {
        for(j=0;j<N/4-1;j++)
        {
        printf("-");
        }
        for(j=0;j<2;j++)
        {
         printf("+");
        }
        for(j=0;j<N/4-1;j++)
        {
        printf("-");
        }
        printf("\n");
       
       }
     
      for(j=0;j<N/4-1;j++)
              {
               printf(" ");
              }
              for(j=0;j<2;j++)
              {
               printf("|");
              }
              for(j=0;j<N/4-1;j++)
              {
               printf(" ");
              }
      
 
 


 


    return 0;
}
