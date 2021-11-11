#include <stdio.h>

/*Funkcija "daj_prost" pomocu staticke varijable izbacuje sljedeci prost broj, pocevsi od broja 2*/

int daj_prost () {
	int i, prost;
	static int num=1;
	do{
		prost=1;
		num++;
		if(num==2) continue;
		for(i=2; i<num; i++){
			if(num%i == 0){
				prost=0;
				break;
			}
		}
	}while(prost==0);
	return num;
}

/*Funkcija "main" trazi od korisnika unos dva broja, nakon cega ispisuje na ekran zbir svih prostih brojeva izmedju ta dva broja*/

int main() {
	int a, b, i, suma=0, temp;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a<1) printf("A nije prirodan broj.\n");
		else if(a>=b) printf("A nije manje od B.\n");
	}while(a>=b || a<1 || b<1);
	
	do{
		temp=daj_prost();
		if(temp>a && temp<b) suma = temp;
	}while(temp<=a);
	
	for(i=1;i>0;i++){
		temp = daj_prost();
		if(temp<b) suma+=temp;
		else break;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
