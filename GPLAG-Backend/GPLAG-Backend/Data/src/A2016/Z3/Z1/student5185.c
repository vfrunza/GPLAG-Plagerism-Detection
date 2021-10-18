#include <stdio.h>


int daj_prost(){
	static int brojac=2;
	int i, j, broj, istinitost=1;
	
	j = 0;
	
	
	while (j < 1)
	{
		broj = brojac;
		if (brojac == 2){
			brojac++;
			j++;
			return broj;
		}
	
		else{
			for (i = 2; i < brojac; i++){
				if (broj % i == 0){
					istinitost = 0;
					break;
					}
				else{
					istinitost = 1;
				}
				}
				if (istinitost == 0){
					brojac++;
					j=0;
				}
				else if (istinitost == 1){
					brojac++;
					j++;
					return broj;
				}
			}
		
	}	
}

int main() {
	int prviBroj, drugiBroj, i, j=0, suma=0, broj;
	
	for (i = 0; i < 1; i++){
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &prviBroj, &drugiBroj);
	
	if (prviBroj <= 0){
		printf("A nije prirodan broj.\n");
		i--;
	}
	else if (prviBroj >= drugiBroj){
		printf("A nije manje od B.\n");
		i--;
	}
	else{
		while (j<1)
		{
			broj = daj_prost();
			if (broj <= prviBroj){
				j=0;
			}
			else if (broj > prviBroj && broj < drugiBroj)
			{
				suma += broj;
				j=0;
			}
			else{
				j++;
			}
		}
		
		printf("Suma prostih brojeva izmedju %d i %d je %d.", prviBroj, drugiBroj, suma);
	}
	}
	
	
	return 0;
}
