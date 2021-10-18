#include <stdio.h>
#include <math.h>

/*Funkcija koja zaokruzuje clanove niza na jednu decimalu */

void zaokruzi1(float niz[],int velicina)

{
   int i;
   float zadnja;
   float temp;
   for (i=0; i<velicina; i++) {
      niz[i]*=10;
      temp=niz[i];
      temp*=10;
      zadnja=((int)temp)%10;
      /*U slucaju negativnog broja uzimamo njegovu apsolutnu vrijednost*/
      zadnja=fabs(zadnja);
      niz[i]=(int)niz[i];
      /*Uvjet zaokruzivanja cifre:ako je sljedeca cifra veca  ili jednaka 5 ,zaokruzujemo na vecu decimalu ,i suprotno */
      if(zadnja>=5) {
         if(niz[i]<0)
            niz[i]--;
         else {
            niz[i]++;
         }
      }
      niz[i]/=10;

   }

}
/*Funkcija koja preslaze elemente niza tako da oni cija je suma cifara veca od k budu ispred onih sa manjom vrijednosti ,ne mijenjajuci im raspored*/
void preslozi(float niz[],int velicina,int k)
{
   int suma=0;
   int j=0;
   int l=0;
   int i;
   float temp;

   /*Deklarisemo dva pomocna niza kako bi lakse operirali nad redosljedom clanova */
   float pomocni[1000];
   float pomocni2[1000];
   int cifra;
   zaokruzi1(niz,velicina);
   /*Postupak dobivanja cifara odredenog broja*/
   for(i=0; i<velicina; i++) {
      temp=niz[i];
      temp=temp*10;
      temp=fabs(temp);
      while(temp!=0) {
         cifra=((int)temp)%10;
         suma=suma+cifra;
         temp=temp/10;

      }
      /*Poredimo sumu cifara datih clanova sa unesenim k */
      if(suma>=k) {
         pomocni[j]=niz[i];
         j++;
      } else {
         pomocni2[l]=niz[i];
         l++;
      }
      suma=0;
   }
   /*Sastavljanje dva pomocna niza u finalni niz */
   for(i=0; i<j; i++) {
      niz[i]=pomocni[i];
   }
   for(i=0; i<l; i++) {
      niz[i+j]=pomocni2[i];
   }
}
/*Funkcija ne vraca nista jer je tipa void */



int main ()
{
   float niz[10000];
   int i;
   int k;
   /*Unos niza*/
   for(i=0; i<10000; i++) {
      scanf("%f",&niz[i]);
   }
   /*Printanje niza nakon poziva funkcije zaokruzi */
   for(i=0; i<10000; i++) {
      zaokruzi1(niz,10000);
      printf("\n %.1f",niz[i]);
   }
   /*Unos k i ispis finalnog niza nakon upotrebe funkcije preslozi*/
   printf("Unesi k");
   scanf("%d",&k);
   for(i=0; i<10000; i++) {
      preslozi(niz,10000,k);

      printf("\n %.1f",niz[i]);
   }

   return 0;
}
