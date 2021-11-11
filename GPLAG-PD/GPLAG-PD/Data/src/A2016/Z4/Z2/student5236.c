#include <stdio.h>

char*kodiraj(char*string, char*pr_string){
	int brojaci[95] = {0};
	int i = 0, duzina1, max = brojaci[0], p, j = 0, k, n;
	n = 0;
	while (string[n] != '\0'){
		n++;
	}
	duzina1 = n;
	i = 0;
	while (i < duzina1){
		brojaci[string[i] - 32]++;
		i++;
	}
	i = 1;
	while (i < 95) {
		if (brojaci[i] > max){
			max = brojaci[i];
		}
		i++;
	}
	p = max;
	while (p > -1){
		i = 0;
		while (i<95){
			if (brojaci[i] == p){
				k = i + 32;
				pr_string[j] = k;
				j++;
			}
			i++;
		}
		p--;
	}
	pr_string[95] = 0;
	for (i = 0; i < duzina1; i++){
		j = 0;
		while (j < 95) {
			if (string[i] == pr_string[j]){
				string[i] = 126 - j;
				break;
			}
			j++;
		}
	}
	return string;
}
char*dekodiraj(char*string,char*pr_string){
	int i = 0, n, duzina;
	char * niz = string;
	n = 0;
	while (string[n] != '\0'){
		n++;
	}
	duzina = n;
	while (i < duzina) {
		string[i] = pr_string[126 - string[i]];
		i++;
	}
	niz = string;
	return niz;
}
int main()
{
	char string[] = "LLMLNLNMONM";
	char pr_string[100];
	kodiraj(string, pr_string);
	printf("%s", string);
	dekodiraj(string, pr_string);
	printf("%s", string);
	return 0;
}