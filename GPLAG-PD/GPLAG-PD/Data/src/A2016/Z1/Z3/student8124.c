#include <stdio.h>
#include <conio.h>

int main ()
{
  char ch;
  printf("Unesite vozila: ");

  int broj_c = 0;
  int broj_b = 0;
  int broj_s = 0;
  int broj_v = 0;
  int broj_p = 0;

  int ukupno;

  int broj_pojave_najpop_boje;
  int rbr_najpop_boje;

  do {

    ch = getch();

    if (ch == 'C' || ch == 'c') {
        broj_c = broj_c + 1;
        putch(ch);
    }
    else if (ch == 'B' || ch == 'b') {
        broj_b = broj_b + 1;
        putch(ch);
    }
    else if (ch == 'S' || ch == 's') {
        broj_s = broj_s + 1;
        putch(ch);
    }
    else if (ch == 'V' || ch == 'v') {
        broj_v = broj_v + 1;
        putch(ch);
    }
    else if (ch == 'P' || ch == 'p') {
        broj_p = broj_p + 1;
        putch(ch);
    }
    else
        printf("Neispravan unos");

  } while (ch != 'k' && ch != 'K');


  ukupno = broj_c + broj_b + broj_s + broj_v + broj_p;

  printf("\nUkupno evidentirano %d vozila.\n", ukupno);


  broj_pojave_najpop_boje = broj_c;
  rbr_najpop_boje = 1;

  if (broj_b > broj_pojave_najpop_boje) {
    rbr_najpop_boje = 2;
    broj_pojave_najpop_boje = broj_b;
  }

  if (broj_s > broj_pojave_najpop_boje) {
    rbr_najpop_boje = 3;
    broj_pojave_najpop_boje = broj_s;
  }

  if (broj_v > broj_pojave_najpop_boje) {
    rbr_najpop_boje = 4;
    broj_pojave_najpop_boje = broj_v;
  }

  if (broj_p > broj_pojave_najpop_boje) {
    rbr_najpop_boje = 5;
    broj_pojave_najpop_boje = broj_p;
  }


  printf("\nNajpopularnija boja je %");

  if (rbr_najpop_boje == 1)
    printf("crna");
  else if (rbr_najpop_boje == 2)
    printf("bijela");
  else if (rbr_najpop_boje == 3)
    printf("siva");
  else if (rbr_najpop_boje == 4)
    printf("crvena");
  else
    printf("plava");

  printf(" (%.2f%%).", (broj_pojave_najpop_boje*100.0)/ukupno);

  return 0;
}