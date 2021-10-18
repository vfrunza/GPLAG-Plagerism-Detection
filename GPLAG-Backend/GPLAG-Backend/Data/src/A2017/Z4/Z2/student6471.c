#include <stdio.h>

int provjeri_duzine(char* tekst, int duzine[], int rijeci) {
   char* t = tekst;
   int rijec = 0;
   int duzina = 0;
   
   if (rijeci <= 0)
   		return 0;

   while (*t != '\0') {
        if ((*t < 'a' || *t > 'z') && (*t < 'A' || *t > 'Z')) {
             if (duzina > 0) {
            	if (duzine[rijec] <= 0 || duzina != duzine[rijec] || rijec > (rijeci-1))
            		return 0;
            	rijec++; 
            	duzina = 0;
            }
        }
        else
           duzina++;
           
        t++;
    }

    if (duzina > 0) {
    	if (duzine[rijec] <= 0 || duzina != duzine[rijec] || rijec != (rijeci - 1))
    		return 0;
    }
    else if (rijec != rijeci)
    	return 0;

    return 1;
}

int main() {
    
	
	/* AT6: Ne-slova na kraju stringa */
	char tekst[] = "Kakav je ovo test!?!?";
	int niz[] = {5,2,3,4};
	int niz2[] = {5,2,3,8};
	int niz3[] = {5,2,3,4,0};
	
	printf("%d ", provjeri_duzine(tekst, niz3, 5));
	printf("%d ", provjeri_duzine(tekst, niz2, 4));
	printf("%d ", provjeri_duzine(tekst, niz, 4));

	return 0;
}