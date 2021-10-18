#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina){
	
	int brojaci[1000]={0},niz[1000],i,j,k,*p,*q,br=0,ponav=0,najv_ponav,vel,najm=1000;
	
	vel=visina*sirina;
	k=0;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			niz[k++]=matrica[i][j];
			
		}
	}

//	for(i=0;i<vel;i++)printf("%d",niz[i]);
	
	
	for(i=0;i<vel;i++){
		for(j=1;j<vel;j++){
			
			
			if(niz[i]==niz[j])br++;
		}
		if(br>ponav)ponav=br;
		br=0;
	}
	
	
	
	for(i=0;i<vel;i++){
		for(j=0;j<vel;j++){
			
			
			if(niz[i]==niz[j])br++;
			
			
		} //printf("%d %d\n",niz[i],br);
		if(br>=ponav && niz[i]<najm)najm=niz[i];
		
		
	
	//	printf("%d ",najm);
		br=0;
		}
		
		
	return najm;
}


int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N){
	
	int i,j,k,l;
		
		if(sirina==2){
			matrica[0][0]=matrica[0][1];
			matrica[0][1]=matrica[0][0];
			matrica[1][0]=matrica[1][1];
			matrica[1][1]=matrica[1][0];
			sirina--;
		}
		
		
		
		for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
		  if(matrica[i][j]==N){
		  	
		  	for(k=0;k<sirina;k++){
		  		for(l=0;l<sirina;l++){
		  	matrica[l][k]=matrica[l][k+1];}}
	//	  	j--;
		  	sirina--;
		  	
		  }
		  }
			
		}
	
	
	
	
	
	
	
return sirina;
}


int main() {
	
	int mat[100][100],visina,sirina,i,j,N,br=0,k;

	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);

	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++){
			scanf("%d",&mat[i][j]);
		}
	}



//	printf("%d",max(mat,visina,sirina));
//N=max(mat,visina,sirina);
//k=izbaci_kolone(mat,visina,sirina,N);


//izbaci_kolone(mat,visina,sirina,max(mat,visina,sirina));

while(sirina-1>0){
N=max(mat,visina,sirina);
k=izbaci_kolone(mat,visina,sirina,N);
	br++;
	printf("Nakon %d prolaza matrica glasi: \n",br);
	for(i=0;i<visina;i++){
		for(j=0;j<k;j++){
			printf("%d ",mat[i][j]);
		}printf("\n");
	}
sirina--;
}

	return 0;
}
