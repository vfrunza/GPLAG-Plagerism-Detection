#include <stdio.h>

int prebroji (char* p) {
    int broj=0;
    
    while(*p != '\0' && ((*p>='a' && *p<='z') || (*p>='A' && *p<='Z'))) {
        p++;
    broj++;
}
    return broj;
}

int duzina_stringa (char* s) {
    int razmak=1, br=0;
    
    while(*s != '\0') {
        
        if (!(*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) razmak=1;
        else if(razmak) {
            razmak=0;
            br++;
        }
        s++;
    }
    return br;
}

int slovo (char s) {
    if((s>='a' && s<='z') || (s>='A' && s<='Z')) return 1;
    return 0;
}

int provjeri_duzine (const char* s, int niz[], int vel) {
    int broj_znakova = duzina_stringa(s), i=0, nekiznak=1;
        
    while(*s!='\0') {
        const char* pok = s;
        
        if (!slovo(*pok)) nekiznak=1;
        else if (nekiznak) {
            nekiznak=0;
            if(niz[i] != prebroji(s)) return 0;
            i++;
            pok--;
        }
            s++;
        }
        
    if (broj_znakova != vel) return 0;
    return 1;
}

int main() {
    
    char tekst[] = "Ovo je neki primjer teksta";
    int niz[]={3, 2, 4, 7, 6};
    printf("%d ", provjeri_duzine(tekst, niz, 5));

	return 0;
}
