#include <stdio.h>

int main() {
	int a[100][100],b[100][100],c[100][100],p[10000][2]={0};

	
	int m,n,i,j,k,t=1;
	
	do
	{
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&m,&n);
	}while(m>100||m<0||n<0||n>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",a[i]+j);
			k=0;
			/*kad se unese jedan clan on ako je do tog trenutka bio jedinstven dobit ce mjesto u matrici, 
			ako nije, naci cemo njegov vec smjesteni duplikat i brojac povecati koji je ustvari 2 kolona matrice tj. kad je j=1*/
			do{
					if(p[k][0]==0&&p[k][1]==0)
					{
						p[k][0]=a[i][j];
						p[k][1]+=2;/*razlog sto uvecavam brojac za 2 jeste taj sto zelim, 
						kad budem ucitavao preostale dvije matrice, da svaki put oduzimam 1 i tako,
						ako se poklapaju, ja cu imati sve nule u drugoj koloni(j=1) moje matrice p,
						ako su sve nule,matrice B i C se poklapaju sa matricom A, ako nisu sve nule,onda se ne poklapaju
						*/
						
						break;
					}
					if(p[k][0]==a[i][j])
					{
						p[k][1]+=2;
						break;
					}
					k++;
			}while(1);
		}
		
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",b[i]+j);
			k=0;
			do{
				if(b[i][j]==p[k][0])
				{
					p[k][1]--;
					break;
				}
				k++;
			}while(k<m*n);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",c[i]+j);
			k=0;
			do{
				if(c[i][j]==p[k][0])
				{
					p[k][1]--;
					break;
				}
				k++;
			}while(k<m*n);
		}
	}
	if(m==0&&n==0){printf("DA\n");return 0;}
	for(i=0;i<m*n+1;i++)
	{
		if(p[i][1]!=0){t=0;break;}
	}
	if(t)printf("DA\n");
	else printf("NE\n");
	return 0;
}
