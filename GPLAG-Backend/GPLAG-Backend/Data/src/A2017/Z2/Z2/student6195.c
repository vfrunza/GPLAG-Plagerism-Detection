#include <stdio.h>
#define broj_elemenata 101

int obrni (int n) {
	int broj = 0, cifra;
	if(n == 0) return -1;
	while(n > 0) {
		cifra = n%10;
		broj = broj*10 + cifra;
		n /= 10;
		if(broj == 0) return -1;
	}
	return broj;
}

int broj_cifara (int n) {
	int brojac = 0;
	if (n == 0) return 1;
	while(n > 0) {
		brojac++;
		n /= 10;
	}
	return brojac;
}

int main() {
	int niz[broj_elemenata], i = 0, j = 0, k = 0, l, vel, pomocni[broj_elemenata], finalni[broj_elemenata], indeks = 0, indekss = 0, broj, brojac = 0;
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d", &vel);
	}while(vel < 0 || vel > 100);
	printf("Unesite clanove niza: ");
	do{
		scanf("%d", &niz[i]);
		if(niz[i] < 0) i--;
		i++;
	}while(i < vel);
	for(i = 0; i < vel; i++) {
		broj = obrni(niz[i]);
		while(broj > 0) {
			pomocni[j++] = broj % 10;
			broj /= 10;
		}
		if(broj == -1) {
			broj = niz[i];
			indeks = broj_cifara(broj); indekss = broj_cifara(broj);
			while(indeks > 0) {
				pomocni[j + indeks - 1] = broj % 10;
				broj /= 10;
				indeks--;
			}
			j += indekss;
		}
	}
	for(i = 0; i < j; i++) {
		finalni[k++] = pomocni[i];
		brojac = 0;
		for(l = i; l < j-1; l++) {
			if(pomocni[l] == pomocni[l+1]) brojac++;
			else break;
		}
		finalni[k++] = brojac+1;
		i = l;
	}
	printf("Finalni niz glasi:\n");
	for(i = 0; i < k; i++) printf("%d ", finalni[i]);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
/*	int niz[broj_elemenata],n,i,j,SIZE,temp;
	int	br=0;
	int finalni_niz[broj_elemenata];
	int min=0;

	do{
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	}while(n<0 || n>100);

	printf("Unesite clanove niza: ");
	//unos clanova niza velicine n, uz uslov da su prirodni brojevi, koju smo u liniji 6 unijeli//
	
		for(i=0; i<n; i++){
		scanf("%d",&niz[i]);
		if(niz[i]<0){

			 i--;}
	}
	//noviniz je niz koji treba da svaki clan predhodnog niza, tj svaki broj podijeli na cifre//
	int noviniz[broj_elemenata];
	SIZE = 0;
	//stavio sam od n-1 da ne moram praviti jos jedan niz, tacnije da ne moram kad rastavim pocetni niz na cifre "obrnuti" da mi//
	//ide s desna na lijevo, pa sam zato petlju stavio da mi ide unatrag odmah//
	for(i=n-1; i>=0; i--){
		temp = niz[i];
		if(niz[i] == 0) {
			noviniz[SIZE++]=0;
		}
		else {
			//dok je clan niza veci od nule dijeli ga sa 10 da mu se cifre razdvoje//
			while(temp > 0) {
				noviniz[SIZE++]=temp%10;
				temp/=10;
			}
		}
	}
	
	// zamijeni niz //
	
	for(j = 0; j < SIZE/2; j++)
	{
		temp = noviniz[j];
		noviniz[j]=noviniz[SIZE-j-1];
		noviniz[SIZE-j-1]=temp;
	}
	// novi niz po ciframa ispisan//
//	for(i = 0; i < SIZE; i++) //
//		printf("%d ", noviniz[i]);//
//koliko puta koji broj se ponavlja//
			j=0;
			i=0;
			
			
		
		finalni_niz[0]=noviniz[0];
		finalni_niz[1]=0;

     for(j=0;j<SIZE;j++)
     {
     	if(finalni_niz[i]==noviniz[j])
     		finalni_niz[i+1]++;
     	else
     	{
     		i+=2;
			finalni_niz[i]=noviniz[j];
			finalni_niz[i+1]=1;
			
}
}
printf("Finalni niz glasi: \n");

for(j=0;j<i+2;j++)
printf("%d ",finalni_niz[j]);
*/
return 0;
}
