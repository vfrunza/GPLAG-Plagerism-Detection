#include <stdio.h>

/*ŽALI BOŽE VREMENA IZGUBLJENOG NA OVOM ZADATKU...*/

void sortiraj(int *niz, int n){
	int i, j,temp;
	for(i = 0; i < (n-1); i++){
		for(j = 0; j < (n-1); j++){
			if(*(niz + j) > *(niz + j + 1)){
				temp = *(niz + j + 1);
				*(niz + j + 1) = *(niz + j);
				*(niz + j) = temp;
			}
		}
	}
}

void kopiraj(int *niz1, int *niz2, int n){
	int i;
	for(i = 0; i < n; i++){
		niz2[i] = niz1[i];
	}
}

int presjek(int *niz1, int n1, int *niz2, int n2, int *temp){
	int i = 0, j = 0, c = 0;
	if(n1 == 0 || n2 == 0) return 0;
	while (i < n1 && j < n2){
		if(*(niz1 + i) < *(niz2 + j)){
			i++;	
		}else if(*(niz1 + i) > *(niz2 + j)){
			j++;
		}else{
			//printf("%d", *(niz2 + j));
			*(temp + c) = *(niz2 + j);
			c++;
			i++;
			j++;
		}
		
	}
	return c;
}

int razlika(int *niz1, int n1, int *niz2, int n2){
	int i = 0,j = 0, c = n1;
	int temp1[100];
	int temp2[100];
	if(n2 == 0){
		return n1;
	}else if(n1 == 0){
		return 0;
	}
	
	kopiraj(niz1, temp1, n1);
	kopiraj(niz2, temp2, n2);
	sortiraj(temp1, n1);
	sortiraj(temp2, n2);
	
	while(i < n1 && j < n2 && c > 0){
		if(*(temp1 + i) < *(temp2 + j)){
			i++;
		}else if(*(temp1 + i)  > *(temp2 + j)){
			j++;
		}else if(*(temp1 + i)  == *(temp2 + j)){
			c--;
			i++;
			j++;
		}
	}
	return c;
}

int dva_od_tri(int *niz1, int n1, int *niz2, int n2, int *niz3, int n3){
	int c1 = 0, c2 = 0, c3 = 0;
	int temp[100];
	int temp1[100];
	int temp2[100];
	int temp3[100];
	/*17.12.2017 najvjerovatnije ti ne valja funkcija razlike, presjek ti je dobar*/
	/*
	-NIZOVI SE PRVO SORTIRAJU RADI LAKŠEG PREGLEDANJA UTVRĐIVANJE PRESJEKA NIZOVA
	*/
	/*KOPIRANJE NIZOVA U PRIVREMENE NIZOVE*/
	kopiraj(niz1, temp1, n1);
	kopiraj(niz2, temp2, n2);
	kopiraj(niz3, temp3, n3);
	/*SORTIRANJE NIZOVA*/
	sortiraj(temp1, n1);
	sortiraj(temp2, n2);
	sortiraj(temp3, n3);
	/*PRELAZIMO NA POREĐENJE PRESJEKA I RAZLIKE NIZOVA, ZA TO KORISTIMO NIZ TEMP*/
	/*POHRANJUJEMO PRESJEK PRVOG I DRUGOG NIZA U TEMP I TRAŽIMO RAZLIKU SA TREĆIM NIZOM*/
	c1 = presjek(temp1, n1, temp2, n2, temp);
	c1 = razlika(temp,c1,niz3,n3);
	c2 = presjek(temp2, n2, temp3, n3, temp);
	c2 = razlika(temp,c2,niz1,n1);
	c3 = presjek(temp1, n1, temp3, n3, temp);
	c3 = razlika(temp,c3,niz2,n1);
	//printf("|%d %d %d|", c1, c2, c3);
	return (c1 + c2 + c3);
}



int main() {
	int niz1[100],niz2[100],niz3[100];
	int n1,n2,n3, vrijednost,i;
	/*UNOŠENJE NIZOVA*/
	printf("Unesi velicinu prvog niza: ");
	scanf("%d",&n1);
	printf("Unesi prvi niz:\n");
	for(i = 0; i < n1; i++){
		scanf("%d",(niz1 + i));
	}
	printf("Unesi velicinu drugog niza: ");
	scanf("%d",&n2);
	printf("Unesi drugi niz:\n");
	for(i = 0; i < n2; i++){
		scanf("%d",(niz2 + i));
	}
	printf("Unesi velicinu treceg niza: ");
	scanf("%d",&n3);
	printf("Unesi treci niz:\n");
	for(i = 0; i < n3; i++){
		scanf("%d",(niz3 + i));
	}
	/*--------------------------------------*/
	vrijednost = dva_od_tri(niz1, n1, niz2, n2, niz3, n3);
	//printf("||%d||",razlika(niz1,n1,niz2,n2));

	printf("Vrijednost je: %d", vrijednost);
	return 0;
}
