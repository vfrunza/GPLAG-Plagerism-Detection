#include <stdio.h>
#define broj_elemenata 200
int main () {
	int matrica[broj_elemenata][broj_elemenata]={0},i,j,x,k,p,q;
	int M=0;
	int N=0;
	do {
	/*provjeravamo da li brojevi ispunjavaju uslove zadatka*/
		printf("Unesite brojeve M i N: ");
		scanf ("%d %d",&M,&N);
		if ((M<1)||(M>200)||(N<1)||(N>200))
		printf ("Brojevi nisu u trazenom opsegu.\n");
	}
	while((M<1)||(M>200)||(N<1)||(N>200));
	printf ("Unesite elemente matrice: ");
	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			scanf ("%d",&matrica[i][j]);
		}
	}
/*izbacujemo kolone koji se ponavljaju*/
for(k=0;k<N-1;k++) {
	x=0;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			if (k==i+1);
			else if (matrica[j][k]==matrica[j][i+1])
			x=1;
			else {
				x=0;
				break;
			}
		}
		/*pomijeramo kolone ako se poklapaju*/
		if (x==1) {
			for(p=0;p<M;p++){
				for(q=i;q<N-2;q++){
					matrica[p][q+1]=matrica[p][q+2];
				}
			}
			N--;
		}
	}
}
/*izbacujemo redove ako se ponavljaju*/
for(k=0;k<M-1;k++){
	x=0;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(k==i+1);
			else if(matrica[k][j]==matrica[i+1][j])
			x=1;
			else {
				x=0;
				break;
			}
		}
		/*ako se redovi poklapaju, pomijeramo ih*/
		if (x==1){
		for (p=i;p<M-2;p++){
			for(q=0;q<N;q++) {
				matrica[p+1][q]=matrica[p+2][q];
			}
		}
		M--;
	}
}
}
printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
for(i=0;i<M;i++) {
	for(j=0;j<N;j++){
		printf("%5d",matrica[i][j]);
	}
	printf("\n");
}
return 0;
}