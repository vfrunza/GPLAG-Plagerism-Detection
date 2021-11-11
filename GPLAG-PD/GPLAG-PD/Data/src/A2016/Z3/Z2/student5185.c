#include <stdio.h>
#define duzinaReda 10

void ubaci (int* p, int duzReda){
	int i, broj, rezultat;
	int* temp;
	temp = p;
	
	for (i = duzReda-1; i >= 0; i--) {
		p = temp;
		broj = *(p+i);
		p = p + 2*i;
		*p = broj;
	
		rezultat = 0;
		while(broj != 0) {
				rezultat += broj%10;
				broj = broj/10;
			}
		p = p + 1;
		if (rezultat < 0){
			rezultat = rezultat * -1; 
		}
		*p=rezultat;
	}

	return;
}





int izbaci (int* p, int duzReda) {
	
	int i, j, broj, temp1, temp2, n, istinitost=0, brojac, length;
	int *temp;
	
	length = duzReda;
	temp = p;
	brojac = length;

	
	for (i=0; i<length; i++) {
		p = temp;
		istinitost = 0;
		broj = *(p+i);
		temp1 = 1;
		temp2 = 1;
		n=1;
		if (broj <= 0){
			istinitost=0;
		}
		else{
			while (n <= broj){
				if (broj == n){
					istinitost=1;
					break;
				}
				else{
					n = temp1+temp2;
					temp1 = temp2;
					temp2 = n;
					istinitost=0;
				}
			}
		}
		if (istinitost == 1) {
			for (j=i+1; j<length; j++) {
				p = temp;
				temp1 = *(p+j);
				p = p + j - 1;
				*p = temp1;
			}
			length--;
			i--;
		}
	
	}

	return length;
}


int main() {
    int i, niz[duzinaReda*2], brojClanova, duzReda;
    int *p;
	duzReda = duzinaReda;
	
	printf("Unesite niz od %d brojeva: ", duzinaReda);
	
	for (i=0; i < duzinaReda; i++)	{
		scanf("%d", &niz[i]);
	}
	p = &niz[0];
	ubaci(p, duzReda);
	
	duzReda = duzReda*2;
	
	brojClanova = izbaci(p, duzReda);
	
	printf("Modificirani niz glasi: ");
	for (i = 0; i < brojClanova; i++) {
		if (i == brojClanova-1) {
			printf("%d.", *(p+i));
			break;
		}
		printf("%d, ", *(p+i));
		
	}


	return 0;
}
