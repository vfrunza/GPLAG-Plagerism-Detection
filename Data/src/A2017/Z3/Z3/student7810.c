#include <stdio.h>

int izbaci_cifre(int *p1, int vel_1, int *p2, int vel_2)
{
	int histogram[10]= {0};		//da bismo prebrojali koliko puta se javlja svaka cifra iz niza cifara
	int *pom1=p1;
	int *pom2=p2;
	int broj,zadnji,k,postoji, negativan,i,j;
	for(i=0; i<vel_2; i++) {
		if(*pom2<0 || *pom2>9) return 0; //ako se u nizu nalzi vrijednost manja od 0 ili veca od 9 niz cifara nije ispravan
		histogram[*pom2]++;
		pom2++;
	}
	for(i=0; i<10; i++) {
		if(histogram[i]>1) return 0; //ako se neki od clanova ponavlja, niz cifara nije ispravan
	}
	for(i=0; i<vel_1; i++) {
		pom2=p2;					//vracamo pokazivac pom2 na pocetak niza cifri(p2 "cuva" pocetak)
		broj=*pom1;					// u varijablu broj smjestamo sadrzaj onog na sta pokazuje pokazivac pom1
		negativan=0;
		if(broj<0) {				//provjeramo da li je clan prvog niza negativan i ako jeste logicku promjenljivu negativan postavljamo na 1
			broj*=-1;
			negativan=1;
		}
		k=1;
		*pom1=0;
		do {
			pom2=p2;
			zadnji=broj%10;			//u varijablu zadnji smjestamo trenutno zadnju cifru broja
			postoji=0;
			for(j=0; j<vel_2; j++)		//krecemo se nizom cifara
				if(*pom2++==zadnji) postoji=1;  //provjeramo da li je odgovarajuca cifra iz niza cifara jednaka varijabli zadnji i ako jeste logicka promjenljiva postoji postaje 1
			if(postoji==0) {			//ako cifru iz odgovarajuceg clana prvog niza ne treba izbaciti
				*pom1+=k*zadnji;
				k*=10;
			}
			broj/=10;

		} while(broj!=0);

		if(negativan==1)
			*pom1*=-1;
		pom1++;
	}
	return 1;
}



int main()	
{
	int niz[4]= {1234, 3476, 3270, 66};
	int cifre[3]= {7,6,3};
	int i;
	izbaci_cifre(niz,4,cifre,3);
	for(i=0; i<4; i++)
		printf("%d ", niz[i]);
	return 0;
}
