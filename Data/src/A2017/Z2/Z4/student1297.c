#include <stdio.h>



int main()
{
    int min,i,j,tmp,y,k,w,z=0,q=0;
    int m,n;
    int brojac=0;
    
    
	int A[100][100];
	int B[100][100];
	int C[100][100];
	
	
	do
	{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m, &n);
	} while(n>100 || m>100);
	
	printf("Unesite clanove matrice A: ");	
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
        
        printf("Unesite clanove matrice B: ");
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&B[i][j]);
        }
        
        printf("Unesite clanove matrice C: ");
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&C[i][j]);
        }
        
        ///////////////////////////////////////////////////

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
        	
        	z=i;
        	q=j;
            min=A[i][j];
            w=j;
            for(k=i;k<m;k++)
            {
                for(;w<n;w++)
                if(A[k][w]<min)
                {
                    min=A[k][w];
                    z=k;
                    q=w;
                }
                w=0;
            }
            if(A[z][q] < A[i][j])
            {
            tmp=A[i][j];
            A[i][j]=min;
            A[z][q]=tmp;
        }
        }
        
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
        	
        	z=i;
        	q=j;
            min=B[i][j];
            w=j;
            for(k=i;k<m;k++)
            {
                for(;w<n;w++)
                if(B[k][w]<min)
                {
                    min=B[k][w];
                    z=k;
                    q=w;
                }
                w=0;
            }
            if(B[z][q] < B[i][j])
            {
            tmp=B[i][j];
            B[i][j]=min;
            B[z][q]=tmp;
        }
        }
        
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
        	
        	z=i;
        	q=j;
            min=C[i][j];
            w=j;
            for(k=i;k<m;k++)
            {
                for(;w<n;w++)
                if(C[k][w]<min)
                {
                    min=C[k][w];
                    z=k;
                    q=w;
                }
                w=0;
            }
            if(C[z][q] < C[i][j])
            {
            tmp=C[i][j];
            C[i][j]=min;
            C[z][q]=tmp;
        }
        }
        
        for(z=0;z<m;z++)
        for(q=0;q<n;q++)
        {
            if((C[z][q]==B[z][q]) && (B[z][q]==A[z][q]))
            {
                brojac++;
            }
        }
        
        
    
    if(brojac==z*q)
    {
    	printf("DA");
    	
    }
    else
    {
    	printf("NE");
    }
    
    
    
    return 0;
}
