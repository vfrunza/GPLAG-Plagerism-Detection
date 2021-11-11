#include <stdio.h>

int main() {
	int mat[100][100];
	int i,j,z,k,a,b,p=0;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&a,&b);
	if(a>200 || a<0 || b>200 || b<0){
	    printf("Brojevi nisu u trazenom opsegu.\n");
	}
	}while(a>200 || a<0 || b>200 || b<0);
	printf("Unesite elemente matrice: ");
	for(i=0;i<a;i++){
	    for(j=0;j<b;j++){
	        scanf("%d",&mat[i][j]);
	    }
	}
	//prvo trazimo sve redove koji se ponavljaju 
	for(i=1;i<a;i++){
	    for(z=0;z<i;z++){
	    	p=0;
	    	for(j=0;j<b;j++){
	    		//ako u matrici nema takvih redova program se prekida
	    		if(mat[i][j] != mat[z][j]){
	    		p=1;
	    		break;
	    	}
	    }
	    //ako postoje takvi redovi onda izbacujemo prvi odozdo takav red
	    	if(p==0){
	    	for(k=i;k<a-1;k++){
	    		for(j=0;j<b;j++)
	    		mat[k][j]=mat[k+1][j];
	    	}
	    	a--;
	    	i--;
	        }
	    }
	}
	//na isti nacin trazimo sve kolone koje se ponavljaju pri cemu poredimo svaki element kolone sa elementom sljedece 
	for(j=1;j<b;j++){
		for(z=0;z<j;z++){
			p=0;
			for(i=0;i<a;i++){
				if(mat[i][j] != mat[i][z]){
				p=1;
				break;
			}
		}
		if(p==0){
			for(k=j;k<b-1;k++){
				for(i=0;i<a;i++)
				mat[i][k]=mat[i][k+1];
			}
			b--;
			j--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<a;i++){
	    for(j=0;j<b;j++){
	       printf("%5d",mat[i][j]);
	    }
	
		printf("\n");
	}
	return 0;
}
