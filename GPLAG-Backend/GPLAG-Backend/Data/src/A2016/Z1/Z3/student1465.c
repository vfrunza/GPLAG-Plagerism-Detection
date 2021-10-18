#include <stdio.h>
#include <math.h>

int main() {
	
	char znak;
	int br_c=0, br_b=0, br_s=0, br_v=0, br_p=0, ukupno_automobila;
	float udio_c, udio_b, udio_s, udio_v, udio_p;
	int br_c2=-1, br_b2=-1, br_s2=-1, br_v2=-1, br_p2=-1;
	int nasao_maks=0;
	printf("Unesite vozila: ");
	do {
		scanf("%c", &znak);
		if(znak != 'c' && znak != 'C' && znak != 'b' && znak != 'B' && znak != 's' && znak != 'S' && znak != 'v' && znak != 'V' && znak != 'p' && znak != 'P' && znak != 'k' && znak != 'K')
		{ printf("Neispravan unos\n"); }
		
		if(znak == 'c' || znak == 'C')
		{
			br_c++;
			if(br_c2 == -1) br_c2 = br_c + br_b + br_s + br_v + br_p;
		}
		else if(znak == 'b' || znak == 'B')
		{
			br_b++;
			if(br_b2 == -1) br_b2 = br_b + br_c + br_s + br_v + br_p;
		}
		else if(znak == 's' || znak == 'S')
		{	
			br_s++;
			if(br_s2 == -1) br_s2 = br_s + br_c + br_b + br_v + br_p;
		} 
		else if(znak == 'v' || znak == 'V') 
		{
			br_v++;
			if(br_v2 == -1) br_v2 = br_v + br_b + br_c + br_p + br_s;
		}
		else if(znak == 'p' || znak == 'P')
		{	
			br_p++;
			if(br_p2 == -1) br_p2 = br_p + br_s + br_b + br_c + br_v;
		}
		}
	while(znak != 'k' && znak != 'K');

		ukupno_automobila = br_c + br_b + br_s + br_v + br_p;
		printf("Ukupno evidentirano %d vozila.", ukupno_automobila);
		if(ukupno_automobila==0) { printf("\nNajpopularnija boja je crna (0.00%)."); return 0; }
		
		udio_c = (br_c/(1. * ukupno_automobila))*100;
		udio_b = (br_b/(1. * ukupno_automobila))*100;
		udio_s = (br_s/(1. * ukupno_automobila))*100;
		udio_v = (br_v/(1. * ukupno_automobila))*100;
		udio_p = (br_p/(1. * ukupno_automobila))*100;
		
		if(br_c > br_b && br_c > br_s && br_c > br_v && br_c > br_p)
			{ 	nasao_maks=1;
				printf("\nNajpopularnija boja je crna (%.2f%%).", udio_c); }
		else if(br_b > br_c && br_b > br_s && br_b > br_v && br_b > br_p)
			{ 	nasao_maks=1;
				printf("\nNajpopularnija boja je bijela (%.2f%%).", udio_b); }
		else if(br_s > br_c && br_s > br_b && br_s > br_v && br_s > br_p)
			{ 	nasao_maks=1;
				printf("\nNajpopularnija boja je siva (%.2f%%).", udio_s); } 
		else if(br_v > br_c && br_v > br_b && br_v > br_s && br_v > br_p)
			{ 	nasao_maks=1;
				printf("\nNajpopularnija boja je crvena (%.2f%%).", udio_v); }
		else if(br_p > br_c && br_p > br_b && br_p > br_s && br_p > br_v)
			{ 	nasao_maks=1;
				printf("\nNajpopularnija boja je plava (%.2f%%).", udio_p); }
			
			if(nasao_maks == 0)
			{
				float maks = udio_c;
				if(udio_b > maks) maks = udio_b;
				else if(udio_s > maks) maks = udio_s;
				else if(udio_v > maks) maks = udio_v;
				else if(udio_p > maks) maks = udio_p;
				
				if(fabs(udio_c - maks)<0.001) printf("\nNajpopularnija boja je crna (%.2f%%).", udio_c);
				else if(fabs(udio_b - maks)<0.001) printf("\nNajpopularnija boja je bijela (%.2f%%).", udio_b);
				else if(fabs(udio_s - maks)<0.001) printf("\nNajpopularnija boja je siva (%.2f%%).", udio_s);
				else if(fabs(udio_v - maks)<0.001) printf("\nNajpopularnija boja je crvena (%.2f%%).", udio_v);
				else if(fabs(udio_p - maks)<0.001) printf("\nNajpopularnija boja je plava (%.2f%%).", udio_p);
			}
		return 0;
}
