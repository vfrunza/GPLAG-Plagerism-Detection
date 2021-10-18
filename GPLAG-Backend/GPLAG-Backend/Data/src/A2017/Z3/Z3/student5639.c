#include <stdio.h>
#include <math.h>

int izbaci_cifre(int* niz_cijelih, int vel1, int* niz_cifara, int vel2){
	int i, j, p, q;
	for(p = 0; p < vel2; p++){
		for(q = 0; q < vel2; q++){
			if(niz_cifara[q] < 0 || niz_cifara[q] > 9) return 0;
			if(niz_cifara[q] == niz_cifara[p] && p != q) return 0;
		}
	}
	for(i = 0; i < vel1; i++){
		int brojac = 0;
		int cijeli = fabs(niz_cijelih[i]);
		do{
			cijeli /= 10;
			brojac++;
		} while(cijeli != 0);
		brojac--;
		int cifra = fabs(niz_cijelih[i]);
		int krajnji_niz = 0;
		do {
			cijeli = cifra;
			cijeli /= pow(10, brojac);
			for(j = 0; j < vel2; j++)
				if(cijeli == niz_cifara[j]) break;
				if(j == vel2) {
					krajnji_niz = krajnji_niz * 10 + cijeli;
				}
				cifra = cifra - pow(10, brojac) * cijeli;
				brojac--;
		} while(brojac >= 0);
			
		if(niz_cijelih[i] < 0) {
			niz_cijelih[i] = -1 * krajnji_niz;
		} else {
			niz_cijelih[i] = krajnji_niz;
			}
		}
		return 1;
	}

int main(){
	int niz_cijelih[100],niz_cifara[100];
	int vel1,vel2,i;
	do {
		printf("Unesite velicine nizova: ");
		scanf("%d %d", &vel1,&vel2);
	} while((vel1<1 || vel1>100) && (vel2<1 || vel2>100));

	printf("Unesite elemente niza cijelih brojeva: ");
	for(i=0; i<vel1; i++) {
		scanf("%d", &niz_cijelih[i]);
	}

	printf("Unesite niz cifara: ");
	for(i=0; i<vel2; i++) {
		scanf("%d", &niz_cifara[i]);
	}
	printf("%d", izbaci_cifre(niz_cijelih,vel1,niz_cifara,vel2));
	return 0;
}
