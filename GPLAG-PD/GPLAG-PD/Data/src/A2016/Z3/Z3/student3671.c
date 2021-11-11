#include <stdio.h>

int main() {
	int M=1,N=1;
	int i,j,k,m,n,p,q,g,h,a,b,x,d,e;
	int matrica[200][200];
	int red1[200],red2[200],red3[200]; 
	/* uvodjenje pomocnih redova radi kasnijeg poredjenja sa matricom */
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<=0 || N<=0 || M>200 || N>200)
		printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M<=0 || M>200 || N<=0 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&matrica[i][j]);
		}
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
			{
				red1[j]=matrica[i][j];
			}
			/* sve jedinice, svi elementi jedne vrste jednaki elementima druge vrste */
		for(k=i+1;k<M;k++)
		{
			red2[k]=1;
		}
		for(m=i+1;m<M;m++)
		{
			for(n=0;n<N;n++)
			{
				if(red1[n]!=matrica[m][n])
				red2[m]=0;
				/* ukoliko red nije jednak redu matrice vraca na nulu */
			}
		}
		
		int c=0; 
		for(p=i+1;p<M;p++)
		{
			if(red2[p]==1)
			{
				if(c>0)
				i++;
				c++;
			for(q=p;q<M-1;q++)
			{
				for(g=0;g<N;g++)
				{
					matrica[q][g]=matrica[q+1][g];  /* izbacuje vrstu */
				}
				red2[q]=red2[q+1];
			}
			M--; /*smanjuje se dimenzija matrice */
			i--; /* smanjuje se broj indeksa u redu*/
		}
		}
	}
	/* provjera kolona analogno vrstama */
	for(j=0;j<N;j++)
	{
		for(i=0;i<M;i++)
		{
			red1[i]=matrica[i][j];
		}
		for(h=j+1;h<N;h++)
		{
			red3[h]=1;
		}
		
		for(a=j+1;a<N;a++)
		{
			for(b=0;b<M;b++)
			{
				if(red1[b]!=matrica[b][a])
				red3[a]=0;
			}
		}
	
	int c=0;
	for(x=1+j;x<N;x++)
	{
		if(red3[x]==1)
		{
			if(c>0)
			j++;
			c++;
		for(d=x;d<N-1;d++)
		{
			for(e=0;e<M;e++)
			{
				matrica[e][d]=matrica[e][d+1]; /*izbacivanje kolona*/
			}
			red3[d]=red3[d+1];
		}
			N--; /*smanjenje broja kolona */
			j--; /* smanjenje broja indeksa u koloni*/
		}
	}
}
		
		
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%5d",matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}
