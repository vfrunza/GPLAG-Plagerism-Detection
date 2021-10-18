#include <stdio.h>
#include <stdbool.h>

bool provjeri_duzine(char *recenica, int niz[], int velicina_niza){
    int br_rijeci=0,br_slova=0;
    char zadnji_char;
    int zadnja_pozicija = 0;
    while (*recenica!='\0') {
        if(br_rijeci>=velicina_niza) return false;
        if((*recenica>='A' && *recenica<='Z')||(*recenica>='a'&& *recenica<='z')){
            recenica++;
            br_slova++;
        }
        else {
            if(br_slova==niz[br_rijeci] && br_slova>0) {
                br_rijeci++;
                br_slova=0;
                recenica++;
                zadnji_char=*recenica;
                zadnja_pozicija++;
                if(!((zadnji_char>='A' && zadnji_char<='Z') || (zadnji_char>='a' && zadnji_char<='z')) && br_rijeci==velicina_niza) {
                    br_rijeci--;
                }
            }
            else if(br_slova>0) return false;
            else recenica++;
        }
    }
    
    if(!((zadnji_char>='A' && zadnji_char <= 'Z') || (zadnji_char>='a' && zadnji_char<='z')) &&  zadnja_pozicija==br_rijeci)return false;
    br_rijeci++;
    if (br_rijeci!=velicina_niza)  return false;
    
    return true;
}
int main() {
    
    char* niz = "rijec-rijec-";
    int niz_brojeva[] = {5,5};
    printf("%d\n", provjeri_duzine(niz, niz_brojeva,2));

	return 0;
}
