#include <stdio.h>

int main() {
	int i,j,k,m,n,br,num,l,l1,l2,l3,ima;
	char da_li_je_tacno[2];
	int A[100][100], B[100][100], C[100][100];
	int a[10000],b[10000], c[10000], n1[10000], n2[10000], n3[10000];
	l=0;
	l1=0;
	l2=0;
	l3=0;
	k=0;
	da_li_je_tacno[0]='D';
	da_li_je_tacno[1]='A';
	
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &n, &m);
	while(m<0 || m>100 || n<0 || n>100)
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &n, &m);
	}
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		scanf("%d", &A[i][j]);
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		scanf("%d", &B[i][j]);
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		scanf("%d", &C[i][j]);
	}
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			a[k]=A[i][j];
			b[k]=B[i][j];
			c[k]=C[i][j];
			k++;
			l++;
		}
	}
	k=0;
	
	
	for(i=0; i<l; i++)
	{
		num=a[i];
		br=0;
		ima=0;
		if(i!=0)
		{
			for(j=0; j<l1; j=j+2)
			{
				if(num==n1[j])ima=1;
			}
		}
		
		if(ima==0)
		{
			for(j=i; j<l; j++)
			{
				if(num==a[j])
				br++;
			}
			n1[k]=num;
			n1[k+1]=br;
			k=k+2;
			l1=l1+2;
		}
	}
	
	k=0;
	
	for(i=0; i<l; i++)
	{
		num=b[i];
		br=0;
		ima=0;
		if(i!=0)
		{
			for(j=0; j<l2; j=j+2)
			{
				if(num==n2[j])ima=1;
			}
		}
		
		if(ima==0)
		{
			for(j=i; j<l; j++)
			{
				if(num==b[j])
				br++;
			}
			n2[k]=num;
			n2[k+1]=br;
			k=k+2;
			l2=l2+2;
		}
	}
	
	k=0;
	
		for(i=0; i<l; i++)
	{
		num=c[i];
		br=0;
		ima=0;
		if(i!=0)
		{
			for(j=0; j<l3; j=j+2)
			{
				if(num==n3[j])ima=1;
			}
		}
		
		if(ima==0)
		{
			for(j=i; j<l; j++)
			{
				if(num==c[j])
				br++;
			}
			n3[k]=num;
			n3[k+1]=br;
			k=k+2;
			l3=l3+2;
		}
	}
	
	if(l1!=l2 || l1!= l3)
	{
		da_li_je_tacno[0]='N';
		da_li_je_tacno[1]='E';
	}
	
	else
	{
		for(i=0; i<l1; i=i+2)
		{
			ima=0;
			for(j=0; j<l1; j=j+2)
			{
				if(n1[i]==n2[j])
				{
					ima=1;
					if(n1[i+1]!=n2[j+1])
					{
						da_li_je_tacno[0]='N';
						da_li_je_tacno[1]='E';
					}
					
				}
			}
			if(ima==0 || da_li_je_tacno[0]=='N')
			{
				da_li_je_tacno[0]='N';
				da_li_je_tacno[1]='E';
				break;
			}
		}
		
		if(da_li_je_tacno[0]=='D')
		{
			for(i=0; i<l1; i=i+2)
		{
			ima=0;
			for(j=0; j<l1; j=j+2)
			{
				if(n1[i]==n3[j])
				{
					ima=1;
					if(n1[i+1]!=n3[j+1])
					{
						da_li_je_tacno[0]='N';
						da_li_je_tacno[1]='E';
					}
					
				}
			}
			if(ima==0 || da_li_je_tacno[0]=='N')
			{
				da_li_je_tacno[0]='N';
				da_li_je_tacno[1]='E';
				break;
			}
		}
		}
	}
	
	printf("%c%c", da_li_je_tacno[0], da_li_je_tacno[1]);
	

	return 0;
}
