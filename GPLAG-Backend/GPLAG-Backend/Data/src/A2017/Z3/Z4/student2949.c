#include <stdio.h>

int max(int matrica[100][100],int visina,int sirina){
	int i=0,j=0,k=0,l=0,max=0,s=0,s1=0;
	
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			for(k=0;k<visina;k++){
				for(l=0;l<sirina;l++){
					if(matrica[i][j]==matrica[k][l])s++;
				}
			}
			if(s>s1){
				max=matrica[i][j];
				s1=s;
			}
			else if(s==s1 && matrica[i][j]<max){
				max=matrica[i][j];
				s1=s;
			}
			s=0;
		}
	}
	
	return max;
}

int izbaci_kolone(int matrica[100][100],int visina,int sirina,int n){
	int i=0,j=0,k=0,l=0,s1=sirina;
	static int br=0;
	for(i=0;i<visina;i++){
		for(j=0;j<s1-br;j++){
			if(matrica[i][j]==n){
				for(k=0;k<visina;k++){
					for(l=j;l<s1-br;l++){
						matrica[k][l]=matrica[k][l+1];
					}
				}
			
				i=0;
				j--;
				br++;
			}
		}
	}
	return s1-br;
}

int main() {
	int i=0,j=0,visina=0,sirina=0,a[100][100],h=1,s=0,s1=0;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	s1=sirina;
	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++){
			scanf("%d",&a[i][j]);
		}
	}


	do{
		
		
		s=izbaci_kolone(a,visina,sirina,max(a,visina,s1));
		s1=s;
		if(s==0){
			printf("\nNakon %d. prolaza matrica je prazna!",h);
		}
		else{
			printf("\nNakon %d. prolaza matrica glasi:\n",h++);
			for(i=0;i<visina;i++){
				for(j=0;j<s;j++){
					printf("%5d",a[i][j]);
				}
				printf("\n");
			}
			
		}
		
	}while(s>0);
	return 0;
}
