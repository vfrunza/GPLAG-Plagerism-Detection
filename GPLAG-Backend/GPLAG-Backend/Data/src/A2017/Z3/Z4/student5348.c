#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina);

int izbaci_kolone(int matrica[100][100], int visina, int sirina,int n);

void ispisi(int matrica[100][100], int visina, int sirina);

int main() {
	
	int sirina,visina;
	int matrica[100][100];
	int brojac=1;
	int i,j;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	
	for(i=0;i<visina;i++)
	{
		printf("Unesite elemente %d. reda: ",i+1);
			for(j=0;j<sirina;j++)
				scanf(" %d",&matrica[i][j]);
	}

	//Pozivam prvo jer ako je nakon prvog puta sirina je 0 nema poente da ulazi u petlju

	sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));
	while(sirina!=0)
	{
	printf("\nNakon %d. prolaza matrica glasi: ",brojac);
	ispisi(matrica,visina,sirina);
	brojac++;
	sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));
	}
	
	printf("\nNakon %d. prolaza matrica je prazna!",brojac);
	
	return 0;
}

int max(int matrica[100][100], int visina, int sirina)
{
	int newmax;
	int oldcount,newcount;
	int i,j,k,g;
	newmax=matrica[0][0];
	
	oldcount=0;
	newcount=oldcount;
	
	//oldcount pamti koliko se puta javio prosli najvise zastupljen borj, dok newcount za trenutni element i ako se new javio vise od old onda old postaje new
	
	for(i=0;i<visina;i++)
	{
		for(j=0;j<sirina;j++)
		{
			newcount=0;
			for(k=0;k<visina;k++)
				for(g=0;g<sirina;g++)
					if(matrica[i][j]==matrica[k][g]) newcount++;
					
				
			if(newcount>oldcount ){newmax=matrica[i][j];oldcount=newcount;}
			else if(newcount==oldcount)
			{
				if(matrica[i][j]<newmax	)newmax=matrica[i][j];
			}
			
		} 
	
	}
return newmax;
}

void ispisi(int matrica[100][100], int visina, int sirina)
{
int i,j;
printf("\n");
	for(i=0;i<visina;i++)
	{
	for(j=0;j<sirina;j++)
	printf("%5d",matrica[i][j]);
	printf("\n");
	}
}


int izbaci_kolone(int matrica[100][100], int visina, int sirina,int n)
{
int i,j,k,g;
int temp;


//Ako se javi kolona sa elementom n premjesta je skroz desno i smanjuje sirinu, zatim j da provjeri  da li ta nova kolona ima clan n

for(i=0;i<visina;i++)
{
	for(j=0;j<sirina;j++)
	{
		if(matrica[i][j]==n)
		{
		for(k=0;k<visina;k++)
		{
			for(g=j;g<sirina-1;g++)
			{
				temp=matrica[k][g];
				matrica[k][g]=matrica[k][g+1];
				matrica[k][g+1]=temp;
			}
			
		}
		
		j--;
		sirina--;
		}
		
	}
}

return (sirina);

}