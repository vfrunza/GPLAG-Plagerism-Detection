#include <stdio.h>
#include <math.h>

int main()
{
	int niz[100], C[1000];
	int n, i, j, broj, br0, br1, br2, br3, br4, br5, br6, br7, br8, br9, ostatak, t=0;
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
	} while(n<0);
	printf("Unesite clanove niza: ");

	
		for(i=0; i<n; i++) {
			scanf("%d", &niz[i]);
			if (niz[i]<0){
				printf("Clanovi moraju biti prirodni brojevi");
				printf("UNesite ponovo %d-ti clan niza: ", i+1);
				scanf("%d", &niz[i]);
			}
		}
	


	for(j=0; j<n; j++) {
		broj=0;
		ostatak=niz[i];
		do {

			broj=ostatak%10;
			ostatak=niz[j]/pow(10,t);
			printf("%d", broj);
			t++;
			
		} while(ostatak>0);

	}


	return 0;
}
