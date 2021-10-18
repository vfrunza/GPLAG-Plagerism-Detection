#include <stdio.h>

int main()
{
	int niz[100], n, k, i,j,p, niz2[1000]= {0};
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &niz[i]);
		if (niz[i]<0) {
			i--;
		}
	}

int brojcifara1=0; //ukupno cifara u cijelom nizu
int l;
	for(l=0; l<n; l++) {
		int broj=niz[l];
		while(broj!=0) {
			broj/=10;
			brojcifara1++;
		}
	}


	for(p=0; p<n; p++) {
		k=niz[p];
		for(j=0; j<brojcifara1; j++) {
			

			while(k!=0) {
				niz2[j]=k%10;
				k/=10;
				
				j++;
			}
		j--;
		
			//printf("\n %d %d ", niz2[j], j);
			
			
			
		}

	}
	
	for (i = 0; i < brojcifara1; i++) {
		printf("%d ", niz2[i]);
	}
	/*

		j=0;
		for (i = 0; i < n; i++) {
			int brojcifara=0;
			int broj=niz[i];

				k=broj;
				while(k!=0) {
					k/=10;
					brojcifara++;
				}

				int broj1=brojcifara;

				while (brojcifara!=0) {

					niz2[j]=broj%10;
					broj=broj/10;
					j++;
					brojcifara--;

				}





		printf("%d ",niz2[i]);
		}
	*/


	return 0;
}
