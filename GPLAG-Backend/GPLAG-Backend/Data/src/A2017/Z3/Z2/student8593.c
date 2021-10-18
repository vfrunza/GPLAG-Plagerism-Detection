#include <stdio.h>
#include <math.h>

void zaokruzi1(float* niz, int vel){
	float *pok2=niz;
	while(pok2<niz+vel){
		*pok2=*pok2*10;
		*pok2=round(*pok2);
		*pok2++/=10;
	}
}

void preslozi(float *niz, int vel, int k){
	float *pok=niz;
	float *pok2=pok;
	float *tu_stavi_veci=pok;
	float *tu_stavi_manji=pok;
	float *pok3;
	float *kopija_tu_veci;
	float *kopija_tu_manji;
	int br;
	int suma=0;
	float broj;
	zaokruzi1(pok, vel);
	while(pok2<pok+vel){
		*pok2*=10;
		br=*pok2; //uleti i prva decimala ispred zareza
		*pok2=*pok2/10;
		suma=0;
		br=fabs(br);
		while(br!=0){
			suma=suma+(br%10); //sabere te brojeve(sve ispred i taj jedan iza)
			br/=10;
		}
		if(suma>=k){ 
			pok3=pok2;
			broj=*pok2;             //12 123 678 3 99 9 999 9999 NPR MORA 123 NA MJESTO 12
			//izbaci taj broj iz niza(a pamtim ga u varijabli broj)
			while(pok3<pok+vel-1){ //12 678 3 99 9 999 9999 9999
				*pok3=*(pok3+1);
				pok3++;
			}
			kopija_tu_veci=pok+vel-1;
			while(kopija_tu_veci>tu_stavi_veci){
				*kopija_tu_veci=*(kopija_tu_veci-1); //12 12 678 3 99 9 999 9999
				kopija_tu_veci--;
			}
			//na to mjesto stavi broj
			*tu_stavi_veci=broj; //123 12 678 3 99 9 999 9999
			tu_stavi_veci++;
			tu_stavi_manji++;
			pok2++;
	    }
	    
	    else if(pok2==tu_stavi_manji){tu_stavi_manji++; pok2++;}
	    else{
	        pok3=pok2;
			broj=*pok2; //1234 565 4 6 45 8 900 npr 8 treba na mjesto 45
			while(pok3<pok+vel-1){ //opet izbacamo taj broj 1234 565 4 6 45 900 900
				*pok3=*(pok3+1);
				pok3++;
			}

			kopija_tu_manji=pok+vel-1;
			while(kopija_tu_manji>tu_stavi_manji){
				*kopija_tu_manji=*(kopija_tu_manji-1); //opet novi pok na 45
				kopija_tu_manji--; //1234 565 4 6 45 45 8 900 
			}
			
			*tu_stavi_manji=broj; 
			tu_stavi_manji++;	
			pok2++;

	    }
	}
}

int main() {
//	printf("Zadaća 3, Zadatak 2");
    int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
	return 0;
}
