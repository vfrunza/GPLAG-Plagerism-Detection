#include <stdio.h>

int Slovo(char s) {
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) return 1;
    else return 0;
}

int brojrijeci(char* s) {
    int brojac=0;
    while(*s != '\0') {
        if(Slovo(*s)) {
            brojac++;
            while(Slovo(*s)) s++;
            s--;
        }
        s++;
    }
    return brojac;
}

int provjeri_duzine (char* s, int niz[], int vel) {
    int i=0, brojac;

    if(vel != brojrijeci(s)) return 0;

    while(*s != '\0') {

        if (Slovo(*s)) {
            
            brojac = 0;
            while(Slovo(*s)) {
                brojac++;
                s++;
            }
            s--;

            if(niz[i] != brojac) return 0;
            i++;
        }
        
        s++;
    }
    return 1;
}
int main()
{

    return 0;
}
