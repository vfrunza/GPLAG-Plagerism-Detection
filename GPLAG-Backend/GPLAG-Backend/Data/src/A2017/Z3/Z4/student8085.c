#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina) {

	int br[1000]={0};
	int max=0; int i,j;
	int maxi=matrica[0][0];
	int broj;
	
	for(i=0; i<visina; i++)
	{
		for(j=0;j<sirina; j++) {
				br[matrica[i][j]]++;
				if(matrica[i][j]>maxi)maxi=matrica[i][j];
		}
	}
	
	broj=maxi;
	for(i=0;i<=maxi;i++) 
		 if(br[i]>max  && br[i]!=0)
		 { 
		 	max=br[i]; 
		 	broj=i;
		 	
		 }
		
		
	return broj;

}

int izbaci_kolone(int mat[100][100],int visina,int sirina, int N) {
	
	int i,j,p,q;
	
	for(i=0; i<visina; i++)  {
		for(j=0; j<sirina; j++) {
				if(mat[i][j]==N) {
					for(p=0;p<visina;p++)
						for(q=j;q<sirina-1;q++)
							mat[p][q]=mat[p][q+1];
					
					sirina--;
					j--;
					
				}
					
		}
	}
	return sirina;	
}

void Ispisi(int mat[100][100],int visina,int sirina)
{
	
	int i,j;
	
	for(i=0; i<visina; i++) {
		for(j=0;j<sirina;j++)
			printf("%5d", mat[i][j]);
		printf("\n");
}
	
	printf("\n");
	
}
int main() {

int i,j;
int br=1;
int sirina,visina;
int mat[100][100];

printf("Unesite sirinu i visinu matrice: ");
scanf("%d %d", &sirina, &visina);
	


for(i=0; i<visina; i++) {
	printf("Unesite elemente %d. reda: ", i+1);
		for(j=0;j<sirina;j++)
			scanf("%d", &mat[i][j]);
}
printf("\n");

while(1)
{
	int a=max(mat,visina,sirina);
	sirina=izbaci_kolone(mat,visina,sirina,a);

	
	if(sirina==0)
	{
		printf("Nakon %d. prolaza matrica je prazna!",br);
		break;
    }
	else 
	{	
     	printf("Nakon %d. prolaza matrica glasi:\n",br);
	    Ispisi(mat,visina,sirina);
	    br++;		
	}
}

	return 0;
}
