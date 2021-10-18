#include <stdio.h>


void unesi(char niz[], int velicina) {
    char znak = getchar();
    if(znak == '\n') znak = getchar();
    int i = 0;
    while(i < velicina - 1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i] = '\0';
}



void najduzi_bp(char* s1, char* s2) {
    
    char* p1 = s1;
    char* p2 = s1;
    char* p3 = s2;
    p2++;
    
    char temp[20];

	while(*p1 != '\0') {
	    
	    if(*p2 = ' ') {
	       p1++; 
	       p2++;
	       *p3 = ' ';
	    }
	    else if (*p2 == *p1) {
	       p1++;
	       p2 = p1;
	    } else {
            *p3 = *p1;	           
	        p2++;
	        p3++;
	    }
	    
	p1++;
	p2 = p1;
	
	}
	
	
	      
 }

	



int main() {
	char tekst[300];
	char niz[300];
	
	printf("Unesite tekst: ");
	
	unesi(tekst, 300);
	
	najduzi_bp(tekst, niz);
	
	
	return 0;
}
