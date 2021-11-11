#include <stdio.h>
#define VELICINAA 40000
int isti(int* prvi,int* drugi,int vel)
{
	int i;
	for(i=0;i<vel;i++) 
	{
		if (prvi[i]!=drugi[i]) return 0;
	}
	return 1;
}


void ispisi(int x)
{
    printf("%5d",x);
}

int main() {
	int m,n,i,b;
	int j,a,k;
	int mat[200][200],niz[VELICINAA],redovi=0,l,p;
	int vel;

	
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	if(m<1 || m>200 || n<1 || n>200) 
	        {
	        printf("Brojevi nisu u trazenom opsegu.\n");
	        }
	}while(m<1 || m>200 || n<1 || n>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	vel=m*n;
	
	i=0;
	b=i+1;
	
	/*poredjenje i izbacivanje redova*/
	
	while(i<m){
	
			for(j=b;j<m;j++)
				{
					redovi=0;
				for(k=0;k<n;k++)
				{
					if(mat[i][k]!=mat[j][k]) redovi++;
				}	
						
						if(redovi==0)
						{
				
							for (l=j; l<m-1; l++) 
									{		
										for(a=0;a<n;a++)
										{
											mat[l][a]=mat[l+1][a];
										}
									}
							vel=vel-n;
							m--;
							j--;
						}
						
				}
				i++;
				b=i+1;
			}
	
	
		k=0;
		i=0;
		while(i<n)
		{
		for(j=0;j<m;j++)
			{
				niz[k++]=mat[j][i];
			}
		i++;
		}

/*Izbacivanje kolona*/

		for(i=0;i<vel;i+=m)
		{
			for(j=i+m;j<vel;j+=m)
			{
				if(isti(niz+i,niz+j,m)==1) 
					{
				
						for(p=j;p<vel-m;p++)
						{
							niz[p]=niz[p+m];
					
						}
			
				vel-=m;
				n--;
				j-=m;
				
					}
			}
		}	
	
	k=0;


	
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				{
		
					mat[j][i]=niz[k];
					k++;
				}
		}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			ispisi(mat[i][j]);
		}
	printf("\n");
	}
		
	return 0;
}
