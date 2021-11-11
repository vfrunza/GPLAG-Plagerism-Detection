#include <stdio.h>

int main() {
	int i, j, k, n;
	int niz1[20], niz2[20];
	printf("Unesite broj tacaka: ");
	while(2==2){
	scanf("%d", &n);
	if(n<11 && n > 0) break;
		else printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
	}
	for(k=0; k<n; k++){
	printf("Unesite %d. tacku: ", k+1);
	scanf("%d", &niz1[k]);
	scanf("%d", &niz2[k]);
	if(niz1[k] > 19 || niz2[k] > 19 || niz1[k] < 0 || niz2[k] < 0)
	{
		printf("Pogresan unos\n");
		k--;
	}
	}
	
	int temp = 0;
		for(i=0; i<20; i++)
		{
			for(j=0; j<20; j++)
			{
				temp = 1;
				for(k=0; k<n; k++)
				{
					if(j==niz1[k]){
					if(i==niz2[k])
					{
						printf("*");
						temp = 0;
						break;
					}}
				}
				if(temp == 1)
				printf(" ");
			}
			printf("\n");
		}
	
	
	return 0;
}
