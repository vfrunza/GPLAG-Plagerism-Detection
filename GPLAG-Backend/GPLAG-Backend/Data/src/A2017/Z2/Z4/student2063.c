#include <stdio.h>

int main() {
	int NA[100][100], NB[100][100], NC[100][100], i, j, tmp, a, b, c, d=0, f=0, R, K, br=0;
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &R, &K);
	
	}
	while(R>100 || K>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<R;i++)
	{
		for(j=0;j<K;j++)
		{
			scanf("%d", &NA[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<R;i++)
	{
		for(j=0;j<K;j++)
		{
			scanf("%d", &NB[i][j]);
		}
	}
		printf("Unesite clanove matrice C: ");
	for(i=0;i<R;i++)
	{
		for(j=0;j<K;j++)
		{
			scanf("%d", &NC[i][j]);
		}
	}
	
	for(i=0;i<R;i++)
	{
		for(j=0;j<K;j++)
		{
			d=i;
			f=j;
			c=NA[i][j];
			b=j;
			for(a=i;a<R;a++)
			{
				for(;b<K;b++)
				{
					if(NA[a][b]<c);
					c=NA[a][b];
					d=a;
					f=b;
				}
				
				b=0;
				a=0;
			}
		}
		if(NA[d][f]<NA[i][j])
		{
			tmp=NA[i][j];
			NA[i][j]=c;
			NA[d][f]=tmp;
			
		}
	}
	
	for(i=0;i<R;i++)
	{
		for(j=0;j<K;j++)
		{
			d=i;
			f=j;
			c=NB[i][j];
			b=j;
			for(a=i;a<R;a++)
			{
				for(;b<K;b++)
				{
					if(NB[a][b]<c);
					c=NB[a][b];
					d=a;
					f=b;
				}
				
				b=0;
				a=0;
			}
		}
		if(NB[d][f]<NB[i][j])
		{
			tmp=NB[i][j];
			NB[i][j]=c;
			NB[d][f]=tmp;
			
		}
		
	}
	for(i=0;i<R;i++)
	{
		for(j=0;j<K;j++)
		{
			d=i;
			f=j;
			c=NC[i][j];
			b=j;
			for(a=i;a<R;a++)
			{
				for(;b<K;b++)
				{
					if(NC[a][b]<c);
					c=NC[a][b];
					d=a;
					f=b;
				}
				
				b=0;
				a=0;
			}
		}
		if(NC[d][f]<NC[i][j])
		{
			tmp=NC[i][j];
			NC[i][j]=c;
			NC[d][f]=tmp;
			
		}
	}
	
	for(d=0;d<R;d++)
	{
		for(f=0;f<K;f++)
		{
			if((NC[d][f]==NB[d][f])&&(NB[d][f]==NA[d][f]))
			{
				br++;
			}
		}
	}
	if(br==d*f)
	{
		printf("DA");
	}
	else
	{
		printf("NE");
	}
	
	return 0;
}
