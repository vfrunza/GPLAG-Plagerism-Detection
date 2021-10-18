#include <stdio.h>
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

int provjeri_duzine(char* tekst, int* niz, int n){
	int br=0, br_rijeci=0;
	while (*tekst!='\0') {
	if((*tekst>='A'&& *tekst<='Z')||(*tekst>='a' && *tekst<='z')) br++;
	else{
	    if(br!=0){
	        if(br!=*niz) return 0;
	        br_rijeci++;
	        niz++;
	        br=0;
	    }
	}
	tekst++;
	if(*tekst=='\0' && br!=0) br_rijeci++;
	}
	if(br_rijeci!=n) return 0;
	else return 1;
}
int main() {
    char tekst[100];
    int niz[100];
    int n=0, i=0;
	printf("Unesi tekst: ");
	unesi(tekst,100);
	printf("Unesi velicinu niza: ");
	scanf("%d",&n);
	printf("Unesi niz: ");
	for(i=0; i<n; i++){
	    scanf("%d",&niz[i]);
	}
	printf("%d",provjeri_duzine(tekst, niz,n));
	return 0;
}
