#include <stdio.h>
int max(int matrica[][100],int visina, int sirina)
{
	int i,j,I,J,b=0,bMax=0,max=0,clan;
	for(i=0; i<visina; i++) {

		for(j=0; j<sirina; j++) {
			b=0;
			//prebrojavanje svakog clana zasebno
			//te uzimanje onog najmanjeg koji se najvise puta ponavlja
			clan=matrica[i][j];
			for(I=0; I<visina; I++) {
				for(J=0; J<sirina; J++) {
					if(matrica[I][J]==clan) b++;
				}
			}
			if(b>bMax) {
				bMax=b;
				max=clan;
			} else if(b==bMax && clan<max) max=clan;

		}

	}
	return max;


}
int izbaci_kolone(int matrica[100][100],int visina,int sirina,int n)
{
	int i,j,I,J,temp=0;

	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			//ukoliko kolona sadrzi broj koji se najvise puta ponavlja
			//datu kolonu prebacimo na zadnju poziciju te smanjimo sirinu
			if(matrica[i][j]==n) {
				for(J=j; J<sirina-1; J++) {
					for(I=0; I<visina; I++) {
						temp=matrica[I][J];
						matrica[I][J]=matrica[I][J+1];
						matrica[I][J+1]=temp;
					}
				}
				sirina--;
				//ukoliko se kolone pomjere neka kolona ili red bi mogla ostati preskocena
				//zbog navedenog razloga se vrsi povratak
				if(i>0) i--;
			}

		}

	}

	return sirina;

}
int main()
{
	int matrica[100][100];
	int visina,sirina,i,j,b=1;
	//unos velicine matrice
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	//unos elemenata matrice red po red
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d",&matrica[i][j]);
		}
	}
	do {
		sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));

		if(sirina>0) {
			printf("\nNakon %d. prolaza matrica glasi:\n",b);
			for(i=0; i<visina; i++) {

				for(j=0; j<sirina; j++) {
					printf("%5.d",matrica[i][j]);
				}
				printf("\n");
			}
		} else printf("\nNakon %d. prolaza matrica je prazna!",b);
		b++;
	} while (sirina>0) ;
	return 0;
}
