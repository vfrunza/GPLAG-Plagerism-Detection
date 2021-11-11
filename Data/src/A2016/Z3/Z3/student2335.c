#include <stdio.h>

int main() {
	int m=0,n=0,i=0,j=0,tmp=0,r=0,p=0,u=0,v=0;
	int mat[200][200],niz[200];
	/*Unos dimenzija matrice pomocu do-while petlje i ispisivanje poruka u zavisnosti od greske koja
	je napravljena prilikom unosa*/
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	if(m>0 && m<=200 && n>0 && n<200)
	break;
	else printf("Brojevi nisu u trazenom opsegu. \n");
	}while(1);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d ",&mat[i][j]);
		}
	}
/*Provjera da li postoje isti redovi, i ako postoje, izbacuje dupli. Provjerava tako sto svaki red poredi
 sa svim redovima koji su poslije njega(dakle ako prva petlja uzme prvi red, druga petlja za jednu vrijednost
 prve petlje prodje kroz svaki red koji je nakon tog reda). Za svaki red se pretpostavi da je jednak redu
 sa kojim se poredi. Treca petlja sluzi da se prolazi i kroz kolone. Ako su elementi razliciti onda 
 pretpostavka sa pocetka petlje nije tacna, dakle redovi nisu jednaki i dalje se nista ne desava, nego 
 se uzima sljedeci red te se provjerava na isti nacin. ako su svi elementi reda jednaki, pretpostavka sa
 pocetka programa je tacna, te se dupli red izbacuje pomocu for-petlji.*/
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			tmp=1;
			for(p=0;p<n;p++){
				if(mat[i][p]!=mat[j][p]){
					tmp=0;
				}
			}
			if(tmp==1){
				for(u=j;u<m-1;u++){
					for(v=0;v<n;v++)
					mat[u][v]=mat[u+1][v];
				}
				m--;
				j--;
			}
		}
	}
	
	/*Provjera da li postoje iste kolone, i ako postoje, izbacuje duplu. Provjerava tako sto svaku kolonu poredi
 sa svim kolonama koje su poslije nje(dakle ako prva petlja uzme prvu kolonu, druga petlja za jednu vrijednost
 prve petlje prodje kroz svaku kolonu koja je nakon te kolone). Za svaku kolonu se pretpostavi da je jednaka koloni
 sa kojom se poredi. Treca petlja sluzi da se prolazi i kroz redove. Ako su elementi razliciti onda 
 pretpostavka sa pocetka petlje nije tacna, dakle kolone nisu jednake i dalje se nista ne desava, nego 
 se uzima sljedeca kolona te se provjerava na isti nacin. ako su svi elementi kolone jednaki, pretpostavka sa
 pocetka programa je tacna, te se dupla kolona izbacuje pomocu for-petlji.*/
	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			tmp=1;
			for(p=0;p<m;p++){
				if(mat[p][i]!=mat[p][j]){
					tmp=0;
				}
			}
			if(tmp==1){
				for(u=j;u<n-1;u++){
					for(v=0;v<m;v++)
					mat[v][u]=mat[v][u+1];
				}
				n--;
				j--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		printf("%5d",mat[i][j]);
		printf("\n");
	}
	
	return 0;
}
