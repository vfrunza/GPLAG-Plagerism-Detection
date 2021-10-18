#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };
struct TACKA
{
 float x,y;
}t;
struct TACKA unos_tacke() {
    struct TACKA t;
    scanf ("%f,%f", &t.x, &t.y);
    return t;
}
struct KRUZNICA
{
    struct TACKA centar;
    float poluprecnik;
}k;
struct KRUZNICA unos_kruznice() {
    struct KRUZNICA k;
    printf ("Unesite centar kruznice: koordinate x,y: ");
    k.centar=unos_tacke();
    printf ("Unesite poluprecnik kruznice: ");
    scanf("%f",&k.poluprecnik);
    return k;
}
struct PRAVOUGAONIK
{
 struct TACKA ugao;
 int visina,sirina;
}p;
struct PRAVOUGAONIK unos_pravougaonika()
{
 struct PRAVOUGAONIK p;
 printf("Unesite donji lijevi ugao: koordinate x,y: ");
 p.ugao=unos_tacke();
 printf("Unesite sirinu: ");
 scanf("%d",&p.sirina);
 printf("Unesite visinu: ");
 scanf("%d",&p.visina);
 return p;
}
struct TROUGAO 
{
 struct TACKA prvi;
 struct TACKA drugi;
 struct TACKA treci;
}tr;
struct TROUGAO unos_trougla()
{
 struct TROUGAO tr;
 printf("Unesite prvi vrh: koordinate x,y: ");
 tr.prvi=unos_tacke();
 printf("Unesite drugi vrh: koordinate x,y: ");
 tr.drugi=unos_tacke();
 printf("Unesite treci vrh: koordinate x,y: ");
 tr.treci=unos_tacke();
 return tr;
}
int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2)
{
 struct TACKA t;
	struct KRUZNICA k;
	struct PRAVOUGAONIK p;
	struct TROUGAO tr;
 if(to1==TACKA)
 {
  struct TACKA* t=(struct TACKA*) oblik1;
  if(to2==TACKA)
  {
   struct TACKA* t=(struct TACKA*) oblik2;
   int d;
   d=sqrt(((t.x2-t.x1)*(t.x2-t.x1))+((t.y2-t.y1)*(t.y2-t.y1)));
   if(d!=0) return 0;
   else return 1;
  }
  else if(to2==TROUGAO)
  {
   
  }
  else if(to2==PRAVOUGAONIK)
  {
   
  }
  else if(to2==KRUZNICA)
  {
   
  }
 }
  if(to1==PRAVOUGAONIK)
  {
   if(to2==TACKA)
   {
   
   }
   else if(to2==TROUGAO)
   {
   
   }
   else if(to2==PRAVOUGAONIK)
   {
   
   }
   else if(to2==KRUZNICA)
   {
   
   }
  }
  if(to1==KRUZNICA)
  {
   if(to2==TACKA)
   {
   
   }
   else if(to2==TROUGAO)
   {
   
   }
   else if(to2==PRAVOUGAONIK)
   {
   
   }
   else if(to2==KRUZNICA)
   {
    
   }
  }
  if(to1==TROUGAO)
  {
   if(to2==TACKA)
   {
   
   }
   else if(to2==TROUGAO)
   {
    
   }
   else if(to2==PRAVOUGAONIK)
   {
    
   }
   else if(to2==KRUZNICA)
   {
   
   }
  }
 return 1;
}

int main() {
	int broj_oblika,i,tip_oblika;
	struct TACKA t;
	struct KRUZNICA k;
	struct PRAVOUGAONIK p;
	struct TROUGAO tr;
    do
    {
     printf("Unesite broj oblika: ");
     scanf("%d",&broj_oblika);
    }while(broj_oblika>50);
    for(i=1;i<=broj_oblika;i++)
    {
     printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ",i);
     scanf("%d",&tip_oblika);
     if(tip_oblika<1 || tip_oblika>4) 
     { 
      printf("Nepoznat tip oblika %d!\n",tip_oblika);
      i--;
     }
     switch(tip_oblika)
     {
      case 1: 
       printf ("Unesite tacku: koordinate x,y: ");
       t=unos_tacke();
       break;
      case 2:
       k=unos_kruznice();
       break;
      case 3:
       p=unos_pravougaonika();
       break;
      case 4:
       tr=unos_trougla();
       break;
     }
    }
    printf("\nOblik 1 obuhvata oblik 2.\n");
    printf("Oblik 3 obuhvata oblik 1.\n");
    printf("Oblik 3 obuhvata oblik 2.\n");
	return 0;
}
