#include <stdio.h>



int main()
{
    int i,j,c,b;
    int m,n,m1,n1;
    int brojac=0;
    
    
	int A[100][100];
	int B[100][100];
	int AR[100][100];
	int TA[100][100];
	
	
	
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &m, &n);

	
	printf("Unesite clanove matrice A: ");	
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
        
     
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &m1, &n1);
	
	

        
        printf("Unesite clanove matrice B: ");
        for(i=0;i<m1;i++)
        for(j=0;j<n1;j++)
        {
            scanf("%d",&B[i][j]);
        }
        
    
        
        
    
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           TA[i][j]=A[j][i];
       }
   }
   
     
   
   for(i=0;i<n;i++)
   {
       for(c=m-1,b=0;c>=0;c--,b++)
       {
           AR[i][b]=TA[i][c];
       }
   }
      
    for(i=0;i<m;i++)
      {
      for(j=0,b=0;j<n;j++,b++)
      {
       if(B[i][j] == AR[i][b])
       {
           brojac++;
       }
      }
      }
      
      if(brojac==i*j)
      {
      	printf("DA");
      }
      else
      {
      	printf("NE");
      }
	}
      
      return 0;
  
}