#include <stdio.h>
#include <math.h>

/* prototipi */
void zaokruzi1(float*, int);
void preslozi(float*, int, int);
int sumaCifara(float);

int main() {
	/* Test kod izbrisan */
	return 0;
}

/* zaoktuzi1 - IMPLEMENTACIJA */
// Funkcija zaokruzuje na najblizu prvu decimalu
void zaokruzi1(float num[], int numLen) {
	int i;
	
	for (i = 0; i < numLen; i++)
		num[i] = round(num[i] * 10.0) / 10.0;
}
// end zaokruzi1

/* preslozi - IMPLEMENTACIJA*/
void preslozi(float num[], int numLen, int k) {
	int i, j, firstNums = 0;
	float tmp;
	
	/* prvo brojeve treba zaokruziti*/
	zaokruzi1(num, numLen);
	
	for (i = 0; i < numLen; i++) {
		/* Ako je njihova suma cifara manja od k, nista sa njih, sami ce biti
		   pomaknuti do kraja*/
		if (sumaCifara(num[i]) < k)
			continue;
		
		/* Inace premjesti broj na njegovu potrebnu poziciju datu sa firstNums */
		for (j = i; j > firstNums; j--) {
			tmp = num[j];
			num[j] = num[j - 1];
			num[j - 1] = tmp;
		}
		
		/* Sljedeci broj po redu */
		firstNums++;
	}
}
// end preslozi

/* sumaCifara - IMPLEMENTACIJA */
/* Funkcija vraca sumu cifara broja, bez obzira je li broj pozitivan ili negativan
   pri tome broj mora biti zaokruzen na jednu decimalu*/
int sumaCifara(float num) {
	int cpNum = (int)(fabs(round(num * 10.0))), sum = 0;
	
	while (cpNum) {
		sum += cpNum % 10;
		cpNum /= 10;
	}
	
	return sum;
}