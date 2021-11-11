#include <stdio.h>

int main() {
	int a[200][200], M=-1, N=-1, i, j,br_red=0, l,k,red[200]={0},br1=0, temp=0, min=0, izbacit=0;
	do{
		printf("Unesite brojeve M i N: ");
	    scanf("%d %d", &M,&N);
	    if(M>200 || M<=0 || N>200 || N<=0) printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M>200 || M<=0 || N>200 || N<=0);
	printf("Unesite elemente matrice:");
	for(i=0; i<M; i++){
	    for(j=0; j<N; j++){
	        scanf("%d", &a[i][j]);
	    }
	}
	//Ugnijezdene petlje koje prolaze kroz matricu, trazi redove koji se ponavljaju, te ih sprema u niz zvani red[200].
	for(i=0; i<M; i++){
		for(k=1+i; k<M; k++){
			br_red=0;
			for(j=0; j<N; j++){
				if(a[i][j]==a[k][j]) br_red++;
			}
			if(br_red==N){
				red[br1]=k;
				br1++;
			}
			
		}
	}
	//Blok naredbi koji iz niza red[] izbacuje one elemente koji se vec nalaze u nizu(ukoliko ovaj blok naredbi ne bi postojao postojala bi mogucnost da se neki broj nalazi vise od jednom
	//sto bi moglo predstavljat problem prilikom izbacivanja redova iz matrice.
	for(i=0; i<br1; i++){
		for(j=1+i; j<br1; j++){
			if(red[i]==red[j]){
				for(k=j; k<br1-1; k++){
					red[k]=red[k+1];
				}
			    br1--;
			    j--;
			}
		}
	}
	//Algoritam koji sortira clanove niza "red[]" u rastucem redoslijedu(da bi kasnije izbacivanje redova iz matrice islo tecnije i bilo lakse pronaci eventualne zastoje.)
	for (i=0; i<br1; i++) {
		 min=i;
		 for (j=i+1; j<br1; j++) {
			  if (red[j] < red[min])
			      min = j;
		}
		temp = red[i];
		red[i] = red[min];
		red[min] = temp;
	}
	//Ugnijezdene petlje koje prolaze kroz matricu i izbacuju redove koji su oznaceni i spremljeni u niz red[].
	//Nakon zavrsetka i-petlje iz matrice ce bit izbaceni svi redovi koji se ponavljaju, u skladu s uslovima zadatka.
	for(i=0; i<br1; i++){
		izbacit=red[i];
		for(k=izbacit; k<M-1; k++){
			for(j=0; j<N; j++){
			a[k][j]=a[k+1][j];	
			}
		}
		M--;
		for(l=i; l<br1; l++) {
			red[l]--;
		}
	}
	br1=0;
	//Ugnijezdene petlje koje prolaze kroz matricu, trazi redove koji se ponavljaju, te ih sprema u niz zvani red[200].
	//Brojac je resetovan pa ne postoji mogucnost mijesanja kolona koje treba izbaciti s redovima koji su izbaceni.
	for(i=0; i<N; i++){
		for(k=i+1; k<N; k++){
			br_red=0;
			for(j=0; j<M; j++){
				if(a[j][i]==a[j][k]) br_red++;
			}
			if(br_red==M){
				red[br1]=k;
				br1++;
			}
			
		}
	}
	//Blok naredbi koji iz niza red[] izbacuje one elemente koji se vec nalaze u nizu(ukoliko ovaj blok naredbi ne bi postojao postojala bi mogucnost da se neki broj nalazi vise od jednom
	//sto bi moglo predstavljat problem prilikom izbacivanja redova iz matrice.
	for(i=0; i<br1; i++){
		for(j=1+i; j<br1; j++){
			if(red[i]==red[j]){
				for(k=j; k<br1-1; k++){
					red[k]=red[k+1];
				}
			    br1--;
			    j--;
			}
		}
	}
	//Algoritam koji sortira clanove niza "red[]" u rastucem redoslijedu(da bi kasnije izbacivanje redova iz matrice islo tecnije i bilo lakse pronaci eventualne zastoje.)
	for (i=0; i<br1; i++) {
		 min=i;
		 for (j=i+1; j<br1; j++) {
			  if (red[j] < red[min])
			      min = j;
		}
		temp = red[i];
		red[i] = red[min];
		red[min] = temp;
	}
	//Ugnijezdene petlje koje prolaze kroz matricu i izbacuju kolone koji su oznaceni i spremljeni u niz red[].
	//Nakon zavrsetka i-petlje iz matrice ce bit izbacene sve kolone koji se ponavljaju, u skladu s uslovima zadatka.
	for(i=0; i<br1; i++){
		izbacit=red[i];
		for(k=izbacit; k<N-1; k++){
			for(j=0; j<M; j++){
			a[j][k]=a[j][k+1];	
			}
		}
		N--;
		for(l=i; l<br1; l++) {
			red[l]--;
		}
	}
	printf(" Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
