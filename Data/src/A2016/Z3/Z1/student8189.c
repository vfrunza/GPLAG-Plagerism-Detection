#include <stdio.h>
/*Po trebno je napraviti funkciju koja daje proste brojeve svaki put kada se pozove.To cu uraditi koristeci pomocnu funkciju koju sam imenovala sa provjera.*/
int provjera(int n) /*Funkcija provjera ce ici kroz for petlju i isptivati da li je broj prost.*/
{  
   int i;
   for(i=2;i<n;i++){
   if(n%i==0) return 0; /* Ako je ostatak pri dijeljenju broja n sa i koji se svaki put povecava do n jednaka 0 znaci da je 
                           broj slozen i neka funkcija vrati 0, u drugom slucaju ako nije slozen onda je prost i neka vrati 1. */
   }
  return 1;
}
   /*Formiranje funkcije daj_prost */
   int daj_prost()
{   /* Posto ce funkcija u svakom narednom koraku vracati prost broj, potrebno je da osiguramo da ce nam neki broj vratiti zato postavljam staticnu varijablu a=1.*/
     
   int i;
   int static a=1; 
   for(i=a+1;i<10000000;i++){ /*Sada kroz ovu for petlju koristimo ispitivanje prostog broja iz funkcije provjera.*/
                             
   if(provjera(i)==1) {
       a=i; return a;
     }
  }  return 0;
}
int main() {
   int A,B,n,i;
   int suma=0;
   /*Vrsimo klasicno ispitivanje unosa brojeva, kroz do-while petlju, gdje sve mogucnosti uzimamo u obzir.*/
   do  {
      printf("Unesite brojeve A i B: ");
      scanf("%d %d",&A,&B);  
      if(A<1) printf("A nije prirodan broj.\n");
     if(A>=B) printf("A nije manje od B.\n");
   }  while(A>=B || A<1 );
   
   /*U narednoj for petlji pozivamo funkciju daj prost i dodjeljujemo je broju n, kako bi ispostovali uslov zadatka da ispisuje proste brojeve strogo vece
    od A i strogo manje od B i na kraju to dodamo sumi te je ispisemo.*/
   for(i=0;i<B;i++){
   n=daj_prost();
   if(n>A && n<B) 
   suma=suma+n;
   }
     printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
   return 0;
}
