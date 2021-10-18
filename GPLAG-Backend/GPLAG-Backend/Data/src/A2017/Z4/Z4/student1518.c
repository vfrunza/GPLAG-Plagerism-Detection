#include <stdio.h>

int provjeri (char* s) {
    char* pamti=s;
    char* pomocni;
    int pomocna=0;
    while (*s) {
        if (*s=='<') {
            pomocna=5;
            break;
        }
        s++;
    }
    if (pomocna==0) return 1;
    s=pamti;
    while (*s) {
        if (*s=='>' && *(s+1)==' ' || *s=='<' && *s==' ') return 0;
        s++;
    }
    s=pamti;
    while (*s) {
        if (*s=='<' && *(s+1)>='a' && *(s+1)<='z') {
            pomocni=s+1;
            while (*s) {
                s++;
                if (*s=='<' && *(s+1)=='/' && *(s+1)!=*pomocni) return 0;
            }
        } 
        s++;
    }
    return 1;
}

int main() {
	return 0;
}
