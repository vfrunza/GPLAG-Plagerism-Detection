#include <stdio.h>
#define MAX_PRISUSTVO    10
#define MAX_ISPIT        20
#define MAX_ZADACE       10
#define MAX_ZAVRSNI      40


int main()
{
   float t_ispit1, t_ispit2, t_prisustvo, t_zadace, t_zavrsni, t_ukupno;
   float b_ispit1, b_ispit2, b_prisustvo, b_zadace, b_zavrsni, b_ukupno;
   float m_ispit1, m_ispit2, m_prisustvo, m_zadace, m_zavrsni, m_ukupno;
   int   t_ocjena, b_ocjena, m_ocjena;

/*TARIK*/
   printf("Unesite bodove za Tarika:\n");

   printf("I parcijalni ispit: ");
   scanf("%f", &t_ispit1);
   if (t_ispit1 < 0 || t_ispit1 > MAX_ISPIT)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &t_ispit2);
   if (t_ispit2 < 0 || t_ispit2 > MAX_ISPIT)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &t_prisustvo);
   if (t_prisustvo < 0 || t_prisustvo > MAX_PRISUSTVO)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Zadace: ");
   scanf("%f", &t_zadace);
   if (t_zadace < 0 || t_zadace > MAX_ZADACE)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &t_zavrsni);
   if (t_zavrsni < 0 || t_zavrsni > MAX_ZAVRSNI)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   t_ukupno = t_ispit1 + t_ispit2 + t_zadace + t_prisustvo + t_zavrsni;


   if (t_ukupno < 55)
   {
      t_ocjena = 0;
   }

   else if (t_ukupno >= 55.00 && t_ukupno < 65.00)
   {
      t_ocjena = 6;
   }

   else if (t_ukupno >= 65.00 && t_ukupno < 75.00)
   {
      t_ocjena = 7;
   }

   else if (t_ukupno >= 75.00 && t_ukupno < 85.00)
   {
      t_ocjena = 8;
   }

   else if (t_ukupno >= 85.00 && t_ukupno < 92.00)
   {
      t_ocjena = 9;
   }

   else if (t_ukupno >= 92.00 && t_ukupno <= 100.00)
   {
      t_ocjena = 10;
   }

/*BOJAN*/
   printf("Unesite bodove za Bojana:\n");

   printf("I parcijalni ispit: ");
   scanf("%f", &b_ispit1);
   if (b_ispit1 < 0 || b_ispit1 > MAX_ISPIT)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &b_ispit2);
   if (b_ispit2 < 0 || b_ispit2 > MAX_ISPIT)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &b_prisustvo);
   if (b_prisustvo < 0 || b_prisustvo > MAX_PRISUSTVO)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Zadace: ");
   scanf("%f", &b_zadace);
   if (b_zadace < 0 || b_zadace > MAX_ZADACE)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &b_zavrsni);
   if (b_zavrsni < 0 || b_zavrsni > MAX_ZAVRSNI)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   b_ukupno = b_ispit1 + b_ispit2 + b_zadace + b_prisustvo + b_zavrsni;


   if (b_ukupno < 55)
   {
      b_ocjena = 0;
   }

   else if (b_ukupno >= 55 && b_ukupno < 65)
   {
      b_ocjena = 6;
   }
   else if (b_ukupno >= 65 && b_ukupno < 75)
   {
      b_ocjena = 7;
   }
   else if (b_ukupno >= 75 && b_ukupno < 85)
   {
      b_ocjena = 8;
   }
   else if (b_ukupno >= 85 && b_ukupno < 92)
   {
      b_ocjena = 9;
   }
   else if (b_ukupno >= 92 && b_ukupno <= 100)
   {
      b_ocjena = 10;
   }

/*MIRZA*/
   printf("Unesite bodove za Mirzu:\n");

   printf("I parcijalni ispit: ");
   scanf("%f", &m_ispit1);
   if (m_ispit1 < 0 || m_ispit1 > MAX_ISPIT)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &m_ispit2);
   if (m_ispit2 < 0 || m_ispit2 > MAX_ISPIT)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &m_prisustvo);
   if (m_prisustvo < 0 || m_prisustvo > MAX_PRISUSTVO)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Zadace: ");
   scanf("%f", &m_zadace);
   if (m_zadace < 0 || m_zadace > MAX_ZADACE)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &m_zavrsni);
   if (m_zavrsni < 0 || m_zavrsni > MAX_ZAVRSNI)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   m_ukupno = m_ispit1 + m_ispit2 + m_zadace + m_prisustvo + m_zavrsni;


   if (m_ukupno < 55)
   {
      m_ocjena = 0;
   }
   else if (m_ukupno >= 55 && m_ukupno < 65)
   {
      m_ocjena = 6;
   }

   else if (m_ukupno >= 65 && m_ukupno < 75)
   {
      m_ocjena = 7;
   }

   else if (m_ukupno >= 75 && m_ukupno < 85)
   {
      m_ocjena = 8;
   }
   else if (m_ukupno >= 85 && m_ukupno < 92)
   {
      m_ocjena = 9;
   }
   else if (m_ukupno >= 92 && m_ukupno <= 100)
   {
      m_ocjena = 10;
   }



   if (m_ocjena == 0 && t_ocjena == 0 && b_ocjena == 0)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (m_ocjena != 0 && t_ocjena != 0 && b_ocjena != 0)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   else if ((m_ocjena == 0 && t_ocjena == 0 && b_ocjena != 0) || (m_ocjena == 0 && b_ocjena == 0 && t_ocjena != 0) || (t_ocjena == 0 && b_ocjena == 0 && m_ocjena != 0))
   {
      printf("Jedan student je polozio.\n");
   }
   else if ((m_ocjena > 0 && t_ocjena > 0 && b_ocjena == 0) || (m_ocjena > 0 && b_ocjena > 0 && t_ocjena == 0) || (t_ocjena > 0 && b_ocjena > 0 && m_ocjena == 0))
   {
      printf("Dva studenta su polozila.\n");
   }

   if (m_ocjena > 0 && t_ocjena > 0 && b_ocjena > 0)
   {
      if (m_ocjena == b_ocjena && b_ocjena == t_ocjena)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((m_ocjena == b_ocjena && b_ocjena != t_ocjena) || (m_ocjena == t_ocjena && b_ocjena != t_ocjena) || (b_ocjena == t_ocjena && b_ocjena != m_ocjena))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (m_ocjena != b_ocjena && b_ocjena != t_ocjena && b_ocjena != m_ocjena)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }



   return(0);
}
