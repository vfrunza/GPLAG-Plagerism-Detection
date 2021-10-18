#include <stdio.h>
int prebroji_rijeci(char s[]){ //brojimo rijeci
    int br_rj=0, let=0;
    while (*s) {
        if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
            let=0; 
        } else if(let==0){
            let=1;
            br_rj++;
        } s++;
    } return br_rj;
}

int provjeri_duzinu(char s[], int niz[], int len) {
    char*p=s;
    int br_s=0;
    int*r=niz;
    while(*s) {
        br_s=0;
        while ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) { //brojimo slova
            s++; 
            br_s++;
        } 
        if (r-niz < len && br_s==*r){
            if(r-niz<prebroji_rijeci(p)) {
                r++;
            } else return 0;
        } else if(len<prebroji_rijeci(p)) return 0;
        else if(*s && !((*s>='a' && *s<='z')|| (*s>='A' && *s<='Z'))) s++;
        else return 0;
    }
    if(r-niz==len) return 1;
    else return 0;
}
    
int main() {
    char s[] = "Ovo je neki primjer teksta";
    int niz1={3,2,4,7,6};
    int niz2={1,2,3,4,5};
    
    printf("%d", provjeri_duzinu(s, niz1, 5));
    printf("%d", provjeri_duzinu(s, niz2, 5));
	return 0;
}
