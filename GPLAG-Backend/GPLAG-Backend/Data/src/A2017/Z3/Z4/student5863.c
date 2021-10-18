#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina){  
	int i,j,p,q;
	int temp;
	int max=matrica[0][0];
	int br=0;
	int maxbr=0;
	
	for(i=0;i<visina;i++){	
		for(j=0;j<sirina;j++){  
			br=0;
			temp=matrica[i][j];
			 
			for(p=i;p<visina;p++){
				for(q=0;q<sirina;q++){  
					if(temp==matrica[p][q])					       
						br++;		
				}
			}
		    
		    if(br>maxbr){
				maxbr=br;
				max=temp;
			}
	     	else if(br==maxbr && temp<max){  
				max=temp;
			}
		}
	}
	
	
	return max;
}

int izbaci_kolone(int mat[100][100],int visina,int sirina,int N){
	int i,j,p,q;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(mat[i][j]==N){
				for(p=0;p<visina;p++)
					for(q=j;q<sirina;q++)
						mat[p][q]=mat[p][q+1];
				j--;
				sirina--;
			}
		}
	}
	
	return sirina;
}

void Ispisi(int matrica[100][100],int visina,int sirina)
{
		int i,j;
	for(i=0;i<visina;i++){
		for( j=0;j<sirina;j++)
			printf("%5d",matrica[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main() {
	
	int matrica[100][100],sirina,visina,i,j;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++){
			scanf("%d",&matrica[i][j]);	
		}
		
	}
	printf("\n");
	sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));
	int br=0;
	
	while(sirina){   
		br++;
		printf("Nakon %d. prolaza matrica glasi:\n",br);
		Ispisi(matrica,visina,sirina);
		sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));
	}
	printf("Nakon %d. prolaza matrica je prazna!",br+1);
		

	return 0;
}
