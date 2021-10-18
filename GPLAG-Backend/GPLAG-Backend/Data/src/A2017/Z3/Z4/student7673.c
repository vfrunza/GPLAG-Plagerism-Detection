#include <stdio.h>


int max(int matrica[100][100], int visina, int sirina)
{
	int i,j,p,q;
	int br,x;
	int maxi=0;
	int broj;
		
		for(i=0;i<visina;i++)
		{
			for(j=0;j<sirina;j++)
			{
				x=matrica[i][j];
				br=0;
				
					for(p=i;p<visina;p++)
					{
						for(q=0;q<sirina;q++)
						{
							if(x==matrica[p][q]) br++;
						}
						
					}
				
				if(br>maxi){ maxi=br; broj=matrica[i][j];}
				else if(br==maxi && matrica[i][j]<broj) broj=matrica[i][j];
				
				
			}
		}
		
		
		
		
	return broj;

}


int izbaci_kolone(int matrica[100][100],int visina,int sirina,int n)
{
	int i,j,p,q;
	
		for(i=0;i<visina;i++)
		{
			for(j=0;j<sirina;j++)
			{
			    if(matrica[i][j]==n)
			    {
			    	for(p=0;p<visina;p++)
			    	{
			    		for(q=j;q<sirina;q++)
			    		{
			    			matrica[p][q]=matrica[p][q+1];
			    		}
			    	}
			    	sirina--;
			    	j--;
			    }
			}
		}
	return sirina;
}

int main() {

	int mat[100][100];
	int visina,sirina;
	int i,j;
	int br=0;
	int maxi;

	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	
	
	for(i=0;i<visina;i++)
	{  
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++)
		{
			scanf("%d",&mat[i][j]);			
		}
	}
	printf("\n");
	
	while(sirina!=0)
	{
		maxi=max(mat,visina,sirina);
		sirina=izbaci_kolone(mat,visina,sirina,maxi);
		if(sirina==0) {printf("Nakon %d. prolaza matrica je prazna!\n",++br); break;}
		printf("Nakon %d. prolaza matrica glasi:\n",++br);
		
		for(i=0;i<visina;i++)
		{
			for(j=0;j<sirina;j++)
			{
				printf("%5d",mat[i][j]);
			}
			printf("\n");
		}
		
		printf("\n");
		
		
	}
	


	return 0;
}