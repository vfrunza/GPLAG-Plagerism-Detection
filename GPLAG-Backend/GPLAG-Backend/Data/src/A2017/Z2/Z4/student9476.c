#include <stdio.h>

int main() {
	
	int m,n,i,j=0;
	int a[100][100],b[100][100],c[100][100];
	int temp=0;
	int k,g;
	int amin,bmin,cmin;
	
	
	do
	{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	}while(m<0 ||m>100 || n<0 ||n>100);
	
	{
	printf("Unesite clanove matrice A: ");
	
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{
	scanf(" %d",&a[i][j]);
	}
		
	
	printf("Unesite clanove matrice B: ");
	
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{
	scanf(" %d",&b[i][j]);
	}
	
	
	printf("Unesite clanove matrice C: ");
	
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{
	scanf(" %d",&c[i][j]);
	}
	}//Unos


for(k=0;k<m;k++)
	for(g=0;g<n;g++)
	{
		amin=a[k][g];
		bmin=b[k][g];
		cmin=c[k][g];
		
		
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				
				if(a[i][j]>amin)
				{
					
					temp=a[i][j];
					a[i][j]=a[k][g];
					a[k][g]=temp;
					amin=temp;
					
				}
				
				if(b[i][j]>bmin)
				{
					temp=b[i][j];
					b[i][j]=b[k][g];
					b[k][g]=temp;
					bmin=temp;
					
				}
				
				if(c[i][j]>cmin)
				{
					temp=c[i][j];
					c[i][j]=c[k][g];
					c[k][g]=temp;
					cmin=temp;
					
				}
			
			}
	}

for(i=0;i<m;i++)
for(j=0;j<n;j++)
if(a[i][j]!=b[i][j] ||a[i][j]!=c[i][j]){printf("NE");return 0;}
printf("DA");

	
	return 0;
}
