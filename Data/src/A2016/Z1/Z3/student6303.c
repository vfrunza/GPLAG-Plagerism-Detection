#include <stdio.h>

int main() {
	int br_c=0, br_b=0, br_s=0, br_v=0, br_p=0;
	double udio_c, udio_b, udio_s, udio_v, udio_p;
	double suma;
	char pomocna='z';
	printf("Unesite vozila: ");
	while(pomocna!='k' && pomocna!='K') {
    scanf("%c", &pomocna);
		if(pomocna=='k' || pomocna=='K') break;
		else if(pomocna==' ') {
			printf("Neispravan unos\n"); continue;
		}
		else if(pomocna=='c' || pomocna=='C') br_c++;
		else if(pomocna=='b' || pomocna=='B') br_b++;
		else if(pomocna=='s' || pomocna=='S') br_s++;
		else if(pomocna=='v' || pomocna=='V') br_v++;
		else if(pomocna=='p' || pomocna=='P') br_p++;
		else if(pomocna!='k' || pomocna!='K' || pomocna!='c' || pomocna!='C' && pomocna!='b' || pomocna!='B' || pomocna!='s' || pomocna!='S' || pomocna!='v' || pomocna!='V' || pomocna!='p' || pomocna!='cP' )
		{
			printf("Neispravan unos\n"); continue;
		}
	}
	suma=br_c+br_b+br_s+br_v+br_p;
	udio_c=br_c/suma*100;
	udio_b=br_b/suma*100;
	udio_s=br_s/suma*100;
	udio_v=br_v/suma*100;
	udio_p=br_p/suma*100;
	printf("Ukupno evidentirano %.0f vozila.", suma);
	if(suma==0) printf("\nNajpopularnija boja je crna (0.00%)."); 
	else if(br_c>=br_b && br_c>=br_s && br_c>=br_v && br_c>=br_p) printf("\nNajpopularnija boja je crna (%.2f%).", udio_c);
	else if(br_b>=br_c && br_b>=br_s && br_b>=br_v && br_b>=br_p) printf("\nNajpopularnija boja je bijela (%.2f%).", udio_b);
	else if(br_s>=br_c && br_s>=br_b && br_s>=br_v && br_s>=br_p) printf("\nNajpopularnija boja je siva (%.2f%).", udio_s);
	else if(br_v>=br_c && br_v>=br_b && br_v>=br_s && br_v>=br_p) printf("\nNajpopularnija boja je crvena (%.2f%).", udio_v);
	else if(br_p>=br_c && br_p>=br_b && br_p>=br_s && br_p>=br_v) printf("\nNajpopularnija boja je plava (%.2f%).", udio_p);
	
	return 0;
}
