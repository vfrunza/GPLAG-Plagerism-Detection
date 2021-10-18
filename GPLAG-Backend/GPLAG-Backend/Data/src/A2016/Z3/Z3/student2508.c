#include <stdio.h>

int main()
{
    int m,n,i,j,mat[200][200],k,izbr=0,p,r,izbk=1;
    do
    {
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&m,&n);
        if(m<=0 || m>200 || n<=0 || n>200)
            printf("Brojevi nisu u trazenom opsegu.\n");
    }
    while(m<=0 || m>200 || n<=0 || n>200);
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
        
  for(k=0;k<m;k++)
  {
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            
            if(k!=i)
            {
             if(mat[k][j]==mat[i][j])
                izbr=1;
            else
                {
                izbr=0;
                break;
                }
                
            }
                
         if(izbr==0) 
       break;    
        }
        
       if(izbr==1)
        {
                for(p=i;p<m-1;p++)
                {
                    for(r=0;r<n;r++)
                    {
                        mat[p][r]=mat[p+1][r];
                    }
                }
                m--;
                i--;
                
        } 
       
    }
    
   }
   
for(k=0;k<n;k++)
{
    for (j=0;j<n;j++)
    {
  
        izbk=1;
            
            if(k==j) continue;
  
        for(i=0;i<m;i++)
        {
           
            
             if(mat[i][k]!=mat[i][j])
             {
                izbk=0;
                break;
             } 
             
             if(izbk==0)
             break;
                
             
                
            
                
                
            }
            
             if(izbk==1)
            {    
                for(p=0;p<m;p++)
                {
                    for(r=j;r<n-1;r++)
                    {
                        mat[p][r]=mat[p][r+1];
                    }
                }
                n--;
                j--;
             }
        }
        
}
   
   

    
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for (i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%5d",mat[i][j]);
            }
            printf("\n");
        }
    return 0;
}