#include <stdio.h>

int isti(int niz[],int niza[], int vel){
	/*funkcija iz main-a prima vrijednosti dva pokazivaca i velicine niza, 
	te provjerava da li su redovi ili kolone isti(zavisno od pokazivaca koje smo poslali iz main funkcije)*/
	int i;
	for(i=0;i<vel;i++){
		if(niz[i]!=niza[i]) return 0;
	}
	/*ako su isti vraca vrijednost 1, ako nisu vraca 0*/
	return 1;
}

int main() {
	
	int m,n,i,j,k;
	int mat[200][200];

	do{
/*unos dimenzija i elemenata matrice*/
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m,&n);
	if(m>200 || m<1|| n>200 || n<1) printf("Brojevi nisu u trazenom opsegu.\n");
	}while(m<1 || n<1 || m>=200 || n>=200);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		scanf("%d",&mat[i][j]);
		}
	}

int niz[40000];
int vel=m*n;
k=0;
/*dvostruka petlja prolazi kroz sve clanove i elemente matrice postavlja u jedan niz
da bi smo kasnije mogli slati te elemente u funkciju*/
  for(i=0;i<m;i++){
  	for(j=0;j<n;j++){
  		niz[k++]=mat[i][j];
  	}
  }
  
  int p;
  /*dvostruka petlja prolazi kroz niz koji smo napravili iznad, ali prolazi samo kroz odredjene elemente koji redom cine kolone matrice*/
  for(i=0;i<vel;i+=n){
  	for(j=i+n;j<vel;j+=n){
  		if(isti(niz+i,niz+j,n)==1){
  			/*u funkciju ubaci saljemo dva pokazivaca (koja pokazuju dvije kolone u matrici) i velicinu niza.
  			Ako funkcija vrati vrijednost 1, kolone su iste pa je treba izbaciti*/
  			for(p=j;p<vel-n;p++){
  				niz[p]=niz[p+n];
  			}
  			vel-=n;
  			m--;
  			j-=n;
  		}
  	}
  }
  
  /*vracamo elemente iz niza u matricu*/
  k=0;
  for(i=0;i<m;i++){
  	for(j=0;j<n;j++){
  		mat[i][j]=niz[k++];
  	}
  }
	
	/*ponanvaljamo isti postupak za redove matrice*/
	k=0; 
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			niz[k++]=mat[j][i]; /*prebacivanje u niz*/
		}
	}
	/*odredjivanje i izbacivanje istih redova*/
	for(i=0;i<vel;i+=m){
  	for(j=i+m;j<vel;j+=m){
  		if(isti(niz+i,niz+j,m)==1){
  			for(p=j;p<vel-m;p++){
  				niz[p]=niz[p+m];
  			}
  			vel-=m;
  			n--;
  			j-=m;
  		}
  	}
  }
  /*vracanje niza u matricu */
  	k=0; 
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			mat[j][i]=niz[k++];
		}
	}
	
	/*ispis nove matrice*/
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
