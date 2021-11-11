#include <stdio.h>
#define DUZINA 100
#define DUZINA2 1000

int main()
{
	int niz[DUZINA],n,clan,final[DUZINA2];
	int i,j;
	/*cijeliBroj,j,dvocifreniBroj,drugiBroj,prviBroj;*/
	int noviFinal=0,brojac=0;
	int a=0,k=0,brojcifara,temp=0;
	/* unos niza */
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++) {
		scanf("%d",&clan);
		brojcifara=0;
		temp=clan;
		while(temp/10!=0) {
			brojcifara++;
			temp/=10;
		}
		k=brojcifara+1;
		while(clan/10!=0) {
			niz[a+brojcifara]=clan%10;
			clan/=10;
			brojcifara--;
		}
		niz[a+brojcifara]=clan;
		a+=k;

	}




	for(i=0; i<a; i++) {
		brojac=0;
		for(j=i; j<a; j++) {
			if(niz[j]==niz[i])
				brojac++;
			else break;
		}
		final[noviFinal]=niz[i];
		final[++noviFinal]=brojac;
		noviFinal++;
		i+=brojac-1;

	}



	/* ispis niza */
	printf("Finalni niz glasi:");
	printf("\n");
	for (j=0; j<noviFinal; j++) {
		printf("%d ", final[j]);

	}
	return 0;
}
