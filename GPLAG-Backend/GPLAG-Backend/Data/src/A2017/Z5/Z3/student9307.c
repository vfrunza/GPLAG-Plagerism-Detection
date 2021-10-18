#include <stdio.h>

int main() {
	FILE* dat=fopen("oblici.dat", "rb");
	char ime[100];
	int ucitano = fread (ime, 1, 99, dat);
	ime [ucitano] = '\0';
	fclose (dat);
	return 0;
}
