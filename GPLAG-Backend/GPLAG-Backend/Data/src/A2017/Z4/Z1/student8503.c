#include <stdio.h>
int *Prekopiraj (const int *izv_p, const int *izv_k,
int *odr)
{
while (izv_p < izv_k)
*odr++ = *izv_p++;
return odr; /* vracamo iza kraja! */
}
int main()
{
int niz1[] = {1, 2, 3, 4, 6};
int niz2[50]; /* dovoljno mjesta... */
int *iza_kraja = Prekopiraj(niz1, niz1 + 5, niz2);
/* ispis niza 2*/
int *poc = niz2;
while (poc < iza_kraja)
printf("%i ", *poc++);
return 0;
}
