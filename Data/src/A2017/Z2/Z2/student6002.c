#include <stdio.h>

int main() {
int n, i, niz[100];
printf ("Unesite velicinu niza: ");
scanf("%d", &n);
   for (i=0; i<n; i++) {
        scanf("%d", &niz[i]);
        if (niz[i] < 0)
        i--;
    }
    
    
    
	return 0;
}
