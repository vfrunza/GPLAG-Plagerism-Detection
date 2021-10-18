#include <stdio.h>
int max(int matrica[100][100],int visina,int sirina){
	int br=0,max=matrica[0][0],max_br=0,i,j,k,z;
	
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			for(k=0;k<visina;k++){
				for(z=0;z<sirina;z++){
					if(matrica[i][j]==matrica[k][z]) br++;
				}
			}
			if(br>max_br){
				max=matrica[i][j];
				max_br=br;
			}
			else if(br==max_br){
				if(matrica[i][j]<max){
					max=matrica[i][j];
					max_br=br;
				}
			}
			br=0;
		}
	}
	return  max;
			
	
}
int izbaci_kolone(int matrica[100][100],int visina,int sirina,int N){
	int i,j,z,l;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(matrica[i][j]==N){
				for(z=j;z<sirina-1;z++){
				for(l=0;l<visina;l++){
				matrica[l][z]=matrica[l][z+1];
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
	int matrica[100][100],visina,sirina,i,j,k,rez;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++){
			scanf("%d",&matrica[i][j]);
		}
	}
	k=1;
    for(;;){
    	rez=max(matrica,visina,sirina);
    	sirina=izbaci_kolone(matrica,visina,sirina,rez);
    	if(sirina==0) {
    		printf("\nNakon %d. prolaza matrica je prazna!",k);
    		break;
    	}
    	else {
    		printf("\nNakon %d. prolaza matrica glasi:\n",k);
    		k++;
    		for(i=0;i<visina;i++){
    			for(j=0;j<sirina;j++){
    				printf("%5d",matrica[i][j]);
    			}
    			printf("\n");
    		}
    	}
    }
	return 0;
}
