#include <stdio.h>

int saberiCifre(int broj){
	int rez = 0;
	if(broj < 0) broj*=-1;
	while(broj != 0){
		rez += broj%10;
		broj/=10;
	}
	return rez;
}

void ubaci(int* niz, int vel){
	int i = vel-1;
	for(i; i>=0; i--){
		niz[i*2] = niz[i];
	}
	for(i = 0; i < vel*2; i+=2){
		niz[i+1] = saberiCifre(niz[i]);
	}
}


int isFibonacci(int broj){
	int preth=1, novi=1, temp,i;
	while(novi < broj){
		temp = preth + novi;
		preth = novi;
		novi = temp;
	}
	if(novi == broj) return 1;
	else return 0;
}

int izbaci(int niz[], int vel){
	int i = 0, j = 0, temp;
	for(i; i<vel; i++){
		if(isFibonacci(niz[i]) == 1){
			for(j = i; j < vel - 1; j++){
				temp = niz[j];
				niz[j] = niz[j + 1];
				niz[j + 1] = temp;
			}
			vel--;
			i--;
		}
	}
	return vel;
}

int main() {
	
	int niz[20], vel = 10, i;
	printf("Unesite niz od 10 brojeva: ");
	for(i = 0; i<10; i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz, vel);
	vel*=2;
	vel = izbaci(niz, vel);
	printf("Modificirani niz glasi: ");
	if(vel == 0){
		return 0;
	}
	printf("%d", niz[0]);
	for(i = 1; i<vel; i++)
		printf(", %d", niz[i]);
	printf(".");
	return 0;
}
