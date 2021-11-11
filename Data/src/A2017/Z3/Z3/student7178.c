#include <stdio.h>

/*Funkcija "izbaci_cifre" prima niz brojeva i niz cifara, iz clanova prvog niza izbacuje cifre koje se nalaze u drugom nizu.*/
int izbaci_cifre(int* brojevi, int velbrojevi, int* cifre, int velcifre)
{
	int *q;
	int y,t,k,i,isti,j,vrati=1;
	int znak=1;
	/*Prvo provjeravamo da li su elementi niza cifara ispravni, ukoliko nisu logicka promjenljiva poprima vrijednost 0.*/
	for(i=0; i<velcifre; i++) {
		if((*(cifre+i))<0 || (*(cifre+i))>9) {
			vrati=0;
			break;
		}
	}
	/*Ukoliko su elemnti niza cifara ispravni, uporedjujemo elemente niza brojeva.*/
	for( i=0; i<velcifre; i++) {
		/*Ako su dva elementa niza jednaka, logicka promjenljiva poprima vrijednost 0, a petlja se prekida*/
		for( j=i+1; j<velcifre; j++)
			if(cifre[j]==cifre[i]) {
				vrati=0;
				break;
			}
		for( j=i-1; j>-1; j--)
			if(cifre[j]==cifre[i]) {
				vrati=0;
				break;
			}

	}

	if(!vrati)return 0;
	else {
		for(i=0; i<velbrojevi; i++) {
			y=0;
			znak=1;
			t=0;
			if ((*(brojevi+i))<0) {
				znak=-1;
				(*(brojevi+i))*=znak;
			}

			/*Ova petlja ce iz itog clana niza izbaciti potrebne cifre*/
			while((*(brojevi+i))!=0) {

				y=(*(brojevi+i))%10;
				isti=1;
				q=cifre;
				/*Ovom petljom cemo "iskljuciti" iz broja onu cifru koja je jednaka elementu niza cifre*/
				while(q<cifre+velcifre) {
					if(y==*q) {
						isti=0;
						break;
					}
					q++;
				}
				if(isti) {
					t*=10;
					t+=y;
				}
				(*(brojevi+i))/=10;
			}

			k=0;
			while(t!=0) {
				y=t%10;
				k*=10;
				k+=y;
				t=t/10;
			}

			(*(brojevi+i))=k*znak;
		}
		return 1;
	}

}


int main()
{
	int brojevi[100], cifre[100], i, velbrojevi, velcifre;
	printf("Unesi velicinu za cifre: ");
	scanf("%d", &velcifre);
	printf("Unesite velicinu za brojeve: ");
	scanf("%d", &velbrojevi);
	printf("Cifre: ");
	for (i=0; i<velcifre; i++) {
		scanf("%d ", (cifre+i));
	}
	printf("Brojevi: ");
	for (i=0; i<velbrojevi; i++) {
		scanf("%d,", (brojevi+i));
	}
	izbaci_cifre(brojevi, velbrojevi, cifre, velcifre);

	for (i=0; i<velcifre; i++) {
		printf("%d ", *(cifre+i));

	}
	return 0;
}
