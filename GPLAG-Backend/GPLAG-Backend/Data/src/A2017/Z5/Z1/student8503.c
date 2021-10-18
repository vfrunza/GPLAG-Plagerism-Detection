#include <stdio.h>
void ispis_niz (int niz[], int n)
{
if (n == 0)
return; /* nema sta ispisati, prazan niz */
ispis_niz(niz, n - 1);
printf ("%d ", niz [n - 1]);
}
int main(void)
{
int niz[] = {1, 5, 6, 0, 3};
ispis_niz(niz, 5);
return 0;
}