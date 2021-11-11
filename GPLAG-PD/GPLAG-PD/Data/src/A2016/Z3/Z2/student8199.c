#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Provjera dva clana za sabiranje i ubacivanje u niz*/

void ubaci (int* p, int len){
	int* var = p;
	int* var2;
	int mem = 0, k = 0, num;

	while (var < p + 2 * len){
		num = abs (*var);
		
		while (num){
			mem += num % 10;
			num /= 10;
		}
	
		for (var2 = p + (len + k); var2 > var; var2--){
			*var2 = *(var2 - 1);
		}
		k++;
		var++;
		*var = mem;
		mem = 0;
		var++;	
	}
}	

/*Kreiranje Fibonaccijevog niza*/

int fib (int num){
	int array[1000];
	
	array[0] = 1;
	array[1] = 1;
	
	if (num == 1) {
		return 1;
	}
	
	int* var1 = array;
	int* var2 = array + 1;
	int* var3 = array + 2;
	
	while (1){
		*var3 = *var2 + *var1;
		
		if (*var3 == num) {
			return 1;
		}
		if (*var3 > num){
			return 0;
		}
		var1++;
		var2++;
		var3++;
	}
}

/*Funkcija izbaci trazi Fibonaccijeve brojeve te ih izbacuje iz niza*/

int izbaci (int*p, int len){
	int *var = p;
	int *var2;
	int num, size = 0;
	
	while (var < p + len){
		
		num = *var;
        num = fib(num);
        if (num == 1){
        	for (var2 = var; var2 < p + len - 1; var2++){
        		*var2 =* (var2 + 1);
         }
        	len--;
        	var--;
    	 }
			var++;
	}
	
	return len;	
}

int main() {
	int i, n, array[100];
	
	printf ("Unesite niz od 10 brojeva: ");
	for (i = 0; i < 10; i++)
		scanf ("%d", &array[i]);
	
	ubaci(array, 10);
	n = izbaci(array, 20);
	
	printf ("Modificirani niz glasi: ");
	for (i = 0; i < n; i++){
		if (i == n - 1)
			printf ("%d.", array[i]);
		else 
			printf ("%d, ", array[i]);
	}
	
	return 0;
}