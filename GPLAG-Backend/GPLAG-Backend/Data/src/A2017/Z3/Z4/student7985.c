#include <stdio.h>

int fun_brojac(int broj, int mat[][100], int vis, int sir){
	int i, j, brojac=0;
	for(i=0; i<vis; i++){
		for(j=0; j<sir; j++){
			if(broj==mat[i][j]) brojac++;
		}
	}
			
	return brojac;
}

int max(int mat[100][100], int vis, int sir){
	int* pmax;
	int i, j, var1, var2;
	if(vis<=0 || sir<=0) return -1;
	pmax=&mat[0][0];
	
	for(i=0; i<vis; i++){
		for(j=0; j<sir; j++){
			var1=fun_brojac(mat[i][j], mat, vis, sir);
			var2=fun_brojac(*pmax, mat, vis, sir);
			if((var1>var2) || (var1==var2 && mat[i][j]<*pmax))
				pmax=&mat[i][j];
			
		}
	}
	
	return *pmax;	
}

int nadji_kolonu(int mat[100][100], int vis, int sir, int n){
	int i, j;
	int indeks_kolone=-1;
	for(i=0; i<vis; i++){
		for(j=0; j<sir; j++){
			if(mat[i][j]==n) {
				indeks_kolone=j;
				return indeks_kolone;
			}
		}
	}
		
	return indeks_kolone;
}

int izbaci_kolonu(int mat[100][100], int vis, int sir, int ind_kolone){
	int i, k;
	
	for(i=0; i<vis; i++){
		for(k=ind_kolone+1; k<sir; k++){
			mat[i][k-1]=mat[i][k];
		}
	}
			
	return sir-1;
}

int izbaci_kolone(int mat[100][100], int vis, int sir, int n){
	int ind_kolone; /* indeks kolone */
	
	while(fun_brojac(n, mat, vis, sir)!=0){
		ind_kolone=nadji_kolonu(mat, vis, sir, n);
		sir=izbaci_kolonu(mat, vis, sir, ind_kolone);		/* svaki poziv sir se smanjuje za 1*/
	}
	
	return sir;
}


int main() {
	int matrica[100][100];
	int i=0, j=0, n=0, br=1;
	int sir=0, vis=0;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d%d", &sir, &vis);
	for(i=0; i<vis; i++){
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sir; j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	
	while(sir>1){
		n=max(matrica, vis, sir);
		sir=izbaci_kolone(matrica, vis, sir, n);
		
		if(sir>0){
			printf("\nNakon %d. prolaza matrica glasi: \n", br++);
			for(i=0; i<vis; i++){
				for(j=0; j<sir; j++)
					printf("%5d", matrica[i][j]);
				printf("\n");
			}
		}
		
	}
	printf("\nNakon %d. prolaza matrica je prazna!", br);
	
	
	return 0;
}
