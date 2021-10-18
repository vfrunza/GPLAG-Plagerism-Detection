#include <stdio.h>
int max(int matrica[100][100],int visina, int sirina)
{
	int br[100][100]= {{0}};
	//brojac koji ce izgledati isto kao i matrica na pozicijama clanova matrice on ce smjestati koliko se ponavljuju clanovi u matrici
	int i,j,m,n;
	int maxm=0,maxbr=0;
	//u maxm cu spremati vrijednost clana matrice koji se najvise puta ponavljuje, a u maxbr koliko se puta ponavljuje
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			//i-j petljom prolazim kroz sve clanove matrice, pa cu svaki taj clan poredit sa svim clanovima od pocetka do kraja matrice prolazeci kroz matricu m-n petljom da bi zapisala koliko se ponavlja taj clan u matrici
			for(m=0; m<visina; m++) {
				for(n=0; n<sirina; n++) {
					if(matrica[m][n]==matrica[i][j]) br[i][j]++;
				}
			}

		}
	}
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(i==0 && j==0) {
				maxbr=br[i][j];
				maxm=matrica[i][j];
				continue;
			}
			//ako se ponavljaju clanovi isti broj puta, kao clan koji se ponavlja najvise puta se zapisuje onaj manji
			if(br[i][j]==maxbr && matrica[i][j]<maxm) maxm=matrica[i][j];
			if(br[i][j]>maxbr){ maxm=matrica[i][j]; maxbr=br[i][j];}
		}

	}
	return maxm;
}
int izbaci_kolone(int b[100][100],int visina,int sirina,int N)
{
	int i,j,m,n,temp;
	//prolazimo kroz matricu po redovima
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			//trazimo clan koji sadrzi element N
			if(b[i][j]==N) {
				//zamjena kolone koja treba biti izbacena sa susjednom desno, i tako sve do kraja
				for(n=j; n<sirina; n++) {
					for(m=0; m<visina; m++) {
						temp=b[m][n];
						b[m][n]=b[m][n+1];
						b[m][n+1]=temp;
					}
				}
				//umanjujemo sirinu da bi kolonu sa datim elementom( a nakon petlje se nalazi na kraju) izbacili
				sirina--;
				//posto se sada na j mjestu nalazi neka druga kolona, moramo sa vratiti i provjeriti i nju
				j--;

			}
		}
	}


	return sirina;

}
int main()
{
	int visina,sirina,a[100][100],i,j,p;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d",&a[i][j]);
		}
	}


	for(p=1; sirina>0; p++) {

		sirina=izbaci_kolone(a,visina,sirina,max(a,visina,sirina));
		if(sirina==0) {
			printf("\nNakon %d. prolaza matrica je prazna!",p);
			break;
		}
		printf("\nNakon %d. prolaza matrica glasi:\n",p);
		for(i=0; i<visina; i++) {

			for(j=0; j<sirina; j++) {
				printf("%5d",a[i][j]);
			}
			printf("\n");
		}
	}

	return 0;

}
