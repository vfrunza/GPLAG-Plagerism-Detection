#include <stdio.h>

int main() {
	char boja;
	int a=0, b=0, c=0, d=0, e=0;
	printf("Unesite vozila: ");
	for( ; ; ) {
		scanf("%c", &boja);
		if(boja=='\n') {
			continue;
		}
		if(boja=='K'||boja=='k') {
			break;
		}
		else if(boja=='C'||boja=='c') {
			a++;
		}
		else if(boja=='B'||boja=='b') {
			b++;
		}
		else if(boja=='S'||boja=='s') {
			c++;
		}
		else if(boja=='V'||boja=='v') {
			d++;
		}
		else if(boja=='P'||boja=='p') {
			e++;
		}
		else {
			printf("Neispravan unos\n");
		}
	}
	printf("Ukupno evidentirano %d vozila.\n", a+b+c+d+e);
	printf("Najpopularnija boja je ");
	if(a+b+c+d+e==0) {
		printf("crna (0.00%%).");
		return 0;
	}
	if(a>=b&&a>=c&&a>=d&&a>=e) {
		printf("crna (%.2f%%).", (float)a/(a+b+c+d+e)*100);
	}
	else if(b>=a&&b>=c&&b>=d&&b>=e) {
		printf("bijela (%.2f%%).", (float)b/(a+b+c+d+e)*100);
	}
	else if(c>=a&&c>=b&&c>=d&&c>=e) {
		printf("siva (%.2f%%).", (float)c/(a+b+c+d+e)*100);
	}
	else if(d>=a&&d>=b&&d>=c&&d>=e) {
		printf("crvena (%.2f%%).", (float)d/(a+b+c+d+e)*100);
	}
	else {
		printf("plava (%.2f%%).", (float)e/(a+b+c+d+e)*100);
	}
	return 0;
}
