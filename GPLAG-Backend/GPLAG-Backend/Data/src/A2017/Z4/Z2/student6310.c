#include <stdio.h>

int duzina_rijeci (char *s){
    int duzina = 0;
    while ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')){
        s++;
        duzina++;
    }
    return duzina;
}

int provjeri_duzine (char *s, int *niz, int vel){
    int index = 0;
    while(s != '\0'){
        if((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
        {
            if(duzina_rijeci(s) != niz[index]) return 0;
            while((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) s++;
            index++;
        }
        if(*s == '\0') 
        {
            if(index == vel) return 1;
            else return 0;
        }
        s++;
    }
}


int main() {

	return 0;
}
