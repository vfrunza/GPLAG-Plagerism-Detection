#include <stdio.h>

void unesi(char niz[], int velicina) {
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

int jeLiSlovo(char c){
    if((c>='A' && c<='Z')||(c>='a' && c<='z'))return 1;
    return 0;
}

int provjeri_duzine(char *s,int niz[],int n){
    char *str=s;
    int q=0,counter=0;
    while(*str!='\0'){
        if(jeLiSlovo(*str)){
        counter++;
        while(jeLiSlovo(*str))str++;
        if(*str=='\0')continue;
        }
        str++;
    }
    if(counter!=n)return 0;
    counter=0;
    str=s;
    while(*str!='\0'){
        if(jeLiSlovo(*str)){
            counter=0;
            while(jeLiSlovo(*str)){
                counter++;
                str++;
            }
            if(q>n)return 0;
            if(counter!=niz[q])return 0;
            if(*str=='\0')break;
            q++;
        }
        str++;
    }
    return 1;
}

int main() {
    char tekst[] = "Ovo je neki primjer teksta";
int niz[] = {3, 2, 4, 7, 6};
int bezveze_niz[] = {1, 2, 3, 4, 5};

printf("%d ", provjeri_duzine(tekst, niz, 5));
printf("%d ", provjeri_duzine(tekst, bezveze_niz, 5));
	return 0;
}
