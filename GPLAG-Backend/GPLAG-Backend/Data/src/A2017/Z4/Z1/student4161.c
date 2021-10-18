#include <stdio.h>
#include <math.h>
void unesi(char niz[], int velicina){
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

char* ubaci_broj(char* tekst, int broj){
	int br_cifri=0, i=0,cifra, br=0;
	char c_temp=' ';
	char* pocetak=tekst;
	char* temp;
	int br_temp=broj;
	do{
		br_temp/=10;
		br_cifri++;
	} while(br_temp!=0);
	
	while(*tekst!='\0'){
		if(c_temp!=' ' && *tekst==' '){
			br=0;
			temp=tekst;
			while (*tekst!='\0') {
				if(*tekst!=' ') br++;
				tekst++;
			}
			tekst=temp;
		
			if(br!=0){
			br_temp=fabs(broj);
		/*Ubacivanje minusa*/
			if(broj<0){
				*tekst=' ';
				tekst++;
				temp=tekst;
			    while (*tekst!='\0') tekst++;
				while(tekst>temp){
					*(tekst+1)=*tekst;
					tekst--;
				}
				*tekst='-';
				tekst++;
			}
			
			temp=tekst;
			while (*tekst!='\0') tekst++;
	
		/*Ubacivanje broja*/
			while (tekst>temp) {
				*(tekst+br_cifri+1)=*tekst;
				tekst--;
			}
			if(broj>=0){
			*tekst=' ';
			tekst++;
			}
			for(i=br_cifri-1; i>=0; i--){
				cifra=br_temp/pow(10,i);
				*tekst=cifra+'0';
				br_temp-=cifra*pow(10,i);
				tekst++;
			}
			*tekst=' ';
		}
		}
		c_temp=*tekst;
		tekst++;
	}
	tekst=pocetak;
	return tekst;
}
int main() {
	char tekst[100];
	int broj;
	printf("Unesite tekst: ");
	unesi(tekst,100);
	printf("Unesite broj: ");
	scanf("%d",&broj);
	ubaci_broj(tekst,broj);
	printf("%s",tekst);
	return 0;
}
