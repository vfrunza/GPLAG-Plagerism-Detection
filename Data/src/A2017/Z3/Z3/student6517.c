#include <stdio.h>
#include <math.h>

int izbaci (int p1, int* his1)          /*Pomocna funkcija "izbaci" u kojoj izbacujemo nezeljene cifre iz promjenjivih koje cine niz N, tj. cifre koje su se kao pojavile u prijasnjoj funkciji kao clanovi niza M. */
{
	int minus=0, cifra_ostatka, cifra_ostatka2, rez1=0, rez2=0;

	if(p1<0) {                /*Ukoliko je vrijednost clana niza N negativna, pretvorim je u pozitivnu da bi lakse manipulisali tom vrijednoscu korz funkciju.*/
		p1=fabs(p1);
		minus=-1;
	}

	while(p1>0) {
		cifra_ostatka=p1%10;     /*U promjenjivu "cifra_ostatka" smijestamo ostatk pri dijeljenju vrijednosti clana niza N i 10.*/
		p1=p1/10;                /*Nakon sto smo dobili zeljeni ostatak dijelimo vrijednost iz niza N sa 10, da bi u svakom drugom prolazu kroz petlju varijabli "cifra_ostatka" dodijelili vrijednost zadnje cifre varijable "p1", te da bi smanjili vrijednosti varijable "p1" tako da nakon finalnog broja prolaz kroz petlju postane 0, sto ce oznaciti kraj petlje.*/

		if(his1[cifra_ostatka]!=1)          /*Porvjeravamo da li su redni brojevi clanova koji odgovaraju promjenjivoj "cifra_ostatka" u histogramu jednaki 1, tj. da li se pojavljuju u nizu M.*/
			rez1=rez1*10 + cifra_ostatka;   /*Ukoliko se ne pojavljuju, ta cifra ce uci u sastav varijable "rez1", tj. bit ce cifra u vrijednosti koji ce na kraju petlje nositi promjenjiva "rez1".*/
	}

	/*Na kraju petlje sve nezeljene cifre iz vrijednosti clanova niza N ce biti izbaceni. s time sto cifre u vrijednosti "rez1" biti poredane u pogresnom redosljedu (npr. umjesto rez1==123, bit ce rez1==321).*/


	while(rez1>0) {
		cifra_ostatka2=rez1%10;

		rez2=rez2*10 + cifra_ostatka2;    /*U ovoj petlji 'ispravljamo' redosljed cifara pogresno poredanih u "rez1" i dodjeljujemo te vrijednosti promjenjivoj "rez2" koju ova funkcija vraca kao finalni produkt.*/
		rez1/=10;
	}

	if(minus==-1) {                       /*Ukoliko je negativna vrijednost niza N usla u ovo funkciju, na samomom pocetku smo je prebacili na pozitivnu vrijednost, pa na samom kraju funkcije joj moramo vratiti prvobitni predznak.*/
		rez2*=minus;
		return rez2;
	}

	return rez2;
}


int izbaci_cifre (int* p, int n, int* q, int m)
{
	int i, j, hist[10]= {0};          /*Konstusisemo niz-histogram od 10 clanova sa vrijednosti postavljenim na 0, s obzirom da cemo u njemu samo povecavati vrijednosti rednog broja clanova za jedan koji odgovara vrijednosti koja se pojavljuje u nizu M*/

	for(i=0; i<m; i++) {
		if(q[i]<0 || q[i]>9)          /*Ukoliko neki clan niza M ima vrijednost manju od 0 ili vecu od 9(sto ga cini dvocifrenim brojem), funkcija prestaje sa radom i vraca 0.*/
			return 0;

		for(j=0; j<10; j++) {
			if(q[i]==j)               /*Za svaku vrijednost clana u nizu M, na lokacji u nizu histograma jednakoj toj vrijednosti, clan niza histograma se poveca za 1.*/
				hist[j]++;
		}
	}

	for(j=0; j<10; j++) {             /*Ukoliko postoji vrijednost u histogramu veca od 1, tj. ako se neki broj pojavio vise od jednom u nizu M, funkcija vraca 0.*/
		if(hist[j]>1)
			return 0;
	}

	for(i=0; i<n; i++)                /*ovaj dio funkcije se izvrsava jedino u slucaju kada se ne ponavlja niti jedan clan u nizu M, i kada nijedan njegov clan nije veci od 9 ili manji od 0.*/
		p[i]=izbaci (p[i], hist);     /*Pravimo pomocnu funkciju "izbaci" u koju je dovoljno da posaljemo svaku vrijednost niza N i pokazivac na prvu vrijednost u histogramu.*/

	return 1;
}

int main()
{
	int i;
	int N[100], M[100], n, m;

	printf("Unesite velicinu niza N i velicinu niza M: ");
	scanf("%d %d", &m, &n);

	printf("Unesite clanove niza N: ");
	for(i=0; i<n; i++)
		scanf("%d", &N[i]);

	printf("Unesite clanove niza M, tako da je svaki element jednocifren broj: ");
	for(i=0; i<m; i++)
		scanf("%d", &M[i]);

	izbaci_cifre(N, n, M, m);         /*funkciji saljem pokazivace na prve clanove niza M i niza N i velicine nizova this istih nizova*/

	for(i=0; i<n; i++)
		printf("%d ", N[i]);

	return 0;
}
