#include <stdio.h>
void unesi(char niz[], int velicina) {
	char znak = getchar();
	if(znak=='\n') znak=getchar();
	int i = 0;
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
char* kodiraj(char *s, char *prazan){
	int brojaci[97]={0};
	int i, j, maxi, max, broj=0, duzina=0, min, temp, eror, n=0;    /*min i temp radi selection sorta :) kojeg nisam koristio*/
	char *p;
	char *poc=s;
	char ASCi[97]=" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUFVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	char znak;
	p=prazan;
	while(*s!='\0'){
		if(*s>=' ' && *s<='~') 
			brojaci[*s - ' ']++;   /*pretvorio slovo u indeks u nizu oduzimajuci ascii vr. razmaka*/
		s++;
	}
	max=brojaci[0];
	maxi=0;
	/*treba mi dio u kojem ce se ispunjavat prazan sa sortiranim*/
//	for(i=0; i<97; i++) {
//		min=i;
//		for(j=i+1; j<97; j++) {
//			if(brojaci[j]>brojaci[min])
//				min=j;
//		}
//		if(i!=min) {
//			temp=brojaci[i];
//			brojaci[i]=brojaci[min];
//			brojaci[min]=temp;
//		}
//	}
	for(i=0;i<97;i++)
		if(brojaci[i]>0)
			maxi++;

	for(i=0;i<96;i++){
		max=brojaci[i];
		znak=ASCi[i];
		eror=0;
		for(j=i+1;j<97;j++){
			if(brojaci[j]>max){
				max=brojaci[j];
				brojaci[j]=brojaci[i];
				brojaci[i]=max;
				znak=ASCi[j];
				ASCi[j]=ASCi[i];
				ASCi[i]=znak;
			}
			else if(brojaci[j]==max)
				if((int)znak>(int)ASCi[j] && brojaci[j]!=0){
					znak=ASCi[i];
					ASCi[i]=ASCi[j];
					ASCi[j]=znak;
					eror=1;
				}
		}
		if(eror)
			i=-1;
	}	
		i=maxi;
		for(j=32; j<=126; j++){
			znak=(char)j;
			eror=0;
			for(min=0; min<maxi; min++)
				if(ASCi[min]==znak){
					eror=1;
				}
			if(eror==0){
				ASCi[i]=znak;
				i++;
			}
		}
	for(i=0;i<97;i++)
		prazan[i]=ASCi[i];
	s=poc;
	while(*s!='\0') {
		while(*s!=prazan[n]) {
			n++;
		}
		*s=126-n;
		s++;
		n=0;
	}
	return poc;
}
char* dekodiraj(char *s, char *prazan){
	int n;
	char *p;
	p=s;
	while(*s!='\0'){
		n=*s;
		*s=prazan[126-n];
		s++;
	}
	return p;
}
int main() {
	char kodirat[1000], dekodirat[1000], prazan[100]="";
	printf("Unesite recenicu koju treba kodirat: ");
	unesi(kodirat, 1000);
	kodiraj(kodirat,prazan);
	printf("Unesite recenicu koju treba dekodirat: ");
	unesi(dekodirat, 1000);
	printf("Recenica koju treba kodirat izgleda ovako %s, a recenica koju treba dekodirat izgleda ovako %s.", kodiraj(kodirat, prazan), dekodiraj(dekodirat, prazan));
	return 0;
}