#include <stdio.h>

/* kolko se broj puta ponavlja u nizu */
int provjera_broja(int* niz, int velicina, int br)
{
  int i = 0;
  int broji = 0;
  for (; i < velicina; ++i)
    if (niz[i] == br)
      ++broji;
  return broji;
}

/* dajem samo dio niza da vidim jesam li vec brojao taj broj*/
int da_li_se_ponavlja_prije(int* niz1, int velicina1, int index, int br)
{
  int i = 0;
  for (; i < index && i < velicina1; ++i)
    if (niz1[i] == br)
      return 1;
  return 0;
}

int dva_od_tri_postoji(int* niz1, int velicina1, int* niz2, int velicina2,
                       int* niz3, int velicina3)
{
  int i = 0;
  int brojac = 0;
  /* provjera elemenata prvog niza sa drugim*/
  for (; i < velicina1; ++i) {

    if (da_li_se_ponavlja_prije(niz1, velicina1, i, niz1[i]) == 0) {

      /* broj pojavljivanja niz1[i] u drugom nizu */
      int imal_u_drugom = provjera_broja(niz2, velicina2, niz1[i]);

      /* ako se nalazi samo jednom i ne nalazi se u trecem*/
      if (imal_u_drugom >= 1 && provjera_broja(niz3, velicina3, niz1[i]) == 0)
        ++brojac;
    }
  }
  return brojac;
}

int dva_od_tri(int* niz1, int velicina1, int* niz2, int velicina2, int* niz3,
               int velicina3)
{
  /* pozivamo pregled izmedju prvog i drugog niza onda prvog i treceg pa drugog
  i treceg i sabereno pojavljivanja */
  return dva_od_tri_postoji(niz1, velicina1, niz2, velicina2, niz3, velicina3) +
         dva_od_tri_postoji(niz1, velicina1, niz3, velicina3, niz2, velicina2) +
         dva_od_tri_postoji(niz2, velicina2, niz3, velicina3, niz1, velicina1);
}

int main()
{
  printf("Zadaća 3, Zadatak 1");
  return 0;
}