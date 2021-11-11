#include <stdio.h>

int izbaci_cifre(int broj[10], int cifra[10]) {
    
    int i,j;
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
        if(broj[i]==cifra[j]) {
            return 1;
        } else return 0;
        }
    } return broj;
}
int main() {
	
	return 0;
}
