#include <stdio.h>

/*void izbaci_redove(int matrica[][200],int M,incekct N){
/*	int i,j,a,broj,s,v,velicina1;
		 velicina1=M*N;
for(i=0;i<M;i++){
	j=i+1;
	while(j<M){
		broj=0;
		 for(a=0;a<N;a++)
		 	if(!(matrica[j][a]==matrica[i][a])) broj++;
		 
		
		 if(broj==0) { s=j;
		 while(s<M-1){
		 	for(v=0;v<N;v++) matrica[s][v]=matrica[s+1][v];
		 
		 	s++;
		 }
		 
		 
		 velicina1-=N;
		 j--;M--;
	}
		j++;
	}
}

return M;}*/

int DalisuJednaki(int p[], int q[],int velicina){
	int i;
	/*PROLAZIMO KROZ SVE*/
	i=0;
	while(i<velicina){
		if(!(q[i]==p[i])) return 0;
		i++;
	}
	return 1;
}


int main() {
	int M,N,i,j;
	int matrica [200][200];
	int velicina1;
	int a,broj,s,v;
	/*Unos dimenzija matrice*/
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&M,&N);
	if(M>200||N>200||M<1||N<1) {
		printf("Brojevi nisu u trazenom opsegu.");
		printf("\n");}
	}while(M>200||N>200||M<1||N<1);
	

	/*Unos elemenata matrice*/
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
		  scanf("%d",&matrica[i][j]);

//	x=izbaci_redove(matrica,M,N);

	
 velicina1=M*N;/* sva polja */
 int niz_kolone[200];/*pomocni niz, za kolone*/

 /*Izbacujemo sve redove koji se ponavljaju*/

for(i=0;i<M;i++){
	j=i+1;
	while(j<M){
		broj=0;
		 for(a=0;a<N;a++)
		 	if(!(matrica[j][a]==matrica[i][a])) broj++;
		 
		
		 if(broj==0) { s=j;
		 while(s<M-1){
		 	for(v=0;v<N;v++) matrica[s][v]=matrica[s+1][v];
		  s++;
		 }
		 
		 
	 velicina1-=N;
	 j--;M--;
	}
		j++;
	}
}
/*	y=izbaci_kolone(matrica,M-x,N);*/
/*Nakon sto smo izbacili redove koji se ponavljaju sada izbacujemo kolone koje se ponavljaju*/

a=0;/*novi brojac*/
for(i=0;i<N;i++) /*setamo se po kolonama*/
for(j=0;j<M;j++){ 
	niz_kolone[a]=matrica[j][i];
	a++;}
	i=0;
	while(i<velicina1){
		j=i+M;
		while(j<velicina1){
			if(DalisuJednaki(niz_kolone+j,niz_kolone+i,M)){
				for(s=j;s<velicina1-M;s++)niz_kolone[s]=niz_kolone[s+M];
				N--;j=j-M;
				velicina1-=M;
			}
			j=j+M;
		}
		i=i+M;
	}
	
	s=0;
	for(i=0;i<N;i++)
	  for(j=0;j<M;j++){
	  	matrica[j][i]=niz_kolone[s];
	  	s++;
	  }

/*Ispisivanje matrice nakon izbacivanja*/
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++){
	   for(j=0;j<N;j++)
	       printf("%5d",matrica[i][j]);
	   printf("\n");
	}
//	printf("%d",x);
	return 0;
}
