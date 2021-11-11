/*Potrebno je napisati program koji omogućuje unos tri matrice cjelobrojnih elemenata A, B i C čije su dimenzije jednake: MxN, a M i N su najviše 100. Najprije se unose brojevi M i N (pomoću do-while petlje osigurati da su ti brojevi u traženom opsegu). Zatim se provjerava da li su matrice B i C sastavljene od istih elemenata kao matrica A, pri čemu se ti elementi trebaju ponavljati isti broj puta. Ako je uslov zadatka ispunjen program treba na ekranu ispisati DA, u suprotnom treba ispisati NE.

Primjeri ulaza i izlaza:
	Unesite brojeve M i N: 101 101
	Unesite brojeve M i N: 2 2
	Unesite clanove matrice A: 1 2 1 2
	Unesite clanove matrice B: 2 1 2 2
	Unesite clanove matrice C: 2 1 2 1
	NE

Objašnjenje: iako se matrice A i B sastoje od istih elemenata (1 i 2) njihov broj nije isti jer se u matrici B dvica javlja 3 puta, a u matrici A dva puta, slično i za broj 1.

Primjer 2:
	Unesite brojeve M i N: 3 3
	Unesite clanove matrice A: 1 2 3 6 6 4 3 7 -1
	Unesite clanove matrice B: -1 3 3 2 6 4 6 1 7
	Unesite clanove matrice C: 3 6 7 2 6 -1 3 4 1
	DA

Napomena: Rješenje koje uvijek ispisuje DA ili NE ili hardcodira rješenja (npr. ako je matrica jednaka nekoj iz autotesta uvijek ispisuje DA ili NE) biće bodovana sa 0 bodova bez obzira na potencijalno ispravne dijelove koda!
*/

#include <stdio.h>

/*Funkcija koja kao parametre uzima adresu niza i broj clanova u nizu i 
sortira niz od najmanjeg ka najvecem.
Ova funkcija bi bila beskorisna trenutno da nema ove zvjezdice
kod parametra niza, tj. ovo int* znaci da je pokazivac u pitanju ili 
adresa te varijable.*/

void sort(int* niz,int k){
	int i,j,temp;
	for( i=0; i<k; i++){
		for(j=0 ;j<k-1; j++){
			
			if(niz[j]>niz[j+1]){
				temp=niz[j];
				niz[j]=niz[j+1];
				niz[j+1]=temp;
			}
		}
	}
}

int main() {
	int a[100][100],b[100][100],c[100][100];
	int niz[10000],niz1[10000],niz2[10000];
	int m,n,i,j,x=0;
	int da=1;
	do{
		printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	} while (m<0 || m>100 || n<0 || n>100);

printf("Unesite clanove matrice A: ");
for(i=0; i<m; i++)
for(j=0; j<n; j++){
scanf("%d", &a[i][j]);
niz[x++]=a[i][j];
}
sort(niz,x);

x=0;
printf("Unesite clanove matrice B: ");
for(i=0; i<m; i++)
for(j=0; j<n; j++){
scanf("%d", &b[i][j]);
niz1[x++]=b[i][j];
}
sort(niz1,x);
x=0;

printf("Unesite clanove matrice C: ");
for(i=0; i<m; i++)
for(j=0; j<n; j++){
scanf("%d", &c[i][j]);
niz2[x++]=c[i][j];
	
}
sort(niz2,x);


for(i=0; i<x; i++){
	if(niz[i]!=niz1[i] || niz[i]!=niz2[i] || niz1[i]!=niz2[i]){
		da=0;
		break;
	}
}

if(da)
printf("DA");
else 
printf("NE");

	return 0;
}
