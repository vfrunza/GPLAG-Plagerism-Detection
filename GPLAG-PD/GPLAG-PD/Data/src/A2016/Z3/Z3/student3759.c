#include <stdio.h>

int main() {
	
	int M, N, mat[200][200]={0}, transmat[200][200]={0}, matfinal[200][200]={0}, i, j, br=0;
	int checker=0, k=0,x=0, u, o, niz[40], velniz=0, f, tf=0;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M<0 || M>201 || N<0 || N>201){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	}while(M<0 || M>201 || N<0 || N>201);
	
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	//POCETAK REDOVA
	u=1;
	for(i=0;i<M;i++){
		if(checker!=M-1 && i!=0) i--;
		else if(checker==M-1){
			i=i;
			u=i+1;
			checker=0;
		}
		for(j=0;j<N;j++){
			if(mat[i][j]==mat[u][j]){
				br++;
			}
			if(br==N){
				niz[x]=u;
				x++;
				velniz++;
			}
			if(j==N-1) checker++;
			}//forJ
			br=0;
			u++;
	}//forI
	for(i=0;i<M;i++){
		o=0;
		for(j=0;j<N;j++){
			while(o<velniz){
				if(i==niz[o]){
					tf=1;
				}
				o++;
			}
			if(tf==1){
				for(f=0;f<N;f++){
					mat[i][f]=9999;
				}
			}
			tf=0;
		}
	}
	for(i=0;i<M;i++){
		if(mat[i][0]==9999){
			for(j=i;j<M-1;j++){
				for(k=0;k<N;k++){
					mat[j][k]=mat[j+1][k];
				}
			}
			i--;
			M--;
		}
	}
	//KRAJ REDOVA
	velniz=0;
	u=1;
	o=0;
	checker=0;
	tf=0;
	//TRANSPONOVANJE
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			transmat[i][j]=mat[j][i];
		}
	}
//	printf("\nTRANSMAT PRIJE PR\n");
//	for(i=0;i<N;i++){
//		for(j=0;j<M;j++){
//			printf("%d ", transmat[i][j]);
//		}
//		printf("\n");
//	}
//	
	u=1;
	for(i=0;i<N;i++){
		if(checker!=N-1 && i!=0) i--;
		else if(checker==N-1){
			u=i+1;
			checker=0;
		}
		for(j=0;j<M;j++){
			if(transmat[i][j]==transmat[u][j]){
				br++;
			}
			if(br==M){
				niz[x]=u;
				velniz++;
				x++;
			}
			if(j==M-1) checker++;
		}
		br=0;
		u++;
	}
	for(i=0;i<N;i++){
		o=0;
		for(j=0;j<M;j++){
			while(o<velniz){
				if(i==niz[o]){
					tf=1;
				}
				o++;
			}
			if(tf==1){
				for(f=0;f<M;f++){
					transmat[i][f]=9999;
				}
			}
			tf=0;
		}
	}
	
	for(i=0;i<N;i++){
		if(transmat[i][0]==9999){
			for(j=i;j<N-1;j++){
				for(k=0;k<M;k++){
					transmat[j][k]=transmat[j+1][k];
				}
			}
		i--;
		N--;
		}
	}
//	printf("\nTRANSMAT poslije\n");
//	for(i=0;i<N;i++){
//		for(j=0;j<M;j++){
//			printf("%d ", transmat[i][j]);
//		}
//		printf("\n");
//	}
	//KRAJ KOLONA
	
	//TRANSPONOVANJE
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			matfinal[i][j]=transmat[j][i];
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
