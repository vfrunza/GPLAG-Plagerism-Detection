#include <stdio.h>
int main() {
int i=0,i1=0,i3=0,i4=0,i5=0,j,m,n;
int matrica[200][200];
do
	{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	if(m>200||n>200||m<1||n<1) 
	printf("Brojevi nisu u trazenom opsegu.\n");
	}
while(m>200||m<0||n>200||n<0);
printf("Unesite elemente matrice: ");
for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	scanf("%d",&matrica[i][j]);
	}
	for(i=0;i<m;i++)
	{
		for(i1=0;i1<m;i1++)
		{
		int ired=1;
		if(i1>i) 
				{
					for(j=0;j<n;j++)
					{
						if(matrica[i][j]!=matrica[i1][j]) ired=0;
					}
						if(ired)
						{
							for(i3=i1;i3<m-1;i3++)
							{
								for(i4=0;i4<n;i4++)
								{
									matrica[i3][i4]=matrica[i3+1][i4];
								}
							}	
							m--;
							i1--;
						}	
				}	
		}
	}	
for(i=0;i<n;i++)
		{
		for(i1=0;i1<n;i1++)
			{
				int ikolona=1;
				if(i1>i) 
				{
					for(j=0;j<m;j++)
					{
						if(matrica[j][i]!=matrica[j][i1]) ikolona=0;
					}
					if(ikolona)
					{
						for(i5=0;i5<m;i5++)
							{
								for(i4=i1;i4<n-1;i4++)
									{ 
										matrica[i5][i4]=matrica[i5][i4+1];
									}	
							}
							n--;
							i1--;
					}	
				}
			}
		}	
printf("Nakon izbacivanja redova/kolona matrica glasi: \n");

for(i=0;i<m;i++) 
{
	for(j=0;j<n;j++)
	{
		if(matrica[i][j]<0) printf("   ");
		if(matrica[i][j]>9) printf("   ");
		if(matrica[i][j]>0&&matrica[i][j]<10) printf("    ");
		printf("%d",matrica[i][j]);
		
	}	
	printf("\n");
}
return 0;
}
