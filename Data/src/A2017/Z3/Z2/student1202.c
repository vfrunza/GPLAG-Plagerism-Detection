#include <stdio.h>
#include <math.h>

void zaokruzi1(float * niz, int dim)
{
	while (dim-- > 0)
		niz[dim] = round(niz[dim] * 10) / 10;
}

int suma_cif(float f)
{
	int suma = 0, a;
	a = fabs(f * 10);
	while (a > 0) {
		suma += a % 10;
		a /= 10;
	}
	return suma;
}

void preslozi(float * niz, int dim, int k)
{
	int i, j, l = 0;
	float temp;
	zaokruzi1(niz, dim);
	for (i = 0; i < dim; i++) {
		if (suma_cif(niz[i]) < k)
			//Ako je suma cifara < k, trazi prvi sljedeci broj cija je suma cifara >= k
			for (j = i + 1; j < dim; j++)
				if (suma_cif(niz[j]) >= k) {
					//Sve clanove iza i-tog pomjera ulijevo, a i-ti mijenja mjesto sa j-tim
					temp = niz[j];
					for (l = j; l > i; l--)
						niz[l] = niz[l - 1];
					niz[i] = temp;
					break;
				}
	}
}
int main()
{
	return 0;
}