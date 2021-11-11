#include <stdio.h>

#define MAXN 80
long long fibonacijevNiz[MAXN + 10];
void generisiFibonacijev() {
	fibonacijevNiz[0] = 1;
	fibonacijevNiz[1] = 1;
	int i;
	for (i = 2; i < MAXN; i++)
		fibonacijevNiz[i] = fibonacijevNiz[i - 1] + fibonacijevNiz[i - 2];
}
int fibBroj(int x) {
	int i;
	for (i = 0; i <= MAXN; i++) {
		if (fibonacijevNiz[i] > x) break;
		if (fibonacijevNiz[i] == x) {
			return 1;
		}
	}
	return 0;
}

void ubaci(int *arr, int n) {
	int i, j;
	int inkr = 0;
	for (i = 0; i < n+n; i += 2) {
		int x = arr[i];
		int sum = 0;
		while (x) {
			sum += (x % 10);
			x /= 10;
		}
		if (sum<0 && arr[i]<0) sum = -sum;
		//printf("Ubacujem - broj = %d, suma = %d, indeks = %d\n", arr[i], sum, i + 1);
		for (j = n - 1 + inkr; j > i; j--) 
			arr[j + 1] = arr[j];
		arr[i + 1] = sum;
		inkr++;
		
	}
}
int izbaci(int *arr, int n) {
	int i, j;
	generisiFibonacijev();
	for (i = 0; i < n; i++) {
		if (fibBroj(arr[i])) {
			for (j = i; j < n - 1; j++)
				arr[j] = arr[j + 1];
			n--;
			i--;
		}
	}
	return n;
}
int main() {
	int i, n;
	int arr[MAXN];
	
	
	//scanf("%d", &n);
	printf("Unesite niz od 10 brojeva: ");
	n = 10;
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	ubaci(arr, n);
	//for (i = 0; i < n + n; i++) printf("%d ", arr[i]);
	int k = izbaci(arr, n+n);
	printf("Modificirani niz glasi: ");
	for (i = 0; i < k - 1; i++) printf("%d, ", arr[i]);
	printf("%d.\n", arr[k - 1]);
	return 0;
}
