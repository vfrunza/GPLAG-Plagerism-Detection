#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int izbaci_cifre (int niz[],int duzina,int niz_cifri[], int velicina)
{
	int i,j,c,temp,brojac_cifri,brojaci[20]= {0};
/*Povjera ispravnosti niza cifri*/
	for(i=0; i<velicina; i++) {
		if(*(niz_cifri+i)<0 || *(niz_cifri+i)>=10) {
			return 0;
			break;
		}
	}


	for(i=0; i<velicina; i++) {
		brojaci[*(niz_cifri+i)]++;

	}
	for(i=0; i<velicina; i++) {
		if(brojaci[*(niz_cifri+i)]>1) {
			return 0;
			break;
		}
	}


/*Rastvljanje na cifre*/
	for(i=0; i<duzina; i++) {

		brojac_cifri=0;
		temp=0;
		while(*(niz+i)!=0) {
			c=*(niz+i)%10;
			*(niz+i)/=10;
/*Poredjenje cifre sa nizom cifri*/
			for(j=0; j<velicina; j++) {

				if(abs(c)==*(niz_cifri+j)) break;

			}
/*Vracanje cifre ukoliko se ne nalazi u nizu cifri*/			
			if(j<velicina) continue;
			temp=temp+(c*pow(10,brojac_cifri));
			brojac_cifri++;



		}
/*Upisivanje pomocne varijable (nove vrijednosti) u clan niza*/
		if(brojac_cifri==0) {
			*(niz+i)=0;
		} else {
			*(niz+i)=temp;
		}

	}

	return 1;

}
int main()
{
	int niz[3],i,niz_cif[]= {1,2,3},tacno;
	printf("Unesite niz: ");
	for(i=0; i<3; i++) {
		scanf("%d", &niz[i]);
	}
	tacno=izbaci_cifre(niz,3,niz_cif,4);
	printf("Tacno/Netacno: %d\n",tacno);
	for(i=0; i<3; i++) {
		printf("%d ", niz[i]);
	}

	return 0;
}
